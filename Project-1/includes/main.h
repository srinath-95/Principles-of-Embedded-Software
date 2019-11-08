
/***************************************
*			INCLUDE FILES
***************************************/


//#define FRDM     // Select FRDM or LINUX based on the system you are working on



#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

#include "exit.h"
#include "help.h"
#include "allocate_memory.h"
#include "free_memory.h"
#include "Context_switch.h"

int memory_allocation_flag = 1;
int32_t *memory_start;
int32_t no_of_bytes = 0;

 

