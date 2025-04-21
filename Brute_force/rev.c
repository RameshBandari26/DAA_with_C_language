#include <stdio.h>
#include <string.h>


void reverseStr(char* str) {
    int n = strlen(str);
    for (int i=0; i<n/2; i++) {
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
}

void main() {
    char str[] = "hello world";
    char sub[] = "dlrow";

    int f1 = 0; 
    int ind;
    int lenStr = strlen(str);
    int lenSub = strlen(sub);
    reverseStr(sub);

    for (int i = 0; i <= lenStr - lenSub; i++) {
        if (sub[0] == str[i]) {
            int f = 0;
            for (int j=0; j<lenSub; j++) {
                if (sub[j] != str[i+j]) {
                    f = 1;
                    break;
                }
            }
            if (f == 0) {
                f1 = 1;
                ind = i;
                break;
            }
        }
    }
    if (f1 == 1) {
        printf("Found at %d\n", ind);
    } else {
        printf("Not Found!\n");
    }
}