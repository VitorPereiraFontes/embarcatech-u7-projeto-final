/**
 * @file KY008.h
 * @author Vítor Pereira Fontes
 * @date 2025-02-22
 * 
 * @brief Arquivo de implementação das funções que irão interagir diretamente com o MOSFET 
 * 2N7000 que controla a passagem de corrente para o módulo transmissor de laser KY008
 */

#include "KY008.h"
#include "src/layers/application/context.h"
#include "pico/stdlib.h"

void toggle_signal(uint8_t gpio){
    gpio_put(gpio, !gpio_get(gpio));
}

bool read_signal(uint8_t gpio){
    return gpio_get(gpio);
}

void setup_KY008_block(){
    gpio_init(12);
    gpio_init(13);
    gpio_set_dir(12,GPIO_OUT);
    gpio_set_dir(13,GPIO_OUT);
    gpio_put(12,true);
    gpio_put(13,true);
}

void run_KY008_block(){
    Context current_context = get_context();

    if (current_context.toggle_X_axis_guide_line){
        toggle_signal(13);

        current_context.toggle_X_axis_guide_line = false;
        current_context.X_axis_guide_line = read_signal(13);
    }else if(current_context.toggle_Y_axis_guide_line){
        toggle_signal(12);

        current_context.toggle_Y_axis_guide_line = false;
        current_context.Y_axis_guide_line = read_signal(12);
    }else if(current_context.toggle_both_guide_lines){
        toggle_signal(13);
        toggle_signal(12);

        current_context.toggle_both_guide_lines = false;
        current_context.Y_axis_guide_line = read_signal(12);
        current_context.X_axis_guide_line = read_signal(13);
    }
    
    update_context(current_context);
}