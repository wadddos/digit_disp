#ifndef IIC_H
#define	IIC_H
//------------------------------------------------------------------------------
#include <xc.h> // include processor files - each processor file is guarded. 
#define FCY          12000000 //default FCY 12MHz
#endif
#include <libpic30.h>
#ifndef I2C_BAUDRATE
#define I2C_BAUDRATE  400000 //default baud rate 400kHz
//------------------------------------------------------------------------------
void i2c_Open (void);// инициализация,значение тактовой частоты процессора, значение частоты шины 
void i2c_stop (void); // формирование стоп
unsigned char i2c_start (unsigned char addres, unsigned char R_W); // адрес устройства и управление младшими битами
unsigned char i2c_restart (unsigned char adres, unsigned char R_W);
unsigned char i2c_write (unsigned char data); //запись байта
unsigned char i2c_read_ack (void);	//чтение с подтверждением
unsigned char i2c_read_noack (void);	//чтение без подтверждения
unsigned char set_write_addres(unsigned char device_addres, unsigned char cell_addres);
unsigned char byte_write(unsigned char device_addres, unsigned char cell_addres, unsigned char current_data); //запись байта по указанному адресу
unsigned char page_write(unsigned char device_addres, unsigned char cell_addres, unsigned char write_data[], unsigned char number); //запись нескольких байт, начиная с указанного адреса 
unsigned char byte_read(unsigned char device_addres, unsigned char cell_addres, unsigned char *value); //чтение байта по указанному адресу
unsigned char page_read(unsigned char device_addres, unsigned char cell_addres, unsigned char reed_data[], unsigned char number); //чтение нескольких байт, начиная с указанного адреса
//------------------------------------------------------------------------------
#endif /* IIC_H */

