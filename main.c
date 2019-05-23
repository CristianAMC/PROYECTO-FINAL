#include <asf.h>
/*-----------------------PIO------------------------*/
int *pio_pdra=0x400E0E04;
int *pio_absra=0x400E0E70;
int *pio_pudra=0x400E0E60;
int *pio_puer=0x400E0E64;
int *pmc_pcer=0x400E0610;
/*-----------------------UART PID8--------------------*/
int *uart_mr=0x400E0804;
int *uart_sr=0x400E0814;
int *uart_ier=0x400E0808;
int *uart_cr=0x400E0800;
int *uart_rhr=0x400E0818;
int *uart_brgr=0x400E0820;
int *uart_thr=0x400E081C;
/*-----------------------TWI0 PID27-------------------*/
int *twi_cr=0x4008C000;
int *twi_mmr=0x4008C004;
int *twi_cwgr=0x4008C010;
int *twi_sr=0x4008C020;
int *twi_rhr=0x4008C030;
int *twi_thr=0x4008C034;
int *twi_ier=0x4008C024;
/*-----------------------TIMER------------------------*/
/*TIOA1, pertenece pin A2 periferico A instancia TC0 ID 27
	El TC0 es el único que srive para medir tiempo en el T0*/
int *t_ccr=0x40080040;
int *t_mrc=0x40080044;
int *t_smr=0x40080048;
int *t_cvr=0x40080050;
int *t_a=0x40080054;
int *t_b=0x40080058;
int *t_c=0x4008005C;
int *t_sr=0x40080060;
int *t_ier=0x40080064;

Bool state=true;
Bool firstData=false;
Bool secondData=false;
char uart_rx_id;

int main (void)
{
	
	board_init();
	sysclk_init();
	
	/*-----------------------PIO------------------------*/
	
	*pio_pdra=0xFFFFFFFF;
	*pio_pudra=0xFFFFFFFF;
	*pio_absra=0x00000000;
	
	/*-----------------------PMC------------------------*/
	
	*pmc_pcer=0x10C00100;  //Habilitamos los perifericos del UART, TWI y Timer en el PMC_0
	
	/*----------------------UART------------------------*/
	
	*uart_cr=0x50;
	*uart_mr=0x0800;
	*uart_ier=0xFFFFFFFF;
	*uart_brgr=0x230;
	
	/*-----------------------TWI------------------------*/
	
	*twi_cwgr=0x70808;
	
	/*-----------------------TIMER------------------------*/
	
	*t_ccr=0x5;// En el canal 1_0 se habilita el timer y un reinicio de inicializacion
	*t_mrc=0x0;// Timer usa la frecuencia mas grande o Timer Clock 1
	*t_ier=0xFFFFFFFF;
	
	/*-----------------------Variables aux.------------------------*/
	
	while(1){
		if((*uart_sr & 0x1)==1){
			state=false;
			uart_rx_id=*uart_rhr;
			*uart_thr=uart_rx_id;
 		}
 		switch (state)
 		{
 			case false:{						//Leyendo del UART y enviando al TWI
				*twi_cr=0x00000024;
				*twi_mmr=0x200000;
				*twi_cr|=0x0000001;
				*twi_cr|=0x0000002;
				*twi_thr=*uart_rhr;
 				state=~state;
 				break;
 			}
 			case true:{					//Leyendo del TWI y enviando al UART
				int a;
				if(*t_cvr<0x1EC1890 && firstData==false){
					*twi_cr=0x00000024;
					*twi_mmr=0x1E1000; // Slave 30
					*twi_cr|=0x0000001;
					*twi_cr|=0x0000002;
					a=*twi_rhr;
					*uart_thr='-';
					delay_ms(1);
					*uart_thr=a;
					delay_ms(1);
					firstData=true;
				}
				else if(*t_cvr>0x33428F0 && firstData==true){
					*twi_cr=0x00000024;
					*twi_mmr=0x1F1000; // Slave 31
					*twi_cr|=0x0000001;
					*twi_cr|=0x0000002;
					a=*twi_rhr;
					*uart_thr='*';
					delay_ms(1);
					*uart_thr=a;
					delay_ms(1);
					firstData=false;
				}
				else if(*t_cvr>0x5C449B0){
					*twi_cr=0x00000024;
					*twi_mmr=0x201000; // Slave 32
					*twi_cr|=0x0000001;
					*twi_cr|=0x0000002;
					a=*twi_rhr;
					*uart_thr='+';
					delay_ms(1);
					*uart_thr=a;
					delay_ms(1);
					*t_ccr=0x5;
				}
				
 				break;
 			}
 			default:{
 				break;
 			}
 		}
	}
}