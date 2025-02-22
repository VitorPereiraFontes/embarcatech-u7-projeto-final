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
        bool X_axis_laser; /** Linha guia do eixo X habilitada ou desabilitada */
        bool Y_axis_laser; /** Linha guia do eixo Y habilitada ou desabilitada */
        float ZX_angle; /** Ângulo entre os eixos X e Z */
        float XY_angle; /** Ângulo entre os eixos X e Y */
        bool calibrating; /** Indica se o comando para calibar o nível foi disparado */
        bool resetting; /** Indica se o comando para resetar a calibragem do nível foi disparado */
    } Context;

    /**
     * @brief Enumeração dos componentes acessíveis pela camada 'Presentation'
     */
    enum Component{
        LASER,
        ACCELEROMETER
    };

    /**
     * @brief Enumeração das ações disponíveis para os componentes acessíveis pela camada 'Presentation'
     */
    enum Action{
        LASER_TOGGLE_X,
        LASER_TOGGLE_Y,
        ACCELEROMETER_CALIBRATE,
        ACCELEROMETER_RESET
    };

    static Context application_context; // Armazena o contexto global da aplicação
    
    /**
     * @brief Interface para que a camada 'Interface' atualize o contexto global da aplicação com novos dados
     * 
     * @param context Endereço da variável que armazena o contexto global da aplicação 
     */
    void update_context(Context* context);

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