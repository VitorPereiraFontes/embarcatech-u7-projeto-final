/**
 * @file context.h
 * @author Vítor Pereira Fontes
 * @date 2025-02-22
 * 
 * @brief Arquivo de cabeçalho para as funções de contexto da aplicação, responsável pela troca de mensagens e 
 * dados entre as camadas de apresentação e interface.
 */
#ifndef _CONTEXT_H
    #define _CONTEXT_H
    #include "pico/stdlib.h"

    /**
     * @brief Estrutura que define o formato do contexto da aplicação
     */
    typedef struct context{
        // Variáveis que verificam se um comando foi acionado
        bool toggle_X_axis_guide_line; /** True - Comando para inverter estado da linha disparado | False - Nenhum comando disparado */
        bool toggle_Y_axis_guide_line; /** True - Comando para inverter estado da linha disparado | False - Nenhum comando disparado */
        bool toggle_both_guide_lines; /** True - Comando para inverter estado das linhas disparado | False - Nenhum comando disparado */
        bool calibrating; /** True - Comando para calibrar o acelerômetro disparado | False - Nenhum comando disparado */
        bool resetting; /** True - Comando para resetar os valores de calibragem do acelerômetro disparado | False - Nenhum comando disparado */

        // Variáveis que armazenam dados
        float ZX_angle; /** Ângulo entre os eixos X e Z */
        float XY_angle; /** Ângulo entre os eixos X e Y */
        bool button_a_state; /** True - Botão pressionado | False - botão solto */
        bool button_b_state;  /** True - Botão pressionado | False - botão solto */
        bool X_axis_guide_line; /** True - Linha guia ativa | False - Linha guia desativada */
        bool Y_axis_guide_line; /** True - Linha guia ativa | False - Linha guia desativada */
    } Context;

    /**
     * @brief Enumeração dos componentes acessíveis pela camada 'Presentation'
     */
    typedef enum{
        LASER,
        ACCELEROMETER,
        PUSH_BUTTON_A,
        PUSH_BUTTON_B
    } Component;

    /**
     * @brief Enumeração das ações disponíveis para os componentes acessíveis pela camada 'Presentation'
     */
    typedef enum{
        LASER_TOGGLE_X,
        LASER_TOGGLE_Y,
        LASER_TOGGLE_BOTH,
        ACCELEROMETER_CALIBRATE,
        ACCELEROMETER_RESET,
        PUSH_BUTTON_A_READ_STATE,
        PUSH_BUTTON_B_READ_STATE
    } Action;

    // Armazena o contexto global da aplicação
    static Context context = {
        .toggle_X_axis_guide_line = false, 
        .toggle_Y_axis_guide_line = false,
        .toggle_both_guide_lines = false,
        .calibrating = false,
        .resetting = false,
        .ZX_angle = 0.0,
        .XY_angle = 0.0,
        .button_a_state = false,
        .button_b_state = false,
        .X_axis_guide_line = true,
        .Y_axis_guide_line = true
    };
    
    /**
     * @brief Interface para que a camada 'Interface' atualize o contexto global da aplicação com novos dados
     * 
     * @param context Cópia atualizada do contexto global da aplicação 
     */
    void update_context(Context updated_context);

    /**
     * @brief Obtém uma cópia do contexto global da aplicação, pode ser utilizada por todas as camadas da aplicação
     * 
     * @return Uma struct com o contexto global da aplicação 
     */
    Context get_context();

    /**
     * @brief Interface para que a camada 'Presentation' envie solicitações para a camada 'Application'
     * 
     * @param component Qual componente o usuário da camada 'Presentation' está interagindo 
     *
     * @param action Qual ação deverá ser disparada
     */
    void send_message(Component component, Action action);
#endif