#include <stdio.h>

int stringLength(char *str) {
    char *ptr = str;
    int length = 0;

    while (*ptr != '\0') {
        length++;
        ptr++;
    }

    return length;
}

int main() {
    char str[] = "Hello, world!";
    printf("Panjang string \"%s\" adalah: %d\n", str, stringLength(str));
    return 0;
}

