/**
 * test btree
 * @date 2020-8-12,8-15
 * @author forsilence
 */

# include"btree.h"
# include<stdio.h>

int main()
{
    int ls[] = {9,3,7,6,5,4,20,10};
    btree bt = *init_btree(ls,8);
    tree_walk(&bt);
    insert(&bt,8);

    //search ?
    for (int i = 0 ; i < 8 ; i++){
        btnode *snode = search(&bt,ls[i]);
        printf("\nsearch %d in search node is %d\n",ls[i],snode->val);
    }

    // delete npde ?
    delete_node(&bt,ls[4]);
    tree_walk(&bt);

    // successor ?
    btnode * node = successor(&bt,&bt);
    printf("%d successor is %d\n",bt.val,node->val);

    // predecessor ?
    node = predecessor(&bt,&bt);
    printf("%d predecessor is %d\n",bt.val,node->val);

    return 0;
}