#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1,j=0;
char postfix[100];



void push(char a);

void push(char a)
{

  if (top == 99)
  {
    printf("over flow");
  }
  else
  {
    top = top + 1;
    stack[top] = a;
  }
} 

char pop();

char pop()
{

  char b;
  if (top == -1)
    printf("underflow");
  else
    b = stack[top];
  top = top - 1;
  return b;
}

int priority(char d);

int priority(char d)
{

  if (d == '-' || d == '+')
    return 1;
  else if (d == '/' || d == '*')
    return 2;
  else
    return 0;
}


void check(char x);

void check(char x)
{

  if (x == '(')
  {
    push(x);
  }
  else if (x == '+' || x == '-' || x == '/' || x == '*')
  {
    while (priority(stack[top]) >= priority(x))
    {
      postfix[j] = pop();
      j++;
    }
    push(x);
  }
  else if (x == ')')
  {

    while (stack[top] != '(')
    {
      postfix[j] = pop();
      j++;
    }
    pop();
    if(top!=-1)
     push('*');
    
  }
  else
  {
    postfix[j] = x;
    j++;
  }
}



void main()
{
  char exp[100];
  int i = 0;
  printf("enter the expression : ");
  scanf("%s", exp);
  strcat(exp, ")");
  push('(');
  while (exp[i] != '\0')
  {
   check(exp[i]);
    i++;
  }
  postfix[j]='\0';
  printf("The postfix expression is : %s\n",postfix);
  
}