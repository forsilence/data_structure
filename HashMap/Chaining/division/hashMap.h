/**
 * define structure of hash map and function.
 * this will use linked list to solve crash.
 * @author forsilence
 * @date 2020-8-21
 */

# ifndef _HASHMAP_H
# define _HASHMAP_H

# ifndef elem_type
# define elem_type int
# endif

# include<stdbool.h>
# define hashMapLen 1021   // maxprimeNumber of between 0 to 1024

struct hashMapLinkNode
{
    /* data */
    elem_type elem;
    struct hashMapLinkNode *next;
};

typedef struct hashMapLinkNode Node;


typedef struct hashMap
{
    /* data */
    Node* data[hashMapLen];
}hashMap;

// create an empty hash map 
hashMap *init_hashMap();

// hash an element
int hash(elem_type elem);

// add element to hashMap :bool add_elem(hashMap *,elem_type)
bool add_elem(hashMap *hM, elem_type x);

// delete an element from hashMap
bool delete_elem(hashMap *hM, elem_type x);

// find element
Node* find(hashMap *hM, elem_type x);

// element in hashMap ?
bool inMap(hashMap *hM, elem_type x);

Node *parent(hashMap *hM,elem_type x);

int *locLength(hashMap *hM);

void showll(hashMap *hM);

# endif