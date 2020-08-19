/**
 * @date 2020-8-8
 * @author forsilence
 */

# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>
# include"dllist.h"

//create a dll
dllnode *init_dll()
{
    dllist *dll = (dllist *)malloc(sizeof(dllist));
    if ( dll ){
        dll->forword=NULL;
        dll->backword=NULL;
        return dll;
    }
    return NULL;
}

// add node to dll
bool push_dllnode(dllist *dll,elem_type x)
{
    dllnode *new_node = (dllnode *)malloc(sizeof(dllnode));
    if (new_node){
        // init new_node
        new_node->value = x;
        new_node->backword = NULL;
        new_node->forword = NULL;
        dllnode *last = dll_last(dll);      // get last node

        // if empty , linked new_node to backword
        if (dll->backword == NULL){ // empty ? 
            dll->backword = new_node;
            new_node->forword = dll;
            new_node->backword = dll;
        }
        else{
            last->backword = new_node;
            new_node->forword = last;
            new_node->backword = dll;
        } 
        dll->forword = new_node;
    }
    return NULL; 
}

// delete node
elem_type de_dll(dllist *dll,int loc)
{
    dllnode *preNode = dll_locate(dll,loc-1);
    if (preNode){                               //  node in loc is exist
        dllnode *curNode = preNode->backword;
        if ( curNode ){
            preNode->backword = curNode->backword;
            curNode->backword->forword = preNode;
            elem_type val = curNode->value;
            free(curNode);
            return val;
        }
    }
    // node is not exist
    printf("loc is out of range!\n");
    return dll->value;
}

// length of dll
int dll_len(dllist *dll)
{
    dllist *temp = dll;
    int len = 0;
    while ( temp->backword != dll ){
        temp = temp->backword;
        len++;
    }
    return len;
}

// find element in loc location
dllnode *dll_locate(dllist *dll,int loc)
{
    dllist *temp=dll;
    while (temp->backword != dll && loc >= 0){
        temp = temp->backword;
        loc--;
    }
    if ( loc >= 0) return NULL;
    return temp;
}

// find last node in dll
dllnode *dll_last(dllist *dll)
{
    return dll->forword;
}

// print all elements
void print(dllist *dll)
{
    dllnode *temp = dll;
    while ( temp->backword != dll && temp->backword != NULL){
        temp = temp->backword;
        printf("elem is %d\n",temp->value);
    }
}