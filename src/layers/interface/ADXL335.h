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

    #define X_axis_GPIO 26
    #define Y_axis_GPIO 27
    #define Z_axis_GPIO 28

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
     * @brief Lê a aceleração da gravidade em um eixo escolhido.
     *
     * Esta função lê o valor de tensão de uma das saídas do módulo ADXL335 através do ADC da Raspberry Pi Pico W.
     * 
     * @param adc ADC que deve ser utilizado para a leitura.
     *
     * @return Aceleração da gravidade no eixo escolhido.
     */
    uint16_t read_acceleration(ADC adc);

    /**
     * @brief Configura e inicializa o módulo
     */
    void setup_ADXL335_module();

    /**
     * @brief Lê os dados do sensor e atuliza o contexto global da aplicação
     */
    void run_ADXL335_module();
#endif