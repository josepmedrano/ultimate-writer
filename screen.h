/* See LICENSE for license details. */
#ifndef SCREEN_H
#define SCREEN_H

// Pin definition
#define RST_PIN         17
#define DC_PIN          25
#define CS_PIN           8
#define BUSY_PIN        24

// Pin level definition
#define LOW             0
#define HIGH            1

// Display resolution
#define EPD_WIDTH       640
#define EPD_HEIGHT      384

// EPD7IN5 commands
#define PANEL_SETTING                               0x00
#define POWER_SETTING                               0x01
#define POWER_OFF                                   0x02
#define POWER_OFF_SEQUENCE_SETTING                  0x03
#define POWER_ON                                    0x04
#define POWER_ON_MEASURE                            0x05
#define BOOSTER_SOFT_START                          0x06
#define DEEP_SLEEP                                  0x07
#define DATA_START_TRANSMISSION_1                   0x10
#define DATA_STOP                                   0x11
#define DISPLAY_REFRESH                             0x12
#define IMAGE_PROCESS                               0x13
#define LUT_FOR_VCOM                                0x20 
#define LUT_BLUE                                    0x21
#define LUT_WHITE                                   0x22
#define LUT_GRAY_1                                  0x23
#define LUT_GRAY_2                                  0x24
#define LUT_RED_0                                   0x25
#define LUT_RED_1                                   0x26
#define LUT_RED_2                                   0x27
#define LUT_RED_3                                   0x28
#define LUT_XON                                     0x29
#define PLL_CONTROL                                 0x30
#define TEMPERATURE_SENSOR_COMMAND                  0x40
#define TEMPERATURE_CALIBRATION                     0x41
#define TEMPERATURE_SENSOR_WRITE                    0x42
#define TEMPERATURE_SENSOR_READ                     0x43
#define VCOM_AND_DATA_INTERVAL_SETTING              0x50
#define LOW_POWER_DETECTION                         0x51
#define TCON_SETTING                                0x60
#define TCON_RESOLUTION                             0x61
#define SPI_FLASH_CONTROL                           0x65
#define REVISION                                    0x70
#define GET_STATUS                                  0x71
#define AUTO_MEASUREMENT_VCOM                       0x80
#define READ_VCOM_VALUE                             0x81
#define VCM_DC_SETTING                              0x82

// Dirty hack. We don't need this 
// struct. TODO clean this.
typedef int GlyphFontSpec;


void run(void);

// E-Ink functions
// Interface-Level primitives.
int init_if(void);
void digital_write(int pin, int value);
int digital_read(int pin);
void delay_ms(unsigned int delayTime);
void spi_transfer(unsigned char data);
// Screen driver functions.
int sinit(void);
void sreset(void);
void ssend_command(unsigned char command);
void ssend_data(unsigned char data);
void sdisplay_frame(const unsigned char* frame_buffer);
void swait_until_idle(void);
void ssleep(void);

#endif