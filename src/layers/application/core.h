/**
 * @file core.h
 * @author Vítor Pereira Fontes
 * @date 2025-02-22
 * 
 * @brief Arquivo de cabeçalho para as funções principais da aplicação, que irão controlar efetivamente os 
 * demais componentes. Abarca a definição das GPIO's e configurações utilizadas para cada componente.
 */
#ifndef _CORE_H
    #define _CORE_H

    /**
     * @brief Realiza o processamento dos dados advindos do acelerômetro
     *
     * Esta função converte os valores lidos pelo acelerômetro em ângulos de rotação (pitch e roll)
     */
    void process_ADXL335_data();
#endif