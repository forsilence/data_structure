/**
 * Program : hashMap
 * use multiply to hash.
 * @author forsilence
 * @date 2020-8-22
 */

# ifndef _HASHMAP_H
# define _HASHMAP_H

# include<stdbool.h>
# include<math.h>

# ifndef elem_type
# define elem_type int
# endif

struct hashMapNode{
    elem_type elem;
    struct hashMapNode *next;
};
typedef struct hashMapNode Node;

# define M pow(2,14)
# define A (2654435769.0/pow(2,32))    // (5^(1/2)-1)/2 = 0.6180339887...
# define hashMapLen 1 << 14

typedef struct hashMap{
    Node *data[hashMapLen];
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