/*Free Memory*/

/***************************************
*			INCLUDE FILES
***************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
//#include "main.h"

#include "Context_switch.h"

/***************************************
*		FUNCTION PROTOTYPES
***************************************/
int free_memory (int var_args_len, ...);
//void free_memory (int a, int b);

#include "stdarg.h"

extern int memory_allocation_flag;
extern int32_t *memory_start;
extern int32_t no_of_bytes;



