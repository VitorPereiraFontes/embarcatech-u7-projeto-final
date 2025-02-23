/**
 * @file button.h
 * @author Vítor Pereira Fontes
 * @date 2025-02-22
 * 
 * @brief Arquivo de cabeçalho do callback da interrupção a ser disparada quando o usuário pressionar os botões
 */
#ifndef _BUTTON_H
    #define _BUTTON_H

    #include "pico/stdlib.h"

    /**
     * @brief Função de callback para as interrupções disparadas pelas GPIOs
     *
     * @param gpio Qual GPIO disparou a interrupção
     * @param event_mask Máscara de bits contendo os eventos que fizeram a interrupção ser disparada
     */
    void interruption_callback(uint gpio, uint32_t event_mask);
#endif