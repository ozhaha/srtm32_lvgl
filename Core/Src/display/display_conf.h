//
// Created by ozcom on 2022/5/9.
//

#ifndef F4XX_SPI_DISPLAY_CONF_H
#define F4XX_SPI_DISPLAY_CONF_H

#include "main.h"

#define DISPLAY_WIDTH   240
#define DISPLAY_HEIGHT  240

//IC:
//#define IC_ST7789V2
//#define IC_ST7735S
#define IC_GC9A01


// Choose a bus
//#define DISPLAY_USE_I2C
#define DISPLAY_USE_SPI

// I2C Configuration
//#define DISPLAY_I2C_PORT        hi2c1
//#define DISPLAY_I2C_ADDR        (0x3C << 1)

// SPI Configuration
#define DISPLAY_SPI_PORT        hspi2
#define DISPLAY_CS_Port         SPI2_CS_GPIO_Port
#define DISPLAY_CS_Pin          SPI2_CS_Pin
#define DISPLAY_DC_Port         OLED_DC_GPIO_Port
#define DISPLAY_DC_Pin          OLED_DC_Pin
#define DISPLAY_Reset_Port      OLED_RES_GPIO_Port
#define DISPLAY_Reset_Pin       OLED_RES_Pin


#endif //F4XX_SPI_DISPLAY_CONF_H
