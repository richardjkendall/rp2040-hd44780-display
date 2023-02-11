#include "main.h"
#include "lcd.h"

#define  LCD_RS_PIN 10
#define   LCD_E_PIN 11
#define LCD_DB4_PIN 18
#define LCD_DB5_PIN 19
#define LCD_DB6_PIN 20
#define LCD_DB7_PIN 21

int main() {
    stdio_init_all();

    sleep_ms(5000);

    printf("Starting...\n");

    struct LcdDisplay display = setup_display(LCD_RS_PIN, LCD_E_PIN, LCD_DB4_PIN, LCD_DB5_PIN, LCD_DB6_PIN, LCD_DB7_PIN);

    char hello[] = "Hello World";
    write_to_display(hello, display);

    sleep_ms(2000);

    int seconds = 0;

    while(1) {
        seconds++;

        char *message = malloc(50 * sizeof(char));
        sprintf(message, "Running for %d", seconds);
        write_to_display_2_lines(message, "Hello!", display);
        free(message);

        sleep_ms(1000);
        tight_loop_contents();
    }

}