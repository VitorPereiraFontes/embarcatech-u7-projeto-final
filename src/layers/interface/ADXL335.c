/**
 * @file ADXL335.c
 * @author Vítor Pereira Fontes
 * @date 2025-02-23
 * 
 * @brief Arquivo de cabeçalho para as funções de controle do acelerômetro ADXL335
 */
#include "ADXL335.h"
#include "hardware/adc.h"
#include "src/layers/application/context.h"
#include <math.h>

float roud_to_2_decimal(float value){
    return roundf(value * 100) / 100;
}

float read_acceleration(ADC adc){
    adc_select_input(adc);

    uint16_t adc_value = adc_read();

    // Inverte os lados direito-esquerdo do joystick
    if(adc == ADC1){
        adc_value = ADC_MAX_VALUE - adc_value;
    }

    float voltage = (adc_value / ADC_MAX_VALUE) * (XY_MAX_VOLTAGE - XY_MIN_VOLTAGE) + XY_MIN_VOLTAGE;

    // Verifica se a tensão está no intervalo de repouso para os eixos X e Y
    if(voltage >= (ZERO_G_VOLTAGE - XY_ZERO_G_OFFSET) && voltage <= (ZERO_G_VOLTAGE + XY_ZERO_G_OFFSET)){
        return 0;
    }

    float axis_acceleration = (voltage - ZERO_G_VOLTAGE) / TYPICAL_SENSITIVITY;

    return roud_to_2_decimal(axis_acceleration);
}

void setup_ADXL335_module(){
    adc_init();
    adc_gpio_init(X_AXIS_GPIO);
    adc_gpio_init(Y_AXIS_GPIO);
    adc_gpio_init(Z_AXIS_GPIO);
}

void run_ADXL335_module(){
    Context current_context = get_context();

    float x_acceleration = read_acceleration(ADC1);
    float y_acceleration = read_acceleration(ADC0);

    float xy_magnitude = sqrtf(pow(x_acceleration,2) + pow(y_acceleration,2));

    if(xy_magnitude > 1){
        x_acceleration = roud_to_2_decimal(x_acceleration / xy_magnitude);
        y_acceleration = roud_to_2_decimal(y_acceleration / xy_magnitude);
    }

    float z_acceleration = sqrtf(1 - roud_to_2_decimal(pow(x_acceleration,2) + pow(y_acceleration,2)));

    current_context.X_axis_acceleration = x_acceleration;
    current_context.Y_axis_acceleration = y_acceleration;
    current_context.Z_axis_acceleration = z_acceleration;

    update_context(current_context);
}