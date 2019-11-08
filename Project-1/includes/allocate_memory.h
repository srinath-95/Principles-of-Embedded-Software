/* Allocate_Memory*/

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

//void memory_allocate (int, int, int);
int memory_allocate (int var_args_len, ...);
// int memory_allocate (int a, int b);
//extern int memory_allocation_flag; 

//#include <malloc.h>
// #include "allocate_memory.h"
#include "stdarg.h"

extern int memory_allocation_flag;
extern int32_t *memory_start;
extern int32_t no_of_bytes;
