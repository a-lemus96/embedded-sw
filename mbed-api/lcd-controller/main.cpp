#include "mbed.h"
#include "lcd.h"

#define ENABLE 0x08             // enable bit
#define COMMAND_MODE 0x00
#define DATA_MODE 0x04

DigitalOut CS(D10);             // chip select
SPI controller(D11, D12, D13);  // coti, cito, sclk

// function prototypes
void init_lcd();
void write_4bit(int data);
void write_cmd(int cmd);
void write_data(int data);
void print_lcd(char *str);
void shift_out(int data);

int main() {
    controller.format(8, 0);        // 8 bits per frame, mode 0
    controller.frequency(1000000);  // 1 MHz
    CS = 1;                         // disable chip
    init_lcd();                     // initialize lcd
    write_cmd(LCD_DISPLAY_ON | LCD_CURSOR_ON | LCD_BLINK_ON);
}

void shift_out(int data) {
    CS = 0;                     // enable chip
    controller.write(data);     // send data
    CS = 1;                     // disable chip
}

void write_4bit(int data, int mode) {
    int hi_nibble = data & 0xF0;            // high nibble
    int lo_nibble = (data << 4) & 0xF0;     // low nibble
    shift_out(hi_nibble | ENABLE | mode);   // send high nibble
    wait_us(1);
    shift_out(hi_nibble & ~ENABLE);         // disable enable
    shift_out(lo_nibble | ENABLE | mode);   // send low nibble
    wait_us(1);
    shift_out(lo_nibble & ~ENABLE);         // disable enable
}

void write_cmd(int cmd) {
    write_4bit(cmd, COMMAND_MODE);  // send command
}

void init_lcd() {
    thread_sleep_for(40);       // wait for 40 ms
    write_cmd(LCD_8BIT_MODE);   // 8-bit mode
    wait_ms(5);
    write_cmd(LCD_8BIT_MODE);   // 8-bit mode
    wait_us(100);
    write_cmd(LCD_8BIT_MODE);   // 8-bit mode
    wait_us(37);
    write_cmd(LCD_4BIT_MODE);   // 4-bit mode
    wait_us(37);
    // set to 4-bit mode, 1-line display, 5x8 font
    write_cmd(LCD_4BIT_MODE | LCD_1LINE_MODE | LCD_5X8_MODE);
    wait_us(37);
    write_cmd(LCD_DISPLAY_OFF);  // turn off display
    wait_us(37);
    write_cmd(LCD_CLEAR);        // clear display
    wait_ms(2);
    // set entry mode, increment cursor position, no shift
    write_cmd(LCD_ENTRY_MODE_SET | LCD_ENTRY_LEFT);
    wait_us(37);
}
