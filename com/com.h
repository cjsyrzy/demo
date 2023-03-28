#ifndef __COM_H__
#define __COM_H__

#include <Windows.h>
#include <stdint.h>
#include <stdio.h>

int com_init(uint8_t com, uint32_t baudrate);
void com_close(void);
int com_send(uint8_t *buf, uint8_t length);
int com_read(uint8_t *buf, uint8_t length);

#endif /* __COM_H__ */