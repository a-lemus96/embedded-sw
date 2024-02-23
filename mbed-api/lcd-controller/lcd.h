#define LCD_CLEAR           0x01 // clear display
#define LCD_RETURN_HOME     0x02 // return home
#define LCD_ENTRY_MODE_SET  0x04 // set entry mode
#define LCD_CURSOR_SHIFT    0x10 // shift cursor

// entry mode options
#define LCD_ENTRY_RIGHT     0x00 // increment cursor position
#define LCD_ENTRY_LEFT      0x02 // decrement cursor position
#define LCD_ENTRY_SHIFT_INC 0x01 // shift display to right
#define LCD_ENTRY_SHIFT_DEC 0x00 // shift display to left

// display control options
#define LCD_DISPLAY_ON      0x04 // turn on display
#define LCD_DISPLAY_OFF     0x00 // turn off display
#define LCD_CURSOR_ON       0x02 // show cursor
#define LCD_CURSOR_OFF      0x00 // hide cursor
#define LCD_BLINK_ON        0x01 // blink cursor
#define LCD_BLINK_OFF       0x00 // don't blink cursor

// cursor or display shift options
#define LCD_SHIFT_DISPLAY   0x08 // shift display
#define LCD_SHIFT_CURSOR    0x00 // shift cursor

// function set options
#define LCD_8BIT_MODE       0x10 // 8-bit data mode
#define LCD_4BIT_MODE       0x00 // 4-bit data mode
#define LCD_2LINE_MODE      0x08 // 2-line display
#define LCD_1LINE_MODE      0x00 // 1-line display
#define LCD_5x10_MODE       0x04 // 5x10 font
#define LCD_5x8_MODE        0x00 // 5x8 font
