/******************************************************/
/* Author    : Aya Ramzy                              */
/* Date      : 14 SEP 2020                            */
/* Version   : V01                                    */
/******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "MSTK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void HSTP_voidSendSynchronus(u8 Copy_u8DataToSend)
{
	s8 Local_s8Counter;
	u8 Local_u8Bit;
	//send bit by bit start from MSB
	for(Local_u8Counter=7;Local_u8Counter>=0;Local_u8Counter++)
	{
		Local_u8Bit = GET_BIT(Copy_u8DataToSend,Local_u8Counter);
		MGPIO_voidSetPinValue(HSTP_SERIAL_DATA,Local_u8Bit);
		
		/*Send pulse to shift clock */
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,GPIO_HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,GPIO_LOW);
		MSTK_voidSetBusyWait(1);
	
		
	}
	/*Send pulse to store clock */
	MGPIO_voidSetPinValue(HSTP_STORE_CLOCK,GPIO_HIGH);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(HSTP_STORE_CLOCK,GPIO_LOW);
	MSTK_voidSetBusyWait(1);
	
}