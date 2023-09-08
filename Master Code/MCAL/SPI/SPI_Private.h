#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


#define SPI_SPCR_REG						*((volatile u8 *)0x2D)
#define SPI_SPDR_REG						*((volatile u8 *)0x2F)
#define SPI_SPSR_REG						*((volatile u8 *)0x2E)


/* SPCR REG PINS */
#define SPI_SPIE_PIN					7
#define SPI_SPE_PIN						6
#define SPI_DORD_PIN					5
#define SPI_MSTR_PIN					4
#define SPI_CPOL_PIN					3
#define SPI_CPHA_PIN					2
#define SPI_SPR1_PIN					1		
#define SPI_SPR0_PIN					0


/* SPSR REG PINS */
#define SPI_SPI2X_PIN					0
#define SPI_SPIF_PIN					7

/* SPDR REG PINS */

#endif 
