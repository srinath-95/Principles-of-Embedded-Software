/*File Name & Description : exit.c This file allows the user to exit the interactive command line utility application
 File Author Name : Amogh.S & Srinath.S
 Tools used to process the code: (GCC: compiler, ld: GNU linker, GNU: debugger)
 Identification of any leveraged code: No leveraged code
 Applicable Links: None */

#include "../includes/exit.h"

/*******************************************************************************
* Function Name: exit_func
********************************************************************************
*
* Summary:
*  This function is used to exit from the application
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

void exit_func()
{

#ifdef LINUX
	printf("\n Enetered the Exit file");

#endif

#ifdef FRDM
	PRINTF("\n\r Enetered the Exit file");

#endif
	exit(0);
}
