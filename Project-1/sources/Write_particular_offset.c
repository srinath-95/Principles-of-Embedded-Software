/*File Name & Description : Write_particular_offset.c, This file allows the user to enter data at particular address using address offset 
 File Author Name : Amogh.S & Srinath.S
 Tools used to process the code: (GCC: compiler, ld: GNU linker, GNU: debugger)
 Identification of any leveraged code: No leveraged code
 Applicable Links: None */

#include "../includes/Write_particular_offset.h"


typedef enum{
  ERROR = -1,
  SUCCESS = 1,
}status;

/*******************************************************************************
* Function Name: Write_particular_offset
********************************************************************************
*
* Summary:
*  This function is used to enter data at particular address using offset
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
int Write_particular_offset (int var_args_len, ...)
{
	int32_t user_entered_offset_address;
	int32_t user_entered_offset_data;
	int64_t* arguments_arr;
  if(var_args_len==2)
  {
    va_list lst;
    va_start(lst,var_args_len);

    arguments_arr = va_arg (lst,int64_t*);
    va_end (lst);

    user_entered_offset_address = (int32_t) arguments_arr[0];

    user_entered_offset_data = (int32_t) arguments_arr[1];

    if (memory_allocation_flag == 0)
    {

      if((user_entered_offset_address>= 0) && (user_entered_offset_address<no_of_bytes))
      {
        *(memory_start+user_entered_offset_address) = user_entered_offset_data;  // enter data at particular offseted address
      }
      else
      {
        printf("\n Please enter a valid offset address\n");
        return ERROR;
      }
    }
    else
    {
      printf("\n  There is no allocated memory, therefore data cannot be written \n");
      return ERROR;
    }
  }
  else
  {
    printf("\n Please enter the right number of arguments");
    return ERROR;
  }
  return SUCCESS;
}
#endif


#ifdef FRDM
int Write_particular_offset (int var_args_len, ...)
{
	int32_t user_entered_offset_address;
	int32_t user_entered_offset_data;
	//int64_t* arguments_arr;
	int32_t* arguments_arr;
  if(var_args_len==2)
  {
    va_list lst;
    va_start(lst,var_args_len);
    
    arguments_arr = va_arg (lst,int64_t*);
    va_end (lst);

    user_entered_offset_address = (int32_t) arguments_arr[0];

    user_entered_offset_data = (int32_t) arguments_arr[1];

    if (memory_allocation_flag == 0) 
    {
      if((user_entered_offset_address>= 0) && (user_entered_offset_address<no_of_bytes))
      {
        *(memory_start+user_entered_offset_address) = user_entered_offset_data;  // enter data at particular offseted address
      }
      else
      {
        PRINTF("\n\r Please enter a valid offset address\n\r");
        return ERROR;
      }
    }
    else
    {
      PRINTF("\n\r  There is no allocated memory, therefore data cannot be written \n\r");
      return ERROR;
    }
  }
  else
  {
    PRINTF("\n\r Please enter the right number of arguments");
    return ERROR;
  }
  return SUCCESS;
}
#endif
  
