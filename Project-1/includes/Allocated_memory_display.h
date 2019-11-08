/* Allocated_memory_display */

/***************************************
*			INCLUDE FILES
***************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

#include "Context_switch.h"


/***************************************
*		FUNCTION PROTOTYPES
***************************************/
// void allocated_memory_display (int, int);
int allocated_memory_display(int var_args_len, ...);

extern int memory_allocation_flag;
extern int32_t *memory_start;
extern int32_t no_of_bytes;




