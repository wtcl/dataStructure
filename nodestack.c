#include <stdio.h>
#include <stdlib.h>
typedef struct lineStack{
    char data;
    struct lineStack * next;
}lineStack;
lineStack* push(lineStack * stack,char a){
    lineStack * line=(lineStack*)malloc(sizeof(lineStack));
    line->data=a;
    line->next=stack;
    stack=line;
    return stack;
}
lineStack * pop(lineStack * stack){
    if (stack) {
        lineStack * p=stack;
        stack=stack->next;
        printf("��ջԪ�أ�%c ",p->data);
        if (stack) {
            printf("ջ��Ԫ�أ�%c\n",stack->data);
        }else{
            printf("ջ�ѿ�\n");
        }
        free(p);
    }else{
        printf("ջ��û��Ԫ��");
        return stack;
    }
    return stack;
}
int main() {
    lineStack * stack=NULL;
    stack=push(stack, 'a');
    stack=push(stack, 'b');
    stack=push(stack, 'c');
    stack=push(stack, 'd');
    stack=pop(stack);
    stack=pop(stack);
    stack=pop(stack);
    stack=pop(stack);
    stack=pop(stack);
    return 0;
}
