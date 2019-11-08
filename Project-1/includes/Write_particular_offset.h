/*Write_particular_offset*/

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
// void Write_particular_offset (int, int);
int  Write_particular_offset (int var_args_len, ...);

#include "stdarg.h"

extern int memory_allocation_flag;
extern int32_t *memory_start;
extern int32_t no_of_bytes;

