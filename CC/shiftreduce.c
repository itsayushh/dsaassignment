#include <stdio.h>
#include <string.h>

#define SIZE 100

char stack[SIZE], input[SIZE];
int top = -1, i = 0;

void push(char ch) {
    stack[++top] = ch;
}

void pop() {
    if (top >= 0)
        top--;
}

void displayStack() {
    for (int j = 0; j <= top; j++)
        printf("%c", stack[j]);
}

int checkReduce() {
    if (top >= 2 && stack[top] == 'E' && (stack[top - 1] == '+' || stack[top - 1] == '*') && stack[top - 2] == 'E') {
        top -= 2;
        return 1;  
    } else if (top >= 2 && stack[top] == ')' && stack[top - 1] == 'E' && stack[top - 2] == '(') {
        top -= 2;
        stack[top] = 'E';  
        return 1;
    } else if (top >= 1 && stack[top] == 'd' && stack[top - 1] == 'i') {
        top--;             
        stack[top] = 'E';
        return 1;
    }
    return 0;
}

int main() {
    printf("Enter the input string (e.g., id+id*id): ");
    scanf("%s", input);

    printf("\nStack\t\tInput\t\tAction\n");
    printf("-----\t\t-----\t\t------\n");

    while (i < strlen(input)) {
        
        push(input[i]);
        input[i] = ' ';
        i++;

        printf("%-10s\t%-10s\tShift\n", stack, input);

        
        while (checkReduce()) {
            printf("%-10s\t%-10s\tReduce\n", stack, input);
        }
    }

    
    while (checkReduce()) {
        printf("%-10s\t%-10s\tReduce\n", stack, input);
    }

    if (top == 0 && stack[top] == 'E') {
        printf("\nAccepted: Valid expression.\n");
    } else {
        printf("\nRejected: Invalid expression.\n");
    }

    return 0;
}
