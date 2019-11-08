/*========================================================================
** c_buff.c
** Circular buffer
** ECEN5813
**========================================================================*/
#include "../includes/c_buff.h"

enum STATUS {
    SUCCESS = 1,
    FAIL = -1,
    BUFF_FULL =-2,
    BUFF_EMPTY =-3
};


//writ enum which has all return status for all functions

c_buf *buffer; // Creating instance for the structure 

int add_elements(c_buf* add_buff, char item)   // A function to add elements to the user desired buffer
{
    if(add_buff -> num_of_items < add_buff -> size_of_buffer) // Check if the buffer is full before adding elements
    {
      *add_buff -> head = item;  // Add item at the head of c_buff
      if ((add_buff -> head) == ((add_buff -> buffer_number)+(add_buff -> size_of_buffer) - 1) ) // Wrap around
        {
           add_buff -> head = add_buff -> buffer_number; // Move the Head pointer to the start of the buffer
        }
      else
        {
           add_buff -> head ++; // Increment the head pointer to the next location
        }
        add_buff -> num_of_items++; // Increment the number of items variable on addition of character to the buffer
        add_buff -> added_items++;
        return SUCCESS;
    }
    
    else
	{
      printf("\nSorry the buffer is full\n");
      return BUFF_FULL;
	}
    
}


int elements_in_buffer(c_buf* buffer_elemenets)
{
    printf("\nThe no of elements in the buffer is %ld\n",buffer_elemenets->num_of_items);
    return SUCCESS;
}


int display_buffer (c_buf* display_buff)
{
    char* disp_traverse;                      // A character pointer to traverse the buffer from tail to the last valid element
    disp_traverse = display_buff->tail;       // Initialize the pointer with the current value of tail pointer
    
    printf("\nThe contents of the buffer are:\n");
    for (int i =0; i< display_buff->num_of_items; i++ ) // Display elements of the buffer
    {
        if(disp_traverse == ((display_buff -> buffer_number)+(display_buff -> size_of_buffer) - 1)) // Wrap around if the pointer used to traverse the buffer is at the last location 
        {
            printf("%c ", *(disp_traverse) );
            disp_traverse = display_buff->buffer_number;
        }
        
        else
        {
        printf("%c ", *(disp_traverse) );  // Display successive valid buffer elements
        disp_traverse++;
        }
    }
    return SUCCESS;
}

int buffer_resize(c_buf* buff_resize, int size_new)
{
    char* initial_point = buff_resize->buffer_number;
    printf("\nBefore realloc address is %s\n",buff_resize->buffer_number);
     buff_resize->buffer_number = (char *)realloc(buff_resize->buffer_number, size_new);
     if( buff_resize->buffer_number == NULL)
     {
        return FAIL;
     }
     printf("\nAfter realloc address is %s\n",buff_resize->buffer_number);
     char* final_point = buff_resize->buffer_number;
     
     int difference = final_point - initial_point;
   

    printf("\nbefore realloc head is %s\n",buff_resize->head);
    printf("\nbefore realloc items is %ld\n",buff_resize-> num_of_items);
    printf("\nbefore realloc size is %ld\n",buff_resize-> size_of_buffer);
    
     if (buff_resize-> added_items ==buff_resize-> size_of_buffer )
    {
         buff_resize->head =buff_resize-> head + difference+(buff_resize-> added_items) ;
        printf("\nafter realloc head is %s\n",buff_resize->head);
    }
    
    
    
    //printf("\nbefore realloc head is %d\n",buff_resize->head);
   else
   {  
        buff_resize->head += difference;
   }
   
   if (buff_resize-> deleted_items ==buff_resize-> size_of_buffer )
    {
         buff_resize->tail =buff_resize-> tail + difference+(buff_resize-> deleted_items) ;
       // printf("\nafter realloc head is %d\n",buff_resize->head);
    }
   
   else
    {  
        buff_resize->tail += difference;
   }
     //printf("\nafter realloc head is %d\n",buff_resize->head);
     // printf("\nbefore realloc tail is %s\n",buff_resize->tail);
     buff_resize-> tail += difference ;
     // printf("\nafter realloc tail is %s\n",buff_resize->tail);
     // printf("\nbefore realloc size is %ld\n",buff_resize->size_of_buffer);
     buff_resize->size_of_buffer = size_new;
     // printf("\nafter realloc size is %ld\n",buff_resize->size_of_buffer);
     return SUCCESS;
     
}


int delete_buffer (c_buf* delete_buff)           // A function used to delete the elements of the buffer
{
  
    //printf("\nThe address of the structure is %d\n",delete_buff);
    
    if (delete_buff -> num_of_items ==0)           // If there is no valid element in the buffer, nothing to be deleted
    {
        printf("\nThere is no element to be deleted");
        return BUFF_EMPTY;
    }
    else
	{
        
        if ((delete_buff -> tail) == ((delete_buff -> buffer_number)+(delete_buff -> size_of_buffer) - 1) ) // delete in case of wrap around
         {
            delete_buff -> tail = delete_buff -> buffer_number;
         }
        else
		 {
            delete_buff -> tail++; // Delete in normal case
         }
   
        delete_buff -> num_of_items--; 
        delete_buff -> deleted_items++;
    }

    return SUCCESS;
    
}


c_buf *buffer_init(int num_of_buffers, ...)             // A function used for buffer initialization 
{
    int64_t* arguments_arr;
    if(num_of_buffers>= 1)
    {
       
        va_list lst;
        va_start(lst,num_of_buffers);

        arguments_arr = va_arg(lst,int64_t*);
        va_end (lst);

        buffer = (c_buf*)malloc(num_of_buffers * sizeof(c_buf) ); 

        if(buffer != NULL)
        {
            for( int i=0; i< num_of_buffers; i++)
            {
                ((buffer+i)->added_items) = 0;
                ((buffer+i)->num_of_items) = 0;
                ((buffer+i)->deleted_items) = 0;
                
            }
            for( int i=0; i< num_of_buffers; i++)
            {
                (buffer+i)->size_of_buffer = arguments_arr[i];
                ((buffer+i)-> buffer_number) = (char*)malloc((buffer+i)->size_of_buffer);
                if((buffer+i)-> buffer_number == NULL)
                {
                    printf("\n Failed in allocating memory for buffer size\n");
                    return NULL;
                }
            }

            for( int j=0; j< num_of_buffers; j++)
            {
                char* temporary;
                temporary = (buffer+j)-> buffer_number;
                (buffer+j) -> head = temporary;   // Set all the pointers: head and tail at the start address of the different allocated buffers
                (buffer+j) -> tail = temporary;
            }
        }
        else
        {
            printf("\n Failed in allocating memory for circular buffer \n");
            return NULL;
        }

        
    }
    else
    {
         printf("\n Please select a number greater than 1\n");
         return NULL;
    }
    return buffer;
        
}

