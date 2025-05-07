#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100 //オペランドの数が100以下なのでスタックのサイズは100

int stack[STACK_SIZE];
int top = 0;

void push(int x) {
    stack[++top] = x; //前置インクリメント．top++;の後にxを代入する
}

int pop() {
    return stack[top--]; //後置インクリメント．returnの後にtop--;
}

int main(void) {
    char s[100];
    while (scanf("%s", s) != EOF) {
        if (s[0] == '+') {
            int b = pop();
            int a = pop();
            push(a + b);
        } else if (s[0] == '-') {
            int b = pop();
            int a = pop();
            push(a - b);
        } else if (s[0] == '*') {
            int b = pop();
            int a = pop();
            push(a * b);
        } else {
            push(atoi(s));
        }
    }

    printf("%d\n", pop());
    return 0;
}
