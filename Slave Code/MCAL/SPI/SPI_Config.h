#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* Select Data Order Mode */
#define LSB									0
#define MSB									1

#define Data_Order_Mode						MSB

/* Select MC Mode */
#define Master								0
#define Slave								1

#define MC_Mode								Slave

/* Select Clk Polarity */
#define Rising_Falling						0	
#define Falling_Rising						1 

#define Clk_Polarity_Mode					Falling_Rising

/* Select Clk Phase */
#define Sample_Setup						0
#define Setup_Sample						1

#define Clk_Phase_Mode						Setup_Sample

/* Select Clk Rate */

#define Clk_4								0
#define Clk_16								1
#define Clk_64								2
#define Clk_128								3
#define Clk_2								4
#define Clk_8								5
#define Clk_32								6

#define Clk_Rate_Mode						Clk_64


#endif 
