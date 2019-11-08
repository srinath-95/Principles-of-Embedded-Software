/*========================================================================
** amin.h
** Circular buffer
** ECEN5813
**========================================================================*/
#ifndef MAIN_H
#define MAIN_H

/**********************
******INCLUDES*********
**********************/
#include <stdio.h>
#include <stdlib.h>
#include "stdarg.h"

/*********************************
*********GLOBAL STRUCTURE*********
**********************************/

typedef struct circular_buffer
{
    char* buffer_number;
    char* head;
    char* tail;
    size_t size_of_buffer;
    size_t num_of_items;
    size_t added_items;
    size_t deleted_items;
}c_buf;

c_buf *buffer;


int add_elements( c_buf* add_buff, char item);
int elements_in_buffer(c_buf* buffer_elemenets);
int display_buffer (c_buf* display_buff);
int buffer_resize(c_buf* buff_resize, int size_new);
int delete_buffer (c_buf* delete_buff);
c_buf *buffer_init(int num_of_buffers, ...);

// ring_t *init( int length );
// int insert( ring_t *ring, char data);
// int remove_t(ring_t *ring, char *data);
// int entries(ring_t *ring);

#endif
