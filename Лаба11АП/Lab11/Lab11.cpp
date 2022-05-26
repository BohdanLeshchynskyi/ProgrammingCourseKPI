#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, counter = 0;
    char* str1;
    char* str2;

    printf("Enter n for number of symbols you are going to enter: \n");
    scanf_s("%d", &n);
    getchar();

    str1 = (char*)malloc((n + 2) * sizeof(char));

    printf("Enter some symbols among which must be at least one colon(:) : \n");
    fgets(str1, n, stdin);

    printf("Symbols before the first colon: \n");
    for (int i = 0; i < n; i++) {
        if (str1[i] != ':') counter++;
        else break;
    }
    str2 = (char*)malloc((counter + 1) * sizeof(char));

    for (int i = 0; i < counter; i++) {
        str2[i] = str1[i];
    }
    str2[counter] = '\0';

    printf("%s", str2);

    free(str1);
    free(str2);
   
    return 0;
}