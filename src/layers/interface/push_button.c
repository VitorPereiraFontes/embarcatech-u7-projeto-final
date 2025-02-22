/**
 * @file push_button.c
 * @author Vítor Pereira Fontes
 * @date 2025-02-22
 * 
 * @brief Arquivo de implementação das funções que irão interagir diretamente com o push_button
 */
#include "push_button.h"

void setup_push_button(uint8_t gpio){
    gpio_init(gpio);
    gpio_set_dir(gpio,GPIO_IN);
    gpio_pull_up(gpio);
}

bool read_push_button_state(uint8_t gpio){
    return gpio_get(gpio);
}

void initialize_push_button_block(){
    setup_push_button(PUSH_BUTTON_A_GPIO);
    setup_push_button(PUSH_BUTTON_B_GPIO);
}