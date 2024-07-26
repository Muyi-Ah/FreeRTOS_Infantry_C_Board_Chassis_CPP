#ifndef CRC_H
#define CRC_H

#include "stdint.h"
#include "stdlib.h"

uint32_t Verify_CRC8_Check_Sum(uint8_t* pchMessage, uint32_t dwLength);
void Append_CRC8_Check_Sum(uint8_t* pchMessage, uint32_t dwLength);
uint32_t Verify_CRC16_Check_Sum(uint8_t* pchMessage, uint32_t dwLength);
void Append_CRC16_Check_Sum(uint8_t* pchMessage, uint32_t dwLength);

#endif  // CRC_H