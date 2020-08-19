/**
 * simple b tree structure.
 * @author forsilence
 * @date 2020-8-12
 */

# ifndef _BTREE_H
# define _BTREE_H

# include<stdbool.h>
// define elem_type
# ifndef elem_type
# define elem_type int
# endif

typedef struct btree
{
    elem_type val;
    struct btree *lc;
    struct btree *rc;
}btree,btnode;

btree *init_btree(elem_type *,int);

bool insert(btree *bt,elem_type x);

// delete node
void transplant(btree *,btree *,btree *);
bool delete_node(btree *,elem_type);

// search an element
btnode *search(btree *,elem_type);

btnode *minimum(btree *);

btnode *maximum(btree *);

btnode *parent(btree *,btnode *);

void tree_walk(btree *);

btnode *successor(btree *,btnode *);
btnode *predecessor(btree *,btnode *);

# endif