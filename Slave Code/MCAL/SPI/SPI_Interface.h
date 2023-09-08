#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../LIB/STD_TYPES.h"

void SPI_voidInit(void);

u8 SPI_u8SendResieve(u8 Copy_u8SendedByte, u8 *Copy_Pu8Recievedyte);

void SPI_SlaveSendByte(u8 Copy_DataByte);

u8 SPI_RecieveByte(u8 Copy_Pu8RecievedByte);


#endif 
