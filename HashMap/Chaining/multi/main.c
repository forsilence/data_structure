/**
 * test for hashMap
 */

# include<stdio.h>
# include"hashMap.h"

int main()
{
    hashMap hM = *init_hashMap();
    int val = M;

    int insertLen = 20000;
    printf("starting add elements to hashMap\n");
    for (int i = 0; i<insertLen ; i++)
    {
        if (add_elem(&hM,i))
            printf("add %d into hashMap\n",i);
        else
            printf("not add element to hashMap\n");
    }
    printf("ends\n********************************\n");
    
    printf("find nodes\n");
    for (int i = 0 ; i<insertLen ; i++)
    {
        Node *temp = find(&hM,i);
        if (temp)
            printf("element %d is in hashMap\n",temp->elem);
        else 
            printf(" element is not in hashMap\n");
    }
    printf("ends\n*******************************\n");
    showll(&hM);

    return 0;
}