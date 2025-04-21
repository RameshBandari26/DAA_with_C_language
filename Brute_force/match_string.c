//Matching of Sub-substring.

#include<stdio.h>
#include<string.h>

void main()
{
    char str[]="abcabcabcdabcdabcdabcd";
    char sub[]="abcd"; 
    int count=0;

    for(int i=0;i<=strlen(str)-strlen(sub);i++)
    {
        if(str[i]==sub[0])
        {
            int j=0;
            for(j=0;j<strlen(sub);j++)
            {
                if(str[i+j]!=sub[j])
                {
                    break;
                }
            }
            if(j==strlen(sub))
            {
                printf("Pattern found at index %d\n", i);
            }
        }
    }
}
