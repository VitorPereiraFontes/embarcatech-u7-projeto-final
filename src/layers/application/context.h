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

    /**
     * @brief Estrutura que define o formato do contexto da aplicação
     */
    typedef struct context{
        // Variáveis que verificam se um comando foi acionado
        bool toggle_X_axis_guide_line; /** True - Comando para inverter estado da linha disparado | False - Nenhum comando disparado */
        bool toggle_Y_axis_guide_line; /** True - Comando para inverter estado da linha disparado | False - Nenhum comando disparado */
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
    enum Component{
        LASER,
        ACCELEROMETER,
        PUSH_BUTTON_A,
        PUSH_BUTTON_B
    };

    /**
     * @brief Enumeração das ações disponíveis para os componentes acessíveis pela camada 'Presentation'
     */
    enum Action{
        LASER_TOGGLE_X,
        LASER_TOGGLE_Y,
        ACCELEROMETER_CALIBRATE,
        ACCELEROMETER_RESET,
        PUSH_BUTTON_A_READ_STATE,
        PUSH_BUTTON_B_READ_STATE
    };

    static Context context; // Armazena o contexto global da aplicação
    
    /**
     * @brief Interface para que a camada 'Interface' atualize o contexto global da aplicação com novos dados
     * 
     * @param context Cópia atualizada do contexto global da aplicação 
     */
    void update_context(Context context);

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