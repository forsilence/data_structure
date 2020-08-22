/**
 * test for hashMap
 * @author forsilence
 * @date 2020-8-22
 */

# include<stdio.h>
# include"hashMap.h"

int main()
{
    hashMap hM = *init_hashMap();
    for ( int i=0 ; i<hashMapLen ;i++ )
    {
        if (hM.data[i] != NULL){
            printf("init failed\n");
            break;
        }
    }
    printf("starting add elements to hashMap\n");
    for (int i = 0; i<10000 ; i++)
    {
        if (add_elem(&hM,i))
            printf("add %d into hashMap\n",i);
        else
            printf("not add element to hashMap\n");
    }
    printf("ends\n********************************\n");
    
    printf("find nodes\n");
    for (int i = 0 ; i<10000 ; i++)
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