/**
 * This is program for queue.
 * @date 2020-8-7
 * @author forsilence
 */

# ifndef _QUEUE_H
# define _QUEUE_H
# include<stdlib.h>
# include<stdbool.h>

// max length of queue
# define MAX_QUEUE_LEN 1 << 8

/**
 * if not define element type ,this will define as int by default.
 */
# ifndef elem_type
# define elem_type int
# endif

// queue status
# define QUEUE_FULL 1
# define QUEUE_NOT_FULL 2
# define EMPTY 3

// define queue structure
typedef struct {
    elem_type data[MAX_QUEUE_LEN];
    int length;
} queue;

/**
 * operation on queue
 */
// create a queue
queue *init_queue();

// enqueue
bool enqueue(queue *que,elem_type x);

// dequeue
elem_type dequeue(queue *que);

// empty ?
bool empty(queue que);

# endif 