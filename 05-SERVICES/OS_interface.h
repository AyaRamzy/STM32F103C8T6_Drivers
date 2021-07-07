/***********************************************************************/
/* Author      : Aya Ramzy                                             */
/* Date        : 25 Sep 2020                                        */
/* Version     : V01                                                  */
/***********************************************************************/

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

void SOS_voidCreateTask(u8 Copy_u8TaskID,u16 period,void (*ptr)(void),u16 Copy_u16firstDelay);
void SOS_voidStart(void);

void SOS_voidSuspendTask(u8 Copy_u8TaskID);
void SOS_voidResumeTask(u8 Copy_u8TaskID);
void SOS_voidDeleteTask(u8 Copy_u8TaskID);

#endif /* OS_H_ */


#endif