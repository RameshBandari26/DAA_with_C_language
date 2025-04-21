//string matching with skip search.

#include<stdio.h>
#include<string.h>

void main()
{
    char str[]="abcdefghijjlmnopqrstuv";
    char sub[]="acfjou";

    int f1=0; int ind_f;
    for(int i=0;i<=strlen(str)-strlen(sub);i++)
    {
        if(str[i]==sub[0])
        {

            int f=0;
            int sub_iterator=0;
            int skip=2;
            int index=i;
            while (sub_iterator< strlen(sub) && index<strlen(str))
            {
                if(str[index]!=sub[sub_iterator]) 
                {
                    f=1;
                    break;
                }
                index=index+skip;
                skip++;
                sub_iterator++;
            }
            if(f==0)
            {
                f1=1;
                ind_f=i;
                break;
            }    
        }
    }
    if(f1==1)
    {
        printf("Found at index %d ",ind_f);
    }
    else
    {
        printf("not Found !");
    }
}