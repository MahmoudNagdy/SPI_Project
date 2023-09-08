#include "APP_Includes.h"

/* Master Code */

int main(void){
	u8 data;
	DIO_voidInit();
	SPI_voidInit();
	
	while(1){
		SPI_u8SendResieve(5, &data);
		if(data == 10){
			DIO_u8SetPinValue(0, 0, 1);
		}
		_delay_ms(20);
	}
	return 0;
}
