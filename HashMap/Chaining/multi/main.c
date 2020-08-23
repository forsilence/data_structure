/**
 * test for hashMap
 */

# include<stdio.h>
# include"hashMap.h"

int main()
{
    char *key[] = {"12","13","14","15"};
    char *val[] = {"hello","new","world","forsilence"};
    hashMap hM = *init_hashMap();

    // check initialize successful?
    for ( int i=0 ; i<hashMapLen ;i++ )
    {
        if (hM.data[i] != NULL){
            printf("init failed\n");
            break;
        }
    }

    // add key and value to hashMap
    printf("--> starting add elements to hashMap\n");
    for (int i = 0; i<4 ; i++)
    {
        if (add(&hM,key[i],val[i]))
            printf("add %s into hashMap [%d]\n",val[i],hash(key[i]));
        else
            printf("not add element to hashMap\n");
    }
    printf("-->ends\n");
    
    // use key to find value
    printf("--> find nodes\n");
    for (int i = 0 ; i<4 ; i++)
    {
        Node *temp = find(&hM,key[i]);
        if (temp)
            printf("element %s is in hashMap\n",temp->elem_node->val);
        else 
            printf(" element is not in hashMap\n");
    }
    printf("--> ends\n");
    
    // delete function:-> delete by key
    if (delete_elem(&hM,key[3]))
    {
        printf("check for delete\n");
            printf("--> find nodes\n");
        for (int i = 0 ; i<4 ; i++)
        {
            Node *temp = find(&hM,key[i]);
            if (temp)
                printf("element %s is in hashMap\n",temp->elem_node->val);
            else 
                printf(" element is not in hashMap\n");
        }
        printf("--> ends\n");
    }
    // showll(&hM);

    return 0;
}