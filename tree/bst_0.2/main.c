/**
 * test program -->
 * @date 2020-9-15
 * @author forsilence
 */

# include<stdio.h>
# include<stdlib.h>
# include"bst.h"


int main(int argc , char *argv[]){
    int ls[]={6,2,4,1,5,3,8,9,7};
    bst_t T=init_bst();
    for (int i=0 ; i<9 ; i++)
        if (!bst_insert(&T,ls[i])) exit(1);
    tree_walk(&T);

    for (int i=0 ;i<9; i++)
    {
        bst_node *n=bst_search(&T,ls[i]);
        printf("search %d in tree is %d \n",ls[i],n->data);
    }
    printf("max node value %d\n",bst_maximum(T.root)->data);
    printf("min value node %d\n",bst_minimum(T.root)->data);
    printf("remove max value node--\n");
    bst_remove(&T,9);
    printf("max value node %d\n",bst_maximum(T.root)->data);

    tree_walk(&T);

    return 0;
}