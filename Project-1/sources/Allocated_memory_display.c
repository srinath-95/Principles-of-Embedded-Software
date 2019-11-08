
/*File Name & Description : Allocated_memory_display.c, This file allows the user to see all the addresses available to the user to work with and the corresponding data
 File Author Name : Amogh.S & Srinath.S
 Tools used to process the code: (GCC: compiler, ld: GNU linker, GNU: debugger)
 Identification of any leveraged code: No code leveraged in this file
 Applicable Links: No links */


#include "../includes/Allocated_memory_display.h"
#include "stdarg.h"



typedef enum{
  ERROR = -1,
  SUCCESS = 1,
}status;

/*******************************************************************************
* Function Name: allocated_memory_display
********************************************************************************
*
* Summary:
*  Displays the allocated memory and corresponding data
*
* Parameters:
*  integer
*
* Return:
*  None.
*
*
*
* Reference: Self
*
*******************************************************************************/
#ifdef LINUX
int allocated_memory_display(int var_args_len, ...)
{
  if(var_args_len == 0)
  {
    if (memory_allocation_flag == 0)                            //  if memory is allocated then only display the address and the data
    {
      for (int j=1; j<= no_of_bytes; j++)
      {
        printf ("\n The address of word %d\t: %p ", j, (memory_start-1 +j));  // display all the allocated addresses and the corresponding data at evry addresses
        printf ("Data: 0x%x " , *(memory_start-1 +j));
        
      }
    }
    else
    {
      printf(" \n There is no allocated memory to display \n" );
      return ERROR;
    }
  }
  else
  {
    printf("\n Please enter right number of arguments");
    return ERROR;
  }
  return SUCCESS;
}
#endif


#ifdef FRDM
int allocated_memory_display(int var_args_len, ...)
{
  if(var_args_len == 0)
  {
    if (memory_allocation_flag == 0)                            //  if memory is allocated then only display the address and the data
    {
      for (int j=1; j<= no_of_bytes; j++)
      {
        PRINTF ("\n\r The address of word %d\t: %p ", j, (memory_start-1 +j));  // display all the allocated addresses and the corresponding data at evry addresses
        PRINTF ("Data: 0x%x " , *(memory_start-1 +j));

      }
    }
    else
    {
    	PRINTF(" \n\r There is no allocated memory to display \n\r" );
      return ERROR;
    }
  }
  else
  {
	  PRINTF("\n\r Please enter right number of arguments");
    return ERROR;
  }
  return SUCCESS;
}
#endif

