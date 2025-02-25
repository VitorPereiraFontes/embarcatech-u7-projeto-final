/**
 * @file ADXL335.h
 * @author Vítor Pereira Fontes
 * @date 2025-02-22
 * 
 * @brief Arquivo de cabeçalho para as funções que irão interagir diretamente com o acelerômetro ADXL335
 */

#ifndef _ADXL335_H
    #define _ADXL335_H

    #include "pico/stdlib.h"

    #define X_AXIS_GPIO 27
    #define Y_AXIS_GPIO 26
    #define Z_AXIS_GPIO 28
    #define TYPICAL_SENSITIVITY 0.330f // Sensibilidade do sensor
    #define ZERO_G_VOLTAGE 1.5f // Tensão do sensor em repouso, para os eixos X e Y, numa superfície completamente plana
    #define XY_ZERO_G_OFFSET 0.15f // Valor da variação que o sensor considera como em repouso para os eixos X, Y e Z
    #define XY_MAX_VOLTAGE 1.98f // Tensão máxima que o sensor consegue medir, para os eixos X e Y, em uma variação de +- 1g
    #define XY_MIN_VOLTAGE 1.02f // Tensão mínima que o sensor consegue medir, para os eixos X e Y, em uma variação de +- 1g
    #define Z_ZERO_G_OFFSET 0.3f // Valor da variação que o sensor considera como em repouso para o eixo Z
    #define ADC_MAX_VALUE 4095.f

    /*
     * Enumeração que representa as entradas no multiplexador do ADC do RP2040.
     * Cada constante representa uma entrada no multiplexador.
     * A contagem começa no 0 e vai incrementando em 1.
     */
    typedef enum {
        ADC0,
        ADC1,
        ADC2,
    } ADC;

    /**
     * @brief Arredonda a parte decimal de um número em ponto flutuante para que hajam apenas duas casas decimais
     *
     * @param value Valor que será arredondado
     *
     * @return Valor com duas casas decimais
     */
    float roud_to_2_decimal(float value);

    /**
     * @brief Lê a aceleração da gravidade em um eixo escolhido.
     *
     * Esta função lê o valor de tensão de uma das saídas do módulo ADXL335 através do ADC da Raspberry Pi Pico W.
     * 
     * @param adc ADC que deve ser utilizado para a leitura.
     *
     * @return Aceleração da gravidade no eixo escolhido.
     */
    float read_acceleration(ADC adc);

    /**
     * @brief Configura e inicializa o módulo
     */
    void setup_ADXL335_module();

    /**
     * @brief Lê os dados do sensor e atuliza o contexto global da aplicação
     */
    void run_ADXL335_module();
#endif