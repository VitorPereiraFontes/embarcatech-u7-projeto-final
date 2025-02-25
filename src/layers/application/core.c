/**
 * @file core.h
 * @author Vítor Pereira Fontes
 * @date 2025-02-23
 * 
 * @brief Arquivo de cabeçalho para as funções principais da aplicação, que irão processar os dados advindos
 * dos demais componentes
 */
#include "core.h"
#include "context.h"
#include <math.h>

void process_ADXL335_data(){
    Context current_context = get_context();

    float pitch_radian, roll_radian, pitch_degree, roll_degree; // Termos da aviação. Pitch é a inclinação para frente ou para trás, enquantp roll é a inclinação para a esquerda ou direita

    pitch_radian = atan2(current_context.Y_axis_acceleration,current_context.Z_axis_acceleration);

    roll_radian = atan2(current_context.X_axis_acceleration,current_context.Z_axis_acceleration);

    pitch_degree = pitch_radian * 180.f / M_PI;

    roll_degree = roll_radian * 180.f / M_PI;

    current_context.roll = roll_degree;
    current_context.pitch = pitch_degree;

    update_context(current_context);
}