//
// Created by ozcom on 2022/4/23.
//

#ifndef F4XX_SPI_DRIVER_W25QXX_CONF_H
#define F4XX_SPI_DRIVER_W25QXX_CONF_H

#define FLASH_CS_GPIO_Port GPIOB
#define FLASH_CS_Pin GPIO_PIN_0

#define _W25QXX_SPI                   hspi1
#define _W25QXX_CS_GPIO               FLASH_CS_GPIO_Port
#define _W25QXX_CS_PIN                FLASH_CS_Pin
#define _W25QXX_USE_FREERTOS          0
#define _W25QXX_DEBUG                 0


#endif //F4XX_SPI_DRIVER_W25QXX_CONF_H
