#include "lin.h"

enum mode
{
    ModeStandby = 0,
    ModeMaster,
    ModeSlaver,
    ModeListening
};

enum head
{
    HeadConfig = 0x11,
    HeadMasterWrite = 0x22,
    HeadMasterRead = 0x33
};

uint8_t lin_header_cal(uint8_t id)
{
    uint8_t TempPID;
    uint8_t Parity_P1, Parity_P0;
    /* Calculate the Parity bits P0 & P1 */
    Parity_P0 = (uint8_t)(((id) ^ (id >> 1U) ^ (id >> 2U) ^ (id >> 4U)) & 0x01U);

    Parity_P1 = (uint8_t)((~((id >> 1U) ^ (id >> 3U) ^ (id >> 4U) ^ (id >> 5U))) & 0x01U);

    /* Assign the Parity bits and the header values in to the TempPID */
    TempPID = (uint8_t)(id | ((uint8_t)Parity_P0 << 6U) | ((uint8_t)Parity_P1 << 7U));

    return TempPID;
}

uint8_t lin_checksum(uint8_t pid, uint8_t u8data[], uint8_t len, uint8_t is_enhanced)
{
    uint16_t sum;
    uint8_t i;
    if (is_enhanced != 0x00U)
    {
        sum = pid;
    }
    else
    {
        sum = 0x00U;
    }
    for (i = 0U; i < len; i++)
    {
        sum += u8data[i];
        if ((sum & 0xFF00U) != 0x00U)
        { /* Whether the high bit overflows */
            sum = (sum & 0x00FFU) + 1U;
        }
    }
    sum ^= 0x00FFU;
    return (uint8_t)sum;
}

uint8_t cal_crc(uint8_t *dat)
{
    uint8_t crc = 0;
    uint8_t i = 0;

    for (i = 0; i < 14; i++)
    {
        crc += dat[i];
    }

    crc = ~crc + 1;

    return crc;
}

void lin_init(void)
{
    uint8_t dat[16];

    memset(dat, 0, 16);
    dat[0] = HeadConfig;
    dat[1] = ModeStandby;
    dat[2] = 0x4E;
    dat[3] = 0x00;
    dat[15] = cal_crc(dat);
    com_send(dat, 16);

    Sleep(200);

    memset(dat, 0, 16);
    dat[0] = HeadConfig;
    dat[1] = ModeMaster;
    dat[2] = 0x4E;
    dat[3] = 0x00;
    dat[15] = cal_crc(dat);
    com_send(dat, 16);
}

void lin_write(uint8_t id, uint8_t *wdat, uint8_t enhanced_crc)
{
    uint8_t dat[16];
    memset(dat, 0, 16);

    dat[0] = HeadMasterWrite;
    dat[1] = 0;
    dat[2] = id;
    dat[3] = 0;
    dat[4] = enhanced_crc ? 2 : 1;
    dat[5] = 8;
    memcpy(&dat[6], wdat, 8);
    // dat[14] = lin_checksum(id, wdat, 8, enhanced_crc);
    dat[15] = cal_crc(dat);
    com_send(dat, 16);
}

void lin_read(uint8_t id, uint8_t *rdat, uint8_t enhanced_crc)
{
    uint8_t dat[16];
    memset(dat, 0, 16);

    dat[0] = HeadMasterRead;
    dat[1] = 1;
    dat[2] = id;
    dat[3] = 1;
    dat[4] = enhanced_crc ? 2 : 1;
    dat[5] = 8;
    dat[15] = cal_crc(dat);
    com_send(dat, 16);
    
    uint8_t i=0;
    for(i=0;i<16;i++)
    {
        printf("%02X ", dat[i]);
    }
    printf("\r\n");
}

void mass_write(uint8_t *dat, uint8_t length)
{
}

void mass_read(uint8_t *dat, uint8_t length)
{
}
