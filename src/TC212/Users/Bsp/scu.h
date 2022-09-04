/**********************************************************************************************************************
 * \file SCU_Reset_Detection.h
 * \copyright Copyright (C) Infineon Technologies AG 2019
 *
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are solely in the form of
 * machine-executable object code generated by a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *********************************************************************************************************************/

#ifndef SCU_RESET_DETECTION_H_
#define SCU_RESET_DETECTION_H_

/*********************************************************************************************************************/
/*---------------------------------------------------Enumerations----------------------------------------------------*/
/*********************************************************************************************************************/
/* Reset types */
typedef enum
{
    IfxScuRcu_ResetType_coldpoweron = 0,    /* Cold Power On Reset           */
    IfxScuRcu_ResetType_system      = 1,    /* System Reset                  */
    IfxScuRcu_ResetType_application = 2,    /* Application reset             */
    IfxScuRcu_ResetType_warmpoweron = 3,    /* Warm Power On Reset           */
    IfxScuRcu_ResetType_debug       = 4,    /* Debug reset                   */
    IfxScuRcu_ResetType_undefined   = 5     /* Undefined Reset               */
} scuRcuResetType;

/* Reset Triggers */
typedef enum
{
    IfxScuRcu_Trigger_esr0      = 0,        /* ESR0                          */
    IfxScuRcu_Trigger_esr1      = 1,        /* ESR1                          */
    IfxScuRcu_Trigger_smu       = 3,        /* SMU                           */
    IfxScuRcu_Trigger_sw        = 4,        /* SW                            */
    IfxScuRcu_Trigger_stm0      = 5,        /* STM0 Compare Match            */
    IfxScuRcu_Trigger_stm1      = 6,        /* STM1  Compare Match           */
    IfxScuRcu_Trigger_stm2      = 7,        /* STM2 Compare Match            */
    IfxScuRcu_Trigger_porst     = 16,       /* PORST                         */
    IfxScuRcu_Trigger_cb0       = 18,       /* Cerberus System Reset         */
    IfxScuRcu_Trigger_cb1       = 19,       /* Cerberus Debug Reset          */
    IfxScuRcu_Trigger_cb3       = 20,       /* Cerberus Application Reset    */
    IfxScuRcu_Trigger_evr13     = 23,       /* EVR13                         */
    IfxScuRcu_Trigger_evr33     = 24,       /* EVR33                         */
    IfxScuRcu_Trigger_swd       = 25,       /* Supply Watchdog               */
    IfxScuRcu_Trigger_stbyr     = 28,       /* Standby Regulator Watchdog    */
    IfxScuRcu_Trigger_undefined = 255       /* Undefined Value               */
} scuRcuTrigger;

/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/
typedef struct
{
    scuRcuResetType resetType;              /* Reset Type                    */
    scuRcuTrigger   resetTrigger;           /* Reset Trigger                 */
} scuRcuResetCode;

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define RESET_SRC               APPLICATION_RESET                   /* Macro used to set the type of software reset */
#define APPLICATION_RESET       IfxScuRcu_ResetType_application
#define SYSTEM_RESET            IfxScuRcu_ResetType_system

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void detectResetSource(void);
scuRcuResetCode evaluateReset(void);
void clearColdPowerOnResetBits(void);
void triggerSwReset(scuRcuResetType resetType);

#endif /* SCU_RESET_DETECTION_H_ */