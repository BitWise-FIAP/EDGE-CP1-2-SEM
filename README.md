# Projeto de Monitoramento de Luminosidade com ESP32 e FIWARE

**Bruno Biletsky** - RM: 554739

**Enrico Ricarte** - RM: 558571

**Victor Freire** - RM: 556191

## Introdução
O **Projeto de Monitoramento de Luminosidade com ESP32 e FIWARE** é uma iniciativa inovadora que explora a integração entre computação na borda e na nuvem para o monitoramento em tempo real das condições ambientais. Utilizando o módulo **ESP32 DOIT Devkit V1** e a plataforma **FIWARE**, o projeto coleta dados de luminosidade através de um sensor LDR (Light Dependent Resistor) e os transmite para uma instância do FIWARE Context Broker hospedada na **AWS (Amazon Web Services)**.

## Objetivo
O objetivo principal deste projeto é demonstrar a eficácia e a funcionalidade da arquitetura de computação na borda (edge computing) combinada com soluções de computação em nuvem. Através da coleta e análise de dados de luminosidade, buscamos evidenciar como dados podem ser processados localmente e sincronizados com a nuvem para uma análise mais abrangente e decisões informadas.

## Componentes e Tecnologias
### Hardware
- **ESP32 DOIT Devkit V1**: Um microcontrolador versátil com conectividade Wi-Fi e Bluetooth, ideal para aplicações IoT.
- **Sensor LDR**: Um resistor dependente de luz que mede a intensidade da luminosidade em um ambiente.

### Software
- **FIWARE**: Plataforma de código aberto que permite a construção de soluções digitais avançadas, utilizada para o gerenciamento e análise dos dados.
- **AWS (Amazon Web Services)**: Serviço de nuvem que hospeda a instância do FIWARE Context Broker.
- **Arduino IDE**: Ambiente de desenvolvimento utilizado para a programação do ESP32.
- **Simulador ONLINE Wokwi**: Ambiente virtual onde a simulação do projeto foi realizada.

## Implementação
1. **Montagem do Circuito**:
   - O sensor LDR é conectado ao ESP32 através de uma protoboard, permitindo que o microcontrolador leia e interprete os valores de luminosidade.

2. **Desenvolvimento do Código**:
   - Programamos o ESP32 para coletar dados do sensor LDR e enviar essas informações para o FIWARE Context Broker. O código foi desenvolvido em [linguagem específica, como C++ ou Python] e configurado para garantir a comunicação eficaz com a plataforma FIWARE.

3. **Configuração do FIWARE**:
   - Instalamos e configuramos o FIWARE Context Broker em uma máquina virtual na AWS, preparando-o para receber e processar os dados de luminosidade enviados pelo ESP32.

4. **Integração e Testes**:
   - Realizamos testes para verificar a comunicação entre o ESP32 e o FIWARE, assegurando a integridade dos dados transmitidos e a resposta do sistema para garantir o correto funcionamento.

## Funcionalidades
- **Coleta de Dados em Tempo Real**: O sensor LDR mede continuamente a luminosidade do ambiente e transmite essas informações para o FIWARE.
- **Análise na Nuvem**: A plataforma FIWARE processa os dados recebidos, oferecendo ferramentas para análise e visualização detalhada das informações de luminosidade.
- **Arquitetura Edge-to-Cloud**: Demonstra a eficácia da combinação entre processamento local e armazenamento na nuvem, permitindo um gerenciamento de dados mais eficiente.
- **Alterar o estado do LED**: É possível ligar e desligar o LED do ESP32 através de publicações via Postman. (espécie de smart lamp) 

## Resultados Esperados
Esperamos que este projeto evidencie a eficácia da arquitetura de edge computing na coleta e gerenciamento de dados em tempo real. Além disso, destacamos a capacidade do FIWARE em integrar e processar informações provenientes de diferentes fontes. O projeto visa ilustrar como a combinação de tecnologias modernas pode criar soluções inteligentes e eficazes para o monitoramento ambiental.

## Conclusão
O **Projeto de Monitoramento de Luminosidade com ESP32 e FIWARE** serve como um protótipo funcional que integra hardware e software em um ambiente IoT. Ele oferece uma visão prática da implementação de soluções de edge computing e sua sincronização com a nuvem, estabelecendo uma base sólida para futuros desenvolvimentos em áreas semelhantes.
