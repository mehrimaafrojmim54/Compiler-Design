#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *keywords[] = {"int", "float", "if", "else", "while", "for", "return"};
int keywordCount = 7;

int isKeyword(char *str) {
    for (int i = 0; i < keywordCount; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '=' || ch == '<' || ch == '>' || ch == '!');
}

int main() {
    char str[100];
    printf("Enter an expression: ");
    gets(str) ;

    int i = 0;
    while (str[i] != '\0') {
        if (isspace(str[i])) {
            i++;
            continue;
        }

        // Identifier or Keyword
        if (isalpha(str[i])) {
            char temp[50];
            int k = 0;

            while (isalnum(str[i])) {
                temp[k++] = str[i++];
            }
            temp[k] = '\0';

            if (isKeyword(temp))
                printf("Keyword: %s\n", temp);
            else
                printf("Identifier: %s\n", temp);
        }

        // Number
        else if (isdigit(str[i])) {
            char temp[50];
            int k = 0;

            while (isdigit(str[i])) {
                temp[k++] = str[i++];
            }
            temp[k] = '\0';
            printf("Number: %s\n", temp);
        }

        // Operators (single or double)
        else if (isOperator(str[i])) {
            char op = str[i];

            // Check for multi-character operator
            if ((op == '=' || op == '<' || op == '>' || op == '!') && str[i+1] == '=') {
                printf("Operator: %c%c\n", str[i], str[i+1]);
                i += 2;
            }
            else {
                printf("Operator: %c\n", str[i]);
                i++;
            }
        }

        // Parenthesis
        else if (str[i] == '(' || str[i] == ')') {
            printf("Parenthesis: %c\n", str[i]);
            i++;
        }

        // Other symbols (
        else {
            printf("Symbol: %c\n", str[i]);
            i++;
        }
    }

    return 0;
}

