/**
 * @file context.c
 * @author Vítor Pereira Fontes
 * @date 2025-02-22
 * 
 * @brief Arquivo de implementação das funções de contexto da aplicação, responsável pela troca de mensagens e 
 * dados entre as camadas de apresentação e interface.
 */
#include "context.h"
#include "src/layers/interface/KY008.h"
#include "string.h"

void update_context(Context updated_context){
    memcpy(&context, &updated_context, sizeof(Context));
}

Context get_context(){
    return context;
}

void send_message(Component component, Action action){
    Context current_context = get_context();

    switch (component){
        case LASER:
            switch (action){
                case LASER_TOGGLE_X:
                current_context.toggle_X_axis_guide_line = true;
                break;
            
                case LASER_TOGGLE_Y:
                    current_context.toggle_Y_axis_guide_line = true;
                break;

                case LASER_TOGGLE_BOTH:
                    current_context.toggle_both_guide_lines = true;
                break;
            }
        break;

        case ACCELEROMETER:
            switch (action){
                case ACCELEROMETER_CALIBRATE:
                break;

                case ACCELEROMETER_RESET:
                break;
            }
        break;

        case PUSH_BUTTON_B:
            switch (action){
                case PUSH_BUTTON_B_READ_STATE:
                break;
            }
        break;
    }

    update_context(current_context);
}