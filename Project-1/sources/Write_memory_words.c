/*File Name & Description : Write_memory_words.c This file allows the user to write data at the user mentioned address
 File Author Name : Amogh.S & Srinath.S
 Tools used to process the code: (GCC: compiler, ld: GNU linker, GNU: debugger)
 Identification of any leveraged code: No leveraged code
 Applicable Links: None */

#include "../includes/Write_memory_words.h"

typedef enum{
  ERROR = -1,
  SUCCESS = 1,
}status;

/*******************************************************************************
* Function Name: Write_memory_words
********************************************************************************
*
* Summary:
*  This function is used to write data at user defined address
*
* Parameters:
*  integer
*
* Return:
*  None.
*
* Reference: Self
*
*******************************************************************************/  	
#ifdef LINUX
int Write_memory_words(int var_args_len, ...)
{
	int64_t *user_entered_address;
	int64_t temporary_address;
	int64_t* arguments_arr;
	int user_write_value ;
	int32_t user_entered_data;
  if(var_args_len ==2)
  {
    if (memory_allocation_flag == 0)
    {
      
      va_list lst;
      va_start(lst,var_args_len);
      
      arguments_arr = va_arg (lst,int64_t*);
      va_end (lst);

      user_entered_address = (int64_t *) arguments_arr[0];

      user_entered_data = (int32_t) arguments_arr[1];


      for (int j=0; j< no_of_bytes; j++)  // check if the user entered address is a valid address
      {
        temporary_address = (int64_t)(memory_start +j);
        if (user_entered_address == (int64_t*)temporary_address )
        {
          user_write_value = 1;
        }
      }
      if (user_write_value == 1)
      {
        
        for(int i=0;i<=90;i++)               // To display organised GUI
        {
          printf("*");
        } 
        printf("\n");
        printf("\n ---> ");
        user_write_value = 0;

        *user_entered_address = user_entered_data; // enter the required hex data at the given address
        
      }

      else
      {
        printf("\n Please enter the valid address \n"); 
        return ERROR;
      }
    }
    else
    {
      printf(" \n There is no allocated memory, therefore data cannot be written\n" );
      return ERROR;
    }
  }
  else
  {
    printf("\n Please enter the  valid number of arguments\n");
    return ERROR;
  }
  return SUCCESS;
}

#endif

#ifdef FRDM
int Write_memory_words(int var_args_len, ...)
{
	int32_t *user_entered_address;
	int32_t temporary_address;
	int32_t* arguments_arr;
	int memory_allocation_flag;
	int user_write_value ;
	int32_t user_entered_data;
  if(var_args_len ==2)
  {
    if (memory_allocation_flag == 0)
    {

      va_list lst;
      va_start(lst,var_args_len);

      arguments_arr = va_arg(lst,int32_t*);
      va_end (lst);

      user_entered_address = (int32_t *) arguments_arr[0];

      user_entered_data = (int32_t) arguments_arr[1];


      for (int j=0; j< no_of_bytes; j++)  // check if the user entered address is a valid address
      {
        temporary_address = (int32_t)(memory_start +j);
        if (user_entered_address == (int32_t*)temporary_address )
        {
          user_write_value = 1;
        }
      }
      if (user_write_value == 1)
      {
        for(int i=0;i<=90;i++)               // To display organised GUI
        {
        	PRINTF("*");
        }
        PRINTF("\n\r");
        PRINTF("\n\r ---> ");
        user_write_value = 0;

        *user_entered_address = user_entered_data; // enter the required hex data at the given address

      }

      else
      {
    	  PRINTF("\n\r Please enter the valid address \n\r");
        return ERROR;
      }
    }
    else
    {
    	PRINTF(" \n\r There is no allocated memory, therefore data cannot be written\n\r" );
      return ERROR;
    }
  }
  else
  {
	  PRINTF("\n\r Please enter the  valid number of arguments\n\r");
    return ERROR;
  }
  return SUCCESS;
}

#endif

