/*File Name & Description : help.c This file allows the user to browse through the possible commands in the application
 File Author Name : Amogh.S & Srinath.S
 Tools used to process the code: (GCC: compiler, ld: GNU linker, GNU: debugger)
 Identification of any leveraged code: No leveraged code
 Applicable Links: None */

#include "../includes/help.h"
#include "../includes/allocate_memory.h"
#include "../includes/free_memory.h"
#include "../includes/Allocated_memory_display.h"
#include "../includes/Write_memory_words.h"
#include "../includes/exit.h"
#include "../includes/Display_particular_address.h"
#include "../includes/Write_particular_offset.h"
#include "../includes/Invert_memory_block.h"
#include "../includes/Write_pattern.h"
#include "../includes/Verify_pattern.h"

/*******************************************************************************
* Function Name: help_func
********************************************************************************
*
* Summary:
*  This function is used to display the possible commands which the user can make use of
*
* Parameters:
*  none
*
* Return:
*  None.
*
* Reference: Self
*
*******************************************************************************/ 

void help_func(void)
{
  int ch=0;
  int var_args=0;
 #ifdef LINUX
  int64_t arr[10];
#endif

#ifdef FRDM
  int32_t arr[10];
#endif

#ifdef LINUX
printf("\nPlease enter a value between 0 to 9 and select the functionality to be implemented from the menu\n");
#endif

#ifdef FRDM
PRINTF("\n\rPlease enter a value between 0 to 9 and select the functionality to be implemented from the menu\n");
#endif
 
#ifdef LINUX
  printf("\n\r");
  for(int i=0;i<73;i++)
	  printf("_");
      printf("\n\r");


      printf("|\tName           \t|\tNo of arguments\t|\tArguments  \t|\n\r");
      for(int i=0;i<73;i++)
      printf("_");
      printf("\n\r");

      printf("|  0 | \tallocate memory\t|\t1              \t|\tNo of bytes\t|\n\r");
      for(int i=0;i<73;i++)
      printf("_");
      printf("\n\r");


      printf("|  1 | \tfree memory\t|\t0              \t|\t-           \t|\n\r");
      for(int i=0;i<73;i++)
      printf("_");
      printf("\n\r");


      printf("|  2 | \twrite memory\t|\t2              \t|\tAddress, Data\t|\n\r");
      for(int i=0;i<73;i++)
      printf("_");
      printf("\n\r");


      printf("|  3 | \tdisplay parti-\t|\t2              \t|\tStart offset,\t|\n\r");
      printf("|    |\taddress range \t|\t              \t|\tEnd offset\t|\n\r");
      for(int i=0;i<73;i++)
      printf("_");
      printf("\n\r");

      printf("|  4 | \tInvert Block\t|\t3              \t|\tUser choice,\t|\n\r");
      printf("|    |\t            \t|\t               \t|\taddress/offset,\t|\n\r");
      printf("|    |\t            \t|\t               \t|\tno of blocks\t|\n\r");
      for(int i=0;i<73;i++)
      printf("_");
      printf("\n\r");


      printf("|  5 | \tWrite pattern\t|\t3              \t|\tStart address,\t|\n\r");
      printf("|    |\t            \t|\t               \t|\tno of blocks,\t|\n\r");
      printf("|    |\t            \t|\t               \t|\tseed value\t|\n\r");
      for(int i=0;i<73;i++)
      printf("_");
      printf("\n\r");



      printf("|  6 | \tVerify pattern\t|\t3              \t|\tStart address\t|\n\r");
      printf("|    |\t            \t|\t               \t|\tno of blocks,\t|\n\r");
      printf("|    |\t            \t|\t               \t|\tseed value\t|\n\r");
      for(int i=0;i<73;i++)
      printf("_");
      printf("\n\r");


      printf("|  7 | \twrite partic-\t|\t2              \t|\tOffset address,\t|\n\r");
      printf("|    |\t   ular      \t|\t               \t|\tdata at offset\t|\n\r");
      for(int i=0;i<73;i++)
      printf("_");
      printf("\n\r");



      printf("|  8 | \tallocated mem-\t|\t0              \t|\t-             \t|\n\r");
      printf("|    |\tory address \t|\t               \t|\t                | \n\r");
      for(int i=0;i<73;i++)
      printf("_");
      printf("\n\r");


      printf("|  9 | \tExit the uti-\t|\t0              \t|\t-              \t\n\r");
      printf("|    |\t lity        \t|\t               \t|\t                |\n\r");
      for(int i=0;i<73;i++)
      printf("_");
      printf("\n\r");
#endif


//#ifdef LINUX
//  printf("\n ***************************************** HELP **************************************** ");
//  printf("\n Please enter the number corresponding to the functionality that you want to implement:");
//  printf("\n 0 --> Allocate memory");
//  printf("\n 1 --> Free memory");
//  printf("\n 2 --> Write memory words");
//  printf("\n 3 --> Display particular address");
//  printf("\n 4 --> Invert Block");
//  printf("\n 5 --> Write pattern");
//  printf("\n 6 --> Verify pattern");
//  printf("\n 7 --> Write_particular_offset");
//  printf("\n 8 --> allocated_memory_display\n");
//  printf("\n 9 --> Exit the Utility\n");
//
//#endif



/*#ifdef FRDM
  PRINTF("\n\r ***************************************** HELP **************************************** ");
  PRINTF("\n\r Please enter the number corresponding to the functionality that you want to implement:");
  PRINTF("\n\r 0 --> Allocate memory | No of arguments is 1 | Argument 1 is no of bytes to allocate");
  PRINTF("\n\r 1 --> Free memory | No of arguments is 0 ");
  PRINTF("\n\r 2 --> Write memory words| No of arguments is 2 | Argument 1 is address at which data should be written | Argument 2 : Enter the data value");
  PRINTF("\n\r 3 --> Display particular address | No of arguments is 2 | Argument 1 is offset of the start address from where you want display | Argument 2 : offset of the end address till where you want display");
  PRINTF("\n\r 4 --> Invert Block | No of arguments is 2 | Argument 1 Press '1' to give address directly  | Argument 2 : Press '2' to give offset directly");
  PRINTF("\n\r 5 --> Write pattern | No of arguments is 3 | Argument 1 : start address at which pattern should be written  | Argument 2 : length of the words until which pattern needs to be written| Argument 3 : Enter the seed value ");
  PRINTF("\n\r 6 --> Verify pattern | No of arguments is 3 | Argument 1 : start address at which pattern should be verified  | Argument 2 : length of the words until which pattern needs to be verified| Argument 3 : Enter the seed value");
  PRINTF("\n\r 7 --> Write_particular_offset| No of arguments is 2 | Argument 1 is offset of the address | Argument 2 : value at the offset");
  PRINTF("\n\r 8 --> allocated_memory_display | No of arguments is 0\n");
  PRINTF("\n\r 9 --> Exit the Utility | No of arguments is 0\n");
#endif*/


#ifdef FRDM
  PRINTF("\n\r");
  for(int i=0;i<73;i++)
	  PRINTF("_");
      PRINTF("\n\r");


      PRINTF("|\tName           \t|\tNo of arguments\t|\tArguments  \t|\n\r");
      for(int i=0;i<73;i++)
      PRINTF("_");
      PRINTF("\n\r");

      PRINTF("|  0 | \tallocate memory\t|\t1              \t|\tNo of bytes\t|\n\r");
      for(int i=0;i<73;i++)
      PRINTF("_");
      PRINTF("\n\r");


      PRINTF("|  1 | \tfree memory\t|\t0              \t|\t-           \t|\n\r");
      for(int i=0;i<73;i++)
      PRINTF("_");
      PRINTF("\n\r");


      PRINTF("|  2 | \twrite memory\t|\t2              \t|\tAddress, Data\t|\n\r");
      for(int i=0;i<73;i++)
      PRINTF("_");
      PRINTF("\n\r");


      PRINTF("|  3 | \tdisplay parti-\t|\t2              \t|\tStart offset,\t|\n\r");
      PRINTF("|    |\taddress range \t|\t              \t|\tEnd offset\t|\n\r");
      for(int i=0;i<73;i++)
      PRINTF("_");
      PRINTF("\n\r");

      PRINTF("|  4 | \tInvert Block\t|\t3              \t|\tUser choice,\t|\n\r");
      PRINTF("|    |\t            \t|\t               \t|\taddress/offset,\t|\n\r");
      PRINTF("|    |\t            \t|\t               \t|\tno of blocks\t|\n\r");
      for(int i=0;i<73;i++)
      PRINTF("_");
      PRINTF("\n\r");


      PRINTF("|  5 | \tWrite pattern\t|\t3              \t|\tStart address,\t|\n\r");
      PRINTF("|    |\t            \t|\t               \t|\tno of blocks,\t|\n\r");
      PRINTF("|    |\t            \t|\t               \t|\tseed value\t|\n\r");
      for(int i=0;i<73;i++)
      PRINTF("_");
      PRINTF("\n\r");



      PRINTF("|  6 | \tVerify pattern\t|\t3              \t|\tStart address\t|\n\r");
      PRINTF("|    |\t            \t|\t               \t|\tno of blocks,\t|\n\r");
      PRINTF("|    |\t            \t|\t               \t|\tseed value\t|\n\r");
      for(int i=0;i<73;i++)
      PRINTF("_");
      PRINTF("\n\r");


      PRINTF("|  7 | \twrite partic-\t|\t2              \t|\tOffset address,\t|\n\r");
      PRINTF("|    |\t   ular      \t|\t               \t|\tdata at offset\t|\n\r");
      for(int i=0;i<73;i++)
      PRINTF("_");
      PRINTF("\n\r");



      PRINTF("|  8 | \tallocated mem-\t|\t0              \t|\t-             \t|\n\r");
      PRINTF("|    |\tory address \t|\t               \t|\t                | \n\r");
      for(int i=0;i<73;i++)
      PRINTF("_");
      PRINTF("\n\r");


      PRINTF("|  9 | \tExit the uti-\t|\t0              \t|\t-              \t\n\r");
      PRINTF("|    |\t lity        \t|\t               \t|\t                |\n\r");
      for(int i=0;i<73;i++)
      PRINTF("_");
      PRINTF("\n\r");
#endif


#ifdef LINUX
//  for(i=0;i<=90;i++)               // To display organised GUI
//  {
//    printf("*");
//  } 
  
  printf("\n ---> "); 
  scanf(" %d",&ch);
  if (memory_allocation_flag == 0 && ch == 2)
  {
    printf("\n The available address space is: \n");  // display the allocated memory 
    for (int j=1; j<= no_of_bytes; j++)
    {
      printf ("\n The address of word %d\t: %p ", j, (memory_start-1 +j));
      printf ("Data: 0x%x " , *(memory_start-1 +j));
    }
  }
  printf("\n Enter the number of arguments as per the HELP menu to pass along with the Function: ");
  scanf(" %d",&var_args);

  for(int i=0;i<var_args;i++)
  {
    printf("\n Enter the argument %d value: ",i+1);
    scanf("%lx",&arr[i]);
//scanf("%d",&arr[i]);
    printf("\n The entered value is %lx\n",arr[i]);
  }
  for(int i=0;i<=90;i++)
  {
    printf("*");
  } 
  printf("\n");

  int Exit_the_utility (int var_args_len, ...)
  {
    exit(0);
  }

  if ((ch>=0) && (ch<=9)) // use function pointers and look up table to invoke various functions
  {

    int (*fun_ptr_arr[])(int, ...) = {memory_allocate, free_memory,  Write_memory_words, Display_particular_address, Invert_Block, Write_pattern, Verify_pattern, Write_particular_offset, allocated_memory_display, Exit_the_utility}; 
    (*fun_ptr_arr[ch])(var_args, &arr);  // invoke the required functions
  }

  else
  {
    printf("\n Please enter a valid number as per the menu !\n");
    help_func();     
  }

#endif


#ifdef FRDM
//  for(int i=0;i<=90;i++)               // To display organised GUI
//  {
//    PRINTF("*");
//  }

  PRINTF("\n\r ---> ");
  SCANF(" %d",&ch);
  if (memory_allocation_flag == 0 && ch == 2)
  {
  	PRINTF("\n\r The available address space is: \n");  // display the allocated memory
    for (int j=1; j<= no_of_bytes; j++)
    {
  	  PRINTF ("\n\r The address of word %d\t: %p ", j, (memory_start-1 +j));
  	  PRINTF ("Data: 0x%x " , *(memory_start-1 +j));
    }

    PRINTF("\n\r Please enter the address location, where you want to modify the data and the data\n\r");
  }
  PRINTF("\n\r Enter the number of arguments to pass along with the Function: ");
  SCANF("%d",&var_args);

  for(int i=0;i<var_args;i++)
  {
  	PRINTF("\n\r Enter the argument %d value: ",i+1);
  	SCANF("%x",&arr[i]);
    PRINTF("\n\r the entered value is %x\n\r",arr[i]);
  }
  for(int i=0;i<=90;i++)
  {
  	PRINTF("*");
  }
  PRINTF("\n\r");

  int Exit_the_utility (int var_args_len, ...)
  {
    exit(0);
  }

  if ((ch>=0) && (ch<=9)) // use function pointers and look up table to invoke various functions
  {
    int (*fun_ptr_arr[])(int, ...) = {memory_allocate, free_memory,  Write_memory_words, Display_particular_address, Invert_Block, Write_pattern, Verify_pattern, Write_particular_offset, allocated_memory_display, Exit_the_utility};
    (*fun_ptr_arr[ch])(var_args, &arr);  // invoke the required functions
  }

  else
  {
  	PRINTF("\n\r Please enter a valid number as per the menu !\n");
    help_func();
  }

#endif        
}
