/*
red and black tree functino apply
*author forsilence
*date 2020-9-26
*/

# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>
# include"_M_rb_tree.h"

bool _M_rbt_allocate(_M_rbt_node **node)
{
	*node=(_M_rbt_node *)malloc(sizeof(_M_rbt_node));
	if(*node) return true;
	return false;
}

bool _M_rbt_right_rotate(_M_rbt_t *tree,_M_rbt_node *node)
{
	if(tree->root==tree->NIL) return false;
	if(node->_M_lc==tree->NIL) return false;
	_M_rbt_node *cur_lc=node->_M_lc;

	// link node-left-child to cur-node-right-child
	node->_M_lc=cur_lc->_M_rc;
	if(cur_lc->_M_rc!=tree->NIL)
		cur_lc->_M_rc->_M_p=node;

	// link cur-node to node-parent node
	cur_lc->_M_p=node->_M_p;
	if(node==tree->root)
		tree->root=cur_lc;
	else
	{
		if(node->_M_p->_M_lc==node)
			node->_M_p->_M_lc=cur_lc;
		else	node->_M_p->_M_rc=cur_lc;
	}

	// link node to cur-node-right-child
	cur_lc->_M_rc=node;
	node->_M_p=cur_lc;
	return true;
}

bool _M_rbt_left_rotate(_M_rbt_t *tree,_M_rbt_node *node)
{
	if(tree->root==tree->NIL) return false;
	if(node->_M_rc==tree->NIL) return false;
	_M_rbt_node *cur_rc=node->_M_rc;

	// link node-right-child ot cur-node
	node->_M_rc=cur_rc->_M_lc;
	if(cur_rc->_M_lc!=tree->NIL)
		cur_rc->_M_lc->_M_p=node;

	// link cur-node to node-parent
	cur_rc->_M_p=node->_M_p;
	if(node==tree->root)
		tree->root=cur_rc;
	else
	{
		if(node->_M_p->_M_lc==node)
			node->_M_p->_M_lc=cur_rc;
		else	node->_M_p->_M_rc=cur_rc;
	}

	// link node to cur-node-left-child
	cur_rc->_M_lc=node;
	node->_M_p=cur_rc;
	return true;
}

bool _M_rbt_insert(_M_rbt_t *tree,_M_rbt_node *node)
{
	_M_rbt_node *pn=tree->NIL;// parent node
	_M_rbt_node *tmp=tree->root;
	while(tmp!=tree->NIL)// finding parent node
	{
		pn=tmp;
		if(node->data > tmp->data) tmp=tmp->_M_rc;
		else if(node->data==tmp->data) return false;
		else tmp=tmp->_M_lc;
	}
	// link node to tree 
	node->_M_p=pn;
	if(pn==tree->NIL) tree->root=node;
	else{
		if(node->data > pn->data) pn->_M_rc=node;
		else pn->_M_lc=node;
	}
	// same initialization for node
	node->_M_lc=tree->NIL;
	node->_M_rc=tree->NIL;
	node->_M_color=_M_red;
	// fix-up tree to keep balance
	_M_rbt_insert_fixup(tree,node);
	return true;
}

void _M_rbt_insert_fixup(_M_rbt_t *tree,_M_rbt_node *node)
{
	data_type flag=node->data;
	while(node->_M_p->_M_color==_M_red)
	{
		if(node->_M_p==node->_M_p->_M_p->_M_lc){
			_M_rbt_node *pb=node->_M_p->_M_p->_M_rc;
			if(pb!=tree->NIL && pb->_M_color==_M_red){
				// condition 1
				node->_M_p->_M_color=_M_black;
				pb->_M_color=_M_black;
				node->_M_p->_M_p->_M_color=_M_red;
				node=node->_M_p->_M_p;
			}
			else{
				// condition 1 can convert to condition 2 or condition 3 and condition 2 cand directly convert to 3
				if(node==node->_M_p->_M_rc){
					// condition 2
					node=node->_M_p;
					_M_rbt_left_rotate(tree,node);
				}
				// condition 3
				node->_M_p->_M_color=_M_black;
				node->_M_p->_M_p->_M_color=_M_red;
				_M_rbt_right_rotate(tree,node->_M_p->_M_p);
			} 
		}
		else{
			// change right <--> left : the rest were same!
			_M_rbt_node *pb=node->_M_p->_M_p->_M_lc;
			if(pb!=tree->NIL && pb->_M_color==_M_red){
				node->_M_p->_M_color=_M_black;
				pb->_M_color=_M_black;
				node->_M_p->_M_p->_M_color=_M_red;
				node=node->_M_p->_M_p;
			}
			else{
				if(node==node->_M_p->_M_lc){
					node=node->_M_p;
					_M_rbt_right_rotate(tree,node);
				}
				node->_M_p->_M_color=_M_black;
				node->_M_p->_M_p->_M_color=_M_red;
				_M_rbt_left_rotate(tree,node->_M_p->_M_p);
			}
		}
	}
	(tree->root)->_M_color=_M_black;
}

void _M_rbt_walk(_M_rbt_t *tree,_M_rbt_node *root,int *cout,void (* data_print)(data_type))
{
	_M_rbt_node *tmp=root;
	if(tmp->_M_lc!=tree->NIL){
		_M_rbt_walk(tree,root->_M_lc,cout,data_print);
	}

	*cout +=1;
	// printf("%2d ",tmp->data);
	data_print(tmp->data);
	if(*cout%10==0) printf("\n");

	if(tmp->_M_rc!=tree->NIL)
		_M_rbt_walk(tree,root->_M_rc,cout,data_print);
}

void _M_tree_walk(_M_rbt_t *tree,void (*data_print)(data_type))
{
	int cout=0;
	if(tree->root!=tree->NIL)
		_M_rbt_walk(tree,tree->root,&cout,data_print);
	else
		printf("tree is empty!\n");
	printf("\n");
}


_M_rbt_t _M_rbt_init(data_type *ls,int len)
{
	_M_rbt_t tree;
	if(!_M_rbt_allocate(&tree.NIL)) exit(1);
	tree.NIL->_M_color=_M_black;
	tree.NIL->_M_p=NULL;
	tree.NIL->_M_lc=NULL;
	tree.NIL->_M_rc=NULL;
	tree.NIL->data=1000;
	tree.root=tree.NIL;
	for(int i=0 ; i< len ; i++){
		_M_rbt_push_val(&tree,ls[i]);
	}
	return tree;
}

bool _M_rbt_push_val(_M_rbt_t *tree,data_type val)
{
	_M_rbt_node *nn=NULL;
	if(!_M_rbt_allocate(&nn)) return false;
	nn->data=val;
	nn->_M_lc=NULL;
	nn->_M_p=NULL;
	nn->_M_rc=NULL;
	nn->_M_color=_M_red;
	if(!_M_rbt_insert(tree,nn)) return false;
	return true;
}

_M_rbt_node* _M_rbt_minimum(_M_rbt_t tree, _M_rbt_node* node)
{
	_M_rbt_node* tmp=node;
	while(tmp!=tree.NIL && tmp->_M_lc!=tree.NIL)
		tmp=tmp->_M_lc;
	return tmp;
}

_M_rbt_node* _M_rbt_maximum(_M_rbt_t tree, _M_rbt_node* node)
{
	_M_rbt_node* tmp=node;
	while(tmp!=tree.NIL && tmp->_M_lc!=tree.NIL)
		tmp=tmp->_M_rc;
	return tmp;
}

void _M_rbt_transparent(_M_rbt_t* tree, _M_rbt_node* h, _M_rbt_node* l)
{
	if(h==tree->root)
		tree->root=l;
	else if(h==h->_M_p->_M_lc)
		h->_M_p->_M_lc=l;
	else
		h->_M_p->_M_rc=l;
	l->_M_p=h->_M_p;
}

void _M_rbt_delete(_M_rbt_t* tree, _M_rbt_node* node)
{
	_M_rbt_node* y = node;
	_M_rbt_color_type y_original_color=y->_M_color;
	_M_rbt_node* x;
	if(node->_M_lc==tree->NIL)
	{
		x = node->_M_rc;
		_M_rbt_transparent(tree,node,node->_M_rc);
	}
	else if(node->_M_rc==tree->NIL)
	{
		x = node->_M_lc;
		_M_rbt_transparent(tree,node,node->_M_lc);
	}
	else
	{
		y = _M_rbt_minimum(*tree,node->_M_rc);
		y_original_color=y->_M_color;
		x = y->_M_rc;
		if(y->_M_p==node)
			x->_M_p=y;
		else
		{
			_M_rbt_transparent(tree,y,y->_M_rc);
			y->_M_rc = node->_M_rc;
		}
		_M_rbt_transparent(tree,node,y);
		y->_M_lc = node->_M_lc;
		y->_M_lc->_M_p = y;
		y->_M_color = node->_M_color;
	}
	if(y_original_color==_M_black)
		_M_rbt_delete_fixup(tree,x);
}

void _M_rbt_delete_fixup(_M_rbt_t* tree, _M_rbt_node* node)
{
	while( node==tree->root && node->_M_color==_M_black )
	{
		if( node == node->_M_p->_M_lc)
		{
			_M_rbt_node* w = node->_M_p->_M_rc;
			if( w->_M_color == _M_red)
			{
				w->_M_color == _M_black;
				node->_M_p->_M_color = _M_red;
				_M_rbt_left_rotate(tree,node->_M_p);
				w = node->_M_p->_M_rc;
			}
			if( w->_M_lc->_M_color == _M_black && w->_M_rc->_M_color == _M_black )
			{
				w->_M_color = _M_red;
				node = node->_M_p;
			}
			else 
			{
				if( w->_M_rc->_M_color == _M_black )
				{
					w->_M_lc->_M_color = _M_black;
					w->_M_color = _M_red;
					_M_rbt_right_rotate(tree,w);
					w = node->_M_p->_M_rc;
				}
				w->_M_color = node->_M_p->_M_color;
				node->_M_p->_M_color = _M_black;
				w->_M_rc->_M_color = _M_black;
				_M_rbt_left_rotate(tree,node->_M_p);
				node = tree->root;
			}
		}
		else
		{
			_M_rbt_node* w = node->_M_p->_M_lc;
			if( w->_M_color == _M_red )
			{
				w->_M_color == _M_black;
				node->_M_p->_M_color = _M_red;
				_M_rbt_right_rotate(tree,node->_M_p);
				w = node->_M_p->_M_rc;
			}
			if( w->_M_rc->_M_color == _M_black && w->_M_lc->_M_color == _M_black )
			{
				w->_M_color = _M_red;
				node = node->_M_p;
			}
			else
			{
				if(w->_M_lc->_M_color == _M_black )
				{
					w->_M_rc->_M_color = _M_black;
					w->_M_color = _M_red;
					_M_rbt_left_rotate(tree,w);
					w = node->_M_p->_M_lc;
				}
				w->_M_color = node->_M_p->_M_color;
				node->_M_p->_M_color = _M_black;
				w->_M_lc->_M_color = _M_black;
				_M_rbt_right_rotate(tree,node->_M_p);
				node = tree->root;
			}
		}
	}
			node->_M_color = _M_black;
}

_M_rbt_node* _M_rbt_search(_M_rbt_t tree, data_type x)
{
	_M_rbt_node* tmp = tree.root;
	while( tmp!=tree.NIL)
	{
		if(tmp->data == x)
			break;
		else if ( x > tmp->data)
			tmp = tmp->_M_rc;
		else
			tmp = tmp->_M_lc;
	}
	return tmp;
}