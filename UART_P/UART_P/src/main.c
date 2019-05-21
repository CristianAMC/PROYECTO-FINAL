/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <asf.h>
#include <uart.h>

int *pio_perb=0x400E1000, *pio_oerb=0x400E1010, *pio_sodrb=0x400E1030, *pio_codrb=0x400E1034;
int *pio_perc=0x400E1200, *pio_oerc=0x400E1210, *pio_sodrc=0x400E1230, *pio_puedc=0x400E1260;
int *pio_pera=0x400E0E00, *pio_pudra=0x400E0E60, *pio_puera=0x400E0E64, *pio_pabsr=0x400E0E70, *pio_pdra=0x400E0E04, *pio_psra=0x400E0E08;
int *UART_CR=0x400E0800, *UART_MR=0x400E0804, *UART_IER=0x400E0808, *UART_IMR=0x400E0810, *UART_SR=0x400E0814, *UART_BRGR=0x400E0820, *UART_THR=0x400E081C, *UART_RHR=0x400E0818, *UART_IDR=0x400E080C ;
int *pmc_pcer0=0x400E0610, *pmc_mckr=0x400E0630, *pmc_pcr=0x400E070C, *pmc_pcsr0=0x400E0618, *CKGR_MOR=0x400E0620;
int *TWI_CR=0x4008C000, *TWI_MMR=0x4008C004, *TWI_IADR=0x4008C00C, *TWI_CWGR=0x4008C010, *TWI_SR=0x4008C020, *TWI_RHR=0x4008C030, *TWI_THR=0x4008C034;
int *TC0_BMR=0x400800C4, *TC0_BCR=0x400800C0, *TC0_0_SR=0x40080020, TC0_0_CCR=0x40080000;
int x=8;

int main (void)
{
	sysclk_init();
	board_init();
	
	*pio_pabsr = 0x000;        // Perifericos
	*pio_pdra = 0xFFFFFFFF;   // Configuracion del PIO
	*pio_pudra = 0xFFFFFFFF; // Configuracion Pheriperal
	*pmc_pcer0 = 0x00400100; // Se activa el PMC UART Y TWI
	
	*UART_CR = 0x00000050;     // Se activa el lectura y escritura
	*UART_MR = 0x00000801;    // Especificar que no tiene paridad.
	*UART_BRGR = 0x00000230; // UART a 9600
	
	*TWI_CR = 0x00000025;      // Configuración de TWI
	*TWI_MMR = 0x001E0000;    // Indentificación del esclavo dir 30
	*TWI_CWGR = 0x7FFFF;    // Clock TWI
	
	
	while(1){
		*TWI_CR = 0x00000025;
		x=*UART_RHR;		 // Almacena lo recibido del UART
		*UART_THR=x;		// Se retransmite
		*TWI_THR=x;			   // Envia el dato por TWI.
		*TWI_CR = 0x00000002; // Se define el bit STOP.
		delay_ms(10);		 // Delay de refresco.
	}
}
