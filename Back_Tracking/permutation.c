//with repetation
#include <stdio.h>
#include<string.h>
void permute(char *str, int start, int end, int length, char *result) {
    if (length == 0) {
        printf("%s\n", result);
        return;
    }

    for (int i = start; i <= end; i++) {
        result[length-1] = str[i];
        permute(str, start, end, length-1, result);
    }
}

int main() {
    char str[20];
    int n;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Enter the length of permutation: ");
    scanf("%d", &n);

    char result[n + 1];
    result[n] = '\0';

    printf("Permutations with repetition:\n");
    permute(str, 0, strlen(str)-1, n, result);

    return 0;
}
