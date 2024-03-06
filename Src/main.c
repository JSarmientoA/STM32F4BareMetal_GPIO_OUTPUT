#include "stm32f4xx.h"



#define GPIOAEN		(1U<<0)// Escribir un uno(1) en el bit cero(0).
#define PIN5		(1U<<5)// Escribir un uno(1) en el bit 5.
#define	LED_PIN		PIN5

int main(void)
{
	/*Habilitación del reoj para el puerto GPIOA*/
	RCC->AHB1ENR  |= 	GPIOAEN;//|=, es asignación con OR binario
	/*Estableser el pin PA5 como salida*/
	GPIOA->MODER  |= 	(1U<<10);//Coloca el bit 10 a 1
	GPIOA->MODER  &=~ 	(1U<<11);// Coloca   el bit 11 a 0, donde &=~ es Asignación con AND binario con complemto de uno
	while(1)
	{
		GPIOA->ODR ^= LED_PIN;//Donde ^=, es alternancia (XOR)
		for(int i=0;i<200000;i++){}
	}
}
/*Repasar los registros del agpioa  y su conexion con el RCC*/
