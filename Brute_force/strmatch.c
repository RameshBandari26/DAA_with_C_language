#include<stdio.h>
#include<string.h>

void main()
{
    char str[]="abcabcabcdabcdabcdf";
    char sub[]="abcdf";

    int f1;
    int index;
    for(int i=0;i<=strlen(str)-strlen(sub);i++)
    {
        int f=0; 
        if(str[i]==sub[0])
        {
            for(int j=1;j<strlen(sub);j++)
            {
                if(sub[j]!=str[j+i])
                {
                    f=1;
                    break;                    
                }
            }
            if(f==0) 
            {
                f1=1;     
                index=i;
                break;
            }
        }
    }
    if(f1==1)
    {
        printf("Found at %d index.",index);
    }
    else
    {
        printf("Not Found!");
    }
}
