#include "APP_Includes.h"

/* Slave Code */

int main(void){
	u8 data, flag = 0;
	DIO_voidInit();
	SPI_voidInit();
	
	while(1){
		SPI_u8SendResieve(10, &data);
		if(data == 5){
			if(!flag){
				DIO_u8SetPinValue(2, 0, 1);
				flag = 1; 
			}
			else{
				DIO_u8SetPinValue(2, 0, 0);
				flag = 0;
			}
			_delay_ms(40);
		}
	}
	return 0;
}
