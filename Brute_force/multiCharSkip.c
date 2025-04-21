//string matching with malti char skip counting.
#include<stdio.h>
#include<string.h>

void main()
{
    char str[]="abcdefghiabcdef";
    char sub[]="ac";
    int count=0;

    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]==sub[0])
        {
            int f=0;
            int sub_iterator=0;
            int index=i;
            int skip=2;

            while (skip<strlen(str) && sub_iterator<strlen(sub))
            {
                if(str[index]!=sub[sub_iterator])
                {
                    f=1; break;
                }
                index=index+skip;
                skip++;
                sub_iterator++;
            }
            if(f==0)
            {
                count++;
            }
            
        }
    }
    printf("Count: %d",count);
}

