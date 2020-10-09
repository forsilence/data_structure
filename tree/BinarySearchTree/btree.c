/**
 * btree
 * @version 0.0
 * @date 2020-8-12,8-15
 * @author forsilence
 */

# include"btree.h"
# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>

// initialize a btree with a list
btree *init_btree(elem_type *ls,int len)
{
    btree *bt = (btree *)malloc(sizeof(btree));
    if (!bt) return NULL; // malloc fail !
    bt->val = ls[0];
    bt->lc = NULL;bt->rc = NULL;
    for (int i=1 ; i < len ; i++){
        insert(bt,ls[i]);
    }
    return bt;
}

// insert node to btree
bool insert(btree *bt,elem_type x){
    btnode *t = bt;
    bool stop = false;
    while (!stop){ // find parent node
        if (t->val > x){
            if(t->lc)t = t->lc;
            else stop = true;
        }
        else if (t->val < x){
            if (t->rc)t = t->rc;
            else stop = true;
        }
        else { // error : same value in btree
            printf("The val is already exist!\n");
            return false;
        }
    }
    btnode *node = (btnode *)malloc(sizeof(btnode));
    if (!node)  return false; // malloc success ?
    node->val = x;
    node->lc = NULL;
    node->rc = NULL;
    // r or l node ?
    if (t->val > x) t->lc = node;
    else t->rc = node;
    return true;
}

// delete node -->
bool delete_node(btree *bt,elem_type x){
    btnode *snode = search(bt,x);
    if (snode == NULL) return false;    // delete node not exist
    if (!snode->lc){                    // left node not exist
        transplant(bt,snode,snode->rc);
    }
    else if (!snode->rc){               // right node not exist
        transplant(bt,snode,snode->lc);
    }
    else {                              // both nodes exist
        btnode *minnode = minimum(snode->rc);
        snode->val = minnode->val;
        transplant(bt,minnode,minnode->rc);
    }
    return true;
}

// part of delete function <--
void transplant(btree *bt,btnode *u,btnode *v){
    btnode *p = parent(bt , u);
    if (p == NULL)bt = v;
    else if (p->lc == u){
        p->lc = v;
    }
    else p->rc = v;
    if (u) free(u);
}

// search an element
btnode *search(btree *bt,elem_type x)
{
    if (!bt) return NULL; // if bt is empty ,return NULL.
    btnode *temp = bt;
    // loop for looking for node with x.
    while (true){
        if ( temp->val > x ){       // look for left child
            temp = temp->lc;
        }
        else if (temp->val < x){    // looking for right child
            temp = temp->rc;
        }
        else {                      // node found out
            return temp;
        }
        // check temp exist,if not return NULL
        if ( !temp ) return NULL;
    }
}

// get minimum value node from tree starting with bt node 
btnode *minimum(btree *bt)
{
    // create a new btnode in case of changing bt
    btnode *temp = bt;
    while (temp->lc)
        temp = temp->lc;
    return temp;
}

// get maximum value node from tree starting with bt 
btnode *maximum(btree *bt)
{
    btnode *temp = bt ;
    while (temp->rc)
        temp = temp->rc;
    return temp;
}

// get parent of node
btnode *parent(btree *bt,btnode *node)
{
    if (bt->val == node->val ) return NULL;
    btnode *temp = bt;
    bool stop = false; // loop flag
    while (!stop){
        if (temp->val > node->val){
            if (!temp->lc)return NULL;  // node not in tree
            if (temp->lc->val == node->val) stop = true;    // find parent
            else temp = temp->lc;
        }else{
            if (!temp->rc)return NULL;  // node not in tree
            if (temp->rc->val == node->val) stop = true;    // find parent
            else temp = temp->rc;
        }
    }
    return temp;
}

// inorder tree walk
void tree_walk(btree *bt)
{
    if (bt){
        tree_walk(bt->lc);
        printf(" %d \n",bt->val);
        tree_walk(bt->rc);
    }
}

// back node ordered by value
btnode *successor(btree *bt,btnode *node)
{
    if (node->rc)
        return minimum(node->rc);
    btnode *p = parent(bt,node);
    while (p != NULL && node == p->rc){
        node = p;
        p = parent(bt,node);
    }
    return p;
}

// forward node ordered by value
btnode *predecessor(btree *bt,btnode *node)
{
    if (node->lc)
        return maximum(node->lc);
    btnode *p = parent(bt,node);
    while (p != NULL && node == p->lc){
        node = p;
        p = parent(bt,node);
    }
    return p;
}