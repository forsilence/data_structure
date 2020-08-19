/**
 * Test pprogram
 * @date 2020-8-8
 * @author forsilence
 */
# include<stdio.h>
# include"byArray/queue.h"

int main()
{
    queue que = *init_queue();
    for( int i=0; i<3 ; i++){
        enqueue(&que,i);
    }
    for( int i=0; i<3 ; i++){
        printf("dequeue member %d is %d\n",i,dequeue(&que));
    }
    return 0;
}