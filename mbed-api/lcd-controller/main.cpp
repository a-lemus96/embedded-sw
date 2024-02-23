#include "mbed.h"

DigitalOut CS(D10); // chip select
SPI controller(D11, D12, D13); // coti, cito, sclk

// function prototypes
void init_lcd();
void write_4bit(int data);
void write_cmd(int cmd);
void write_data(int data);
void print_lcd(char *str);

int main() {
    
}