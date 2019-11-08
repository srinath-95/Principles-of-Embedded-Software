#include "../includes/Verify_pattern.h"


#define systick_stop   SysTick->CTRL&=~(SysTick_CTRL_ENABLE_Msk);


typedef enum{
  ERROR = -1,
  SUCCESS = 1,
}status;


#ifdef LINUX
int Verify_pattern(int var_args_len, ...)

{
	
	int user_write_value_verify_write_pattern;
	int count =0;
	//int count1 =0;
	int32_t *user_entered_address_verify_write_pattern;
	int32_t *temporary_address_verify_write_pattern;

	uint32_t seed_val_verify_pattern, data_length_verify_pattern;
  	clock_t time_stamp;
	int32_t *temp_write_pattern;
	
	int64_t* arguments_arr;
  if(var_args_len ==3)
  {
    if (memory_allocation_flag == 0)
    {
      
      va_list lst;
      va_start(lst,var_args_len);
      
      arguments_arr = va_arg (lst,int64_t*);
      va_end (lst);

      user_entered_address_verify_write_pattern = (int32_t *) arguments_arr[0];
      data_length_verify_pattern = (int32_t) arguments_arr[1];
      seed_val_verify_pattern = (int32_t) arguments_arr[2];

      //printf("\n Please enter the address location, where you want to modify the data\n");
      //for(int i=0;i<=90;i++)               // To display organised GUI
      //{
        //printf("*");
      //} 
      //printf("\n");
      //printf("\n ---> "); 
      //for(int i=0;i<=90;i++)               // To display organised GUI
      //{
        //printf("*");
      //} 

      for (int j=0; j< no_of_bytes; j++)  // check if the user entered address is a valid address
      {
        temporary_address_verify_write_pattern = (memory_start +j);
	//count = count + 1;
        if (user_entered_address_verify_write_pattern == temporary_address_verify_write_pattern )
        {
          user_write_value_verify_write_pattern = 1;
	  count = count +j;

        }
      }

      if (user_write_value_verify_write_pattern == 1)
      {
        if ( (seed_val_verify_pattern >=0) && (data_length_verify_pattern >=0) && (data_length_verify_pattern <= (no_of_bytes - count)) )
        {
          time_stamp = clock(); 
          for(int i=0;i<data_length_verify_pattern;i++)
          {
            temp_write_pattern = user_entered_address_verify_write_pattern; 

            if ((*(temp_write_pattern + i)) == ((uint32_t)(((uintptr_t)(temp_write_pattern + i)) ^ (seed_val_verify_pattern))))
            {
              printf("\nThe data is verified for the address location : %p\n",(temp_write_pattern + i));
            } 
            else
            {
              printf("\n\r Pattern verification failed for %p\n\r",(temp_write_pattern + i));
            }
          } 
          time_stamp = clock()-time_stamp;
          double time_clk = ((double)(time_stamp))/CLOCKS_PER_SEC;
          printf("\n time: %f s",time_clk);
        }
       else
        {
          printf("\n\r Please enter valid length or valid seed value");
          return ERROR;
        }
      }
      else
      {
        printf("\n\rPlease enter a valid address\n\r");
        return ERROR;
      }
    }
    
    else
    {
      printf("\nThere is no allocated memory, therefore data cannot be verified\n");
      return ERROR;
    }

  }
  else
  {
    printf("\nPlease enter the valid number of arguments");
    return ERROR;
  }
 return SUCCESS;
}  
#endif

#ifdef FRDM
int Verify_pattern(int var_args_len, ...)

{
	int user_write_value_verify_write_pattern;
	int32_t *user_entered_address_verify_write_pattern;
	int32_t *temporary_address_verify_write_pattern;
	uint32_t seed_val_verify_pattern, data_length_verify_pattern;
	int32_t *temp_write_pattern;
	int32_t* arguments_arr;
	float cnt=0;
  if(var_args_len ==3)
  {
    if (memory_allocation_flag == 0)
    {

      va_list lst;
      va_start(lst,var_args_len);

      arguments_arr = va_arg (lst,int32_t*);
      va_end (lst);

      user_entered_address_verify_write_pattern = (int32_t *) arguments_arr[0];
      data_length_verify_pattern = (int32_t) arguments_arr[1];
      seed_val_verify_pattern = (int32_t) arguments_arr[2];

//      PRINTF("\n\r Please enter the address location, where you want to modify the data\n\r");
//      for(int i=0;i<=90;i++)               // To display organised GUI
//      {
//      	PRINTF("*");
//      }
//      PRINTF("\n\r");
//      PRINTF("\n\r ---> ");
//      for(int i=0;i<=90;i++)               // To display organised GUI
//      {
//      	PRINTF("*");
//      }

      for (int j=0; j< no_of_bytes; j++)  // check if the user entered address is a valid address
      {
        temporary_address_verify_write_pattern = (memory_start +j);
        if (user_entered_address_verify_write_pattern == temporary_address_verify_write_pattern )
        {
          user_write_value_verify_write_pattern = 1;
        }
      }

      if (user_write_value_verify_write_pattern == 1)
      {
        if ( (seed_val_verify_pattern >=0) && (data_length_verify_pattern >=0) && (data_length_verify_pattern <= no_of_bytes) )
        {

          SysTick_Config(16000000);
          for(int i=0;i<data_length_verify_pattern;i++)
          {
            temp_write_pattern = user_entered_address_verify_write_pattern;

            if ((*(temp_write_pattern + i)) == ((uint32_t)(((uintptr_t)(temp_write_pattern + i)) ^ (seed_val_verify_pattern))))
            {
          	  PRINTF("\n\rThe data is verified for the address location : %p\n\r",(temp_write_pattern + i));
            }
            else
            {
              PRINTF("\n\r Pattern verification failed for %p\n\r",(temp_write_pattern + i));
            }
          }

          cnt = 16000000 - SysTick->VAL;
          systick_stop;
          float time_clk = (cnt/48);
          PRINTF("\n\r time: %f us",time_clk);
        }
        else
        {
          PRINTF("\n\r Please enter valid length or valid seed value");
          return ERROR;
        }
      }
      else
      {
      	PRINTF("\n\rPlease enter a valid address\n\r");
      	return ERROR;
      }
    }
    else
    {
      PRINTF("\n\rThere is no allocated memory, therefore data cannot be verified\n\r");
      return ERROR;
    }

  }
  else
  {
	  PRINTF("\n\rPlease enter the valid number of arguments");
    return ERROR;
  }
 return SUCCESS;
}
#endif


