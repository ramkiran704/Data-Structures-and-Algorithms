#include<stdio.h>
#include<ctype.h>
#include<math.h>

char stack[50];
int top=-1;
char estack[50];
int etop=-1;
void push( char c ){	
	stack[++top]=c;
}

char pop(){	
	return stack[top--];
}

void epush( int v){	
	estack[++etop]=v;
}

int epop(){	
	return estack[etop--];
}

int precedence(char op){	
	if (op=='^')
		return 3;
	else if (op=='*' || op=='/')
		return 2;
	else if (op=='+' || op=='-')
		return 1;
	return 0;
}

int isoperator(char c){	
	return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

void infix_postfix(char infix[], char postfix[])
{	int i,k=0;
	char c;
	for (i=0; infix[i]!='\0';i++)
	{	c=infix[i];
		if (isdigit(c))
			postfix[k++]=c;
		else if (c=='(')
			push(c);
		else if (c==')')
		{	while (stack[top]!='(' && precedence(stack[top]) >= precedence(c))
			{	postfix[k++]=pop();
			}
			pop();
		}
		else if (isoperator(c))
		{	while (top!=-1 && precedence(stack[top]) >= precedence(c)  )
			{	postfix[k++]=pop();
				if (top==-1 || c=='(')
					break;
			}
			push(c);
		}
	}
	while (top!=-1)
	{	postfix[k++]=pop();
	}
	postfix[k]='\0';
}

int evaluate(char postfix[])
{	int i,op1,op2,result;
	for (i=0;postfix[i]!='\0';i++)
	{	char c=postfix[i];
		if (isdigit(c))
			epush(c-'0');
		else
		{	op2=epop();
			op1=epop();
			switch (c){
            	case '+':result=op1+op2;
					break;
				case '-':result=op1-op2;
					break;
				case '*':result=op1*op2;
					break;
				case '/':result=op1/op2;
					break;
				case '^':result=pow(op1,op2);
					break;
			}
			epush(result);
		}
	}
	return epop();
}

int main()
{	char infix[50],postfix[50];
	printf("enter infix expression: ");
	scanf("%s",infix);
	infix_postfix(infix,postfix);
	printf("postfix expression: %s\n",postfix);
	int result=evaluate(postfix);
	printf("result: %d\n",result);
	return 0;
}