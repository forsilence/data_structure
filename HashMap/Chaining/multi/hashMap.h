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

# define M pow(2,14)
# define A (2654435769.0/pow(2,32))    // (5^(1/2)-1)/2 = 0.6180339887...
# define hashMapLen 1 << 14

struct hashMapLinkNode
{
    /* data */
    char *key;
    char *val;
};

typedef struct hashMapLinkNode elem;

struct linkedNode{
    elem *elem_node;
    struct linkedNode *next;
};

typedef struct linkedNode Node;

struct hashMap
{
    /* data */
    Node *data[hashMapLen];
};

typedef struct hashMap hashMap;

// create an empty hash map 
hashMap *init_hashMap();

// hash an element
int hash(char *c);

// add key and val to hashMap
bool add(hashMap *hM,char *key ,char *val);
// add element to hashMap :bool add_elem(hashMap *,elem)
bool add_elem(hashMap *hM, elem *x);

// delete an element from hashMap
bool delete_elem(hashMap *hM,char *key);

// find element by key
Node* find(hashMap *hM, char *key);

// element in hashMap ?
bool inMap(hashMap *hM, elem x);

Node *parent(hashMap *hM,char *key);

// length in each location
int *locLength(hashMap *hM);

void showll(hashMap *hM);

// two array with char type is equal?
bool equals(char *x , char *y);

// get char array length
int get_char_array_len(char *char_array);


# endif