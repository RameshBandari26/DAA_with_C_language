//String matching by reverse search.

#include<stdio.h>
#include<string.h>

void main()
{
    char str[]="abcdef";
    char sub[]="f";
    int f1=0; int ind;
    for(int i=strlen(str)-strlen(sub);i>=0;i--)
    {
        if(sub[0]==str[i])
        {
            int f=0;
            for(int j=0;j<strlen(sub);j++)
            {
                if(sub[j]!=str[i-j])
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                f1=1;
                ind=i;
            }
        }
    }
    if(f1==1)
    {
        printf("Found at %d ",ind);
    }
    else
    {
        printf("Not Found !");
    }
}