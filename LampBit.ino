#include <WiFi.h>
#include <PubSubClient.h>

// Configurações editáveis
const char* TOPICPREFIX      = "lampbit";
const char* TOPICO_SUBSCRIBE = "/TEF/lampbit/cmd";
const char* TOPICO_PUBLISH_1 = "/TEF/lampbit/attrs";
const char* TOPICO_PUBLISH_2 = "/TEF/lampbit/attrs/l";

const bool  Simulation  = true;
const char* SSID        = Simulation ? "Wokwi-GUEST" : "FIAP-IBM";
const char* PASSWORD    = Simulation ? ""            :"Challenge@24!";
const char* BROKER_MQTT = "18.188.61.163";
const int   BROKER_PORT = 1883;
const char* ID_MQTT     = "fiware_bit";
const int   LED_PIN     = 2;

WiFiClient espClient;
PubSubClient MQTT(espClient);
char estadoSaida = '0';

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW); // Inicializa LED desligado

    WiFi.begin(SSID, PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(100);
        Serial.print(".");
    }
    Serial.println("\nConectado à rede WiFi");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());

    MQTT.setServer(BROKER_MQTT, BROKER_PORT);
    MQTT.setCallback(mqtt_callback);

    while (!MQTT.connected()) {
        if (MQTT.connect(ID_MQTT)) {
            MQTT.subscribe(TOPICO_SUBSCRIBE);
            MQTT.publish(TOPICO_PUBLISH_1, "s|on");
        } else {
            Serial.println("Falha ao conectar ao MQTT, tentando novamente em 2s");
            delay(2000);
        }
    }

    // Animação do LED durante a inicialização
    for (int i = 0; i < 10; i++) {
        digitalWrite(LED_PIN, !digitalRead(LED_PIN));
        delay(200);
    }
}

void loop() {
    if (!MQTT.connected()) {
        while (!MQTT.connected()) {
            if (MQTT.connect(ID_MQTT)) {
                MQTT.subscribe(TOPICO_SUBSCRIBE);
            } else {
                delay(2000);
            }
        }
    }
    MQTT.loop();
    handleLuminosity();
    enviarEstadoOutputMQTT();
}

void mqtt_callback(char* topic, byte* payload, unsigned int length) {
    String msg;
    for (unsigned int i = 0; i < length; i++) {
        msg += (char)payload[i];
    }

    if (msg == String(TOPICPREFIX)+"@on|") {
        digitalWrite(LED_PIN, HIGH);
        estadoSaida = '1';
    } else if (msg == String(TOPICPREFIX)+"@off|") {
        digitalWrite(LED_PIN, LOW);
        estadoSaida = '0';
    }
}

void enviarEstadoOutputMQTT() {
    String status = (estadoSaida == '1') ? "s|on" : "s|off";
    MQTT.publish(TOPICO_PUBLISH_1, status.c_str());
    Serial.println("Estado do LED enviado ao broker!");
    delay(1000);
}

void handleLuminosity() {
    int sensorValue = analogRead(34);
    int luminosidade = map(sensorValue, 0, 4095, 0, 100);
    String mensagem = String(luminosidade);
    MQTT.publish(TOPICO_PUBLISH_2, mensagem.c_str());
    Serial.print("Luminosidade: ");
    Serial.println(mensagem);
}
