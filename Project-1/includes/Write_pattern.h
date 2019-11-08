/* Write_pattern */

/***************************************
*			INCLUDE FILES
***************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<time.h>

#include "Context_switch.h"

/***************************************
*		FUNCTION PROTOTYPES
***************************************/
int Write_pattern(int var_args_len, ...);

#include "stdarg.h"


extern int memory_allocation_flag;
extern int32_t *memory_start;
extern int32_t no_of_bytes;
