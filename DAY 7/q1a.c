#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int min=0,max=100,mid;
    char ans[4];
    printf("Think a number between -100 and 100.\n");
    while(1)
    {
        mid=(min+max)/2;
        printf("Is your number %d?\n",mid);
        scanf("%s",ans);
        if(strcmp(ans,"Yes")==0)
        {
            printf("I won\n");
            break;
        }
        else if(strcmp(ans,"M")==0)
        {
            min=mid;

        }
        else
        {
            max=mid;
        }
    }
}