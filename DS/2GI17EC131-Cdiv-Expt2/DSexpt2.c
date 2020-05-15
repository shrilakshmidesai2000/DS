#include <stdio.h>
#include <ctype.h>

#define MAX 100
#define POSTFIXSIZE 100


int stack[MAX];
int top = -1;


void push(int item)
{

    if (top >= MAX - 1) {
        printf("stack over flow");
        return;
    }
    else {
        top = top + 1;
        stack[top] = item;
    }
}

int pop()
{
    int item;
    if (top < 0) {
        printf("stack under flow");
    }
    else {
        item = stack[top];
        top = top - 1;
        return item;
    }
}


void EvalPostfix(char postfix[])
{

    int i;
    char ch;
    int val;
    int A, B;


    for (i = 0; postfix[i] != ')'; i++) {
        ch = postfix[i];
        if (isdigit(ch)) {
            /* we saw an operand,push the digit onto stack
ch - '0' is used for getting digit rather than ASCII code of digit */
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {

            A = pop();
            B = pop();

            switch (ch)
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }

            push(val);
        }
    }
    printf(" \n Result of expression evaluation : %d \n", pop());
}

int main()
{

    int i;

    /* declare character array to store postfix expression */
    char postfix[POSTFIXSIZE];
   printf("Press right parenthesis ')' for end expression : ");
    printf(" \nEnter postfix expression,: ");

    /* take input of postfix expression from user */

    for (i = 0; i <= POSTFIXSIZE - 1; i++) {
        scanf("%c", &postfix[i]);

        if (postfix[i] == ')')
        {
            break;
        }
    }


    EvalPostfix(postfix);

    return 0;
}

