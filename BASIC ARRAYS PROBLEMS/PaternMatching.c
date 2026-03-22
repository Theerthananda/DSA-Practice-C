#include<stdio.h>
#include<string.h>

int main() {
    char text[100], pattern[50];

    printf("Enter Text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter Pattern: ");
    fgets(pattern, sizeof(pattern), stdin);

    int n = strlen(text);
    int m = strlen(pattern);

    // Remove newline from fgets
    if(text[n-1] == '\n') text[n-1] = '\0';
    if(pattern[m-1] == '\n') pattern[m-1] = '\0';

    n = strlen(text);
    m = strlen(pattern);

    for(int i = 0; i <= n - m; i++) {
        int j;

        for(j = 0; j < m; j++) {
            if(text[i + j] != pattern[j]) {
                break;
            }
        }

        if(j == m) {
            printf("Match found from index %d to %d", i, i + m - 1);
            return 0;
        }
    }

    printf("Pattern not found");
    return 0;
}
