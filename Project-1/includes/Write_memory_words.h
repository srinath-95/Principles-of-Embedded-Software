/*Write memory words*/

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

// void Write_memory_words(int , int);
int Write_memory_words(int var_args_len, ...);

#include "stdarg.h"


extern int memory_allocation_flag;
extern int32_t *memory_start;
extern int32_t no_of_bytes;


