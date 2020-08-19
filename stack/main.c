/**
 * test stack
 */

# include<stdio.h>
# include"byArray/stack.h"

int main()
{
    stack st = *init_stack();
    push(&st,2);
    printf("%d\n",st.length);
    pop(&st);
    printf("%d\n",st.length);
    return 0;
}