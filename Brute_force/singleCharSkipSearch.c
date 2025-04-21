////String matching of Single char skip search.

#include <stdio.h>
#include <string.h>

void main()
{
    char str[] = "abcdefghij";
    char sub[] = "fhj";
    int f1=0; int index;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == sub[0])
        {
            int f=0;
            for (int j=1;j<strlen(sub);j++)
            {
                if(sub[j]!=str[i+(j*2)])
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
        printf("Found at index %d",index);
    }
    else
    {
        printf("Not Found");
    }
}
