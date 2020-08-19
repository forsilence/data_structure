/**
 * @date 2020-8-8
 * @author forsilence
 */

# include"queue.h"
# include<stdlib.h>

// create a queue
queue *init_queue()
{
    queue *que = (queue *)malloc(sizeof(queue));
    que->length=0;
    return que;
}

// enqueue
bool enqueue(queue *que,elem_type x)
{
    if ( que->length == MAX_QUEUE_LEN)
        return false;
    que->data[que->length] = x;
    que->length++;
    return true;
}

// dequeue
elem_type dequeue(queue *que)
{
    if (empty(*que))
        return que->data[MAX_QUEUE_LEN];
    que->length--;
    elem_type val = que->data[0];
    for(int i=0 ; i < que->length ; i++){
        que->data[i] = que->data[i+1];
    }
    return val;
}

// empty ?
bool empty(queue que)
{
    if (que.length == 0 )
        return EMPTY;
    return !EMPTY;
}