/*========================================================================
** main.c
** Circular buffer
** ECEN5813
**========================================================================*/
#include "../includes/main.h"



int main(int argc,char *argv[])
{
    int new_size =0;
    int num_of_buffers=0;
    int buffer_in_use=0; 
    int users_choice=0;
    char add_item;
    int64_t arr[100];
    printf("Hello World\n");
    
    
    while(1)
    {
        printf("\n Enter the number of buffers to be allocated\n");
        
        if(scanf("%d",&num_of_buffers) == 1)
            {
               for( int i=0; i< num_of_buffers; i++)
            {
                printf("\n Enter the size of buffer %d\n",i);
                scanf("%lx",&arr[i]);
                
            }
            
            buffer_init(num_of_buffers, &arr);

            while(1)
            {
                printf("\n Enter the buffer number to be operated upon (ex:0,1,2)\n");
                
                scanf("%d", &buffer_in_use);
                
                printf("\nEnter the operation to be performed on buffer%d\n",buffer_in_use);
                
                printf("\n1 --> Add elements\n");
                printf("2 --> Display elements of the selected buffer\n");
                printf("3 --> Delete elements\n");
                printf("4 --> Resize buffer\n");
                printf("5 --> No of items currently present in the buffer\n");
                
                scanf("%d", &users_choice);
                
                switch(users_choice)
                {
                    case 1: printf("\n Enter the character to be added\n");
                            scanf(" %c", &add_item);
                            printf("\n The added item is %c", add_item);
                            add_elements((buffer+buffer_in_use), add_item);
                    break;
                    
                    case 2: display_buffer((buffer+buffer_in_use));
                    break; 
                    
                    case 3: delete_buffer((buffer+buffer_in_use));
                    break;
                    
                    case 4: printf("\n Enter the size of the new buffer:\n");
                            scanf("%d", &new_size);
                            buffer_resize(buffer+buffer_in_use, new_size);
                    break;
                    
                    case 5: elements_in_buffer(buffer+buffer_in_use);
                    break;
     
                    default: 
                    printf("\nError");    
                }
            } 
        }
        else
        {
            printf("\n Please enter a valid data");
            return -1;
        }
   
    
    }
    return 0;
}
