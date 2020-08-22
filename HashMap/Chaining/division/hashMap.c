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
int hash(elem_type elem)
{
    int val = elem%hashMapLen;
    return val;
}

// add element to hashMap
bool add_elem(hashMap *hM, elem_type x)
{
    int location = hash(x);
    if ( !hM->data[location] )          // location is empty!
    {
        hM->data[location] = (Node *)malloc(sizeof(Node));
        if ( hM->data[location] )       // malloc seccessful
        {
            hM->data[location]->elem = x;
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
            temp->next->elem = x;
            temp->next->next = NULL;
        }
        else
            return false;
        return true;
    }
}

// delete element from hashMap
bool delete_elem(hashMap *hM,elem_type x)
{
    Node *curNode = find(hM,x);
    if (curNode)                        // found the node with x
    {
        Node *pNode = parent(hM,x);
        if (pNode)                      // found parent of the node with x
            pNode->next = curNode->next;
        else                            // the node is the head
        {
            int loc = hash(x);
            hM->data[loc] = NULL;
        }
        free(curNode);
        return true;
    }
    return false;                       // x is not in hashMap
}

// find node with element x
Node *find(hashMap *hM,elem_type x)
{
    int loc = hash(x);
    if ( hM->data[loc] )                // loc is not empty
    {
        Node *temp = hM->data[loc];
        while ( temp->elem != x && temp->next)      // not the node with x and have next node
            temp = temp->next;
        if ( temp->elem == x )                      // node is the node with x
            return temp;
    }
    return NULL;
}

// find x parent node
Node *parent(hashMap *hM,elem_type x)
{
    int loc = hash(x);
    // loc is not empty
    if ( hM->data[loc] )
    {
        Node *temp = hM->data[loc];
        // try to find the node 
        while(temp->next && temp->next->elem != x)
            temp = temp->next;
        // found the node
        if (temp->next && temp->next->elem == x)
            return temp;
    }
    return NULL;
}

// element in map ?
bool inMap(hashMap *hM,elem_type x)
{
    Node *curNode = find(hM,x);
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
