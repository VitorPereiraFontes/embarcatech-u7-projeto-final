/**
 * @file button.c
 * @author Vítor Pereira Fontes
 * @date 2025-02-22
 * 
 * @brief Arquivo de implementação do callback da interrupção a ser disparada quando o usuário pressionar os
 * botões
 */

#include "button.h"
#include "src/layers/application/context.h"

#define PUSH_BUTTON_A 5
#define PUSH_BUTTON_B 6

static uint8_t push_button_a_counter = 0;
static uint64_t last_event_time;
static uint32_t event_delay_us = 600000; // 600 ms

void interruption_callback(uint gpio, uint32_t events_mask){
    uint64_t current_time = to_us_since_boot(get_absolute_time());

    if(current_time - last_event_time > event_delay_us){
        last_event_time = current_time;

        switch (gpio){
            case PUSH_BUTTON_A:
                switch (push_button_a_counter){
                    case 0:
                        send_message(LASER,LASER_TOGGLE_X);
    
                        push_button_a_counter++;
                    break;
    
                    case 1:
                        send_message(LASER,LASER_TOGGLE_Y);
    
                        push_button_a_counter++;
                    break;
                
                    default:
                        send_message(LASER,LASER_TOGGLE_BOTH);
    
                        push_button_a_counter = 0;
                    break;
                }
            break;
    
            case PUSH_BUTTON_B:
            break;
        }
    }
}