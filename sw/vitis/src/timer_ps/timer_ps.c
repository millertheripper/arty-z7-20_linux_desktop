/************************************************************************/
/*																		*/
/*	timer_ps.c	--	Timer Delay	for Zynq systems						*/
/*																		*/
/************************************************************************/
/*	Author: Sam Bobrowicz												*/
/*	Copyright 2014, Digilent Inc.										*/
/************************************************************************/
/*  Module Description: 												*/
/*																		*/
/*		Implements an accurate delay function using the scu	timer.     	*/
/*		Code from this module will cause conflicts with other code that */
/*		requires the Zynq's scu timer.									*/
/*																		*/
/*		This module contains code from the Xilinx Demo titled			*/
/*		"xscutimer_polled_example.c"									*/
/*																		*/
/************************************************************************/
/*  Revision History:													*/
/* 																		*/
/*		2/14/2014(SamB): Created										*/
/*																		*/
/************************************************************************/


/* ------------------------------------------------------------ */
/*				Include File Definitions						*/
/* ------------------------------------------------------------ */
#include "timer_ps.h"
#include "xscutimer.h"
#include "xil_types.h"
#include <stdio.h>

/* ------------------------------------------------------------ */
/*				Global Variables								*/
/* ------------------------------------------------------------ */

XScuTimer TimerInstance;	/* Cortex A9 Scu Private Timer Instance */

/* ------------------------------------------------------------ */
/*				Procedure Definitions							*/
/* ------------------------------------------------------------ */

/***	TimerInitialize(u16 TimerDeviceId)
**
**	Parameters:
**		TimerDeviceId - The DEVICE ID of the Zynq SCU TIMER
**
**	Return Value: int
**		XST_SUCCESS if successful
**
**	Errors:
**
**	Description: Configures the global timer struct to access the
**				 the SCU timer. Can be called multiple times without
**				 error.
**
*/
int TimerInitialize(u16 TimerDeviceId)
{
	int Status;
	XScuTimer *TimerInstancePtr = &TimerInstance;
	XScuTimer_Config *ConfigTmrPtr;

	/*
	 * Initialize the Scu Private Timer driver.
	 */
	ConfigTmrPtr = XScuTimer_LookupConfig(TimerDeviceId);

	/*
	 * This is where the virtual address would be used, this example
	 * uses physical address. Note that it is not considered an error
	 * if the timer has already been initialized.
	 */
	Status = XScuTimer_CfgInitialize(TimerInstancePtr, ConfigTmrPtr,
			ConfigTmrPtr->BaseAddr);
	if (Status != XST_SUCCESS || Status != XST_DEVICE_IS_STARTED) {
		return XST_FAILURE;
	}

	/*
	 * Set prescaler to 1
	 */
	XScuTimer_SetPrescaler(TimerInstancePtr, 0);

	return Status;
}
/* ------------------------------------------------------------ */

/***	TimerDelay(u32 uSDelay)
**
**	Parameters:
**		uSDelay - Desired delay in micro seconds
**
**	Return Value:
**
**	Errors:
**
**	Description: Blocks execution for the desired amount of time.
**			TimerInitialize must have been called at least once
**			before calling this function.
*/
/* ------------------------------------------------------------ */
void TimerDelay(u32 uSDelay)
{
	u32 timerCnt;

	timerCnt = (TIMER_FREQ_HZ / 1000000) * uSDelay;

	XScuTimer_Stop(&TimerInstance);
	XScuTimer_DisableAutoReload(&TimerInstance);
	XScuTimer_LoadTimer(&TimerInstance, timerCnt);
	XScuTimer_Start(&TimerInstance);
	while (XScuTimer_GetCounterValue(&TimerInstance))
	{}

	return;
}

void timer_measure_start(void)
{
	/* Collect timer value for performance measurement */
	XScuTimer_LoadTimer(&TimerInstance, 0xFFFFFFFF);
	XScuTimer_Start(&TimerInstance);
    XScuTimer_RestartTimer(&TimerInstance);
}

uint32_t timer_measure_stop(void)
{
    return (0xFFFFFFFF - XScuTimer_GetCounterValue(&TimerInstance));
}

void timer_print_diff(const char *msg, uint32_t tick_diff)
{
	float time_diff = 0;

	time_diff = (float)(tick_diff)/TIMER_FREQ_HZ;
    printf("\r\n%s: %f s\r\n", msg, time_diff);
}

/************************************************************************/
