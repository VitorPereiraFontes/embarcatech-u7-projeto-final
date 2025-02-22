#ifndef _APPLICATION_H
    #define _APPLICATION_H

    #define PUSH_BUTTON_A_GPIO 5
    #define PUSH_BUTTON_B_GPIO 6

    #define I2C_PORT i2c1 // Porta utilizada para comunicação I2C com o display OLED
    #define OLED_DISPLAY_I2C_ADDRESS 0x3C
    #define OLED_DISPLAY_SDA_GPIO 14
    #define OLED_DISPLAY_SCL_GPIO 15
    #define OLED_DISPLAY_CLOCK_FREQUENCY 400 * 1000 // Define a frequência de comunicação com o  display OLED para 400 KHz

    #define X_axis_laser_GPIO 21
    #define Y_axis_laser_GPIO 22
#endif