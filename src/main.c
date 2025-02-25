#include <stdio.h>
#include "pico/stdlib.h"
#include "layers/application/core.h"
#include "layers/presentation/button.h"
#include "layers/interface/ADXL335.h"
#include "layers/interface/push_button.h"
#include "layers/interface/KY008.h"
#include "layers/interface/SSD1306.h"

int main(){
    stdio_init_all();

    initialize_push_button_block();

    gpio_set_irq_enabled_with_callback(PUSH_BUTTON_A_GPIO, GPIO_IRQ_EDGE_FALL,true,interruption_callback);

    setup_KY008_block();
    setup_SSD1306_block();
    setup_ADXL335_module();

    while (true) {
        run_KY008_block();
        run_ADXL335_module();
        process_ADXL335_data();
        run_SSD1306_block();
        sleep_ms(800);
    }
}
