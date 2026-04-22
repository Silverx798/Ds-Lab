#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

char stack[MAX];
int top = -1;
void push(char c) {
    stack[++top] = c;
}
char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}
int isBalanced(char *s) {
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        } else {
            char topChar = pop();
            if (!isMatchingPair(topChar, s[i])) {
                return 0;
            }
        }
    }
    return top == -1;
}
int main() {
    char s[MAX];
    scanf("%s", s);
    if (isBalanced(s))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
