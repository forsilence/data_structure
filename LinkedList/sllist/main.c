/**
 * program for test.
 * @date 2020-8-8
 * @author forsilence
 */

# include"sllist.h"
# include<stdio.h>

int main()
{
    sllist sll=*init_sllist();
    int len=10;
    for( int i=0; i<len ; i++){
        add_node(&sll,i);
    }
    print(&sll);
    printf("Which node do you want to delete ? [%d-%d]\n",0,len-1);
    int deloc = 0;
    scanf("%d",&deloc);
    printf("delete location is %d\n",deloc);
    while(deloc < 0 || deloc > len){
        printf("location is out of range,range is between %d and %d\n",0,sll_len(&sll)-1);
        scanf("%d",&deloc);
    }
    denode(&sll,deloc);
    print(&sll);
    return 0;
}