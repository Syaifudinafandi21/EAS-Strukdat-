#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXSTACK = 1000;
const int MAXCODE = 5000;

typedef struct {
    char items[1000];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char ch) {
    if (stack->top < MAXSTACK - 1) {
        stack->items[++stack->top] = ch;
    }
}

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    }
    return '\0';
}

int awal(char ch) {
    return ch == '(' || ch == '{' || ch == '[' || ch == '<';
}

int akhir(char ch) {
    return ch == ')' || ch == '}' || ch == ']' || ch == '>';
}

int matching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']') ||
           (open == '<' && close == '>');
}

int kodevalid(const char *code) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; code[i] != '\0'; i++) {
        char ch = code[i];

        if (awal(ch)) {
            push(&stack, ch);
        } else if (akhir(ch)) {
            if (isEmpty(&stack) || !matching(pop(&stack), ch)) {
                return 0;
            }
        }
    }

    return isEmpty(&stack);
}

int main() {
    char code[5000] = "";
    char line[1000];

    printf("Masukkan kode yang akan diperiksa (akhiri dengan baris kosong):\n");

    while (1) {
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }

        line[strcspn(line, "\n")] = 0;

        if (strlen(line) == 0) {
            break;
        }

        strcat(code, line);
    }

    if (kodevalid(code)) {
        printf("Kode valid.\n");
    } else {
        printf("Kode tidak valid.\n");
    }

    return 0;
}
