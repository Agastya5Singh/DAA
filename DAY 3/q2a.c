#include<stdio.h>
#define MAXFACTORS 1024
typedef struct{
   int size;
   int factor[MAXFACTORS + 1];
   int exponent[MAXFACTORS + 1];
} FACTORIZATION;
void euclid(int a, int b)
{
    int r=1,c=0;
    while (r != 0 ) 
    {
        c++;
        r = a % b;
        a=b;
        b=r;
    }
    printf("%d\t",c);
}
void consecutive(int a, int b)
{
    int c=0,temp;
    if(a<b)
        temp=a;
    else
        temp=b;
    for (int i=temp;i>0;i--) 
    {
        c++;
        if(a%i == 0 && b%i == 0)
        {
            printf("%d\t",c);
            break;
        }
    }    
}
void FindFactorization(int x, FACTORIZATION* factorization)
{
    int i,j=1,n=x,c=0,k=1,d=0;
    factorization->factor[0] = 1;
    factorization->exponent[0] = 1;
    for (i = 2; i <= n; i++) 
    {
        c = 0;
        d++;
        while (n%i == 0) 
        {
            c++;
            n = n / i;
        }
        if (c > 0) 
        {
            factorization->exponent[k] = c;
            factorization->factor[k] = i;
            k++;
        }
    }
    factorization->size = k - 1;
    printf("%d+",d);
}
void middle_school(int m, int n)
{
    FACTORIZATION mFactorization, nFactorization;
    int r,mi,ni,i,k,x=1,j,c=0,min;
    FindFactorization(m,&mFactorization);
    FindFactorization(n,&nFactorization);
    i=j=1;
    while(i<=mFactorization.size && j<=nFactorization.size) 
    {
        c++;
        if (mFactorization.factor[i] < nFactorization.factor[j])
            i++;
        else if (nFactorization.factor[j] < mFactorization.factor[i])
            j++;
        else
        {
            min = mFactorization.exponent[i] > nFactorization.exponent[j] ? nFactorization.exponent[j] : mFactorization.exponent[i];
            x = x * mFactorization.factor[i] * min;
            i++;
            j++;
        }
    }
    printf("%d\n",c);
}
int main()
{
    euclid(31415, 14142);
    consecutive(31415, 14142);
    middle_school(31415, 14142);
    euclid(56,32566);
    consecutive(56,32566);
    middle_school(56,32566);
    euclid(32566,56);
    consecutive(32566,56);
    middle_school(32566,56);
    euclid(12,15);
    consecutive(12,15);
    middle_school(12,15);
    euclid(31415,31415);
    consecutive(31415,31415);
    middle_school(31415,31415);
    euclid(12,12);
    consecutive(12,12);
    middle_school(12,12);
}