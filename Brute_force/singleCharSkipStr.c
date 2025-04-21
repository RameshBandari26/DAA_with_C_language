//String matching of Single char skip count.

#include<stdio.h>
#include<string.h>

void main()
{
    char sup[]="abcdeafcgehi";
    char sub[]="acei"; 
    int count=0;

    for(int i=0;i<strlen(sup);i++)
    {
        if(sup[i]==sub[0])
        {
            int f=0;
            for(int j=0;j<strlen(sub);j++)
            {
                if(sub[j]!=sup[i+(j*2)])  
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                count++;
            }
        }
    }
    printf("Count : %d",count);
}