
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100
char stack[MAX_SIZE];
int top = -1;
void push(char ch) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow. Cannot push element.\n");
        return;
    }
    top++;
    stack[top] = ch;
}
void pop() {
    if (top == -1) {
        printf("Stack underflow. Cannot pop element.\n");
        return;
    }
    top--;
}
bool isBalanced(char expression[]) {
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (top == -1) {
                return false;
            }
            if ((expression[i] == ')' && stack[top] == '(') ||
                (expression[i] == ']' && stack[top] == '[') ||
                (expression[i] == '}' && stack[top] == '{')) {
                pop();
            } else {
                return false;
            }
        }
    }
    return top == -1;
}
int main() {
    char expression[MAX_SIZE];
    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);

    if (isBalanced(expression)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is not balanced.\n");
    }

    return 0;
}
