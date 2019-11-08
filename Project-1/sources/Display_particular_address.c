/*File Name & Description : Display_particular_address.c, This file allows the user to display a range of addresses by giving the address offset
 File Author Name : Amogh.S & Srinath.S
 Tools used to process the code: (GCC: compiler, ld: GNU linker, GNU: debugger)
 Identification of any leveraged code: No code leveraged in this file
 Applicable Links: No links */

#include "../includes/Display_particular_address.h"

typedef enum{
  ERROR = -1,
  SUCCESS = 1,
}status;


/*******************************************************************************
* Function Name: Display_particular_address
********************************************************************************
*
* Summary:
*  Displays the allocated memory and corresponding data for a given range of addresses
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
int Display_particular_address(int var_args_len, ...)
{
	int32_t offset_address_start;  // the offset address from which the user wants to read the data
	int32_t offset_address_end;    // the end offset address till which the user wants to  read the data
  if(var_args_len == 2)
  {
    if (memory_allocation_flag == 0)
    {
      int64_t* arguments_arr;
      va_list lst;
      va_start(lst,var_args_len);

      arguments_arr = va_arg (lst,int64_t *);
      va_end (lst);
      printf("\n The value of offset_address_start:%lx",arguments_arr[0]);
      printf("\n he value of offset_address_end:%lx",arguments_arr[1]);
      offset_address_start = arguments_arr[0];
      offset_address_end = arguments_arr[1];

      if ( (offset_address_end>= offset_address_start) && ((offset_address_start>=0) && (offset_address_start < no_of_bytes)) && ((offset_address_end>=0) && (offset_address_end < no_of_bytes))) // if the offset is valid, display the required addresses
      {
        for (int k=offset_address_start; k<= offset_address_end; k++)  // display the data from start of the offset address to the end of the offset address
        {
          printf ("\n The address of word %d\t: %p ", k+1, (memory_start+k));
          printf ("Data: 0x%x " , *(memory_start+k));
        }

      }
      else
      {
        printf("\n Please enter the offset value correctly \n"); // The added offset number should be logical
        return ERROR;
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
    printf("\n Please enter the correct number of parameters");
    return ERROR;
  }
  
  return SUCCESS;
}
#endif


#ifdef FRDM
int Display_particular_address(int var_args_len, ...)
{
	int32_t offset_address_start;  // the offset address from which the user wants to read the data
	int32_t offset_address_end;    // the end offset address till which the user wants to  read the data
  if(var_args_len == 2)
  {
    if (memory_allocation_flag == 0)
    {
      int32_t* arguments_arr;
      va_list lst;
      va_start(lst,var_args_len);
      arguments_arr = va_arg (lst,int32_t *);
      va_end (lst);

      PRINTF("\n\r The value of offset_address_start:%lx",arguments_arr[0]);
      PRINTF("\n\r he value of offset_address_end:%lx",arguments_arr[1]);
      offset_address_start = arguments_arr[0];
      offset_address_end = arguments_arr[1];

      if ( (offset_address_end>= offset_address_start) && ((offset_address_start>=0) && (offset_address_start < no_of_bytes)) && ((offset_address_end>=0) && (offset_address_end < no_of_bytes))) // if the offset is valid, display the required addresses
      {
        for (int k=offset_address_start; k<= offset_address_end; k++)  // display the data from start of the offset address to the end of the offset address
        {
      	  PRINTF ("\n\r The address of word %d\t: %p ", k+1, (memory_start+k));
      	  PRINTF ("Data: 0x%x " , *(memory_start+k));
        }

      }
      else
      {
      	PRINTF("\n\r Please enter the offset value correctly \n\r"); // The added offset number should be logical
        return ERROR;
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
	  PRINTF("\n Please enter the correct number of parameters");
    return ERROR;
  }

  return SUCCESS;
}
#endif



