/*File Name & Description : Invert_Block.c, This file allows the user to invert the data at any allocated address 
 File Author Name : Amogh.S & Srinath.S
 Tools used to process the code: (GCC: compiler, ld: GNU linker, GNU: debugger)
 Identification of any leveraged code: The calculation of the time required by the block to get inverted is taken from Geeks for Geeks
 Applicable Links: https://www.geeksforgeeks.org/time-function-in-c/
                   https://www.geeksforgeeks.org/clock-function-in-c-c/ */

#include "../includes/Invert_memory_block.h"

#define systick_stop   SysTick->CTRL&=~(SysTick_CTRL_ENABLE_Msk);// https://community.nxp.com/thread/422981


typedef enum{
  ERROR = -1,
  SUCCESS = 1,
}status;


/*******************************************************************************
* Function Name: Invert_Block 
********************************************************************************
*
* Summary:
*  This function is used to invert a block of memory at user entered address
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
int Invert_Block (int var_args_len, ...)
{
	int users_choice;
  	int length;
	int count =0 ;
	//int count1 =0;
	int user_write_value_invert = 0;              // Flag to check if the user entered address is a valid address
	int64_t temporary_address_invert;            // A temporary variable to store the addresses
	int64_t user_entered_offset_address_invert;   // this variable hold the offset value of the address
	clock_t time_stamp;
	int32_t* user_entered_address_invert;
	int64_t* arguments_arr;
  
  if(var_args_len == 3)
  {
    va_list lst;
    va_start(lst,var_args_len);
    
    arguments_arr = va_arg (lst,int64_t*);
    va_end (lst);

    users_choice = arguments_arr[0];
    length = arguments_arr[2];
    if( users_choice>0 && users_choice<3 )
    {
      if(users_choice ==1)          // The address is directly given as address
      {
        if (memory_allocation_flag == 0)
        {

          user_entered_address_invert = (int32_t *) arguments_arr[1];
             
          for (int j=0; j< no_of_bytes; j++)           // check if the user entered address is a valid address
          {
            temporary_address_invert = (int64_t) (memory_start +j);  
	    //count = count + 1;
            if (user_entered_address_invert == (int32_t *)temporary_address_invert)
            {
              user_write_value_invert = 1;
	      count = count + j;
	      break;
            }
          }

          if((user_write_value_invert ==1) && (length >= 0) && (length <= (no_of_bytes - count)))        // if the entered address is a valid address , invert the memory at that location
          { 
            for(int i =0 ;i<length ;i++)
            {
              time_stamp = clock();                // logic to count the time required to complete the function
              *(user_entered_address_invert + i) = ~(*(user_entered_address_invert +i)); // logic to invert the data
              //printf("\n check");
            }

            time_stamp = clock()-time_stamp;
            double time_clk = ((double)(time_stamp))/CLOCKS_PER_SEC;
            user_write_value_invert =0;
            printf("\n time: %f seconds",time_clk);
          }
          else
          {
            printf("\n Enter appropriate address/length \n");
            return ERROR;
          }
        } 
        else 
        {
          printf("\n Please allocate the memory before inverting the data\n");
          return ERROR;
        } 
      }

      if(users_choice ==2)   // enter the address via offset
      {
        if (memory_allocation_flag == 0)
        {    
          user_entered_offset_address_invert = (int64_t) arguments_arr[1];
          if((user_entered_offset_address_invert>= 0) && (user_entered_offset_address_invert<no_of_bytes) && (length >= 0) && (length <= (no_of_bytes - user_entered_offset_address_invert)))
          {
            for(int i =0 ;i<length ;i++)
            {
              time_stamp = clock();                // logic to count the time required to complete the function
              *(memory_start+user_entered_offset_address_invert + i) = ~(*(memory_start+user_entered_offset_address_invert +i)); // logic to invert the data
            }

            time_stamp = clock()-time_stamp;
            double time_clk = ((double)(time_stamp))/CLOCKS_PER_SEC;
            user_write_value_invert =0;
            printf("\n time: %f seconds",time_clk);
          }
          // if((user_entered_offset_address_invert>= 0) && (user_entered_offset_address_invert<no_of_bytes))
          // {
          //   time_stamp = clock();
          //   *(memory_start+user_entered_offset_address_invert) = ~(*(memory_start+user_entered_offset_address_invert)); // logic to invert the data
          //   time_stamp = clock()-time_stamp;
          //   double time_clk = ((double)(time_stamp))/CLOCKS_PER_SEC;
          //   printf("\n time: %f",time_clk);
          // }
          else
          {
            printf("\n Please enter valid offset value\n");
            return ERROR;
          }
        }
        else 
        {
          printf("\n Please allocate the memory before inverting the data\n");
          return ERROR;
        }
      }

    }

    else
    {     
      printf(" \nEnter a valid input, '1'  OR '2' \n ");
      return ERROR;
    }
  }
  else
  {
    printf("\n Please enter the right number of arguments \n");
    return ERROR;
  }
  
  return SUCCESS;
}
#endif

#ifdef FRDM
int Invert_Block (int var_args_len, ...)
{
	int users_choice;
    	int length;
	int user_write_value_invert =0 ;              // Flag to check if the user entered address is a valid address
	int32_t temporary_address_invert;            // A temporary variable to store the addresses
	int32_t user_entered_offset_address_invert;   // this variable hold the offset value of the address
	int32_t* user_entered_address_invert;
	int32_t* arguments_arr;
	float cnt=0;
	float time_clk=0;
  if(var_args_len == 3)
  {
  

    va_list lst;
    va_start(lst,var_args_len);

    arguments_arr = va_arg (lst,int32_t*);
    va_end (lst);

    users_choice = arguments_arr[0];
    length = arguments_arr[2];

    if( users_choice>0 && users_choice<3 )
    {
      if(users_choice ==1)          // The address is directly given as address
      {
        if (memory_allocation_flag == 0)
        {

          user_entered_address_invert = (int32_t *) arguments_arr[1];
          PRINTF("\n\r no of bytes : %d", no_of_bytes);

          for (int j=0; j< no_of_bytes; j++)           // check if the user entered address is a valid address
          {
            temporary_address_invert = (int32_t) (memory_start +j);
           // PRINTF("\n\r The temp address vale is % p\n\r",temporary_address_invert);
		count = count + 1;
            if (user_entered_address_invert == (int32_t *)temporary_address_invert)
            {
              user_write_value_invert = 1;
		count1 =count;
            }
          }

          if((user_write_value_invert ==1) && (length >= 0) && (length <= no_of_bytes))        // if the entered address is a valid address , invert the memory at that location
          { 
            SysTick_Config(16000000); 
            for(int i =0 ;i<length ;i++)
            {
                             // logic to count the time required to complete the function
              *(user_entered_address_invert + i) = ~(*(user_entered_address_invert +i)); // logic to invert the data
              //printf("\n check");
            }

            cnt = 16000000 - SysTick->VAL;
           // PRINTF("\n\r count: %f",cnt);
            systick_stop;
            time_clk = (cnt/48);
            PRINTF("\n\r time: %f us",time_clk);
          }
          else
          {
      	  PRINTF("\n\r Enter appropriate address\n\r");
            return ERROR;
          }
        }
        else
          {
            PRINTF("\n\r Please allocate the memory before inverting the data\n\r");
            return ERROR;
          }
      }


      if(users_choice ==2)   // enter the address via offset
      {
        if (memory_allocation_flag == 0)
        {
          user_entered_offset_address_invert = (int32_t) arguments_arr[1];

          if((user_entered_offset_address_invert>= 0) && (user_entered_offset_address_invert<no_of_bytes) && (length >= 0) && (length <= no_of_bytes))
          {
            SysTick_Config(16000000);
            for(int i =0 ;i<length ;i++)
            {
              
              *(memory_start+user_entered_offset_address_invert + i) = ~(*(memory_start+user_entered_offset_address_invert +i)); // logic to invert the data
            }

            cnt = 16000000 - SysTick->VAL;
          //  PRINTF("\n\r count: %f",cnt);
            systick_stop;
            time_clk = (cnt/48);
            PRINTF("\n\r time: %f us",time_clk);
          }
          else
          {
          	PRINTF("\n\r Please enter valid offset value\n\r");
            return ERROR;
          }
        }
        else
        {
      	  PRINTF("\n\r Please allocate the memory before inverting the data\n\r");
          return ERROR;
        }
      }

    }

    else
    {
  	  PRINTF(" \n\rEnter a valid input, '1'  OR '2' \n\r ");
      return ERROR;
    }

  }
  else
  {
	  PRINTF("\n\r Please enter the right number of arguments \n\r");
    return ERROR;
  }

  return SUCCESS;
}
#endif


