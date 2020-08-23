# include"hashMap.h"
# include<stdbool.h>
# include<stdlib.h>
# include<stdio.h>

hashMap *init_hashMap(){
    hashMap *hM = (hashMap*)malloc(sizeof(hashMap));
    if (!hM)
        return NULL;
    for(int i=0 ; i<hashMapLen ; i++){
        hM->data[i] = NULL;
    }
    return hM;
}

// hash by division
int hash(char *c)
{
    int len = get_char_array_len(c);
    int val = 0;
    for ( int i=0 ; i<len ; i++)
        val+=(int)c[i];
    int loc = val%hashMapLen;
    return loc;
}

// add key and val to hashMap
bool add(hashMap *hM,char *key,char *val)
{
    elem *new_node = (elem *)malloc(sizeof(elem));
    if ( new_node )
    {                                           // malloc successful
        int keylen=get_char_array_len(key);
        int vallen=get_char_array_len(val);
        new_node->key = (char *)malloc(sizeof(char)*(keylen+1));
        new_node->val = (char *)malloc(sizeof(char)*(vallen+1));
        if ( !new_node->key )
            return false;
        // add key to new_node key
        for ( int i=0 ; i<keylen ; i++ )
            new_node->key[i] = key[i];
        new_node->key[keylen]='\0';

        if ( !new_node->val )
            return false;
        // add val to new_node val
        for ( int i=0 ; i<vallen ; i++ )
            new_node->val[i] = val[i];
        new_node->val[vallen]='\0';
        // add element failed
        if ( !add_elem(hM,new_node) )
        {
            printf("can not add to array \n");
            return false;
        }
    }
    else                                        // malloc failed
        return false;

    return true;
}

// add element to hashMap
bool add_elem(hashMap *hM, elem *x)
{
    int location = hash(x->key);
    if ( !hM->data[location] )          // location is empty!
    {
        hM->data[location] = (Node *)malloc(sizeof(Node));
        if ( hM->data[location] )       // malloc seccessful
        {
            hM->data[location]->elem_node = x;
            hM->data[location]->next = NULL;
        }
        else                            // malloc failed 
            return false;
        return true;
    }
    else                                // location is not empty
    {
        Node *temp = hM->data[location];
        while ( temp->next ){           // find the last node in this location
            temp = temp->next;
        }
        temp->next = (Node *)malloc(sizeof(Node));
        if ( temp->next ){              // malloc successful
            temp->next->elem_node = x;
            temp->next->next = NULL;
        }
        else
            return false;
        return true;
    }
}

// delete element from hashMap
bool delete_elem(hashMap *hM,char *key)
{
    Node *curNode = find(hM,key);
    if (curNode)                        // found the node with x
    {
        Node *pNode = parent(hM,key);
        if (pNode)                      // found parent of the node with x
            pNode->next = curNode->next;
        else                            // the node is the head
        {
            int loc = hash(key);
            hM->data[loc] = NULL;
        }
        free(curNode);
        return true;
    }
    return false;                       // x is not in hashMap
}

// find node with element x
Node *find(hashMap *hM,char *key)
{
    int loc = hash(key);
    if ( hM->data[loc] )                // loc is not empty
    {
        Node *temp = hM->data[loc];
        while ( equals(temp->elem_node->key,key) && temp->next)      // not the node with x and have next node
            temp = temp->next;
        if ( equals( temp->elem_node->key,key) )                      // node is the node with x
            return temp;
    }
    printf("not find!\n");
    return NULL;
}

// find x parent node
Node *parent(hashMap *hM,char *key)
{
    int loc = hash(key);
    // loc is not empty
    if ( hM->data[loc] )
    {
        Node *temp = hM->data[loc];
        // try to find the node 
        while(temp->next && !equals(temp->next->elem_node->key,key))
            temp = temp->next;
        // found the node
        if (temp->next && equals(temp->next->elem_node->key,key))
            return temp;
    }
    return NULL;
}

// element in map ?
bool inMap(hashMap *hM,elem x)
{
    Node *curNode = find(hM,x.key);
    if (curNode)
        return true;
    return false;
}

// get length of every location
int *locLength(hashMap *hM)
{
    int *lenLs = (int *)malloc(sizeof(int)*hashMapLen);
    // lenLs malloc failed
    if ( !lenLs )
        return NULL;
    // lenLs malloc successful
    else {
        // count elements of every location 
        for( int i=0 ; i<hashMapLen ; i++)
        {
            lenLs[i] = 0;
            Node *temp = hM->data[i];
            while (temp != NULL )
            {
                lenLs[i]++;
                temp = temp->next;
            }
        }
    }
    return lenLs;
}

// show locations length
void showll(hashMap *hM)
{
    int *ls = locLength(hM);
    printf("showll\n");
    for (int i=0 ; i<hashMapLen ; i++)
    {
        printf("location %d length:[",i);
        for (int y=0 ; y<ls[i] ; y++ )
        {
            printf("#");
        }
        printf("]\n",ls[i]);
    }
}

// two elems equals ?
bool equals(char *x , char *y)
{
    int xlen = get_char_array_len(x);
    int ylen = get_char_array_len(y);
    if (xlen == ylen)
    {
        for( int i=0 ; i<xlen ; i++ )
        {
            if ( x[i] != y[i] )
                return false;
        }
        return true;
    }
    return false;
}

int get_char_array_len(char *char_array)
{
    int len = 0;
    while (char_array[len] != '\0')
        len++;
    return len;
}