

#include "../includes/Write_pattern.h"

#define systick_stop   SysTick->CTRL&=~(SysTick_CTRL_ENABLE_Msk);


typedef enum{
  ERROR = -1,
  SUCCESS = 1,
}status;

#ifdef LINUX
int Write_pattern(int var_args_len, ...)

{
	int user_write_value_verify_pattern;
	int count =0;
	//int count1 =0;
	int32_t *user_entered_address_verify_pattern;
	int32_t *temporary_address_verify_pattern;
	uint32_t seed_val, data_length;
	clock_t time_stamp;
	int32_t *temp_pattern;
	int64_t* arguments_arr;
  if(var_args_len ==3)
  {
    if (memory_allocation_flag == 0)
    {
      va_list lst;
      va_start(lst,var_args_len);

      arguments_arr = va_arg (lst,int64_t*);
      va_end (lst);

      user_entered_address_verify_pattern = (int32_t *) arguments_arr[0];
      data_length = (int32_t) arguments_arr[1];
      seed_val = (int32_t) arguments_arr[2];

//      for(int i=0;i<=90;i++)               // To display organised GUI
//      {
//        printf("*");
//      }
      printf("\n");
      printf("\n ---> ");
//      for(int i=0;i<=90;i++)               // To display organised GUI
//    {
//        printf("*");
//      }

      for (int j=0; j< no_of_bytes; j++)  // check if the user entered address is a valid address
      {
        temporary_address_verify_pattern = (memory_start +j);
	//count = count + 1;
        if (user_entered_address_verify_pattern == temporary_address_verify_pattern )
        {
          user_write_value_verify_pattern = 1;
	  count = count + j;
	  break;
	  
        }
      }

      if (user_write_value_verify_pattern == 1)
      {
	//printf("\n The count value is: %d",(count-1));
        if ((seed_val >=0) && (data_length >=0) && (data_length <= (no_of_bytes - count)) )
        {
          time_stamp = clock();
          for(int i=0;i<data_length;i++)
          {
            temp_pattern = user_entered_address_verify_pattern;
            *(temp_pattern + i) = (((uintptr_t)(temp_pattern + i)) ^ (seed_val));
          }
          time_stamp = clock()-time_stamp;
          double time_clk = ((double)(time_stamp))/CLOCKS_PER_SEC;
          printf("\n time: %f s\n",time_clk);
        }
        else
        {
          printf("\n Please enter valid valid length or valid seed value");
          return ERROR;
        }
      }
      else
      {
        printf("\n Please enter a valid address");
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
    printf("\nPlease enter the right number of arguments\n");
    return ERROR;
  }
  return SUCCESS;
}
#endif


#ifdef FRDM
int Write_pattern(int var_args_len, ...)

{
	int user_write_value_verify_pattern;
	int32_t *user_entered_address_verify_pattern;
	int32_t *temporary_address_verify_pattern;
	uint32_t seed_val, data_length;
	int32_t *temp_pattern;
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

      user_entered_address_verify_pattern = (int32_t *) arguments_arr[0];
      data_length = (int32_t) arguments_arr[1];
      seed_val = (int32_t) arguments_arr[2];

      for(int i=0;i<=90;i++)               // To display organised GUI
      {
        PRINTF("*");
      } 
      PRINTF("\n\r");
      PRINTF("\n\r ---> ");
      for(int i=0;i<=90;i++)               // To display organised GUI
      {
        printf("*");
      } 

      for (int j=0; j< no_of_bytes; j++)  // check if the user entered address is a valid address
      {
        temporary_address_verify_pattern = (memory_start +j);
        if (user_entered_address_verify_pattern == temporary_address_verify_pattern )
        {
          user_write_value_verify_pattern = 1;
        }
      }

      if (user_write_value_verify_pattern == 1)
      {
        if ( (seed_val >=0) && (data_length >=0) && (data_length <= no_of_bytes) )
        {
          //time_stamp = clock();
        	SysTick_Config(16000000);
          for(int i=0;i<data_length;i++)
          {
            temp_pattern = user_entered_address_verify_pattern;
            *(temp_pattern + i) = (((uintptr_t)(temp_pattern + i)) ^ (seed_val));
          //  PRINTF("%d ",*(temp_pattern + i));
          } 
          cnt = 16000000 - SysTick->VAL;
          systick_stop;
        //  PRINTF("\n\r count: %f",cnt);
          float time_clk = (cnt/48);
          PRINTF("\n\r time: %f us",time_clk);
        }
        else
        {
        	PRINTF("\n\r Please enter valid valid length or valid seed value");
          return ERROR;
        }
      }
      else
      {
    	  PRINTF("\n\r Please enter a valid address");
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
	  PRINTF("\n\rPlease enter the right number of arguments\n\r");
    return ERROR;
  }
   return SUCCESS;
}    
#endif

      




















