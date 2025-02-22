#ifndef _ADXL335_H
    #define _ADXL335_H

    #include "pico/stdlib.h"

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
     * @return Aceleração da gravidade no eixo escolhido.
     */
    uint16_t read_acceleration(ADC adc);
#endif