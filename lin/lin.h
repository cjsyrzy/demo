#ifndef __LIN_H__
#define __LIN_H__

#include <Windows.h>
#include <stdint.h>
#include "com.h"

void lin_init(void);
void lin_write(uint8_t id, uint8_t *wdat, uint8_t enhanced_crc);
void lin_read(uint8_t id, uint8_t *rdat, uint8_t enhanced_crc);
void mass_write(uint8_t *dat, uint8_t length);
void mass_read(uint8_t *dat, uint8_t length);

#endif /* __LIN_H__ */