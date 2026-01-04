#include <stdio.h>
#include <ctype.h>
#include <string.h>

int stack[100];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluatePrefix(char* expr) {
    int length = strlen(expr);

    // Right to Left scan
    for (int i = length - 1; i >= 0; i--) {
        char ch = expr[i];

        if (isdigit(ch)) {
            push(ch - '0');
        }
        else if (ch == ' ') {
            continue;
        }
        else {
            int val1 = pop();
            int val2 = pop();

            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }

    return pop();
}

int main() {
    // USER INPUT নেবে না — expression এখানেই থাকবে
    char expr[] = "* + 5 3 8";

    printf("Result: %d\n", evaluatePrefix(expr));

    return 0;
}
