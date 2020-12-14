/**
 * simple b tree structure.
 * @author forsilence
 * @date 2020-9-15
 * @version 0.1
 */

# if !defined(_BST_H)
# define _BST_H

# include<stdbool.h>

# if !defined(data_type)
# define data_type int
# endif

struct bst_node{
    data_type data;
    struct bst_node *father;
    struct bst_node *lc;
    struct bst_node *rc;
};
typedef struct bst_node bst_node;
/**bst node struct
 *   root        lc
 *  -------    -------
 *  |     | ==>|     |
 *  |     |    -------
 *  |     |      rc
 *  |     |    -------
 *  |     | ==>|     |
 *  -------    -------
 */

typedef struct bst_t
{
    bst_node *root;
}bst_t;

bst_t init_bst();

bool bst_insert(bst_t *T,data_type data);

void tree_walk(bst_t *T);
void m_walk(bst_node *node);

bst_node *bst_search(bst_t *T,data_type data);
bool bst_remove(bst_t *T,data_type data);
bst_node *bst_minimum(bst_node *root);
bst_node *bst_maximum(bst_node *root);
void bst_transplant(bst_t *T,bst_node *v,bst_node *u);

# endif