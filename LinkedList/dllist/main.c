/**
 * program tests dllist.
 * @date 2020-8-8
 * @author forsilence
 */

# include<stdio.h>
# include<stdlib.h>
# include"dllist.h"

int main()
{
    dllist dll = *init_dll();
    int len = 10;
    for(int i=0 ; i<len ; i++){
        push_dllnode(&dll,i);
    }
    print(&dll);
    return 0;
}