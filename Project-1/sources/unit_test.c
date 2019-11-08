#include "../includes/Context_switch.h"
#ifdef LINUX

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include <CUnit/Automated.h>
#include <CUnit/CUnit.h>
#include <time.h>

#include "../includes/main.h"
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
#include "../includes/Context_switch.h"


// int memory_allocate (int var_args_len, ...);
/* The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */

int64_t array_elements[10];
int64_t array_elements1[10];

FILE *temp_file;
extern int32_t *memory_start;

typedef enum{
  ERROR = -1,
  SUCCESS = 1,
}status;

// int32_t no_of_bytes;
// int32_t *memory_start;

int init_suite1(void);
int clean_suite1(void);
int init_allocate_memory(void);
void test_allocate_memory(void);
int register_test_suite(void);

int init_suite1(void)
{
   
      return 0;  
}
/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite1(void)
{
    return 0;
}

/**************************************************************************************************************************************/

/*Carrying all the basic functionalities without any error checks*/
void test_suite1() //suite1
{
	array_elements1[0] = 6;
	CU_ASSERT_EQUAL((memory_allocate(1,array_elements1)),SUCCESS);
	array_elements[0] = (int64_t) memory_start;
	array_elements[1] = 50;
	CU_ASSERT_EQUAL((Write_memory_words(2,array_elements)),SUCCESS); 
	array_elements[0] = 0;
	array_elements[1] = 3;
	CU_ASSERT_EQUAL((Display_particular_address(2,array_elements)),SUCCESS); 
	array_elements[0] = 1;
	array_elements[1] = (int64_t) memory_start;
	array_elements[2] = 3;
	CU_ASSERT_EQUAL((Invert_Block(3,array_elements)),SUCCESS); 
	array_elements[0] = (int64_t) memory_start;
	array_elements[1] = 2;
	array_elements[2] = 2;
	CU_ASSERT_EQUAL((Write_pattern(3,array_elements)),SUCCESS);
	array_elements[0] = (int64_t) memory_start;
	array_elements[1] = 2;
	array_elements[2] = 2;
	CU_ASSERT_EQUAL((Verify_pattern(3,array_elements)),SUCCESS);
	array_elements[0] = 3;
	array_elements[1] = 45;
	CU_ASSERT_EQUAL((Write_particular_offset(2,array_elements)),SUCCESS);

	CU_ASSERT_EQUAL((allocated_memory_display(0)),SUCCESS);
	
	CU_ASSERT_EQUAL((free_memory(0)),SUCCESS);

}
/*Free memory without allocating memory*/
void test_suite2() //suite2
{	
	CU_ASSERT_EQUAL((free_memory(0)),ERROR);
}

/*Write value to an address or offset that is not allocated*/
void test_suite3() //suite3
{
	array_elements[0] = 5;

	CU_ASSERT_EQUAL((memory_allocate(1,array_elements)),SUCCESS);

	/*Write to an invalid an unallocated memory*/
	array_elements[0] = (int64_t) (memory_start -1 );
	array_elements[1] = 50;
	CU_ASSERT_EQUAL((Write_memory_words(2,array_elements)),ERROR);

	/*Invalid Address boundary check for INvert_block*/
	array_elements[0] = 1;
	array_elements[1] = (int64_t) (memory_start -5);
	CU_ASSERT_EQUAL((Invert_Block(2,array_elements)),ERROR);

	/*Invalid Offset boundary check for Invert_block*/
	array_elements[0] = 2;
	array_elements[1] = 6;
	CU_ASSERT_EQUAL((Invert_Block(2,array_elements)),ERROR);

	/*Giving a greater offset value first and lesser one next*/
	array_elements[0] = 3;
	array_elements[1] = 0;
	CU_ASSERT_EQUAL((Invert_Block(2,array_elements)),ERROR);

	/*Write to address that is unallocated*/
	array_elements[0] = (int64_t) (memory_start -5);
	array_elements[1] = 2;
	array_elements[2] = 2;
	CU_ASSERT_EQUAL((Write_pattern(3,array_elements)),ERROR);

	/* Verify address that is unallocated*/
	array_elements[0] = (int64_t) (memory_start-3);
	array_elements[1] = 2;
	array_elements[2] = 1;
	CU_ASSERT_EQUAL((Verify_pattern(3,array_elements)),ERROR);	
}

/*Allocate memory with 0 bytes*/
void test_suite4() //suite4
{
	array_elements[0] = 0;
	CU_ASSERT_EQUAL((memory_allocate(1,array_elements)),ERROR);

}

int register_test_suite(void)
{
 return 0;
}

int main()
{
	//CU_pSuite pSuite1= NULL;

	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
	  return CU_get_error();

  	if(register_test_suite() == -1)
  	{
  		CU_cleanup_registry();
  		return CU_get_error();
  	}

 	/* add a suite to the registry */
 	CU_pSuite pSuite1 = NULL;
 	pSuite1 = CU_add_suite("Suite_2", init_suite1, clean_suite1);
	if (NULL == pSuite1) 
	{
	CU_cleanup_registry();
	return CU_get_error();
	}
	if ((CU_add_test(pSuite1, "test of allocate_memory", test_suite1)) == NULL)
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
 	
/**************************************************************************************************************************************/
 	/* add a suite to the registry */

    CU_pSuite pSuite2 = NULL;
  	pSuite2 = CU_add_suite("Suite_3", init_suite1, clean_suite1);
	 if (NULL == pSuite2) 
	 {
	 CU_cleanup_registry();
	 return CU_get_error();
	 }
	 if ((CU_add_test(pSuite2, "test of Write_memory_words", test_suite2)) == NULL)
	{
	  CU_cleanup_registry();
	   return CU_get_error();
	}

/**************************************************************************************************************************************/
 	/* add a suite to the registry */

	CU_pSuite pSuite3 = NULL;
  	pSuite3 = CU_add_suite("Suite_3", init_suite1, clean_suite1);
	 if (NULL == pSuite3) 
	 {
	 CU_cleanup_registry();
	 return CU_get_error();
	 }
	 if ((CU_add_test(pSuite3, "test of Write_memory_words", test_suite3)) == NULL)
	{
	  CU_cleanup_registry();
	   return CU_get_error();
	}
/**************************************************************************************************************************************/
 /* add a suite to the registry */


    CU_pSuite pSuite4 = NULL;
  	pSuite4 = CU_add_suite("Suite_4", init_suite1, clean_suite1);
	 if (NULL == pSuite4) 
	 {
	 CU_cleanup_registry();
	 return CU_get_error();
	 }
	 if ((CU_add_test(pSuite4, "test of free_memory", test_suite4)) == NULL)
	{
	  CU_cleanup_registry();
	   return CU_get_error();
	}
 	
/******************************************************************************************************************************************/
 	

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}

#endif
