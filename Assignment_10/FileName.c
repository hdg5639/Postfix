#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE_STACK 100

typedef int element;
typedef struct {
    element stack[MAX_SIZE_STACK];
    int top;
}StackType;

void init(StackType* s) {
    s->top = -1;
}

int is_empty(StackType* s) {
    return s->top == -1;
}

int is_full(StackType* s) {
    return s->top == MAX_SIZE_STACK - 1;
}

void push(StackType* s, element item) {
    if (is_full(s))
        exit(1);
    s->stack[++(s->top)] = item;
}

element pop(StackType* s) {
    if (is_empty(s))
        exit(1);
    return s->stack[(s->top)--];
}

element peek(StackType* s) {
    if (is_empty(s))
        exit(1);
    return s->stack[s->top];
}

int eval(char exp[]) {
    int op1, op2, value, i, j=0;
    int len = (int)strlen(exp);
    char ch;
    StackType s;
    init(&s);
    for (i = 0; i < len; i++) {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            if (isdigit(ch) == 0) {
                printf("Error: Invalid character\n");
                system("pause");
                exit(1);
            }
            else {
                value = ch - '0';
                push(&s, value);
                j++;
                continue;
            }
        }

        op2 = pop(&s);
        op1 = pop(&s);
        
        switch (ch) {
        case '+': value = op1 + op2; break;
        case '-': value = op1 - op2; break;
        case '*': value = op1 * op2; break;
        case '/': value = op1 / op2; break;
        default: exit(1); break;
        }
        push(&s, value);
    }
    if ((len - j) != (j - 1)) {
        printf("Error: Invalid character\n");
        system("pause");
        exit(1);
    }
    return pop(&s);
}

int main() {
    int result;
    char postfix[MAX_SIZE_STACK];
    printf("Enter an infix expression: ");
    scanf_s("%s", &postfix,MAX_SIZE_STACK);
    result = eval(postfix);
    printf("Postfix expression: %s\nResult: %d\n", postfix, result);
    system("pause");
    return 0;
}
