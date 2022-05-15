//
// Created by ozcom on 2022/4/23.
//


#include "bsp_flash.h"
#include "w25qxx/driver_w25qxx.h"
#include "log.h"

uint8_t TEXT_Buffer[] = {
        "Android Studio provides the fastest tools for building apps on every type of Android device."};
#define SIZE sizeof(TEXT_Buffer)

extern uint32_t FLASH_SIZE;

uint8_t dataRead[SIZE];

void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi) {

//    HAL_SPI_DMAStop(hspi);
//    W25QXX_CS_1;
//
//    LOGD("--->%s", dataRead);

}


void flash_driver_w25qxx_test() {

    LOGD("--->w25qxx.BlockCount=%lu", w25qxx.BlockCount);
    LOGD("--->w25qxx.BlockSize=%lu", w25qxx.BlockSize);
    LOGD("--->w25qxx.CapacityInKiloByte=%lu", w25qxx.CapacityInKiloByte);
    LOGD("--->w25qxx.ID=%u", w25qxx.ID);
    LOGD("--->w25qxx.Lock=%hhu", w25qxx.Lock);
    LOGD("--->w25qxx.PageCount=%lu", w25qxx.PageCount);
    LOGD("--->w25qxx.PageSize=%hu", w25qxx.PageSize);
    LOGD("--->w25qxx.SectorCount=%lu", w25qxx.SectorCount);
    LOGD("--->w25qxx.SectorSize=%lu", w25qxx.SectorSize);
    LOGD("--->w25qxx.StatusRegister1=%hhu", w25qxx.StatusRegister1);
    LOGD("--->w25qxx.StatusRegister2=%hhu", w25qxx.StatusRegister2);
    LOGD("--->w25qxx.StatusRegister3=%hhu", w25qxx.StatusRegister3);
    LOGD("--->w25qxx.UniqID=%s", w25qxx.UniqID);

//    TEXT_Buffer
    W25qxx_WritePage(TEXT_Buffer, 0, 0, SIZE);

    W25qxx_ReadBytes(dataRead, 0, SIZE);

    LOGD("--->dataRead: %s", dataRead);
}


