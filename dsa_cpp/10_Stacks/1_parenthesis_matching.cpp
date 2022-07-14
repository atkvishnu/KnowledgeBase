/* Parentheses matching, it won't check for syntax error, only if the parentheses are balanced */
 
#include "stdio.h"
#include "stdlib.h"
 

// typedef vs #define
// #define is a C-directive which is also used to define the aliases for various data types similar to typedef but with the following differences −
// typedef is limited to giving symbolic names to types only. whereas `#define` can be used to define alias for values as well, q., you can define 1 as ONE etc.
// typedef interpretation is performed by the compiler. whereas `#define` statements are processed by the pre-processor.


typedef struct Node {       // typedef, can be used to give a `type` a new name
    char *data;
    struct Node *next;
} Stack;                    // `struct Node` has been given the name `Stack`. Later on we can use `Stack` in the place of `struct Node`
 

// Enumeration is a user defined datatype in C language. 
// It is used to assign names to the integral constants which makes a program easy to read and maintain. 
// The keyword “enum” is used to declare an enumeration.

// syntax of enum
// enum enum_name{const1, const2, ....... };
// #include<stdio.h>
// enum week{Mon=10, Tue, Wed, Thur, Fri=10, Sat=16, Sun};
// enum day{Mond, Tues, Wedn, Thurs, Frid=18, Satu=11, Sund};
// int main() {
//    printf("The value of enum week: %d\t%d\t%d\t%d\t%d\t%d\t%d\n\n",Mon , Tue, Wed, Thur, Fri, Sat, Sun);
//    printf("The default value of enum day: %d\t%d\t%d\t%d\t%d\t%d\t%d",Mond , Tues, Wedn, Thurs, Frid, Satu, Sund);
//    return 0;
// }
enum BOOL {FALSE, TRUE};  
 
Stack *top=NULL;
 
Stack *alloc(void );
void push(char n);
int empty(void);
int full(void);
char pop(void);
int validate(void);

Stack *alloc(void)
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->data = (char *)malloc(sizeof(char)*600);
    return p;
}
 
void push(char n)
{
    Stack *q=alloc();
 
    if (!full()) {
        if (top == NULL) {
            top = q;
            *(q->data) = n;
            *(++q->data) = '\0';
            q->next = NULL;
        } else {
            q->next = top;
            top = q;
            *(q->data) = n;
            *(++q->data) = '\0';
        }
    } else
        printf("Stack overflow !\n");
}
 
int empty(void)
{
    return (top == NULL) ? TRUE : FALSE;
}
 
int full(void)
{
    int state;
    Stack *t=alloc();
    (state=(t == NULL)) ? TRUE : FALSE;
    free((Stack *) t);
    return state;
}
 
char pop(void)
{
    Stack *new_top;
    char x;
 
    if (empty());
    x = *(--top->data);
    new_top = top->next;
    free((Stack *) top);
    top = new_top;
    return x;
}
 
int validate(void)
{
    Stack *q=alloc();
    char x;
 
    puts("Enter a string: ");
    fgets(q->data, 600, stdin);
    printf("%s\n", q->data);
 
    while (*(q->data)) {
        if (*(q->data) == '(' || *(q->data) == '[' || *(q->data) =='{')
            push(*(q->data));
        if (*(q->data) == ')' || *(q->data) == ']' || *(q->data) =='}') {
            if (empty())
                return FALSE;
            x = pop();
            if (x > *(q->data) || *(q->data)-x > 2)
                return FALSE;
        }
        (q->data)++;
    }
    return (empty()) ? TRUE : FALSE;
}
 

int isbalance(char *exp)
{
    Stack *t;
    int i ;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='{'||exp[i]=='('||exp[i]=='[')
            {
                push(exp[i]);
            }
        else
        {
            if(exp[i]=='}'||exp[i]==')'||exp[i]==']')
            {
                    t=top;
                    if(exp[i]==93)
                    {
                        if(exp[i] - *t->data == 2)
                        {
                            pop();
                        }
                    }
                    else if(exp[i]==125)
                    {
                        if(exp[i] - *t->data == 2)
                        {
                            pop();
                        }
                    }
                    else if(exp[i]==41)
                    {
                        if(exp[i] - *t->data == 1)
                            pop();
                    }
            }
        }
    }
    if(top==NULL)
            return 1;
        else
            return 0;
}


int main(void)
{
    int i=0, valid=0, invalid=0;
    while (i++ < 1000) {
        if (validate() == TRUE) {
            puts("Parentheses are balanced");
            valid++;
        } else {
            puts("Parentheses are not balanced");
            invalid++;
        }
    }
    printf("Total valid: %d || Total invalid: %d\n", valid, invalid);
    return 0;
}