# include<stdlib.h>
# include<stdio.h>

int primeNumer(int maxn);

int main()
{
    int maxn = 100;
    int val = primeNumer(maxn);
    printf("The max primeNumber between 0 to %d is %d",maxn,val);
    return 0;
}

int primeNumer(int maxn)
{
    int maxprimeNumer = 2;
    for (int i = maxn; i>0 ;i--)
    {
        for ( int y = 2 ; y < maxn/2 ; y++)
        {
            if ( i%y == 0){
                maxprimeNumer = 0;
                break;
            }
            else {
                maxprimeNumer = i;
            }
        }
        if ( maxprimeNumer != 0 )
            break;
    }
    return maxprimeNumer;
}