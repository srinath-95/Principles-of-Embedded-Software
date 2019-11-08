/*File Name & Description : allocate_memory.c This file allows the user to allocate required no of words for the application
 File Author Name : Amogh.S & Srinath.S
 Tools used to process the code: (GCC: compiler, ld: GNU linker, GNU: debugger)
 Identification of any leveraged code: No leveraged code
 Applicable Links: None */
#include "../includes/allocate_memory.h"

typedef enum{
  ERROR = -1,
  SUCCESS = 1,
}status;

/*******************************************************************************
* Function Name: memory_allocate
********************************************************************************
*
* Summary:
*  This function is used to allocate required no of bytes as per the user
*
* Parameters:
*  integer
*
* Return:
*  int
*
* Reference: Self
*
*******************************************************************************/ 

#ifdef LINUX
int memory_allocate(int var_args_len, ...)
{ 
  if(var_args_len==1)
  {
    if(memory_allocation_flag == 1)
    {
      int64_t* arguments_arr;
      va_list lst;
      va_start(lst,var_args_len);      
      arguments_arr = va_arg (lst,int64_t *);     // Getting the argument value passed by user
      va_end (lst);

      printf("\n The no of bytes of data to be allocated is:%ld",arguments_arr[0]);
      no_of_bytes = arguments_arr[0];
      if( no_of_bytes >= 1 )
     {
      memory_start = (int32_t*)malloc(no_of_bytes*sizeof(int32_t));       // logic to allocate memory as per the need of the user
      if (memory_start == NULL )
      {
        printf("\n Sorry failed to allocate memory \n");
        return ERROR;
      }
      else 
      {
        printf("\n Success ! %d words of memory allocated successfully \n",no_of_bytes);
        //return SUCCESS;
        
      }
      memory_allocation_flag = 0;
      for (int j=0; j< no_of_bytes; j++)
      {
        printf ("\n The address of word %d\t: %p ", j, (memory_start+j));
        printf ("Data: 0x%x " , *(memory_start +j));
      }
      printf("\n");
    }
     else
    {
      printf("\n Please enter no of bytes more than 1 byte");
    }
   }
    else
    {
      printf("\nWarning! Please free the initial block of memory allocated\n");
      return ERROR;
    }
    
  }
  else
  {
    printf("\nPlease pass the correct number of arguments\n");
    return ERROR;
  }
  return SUCCESS;


}
#endif

#ifdef FRDM
int memory_allocate(int var_args_len, ...)
{
  if(var_args_len==1)
  {
    if(memory_allocation_flag == 1)
    {
      int32_t* arguments_arr;
      va_list lst;
      va_start(lst,var_args_len);

      arguments_arr = va_arg (lst,int32_t *);
      va_end (lst);
      PRINTF("\n\r The no of bytes of data to be allocated is:%d",arguments_arr[0]);
      no_of_bytes = arguments_arr[0];
     
      memory_start = (int32_t*)calloc(sizeof(int32_t),no_of_bytes);       // logic to allocate memory as per the need of the user
      if ( memory_start == NULL )
      {
    	  PRINTF("\n\r Sorry failed to allocate memory \n\r");
        return ERROR;
      }
      else
      {
    	  PRINTF("\n\r Success ! %d words of memory allocated successfully \n\r",no_of_bytes);

      }
      memory_allocation_flag = 0;
      for (int j=0; j< no_of_bytes; j++)
      {
    	  PRINTF ("\n\r The address of word %d\t: %p ", j, (memory_start+j));
    	  PRINTF ("Data: 0x%x " , *(memory_start +j));
      }
    }
    else
    {
    	PRINTF("\n\rWarning! Please free the initial block of memory allocated\n\r");
        return ERROR;
    }

  }
  else
  {
    PRINTF("\n\rPlease pass the correct number of arguments\n\r");
    return ERROR;
  }
  return SUCCESS;

}
#endif


