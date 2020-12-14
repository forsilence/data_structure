/*
*red and black tree
*@author forsilence
*@date 2020-9-26
*/

# if !defined(_M_RB_TREE_H)
# define _M_RB_TREE_H
# include<stdbool.h>

# if !defined(data_type)
# define data_type int
# endif

# define _M_rbt_color_type bool // true red ,false black
# define _M_red true
# define _M_black false

struct _M_rbt_node_base{
	data_type data;
	struct _M_rbt_node_base *_M_p;
	struct _M_rbt_node_base *_M_lc;
	struct _M_rbt_node_base *_M_rc;
	_M_rbt_color_type _M_color;
};

typedef struct _M_rbt_node_base _M_rbt_node_base;
typedef _M_rbt_node_base _M_rbt_node;
struct _M_rbt_t{
	_M_rbt_node *NIL;
	_M_rbt_node *root;
};
typedef struct _M_rbt_t _M_rbt_t;

_M_rbt_t _M_rbt_init(data_type *ls,int len);
bool _M_rbt_allocate(_M_rbt_node **node);
bool _M_rbt_right_rotate(_M_rbt_t *tree,_M_rbt_node *node);
bool _M_rbt_left_rotate(_M_rbt_t *tree,_M_rbt_node *node);
bool _M_rbt_insert(_M_rbt_t *tree,_M_rbt_node *node);
bool _M_rbt_push_val(_M_rbt_t *tree,data_type val);
void _M_rbt_insert_fixup(_M_rbt_t *tree,_M_rbt_node *node);
void _M_tree_walk(_M_rbt_t *tree,void (* data_print)(data_type));
_M_rbt_node* _M_rbt_minimum(_M_rbt_t tree, _M_rbt_node *node);
_M_rbt_node* _M_rbt_maximum(_M_rbt_t tree, _M_rbt_node* node);
void _M_rbt_transparent(_M_rbt_t* tree, _M_rbt_node* h, _M_rbt_node* l);
void _M_rbt_delete(_M_rbt_t* tree, _M_rbt_node* node);
void _M_rbt_delete_fixup(_M_rbt_t* tree, _M_rbt_node* node);
_M_rbt_node* _M_rbt_search(_M_rbt_t tree, data_type x);
#endif