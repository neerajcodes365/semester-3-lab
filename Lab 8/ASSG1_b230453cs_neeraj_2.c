#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

int max(int a, int b) {
    return (a > b) ? a : b;
}

void preprocessBadCharacter(char *pattern, int m, int badCharShift[]) {
    for (int i = 0; i < MAX_CHAR; i++) {
        badCharShift[i] = m;
    }
    for (int i = 0; i < m - 1; i++) {
        badCharShift[(unsigned char)pattern[i]] = m - 1 - i;
    }
}

int boyerMooreSearch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    if (m > n) return -1;

    int badCharShift[MAX_CHAR];
    preprocessBadCharacter(pattern, m, badCharShift);

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }
        if (j < 0) {
            return s;
        } else {
            s += max(1, j - badCharShift[(unsigned char)text[s + j]]);
        }
    }
    return -1;
}

int main() {
    char *text = (char *)malloc(10000005 * sizeof(char));
    char *pattern = (char *)malloc(100005 * sizeof(char));

    fgets(text, 10000005, stdin);
    text[strlen(text) - 1] = '\0';
    fgets(pattern, 100005, stdin);
    pattern[strlen(pattern) - 1] = '\0';

    int result = boyerMooreSearch(text, pattern);

    printf("%d\n", result);

    free(text);
    free(pattern);

    return 0;
}


//Convolutional neural networks (CNNs) are widely regarded as the most effective for image classification. They learn spatial hierarchies of features through backpropagation and can handle complex visual tasks.