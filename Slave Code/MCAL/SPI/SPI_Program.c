#include "../../LIB/BIT_MATH.h"
#include "../../LIB/ERROR_STATE.h"
#include "../../LIB/STD_TYPES.h"

#include "../DIO/DIO_Interface.h"

#include "SPI_Config.h"
#include "SPI_Private.h"


void SPI_voidInit(void){
	
	/* Select MC Mood */
	#if MC_Mode == Master
		/* PINS Direction */
		DIO_u8SetPinDirection(DIO_u8_PORTB, DIO_u8_PIN4, DIO_u8_INPUT);
		DIO_u8SetPinDirection(DIO_u8_PORTB, DIO_u8_PIN5, DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(DIO_u8_PORTB, DIO_u8_PIN6, DIO_u8_INPUT);
		DIO_u8SetPinDirection(DIO_u8_PORTB, DIO_u8_PIN7, DIO_u8_OUTPUT);
		DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN4, DIO_u8_INPUT_PULLUP);
		/* Select Data Order => MSB */	
		#if Data_Order_Mode == MSB
			CLR_BIT(SPI_SPCR_REG, SPI_DORD_PIN);
		#elif Data_Order_Mode == LSB
			SET_BIT(SPI_SPCR_REG, SPI_DORD_PIN);
		#endif
			
		/* Select Master Mode */
		SET_BIT(SPI_SPCR_REG, SPI_MSTR_PIN);
		
		/* Select Clk Rate Mode => Clk/64 */
		#if Clk_Rate_Mode == Clk_4
			CLR_BIT(SPI_SPCR_REG, SPI_SPR0_PIN);
			CLR_BIT(SPI_SPCR_REG, SPI_SPR1_PIN);
			CLR_BIT(SPI_SPSR_REG, SPI_SPI2X_PIN);
		#elif Clk_Rate_Mode == Clk_16
			SET_BIT(SPI_SPCR_REG, SPI_SPR0_PIN);
			CLR_BIT(SPI_SPCR_REG, SPI_SPR1_PIN);
			CLR_BIT(SPI_SPSR_REG, SPI_SPI2X_PIN);
		#elif Clk_Rate_Mode == Clk_64
			CLR_BIT(SPI_SPCR_REG, SPI_SPR0_PIN);
			SET_BIT(SPI_SPCR_REG, SPI_SPR1_PIN);
			CLR_BIT(SPI_SPSR_REG, SPI_SPI2X_PIN);
		#elif Clk_Rate_Mode == Clk_128
			SET_BIT(SPI_SPCR_REG, SPI_SPR0_PIN);
			SET_BIT(SPI_SPCR_REG, SPI_SPR1_PIN);
			CLR_BIT(SPI_SPSR_REG, SPI_SPI2X_PIN);
		#elif Clk_Rate_Mode == Clk_2
			CLR_BIT(SPI_SPCR_REG, SPI_SPR0_PIN);
			CLR_BIT(SPI_SPCR_REG, SPI_SPR1_PIN);
			SET_BIT(SPI_SPSR_REG, SPI_SPI2X_PIN);
		#elif Clk_Rate_Mode == Clk_8
			SET_BIT(SPI_SPCR_REG, SPI_SPR0_PIN);
			CLR_BIT(SPI_SPCR_REG, SPI_SPR1_PIN);
			SET_BIT(SPI_SPSR_REG, SPI_SPI2X_PIN);
		#elif Clk_Rate_Mode == Clk_32
			CLR_BIT(SPI_SPCR_REG, SPI_SPR0_PIN);
			SET_BIT(SPI_SPCR_REG, SPI_SPR1_PIN);
			SET_BIT(SPI_SPSR_REG, SPI_SPI2X_PIN);
		#endif
			
		/* Select Clk Polarity => Falling,Rising */
		#if Clk_Polarity_Mode == Falling_Rising
			SET_BIT(SPI_SPCR_REG, SPI_CPOL_PIN);
		#elif Clk_Polarity_Mode == Rising_Falling
			CLR_BIT(SPI_SPCR_REG, SPI_CPOL_PIN);
		#endif 
		
		/* Select Clk Phase => Setup,Sample */
		#if Clk_Phase_Mode == Setup_Sample
			SET_BIT(SPI_SPCR_REG, SPI_CPHA_PIN);
		#elif Clk_Phase_Mode Sample_Setup
			CLR_BIT(SPI_SPCR_REG, SPI_CPHA_PIN);
		#endif
			
	#elif MC_Mode == Slave
		/* PINS Direction */
		DIO_u8SetPinDirection(DIO_u8_PORTB, DIO_u8_PIN4, DIO_u8_INPUT);
		DIO_u8SetPinDirection(DIO_u8_PORTB, DIO_u8_PIN5, DIO_u8_INPUT);
		DIO_u8SetPinDirection(DIO_u8_PORTB, DIO_u8_PIN6, DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(DIO_u8_PORTB, DIO_u8_PIN7, DIO_u8_INPUT);
		DIO_u8SetPinValue(DIO_u8_PORTB, DIO_u8_PIN4, DIO_u8_INPUT_PULLUP);
		/* Select Slave Mode */
		CLR_BIT(SPI_SPCR_REG, SPI_MSTR_PIN);
		
		/* Select Data Order => MSB */	
		#if Data_Order_Mode == MSB
			CLR_BIT(SPI_SPCR_REG, SPI_DORD_PIN);
		#elif Data_Order_Mode == LSB
			SET_BIT(SPI_SPCR_REG, SPI_DORD_PIN);
		#endif
			
		/* Select Clk Polarity => Falling,Rising */
		#if Clk_Polarity_Mode == Falling_Rising
			SET_BIT(SPI_SPCR_REG, SPI_CPOL_PIN);
		#elif Clk_Polarity_Mode == Rising_Falling
			CLR_BIT(SPI_SPCR_REG, SPI_CPOL_PIN);
		#endif 
		
		/* Select Clk Phase => Setup,Sample */
		#if Clk_Phase_Mode == Setup_Sample
			SET_BIT(SPI_SPCR_REG, SPI_CPHA_PIN);
		#elif Clk_Phase_Mode Sample_Setup
			CLR_BIT(SPI_SPCR_REG, SPI_CPHA_PIN);
		#endif
	#endif 

	/* Enable SPI */
	SET_BIT(SPI_SPCR_REG, SPI_SPE_PIN);
}

u8 SPI_u8SendResieve(u8 Copy_u8SendedByte, u8 *Copy_Pu8Recievedyte){
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if(Copy_Pu8Recievedyte != NULL){
		/* Send Byte */
		SPI_SPDR_REG = Copy_u8SendedByte;
		/* Check if Transmission is Completed */
		while((GET_BIT(SPI_SPSR_REG, SPI_SPIF_PIN)) == 0);
		/* Read Byte */
		*Copy_Pu8Recievedyte = SPI_SPDR_REG;
		
		Local_u8ErrorState = STD_TYPES_OK;
	}
	
	return Local_u8ErrorState;
}
void SPI_SlaveSendByte(u8 Copy_DataByte){
	/* Send Byte */
	SPI_SPDR_REG = Copy_DataByte;
}
u8 SPI_RecieveByte(u8 *Copy_Pu8RecievedByte){
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if(Copy_Pu8RecievedByte != NULL){
		/* Check if Transmission is Completed */
		while((GET_BIT(SPI_SPSR_REG, SPI_SPIF_PIN)) == 0);
		/* Read Byte */
		*Copy_Pu8RecievedByte = SPI_SPDR_REG;
		
		Local_u8ErrorState = STD_TYPES_OK;
	}
	
	return Local_u8ErrorState;
}
