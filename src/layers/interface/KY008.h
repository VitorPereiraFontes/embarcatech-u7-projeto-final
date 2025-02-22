/**
 * @file KY008.h
 * @author Vítor Pereira Fontes
 * @date 2025-02-22
 * 
 * @brief Arquivo de cabeçalho para as funções que irão interagir diretamente com o MOSFET 
 * 2N7000 que controla a passagem de corrente para o módulo transmissor de laser KY008
 */

#ifndef _KY008_H
    #define _KY008_H

    #include "pico/stdlib.h"

    /**
     * @brief Altera o nivel lógico da GPIO conectada ao pino gate do MOSFET
     * 
     * @param gpio GPIO que deve ter seu nível lógico alterado
     */
    void toggle_signal(uint8_t gpio);

    /**
     * @brief Lê nivel lógico da GPIO conectada ao pino gate do MOSFET
     * 
     * @param gpio GPIO que deve ser utilizada para a leitura
     *
     * @return Verdadeiro ou falso
     */
    bool read_signal(uint8_t gpio);
#endif