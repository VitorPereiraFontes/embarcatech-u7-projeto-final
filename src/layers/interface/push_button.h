/**
 * @file push_button.h
 * @author Vítor Pereira Fontes
 * @date 2025-02-22
 * 
 * @brief Arquivo de cabeçalho para as funções que irão interagir diretamente com o push_button
 */

#ifndef _PUSH_BUTTON_H
    #define _PUSH_BUTTON_H

    #include "pico/stdlib.h"

    #define PUSH_BUTTON_A_GPIO 5
    #define PUSH_BUTTON_B_GPIO 6

    /**
     * @brief Inicializa e configura o push button conectado à uma GPIO
     *
     * @param gpio GPIO a qual o push button está conectado
     */
    void setup_push_button(uint8_t gpio);

    /**
     * @brief Verifica se o push button está pressionado
     *
     * @param gpio GPIO a qual o push button está conectado
     * 
     * @return Verdadeiro ou falso
     */
    bool read_push_button_state(uint8_t gpio);

    /**
     * @brief Inicializa e configura o bloco
     */
    void initialize_push_button_block();
#endif