/*
 * Context_switch.h
 *
 *  Created on: Mar 10, 2019
 *      Author: amosh
 */

#ifndef INCLUDES_CONTEXT_SWITCH_H_
#define INCLUDES_CONTEXT_SWITCH_H_


#define LINUX     // Select FRDM or LINUX based on the system you are working on

#ifdef FRDM
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "pin_mux.h"
#endif


#endif /* INCLUDES_CONTEXT_SWITCH_H_ */
