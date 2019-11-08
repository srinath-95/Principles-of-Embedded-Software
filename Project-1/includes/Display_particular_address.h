/* Display_particular_address*/

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
int Display_particular_address(int var_args_len, ...);

#include "stdarg.h"

//int user_write_value=0; 
extern int memory_allocation_flag;
extern int32_t *memory_start;
extern int32_t no_of_bytes;

