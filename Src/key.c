/*-----------------------------------------------------------------
 * Name:    key.c   
 * Purpose: key driver  
 *-----------------------------------------------------------------
 * 
 * Copyright (c) *reserve
 
||                       _      _               ||
||    /\  /\  __  _  __ | | __ | | ____  ___ _  ||
||   /  \/  \/ _ ` |/ _ ` |/ _ ` |/ _  \/ _ ` | ||
||  / /\  /\  (_|    (_|    (_|    (_)   (_)  | ||
|| /_/  \/  \_.__, |\__, _|\__, _|\____/\___. | ||
|| =====================================|____/  ||
||                                              ||

 -----------------------------------------------------------------*/
 
/********************************************************************************************************
 *                                               INCLUDES
 ********************************************************************************************************/
//#include "stm32f4xx_hal.h"
#include "key.h"
/********************************************************************************************************
 *                                                 MACROS
 ********************************************************************************************************/


/********************************************************************************************************
 *                                               CONSTANTS
 ********************************************************************************************************/

 
/********************************************************************************************************
 *                                               GLOBAL VARIABLES
 ********************************************************************************************************/


/********************************************************************************************************
 *                                               EXTERNAL VARIABLES
 ********************************************************************************************************/
extern uint8_t  Key_Up;
extern uint32_t Time_1ms;
 
/********************************************************************************************************
 *                                               EXTERNAL FUNCTIONS
 ********************************************************************************************************/


/********************************************************************************************************
 *                                               LOCAL VARIABLES
 ********************************************************************************************************/

 
/********************************************************************************************************
 *                                               LOCAL FUNCTIONS
 ********************************************************************************************************/

 
/********************************************************************************************************
 *                                               PUBLIC FUNCTIONS
 ********************************************************************************************************/
 
/*********************************************************************
 * @fn        Key_Scan()
 *
 * @brief     ����ɨ������ 
 *
 * @param     none
 *
 * @return    Key_None--������Ч   Key_Short--�����̰�   Key_Long--��������
 */
KeyStatus Key_Scan(void)
{
	if(Key_Up == 1)        // �а�������
	{
		Time_1ms = 0;
		Key_Up = 0;
		if(Time_1ms > Long_Thre)       return Key_Long;         // ��������ʱ�����2s      ����
		else if(Time_1ms > Short_Thre) return Key_Short;        // ��������ʱ��С��2s      �̰�      
		else                           return Key_None;         // ������������
	}
	return Key_None;
}
 /********************************************************************************************************
 *                                               LOCAL FUNCTIONS
 ********************************************************************************************************/

/*********************************************************************
 * @fn      
 *
 * @brief   
 *
 * @param   
 *
 * @return  
 */
 
 


/*********************************************************************
 */