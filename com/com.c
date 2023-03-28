#include "com.h"

static HANDLE hcom = INVALID_HANDLE_VALUE;

int com_init(uint8_t com, uint32_t baudrate)
{
    wchar_t scom[] = L"COM12";
    swprintf(scom, sizeof(scom), L"COM%d", com);

    hcom = CreateFile(scom,                         //串口名称
                      GENERIC_READ | GENERIC_WRITE, //允许读和写
                      0,                            //独占方式
                      NULL,                         // 无安全属性，不可被子程序继承
                      OPEN_EXISTING,                //创建文件的性质，打开而不是创建
                      0,                            // Non Overlapped I/O
                      NULL);                        // Null for Comm Devices

    if (hcom == INVALID_HANDLE_VALUE)
    {
        printf("COM%d open failure.\r\n", com);
        return -1;
    }

    if (!SetupComm(hcom, 1024, 1024))
    {
        printf("COM set buf failure\r\n");
        return -1;
    }

    /* 配置参数 */
    DCB dcb;
    GetCommState(hcom, &dcb);
    dcb.BaudRate = baudrate;
    dcb.ByteSize = 8;
    dcb.Parity = NOPARITY;
    dcb.StopBits = ONESTOPBIT;
    SetCommState(hcom, &dcb);

    printf("COM%d open success.\r\n", com);
}

void com_close(void)
{
    if (INVALID_HANDLE_VALUE != hcom)
    {
        CloseHandle(hcom);
        hcom = INVALID_HANDLE_VALUE;
    }
}

int com_send(uint8_t *buf, uint8_t length)
{
    DWORD write_size;

    WriteFile(hcom,        //串口句柄
              buf,         //指向一个缓冲区，包含要写入的数据
              length,      //要写入数据的字节数
              &write_size, //实际写入的字节数
              NULL);       //指向一个OVERLAPPEN结构体

    printf("send length %d %d\r\n", length, write_size);

    return (write_size == length) ? 0 : -1;
}

int com_read(uint8_t *buf, uint8_t length)
{
}