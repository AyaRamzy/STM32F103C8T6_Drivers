/******************************************************/
/* Author    : Aya Ramzy                              */
/* Date      : 10 OCT 2020                            */
/* Version   : V01                                    */
/******************************************************/
#ifndef MDMA_INTERFACE_H
#define MDMA_INTERFACE_H

void MDMA_voidChannel1Init(void);

void MDMA_voidChannel1Start(u32* Copy_pu32SourceAddress, u32* Copy_pu32DestinationAddress, u16 Copy_u16BlockLength);

#endif