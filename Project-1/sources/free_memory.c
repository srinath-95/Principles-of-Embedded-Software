/*File Name & Description : free_memory.c, This file allows the user to free the allocated memory
 File Author Name : Amogh.S & Srinath.S
 Tools used to process the code: (GCC: compiler, ld: GNU linker, GNU: debugger)
 Identification of any leveraged code: No code leveraged in this file
 Applicable Links: No links */

#include "../includes/free_memory.h"
#include "../includes/allocate_memory.h"

typedef enum{
  ERROR = -1,
  SUCCESS = 1,
}status;

/*******************************************************************************
* Function Name: free_memory 
********************************************************************************
*
* Summary:
*  Frees the allocated memory for further memory allocation
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
int free_memory (int var_args_len, ...)
{
  if(var_args_len==0)
  {
    if( memory_start != NULL && memory_allocation_flag == 0)     // free the memory only if there is some memory allocated for the application
    {
      memory_allocation_flag = 1;                              // indicate that the allocated memory is now freed
      free (memory_start);    
      printf("\n The allocated memory is now freed \n"); 
    }
    else 
    {
      printf("\n You need to allocate memory before freeing it \n");
      return ERROR;
    }
  }
  else
  {
    printf("\n Please enter valid number of arguments");
    return ERROR;
  } 

 return SUCCESS;   
}
#endif



#ifdef FRDM
int free_memory (int var_args_len, ...)
{
  if(var_args_len==0)
  {
    if( memory_start != NULL && memory_allocation_flag == 0)     // free the memory only if there is some memory allocated for the application
    {
      memory_allocation_flag = 1;                              // indicate that the allocated memory is now freed
      free (memory_start);
      PRINTF("\n\r The allocated memory is now freed \n");
    }
    else
    {
    	PRINTF("\n\r You need to allocate memory before freeing it \n");
      return ERROR;
    }
  }
  else
  {
	  PRINTF("\n\r Please enter valid number of arguments");
    return ERROR;
  }

 return SUCCESS;
}
#endif
