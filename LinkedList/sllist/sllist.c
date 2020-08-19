/**
 * program for single linked list.
 * @date 2020-8-8
 * @author forsilence
 */

# include<stdbool.h>
# include<stdlib.h>
# include<stdio.h>
# include"sllist.h"

/**
 * create a head for single linked list,
 * if can't ,return NULL.
 */
sllist *init_sllist()
{
    sllist *head = (sllist *)malloc(sizeof(sllist));
    if (head){
        head->next = NULL;
        return head;
    }
    else {
        printf("can create a single linked list!");
        return NULL;
    }
}

/**
 * add a node to a single linked list return true,
 * if can't ,return false
 */
bool add_node(sllnode *sl,elem_type x)
{
    sllnode * lastnode;
    sllnode * new_node = (sllnode *)malloc(sizeof(sllnode));
    new_node->next=NULL;
    new_node->value=x;
    if ( new_node ){
        lastnode = last(sl);
        lastnode->next = new_node;
    }
    else
    {
        return false;
    }
    return true;
}

// delete node from sll
elem_type denode(sllnode *sl,int loc)
{
    sllnode *preNode = locate(sl,loc-1);
    if (preNode == NULL){                       // loc is out of range
        printf("location is not in sl range.\n");
        return sl->value;
    }
    else{
        sllnode *curNode = preNode->next;
        if (curNode == NULL){                   // loc is out of range
            printf("location is not right.\n");
            return sl->value;
        }
        preNode->next=curNode->next;
        elem_type val = curNode->value;
        free(curNode);
        return val;
    }
}

// get sll length
int sll_len(sllist *sl)
{
    int length=0;
    sllnode *temp = sl;
    while (temp->next){
        temp = temp->next;
        length++;
    }
    return length;
}

// get the last node
sllist *last(sllist *sl)
{
    sllnode *temp = sl;
    while (temp->next){
        temp=temp->next;
    }
    return temp;
}

// node in location
sllnode *locate(sllist *sl,int loc)
{
    if (loc == -1) return sl;
    sllnode *temp = sl;
    while (temp->next && loc >= 0){ // when loc == -1 ,it's head node
        temp = temp->next;
        loc--;
    }
    if (loc < -1)
        return NULL;
    return temp;
}

void print(sllist *sl)
{
    sllnode *temp = sl;
    int loc=0;
    while (temp->next){
        temp=temp->next;
        printf("The %d number is %d.\n",loc+1,temp->value);
        loc++;
    }
}