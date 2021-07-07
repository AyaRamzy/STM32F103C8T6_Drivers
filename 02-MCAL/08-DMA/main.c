/******************************************************/
/* Author    : Aya Ramzy                              */
/* Date      : 10 OCT 2020                            */
/* Version   : V01                                    */
/******************************************************/
#include "STD_TYPES.h"
#include "BITMATH.h"

#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "MDMA_interface.h"
#include "MDMA_private.h"

u16 Local_u16Index;
void main(void)
{
	u32 Arr1[1000]={0};
	u32 Arr2[1000];

	u32 Arr3[1000]={0};
	u32 Arr4[1000];


    RCC_voidInitSysClock();
	/*Enable clock on DMA Peripheral*/
	RCC_voidEnablePeripheralClock(RCC_AHB,0);

	MDMA_voidChannelInit();

	NVIC_u8InterruptEnable(11);
	MDMA_voidChannelStart(Arr1,Arr2,1000);

	for(Local_u16Index=0;Local_u16Index<1000;Local_u16Index++)
	{
		Arr4[Local_u16Index]=Arr3[Local_u16Index];
	}


	while(1)
	{

	}
}
void DMA1_Channel1_IRQHandler(void)
{
	/*Clear Interrupt flag*/
	DMA->IFCR=1<<0;		/*Clear Global Interrupt flag of channel1*/
	DMA->IFCR=1<<1;		/*Clear transfer complete Interrupt flag of channel1*/
}
