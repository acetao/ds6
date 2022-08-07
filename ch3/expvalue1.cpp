//求简单表达式的值
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MaxSize 100
//---------------------------------------------------------
//--运算符栈基本运算---------------------------------------
//---------------------------------------------------------
//---------------------------------------------------------

char* trans(char *exp)					//将算术表达式exp转换成后缀表达式postexp
{
	int n = strlen(exp);
	char *data = (char*)malloc(n * sizeof(char));	//data模拟运算符栈
	int top = -1;									//初始化运算符栈
	char* postexp = (char*)malloc(2 * n * sizeof(char));	//存放后缀表达式
	char e;
	int i = 0, j = 0;						//i遍历exp,j作为postexp的下标
	while (i < n)							//exp表达式未扫描完时循环
	{
		switch (exp[i])
		{
		case ' ': i++; break;				//跳过空格
		case '(':						//判定为左括号
			top++; data[top] = exp[i++];				//左括号进栈
			break;
		case ')':						//判定为右括号
			e = data[top]; top--;			//出栈元素e
			while (e != '(')				//不为'('时循环
			{
				postexp[j++] = e;			//将e存放到postexp中
				e = data[top]; top--;			//继续出栈元素e
			}
			i++;						//继续扫描其他字符
			break;
		case '+':						//判定为加或减号
		case '-':
			while (top != -1)	          //栈不空循环
			{
				e = data[top];			//取栈顶元素e
				if (e != '(')				//e不是'('
				{
					postexp[j++] = e;		//将e存放到postexp中
					e = data[top]; top--;		//出栈元素e
				}
				else					//e是'(时退出循环
					break;
			}
			top++; data[top] = exp[i++];			//将'+'或'-'进栈
			break;
		case '*':						//判定为'*'或'/'号
		case '/':
			while (top != -1)	//栈不空循环
			{
				e = data[top];			//取栈顶元素e
				if (e == '*' || e == '/')	//将栈顶'*'或'/'运算符出栈并存放到postexp中
				{
					postexp[j++] = e;		//将e存放到postexp中
					e = data[top]; top--;		//出栈元素e
				}
				else					//e为非'*'或'/'运算符时退出循环
					break;
			}
			top++; data[top] = exp[i++];		//将'*'或'/'进栈
			break;
		default:				//处理数字字符
			while (exp[i] >= '0' && exp[i] <= '9') //判定为数字
			{
				if (exp[i] == ' ')
				{
					i++;
					continue;
				}
				postexp[j++] = exp[i++];
			}
			postexp[j++] = '#';	//用#标识一个数值串结束
		}
	}
	while (top != -1)	//此时exp扫描完毕,栈不空时循环
	{
		e = data[top]; top--;		//出栈元素e
		postexp[j++] = e;			//将e存放到postexp中
	}
	postexp[j] = '\0';			//给postexp表达式添加结束标识
	free(data);		//销毁栈
	return postexp;
}
//---------------------------------------------------------
//--操作数栈基本运算---------------------------------------

int compvalue(char *postexp)	//计算后缀表达式的值
{
	long a, b, c, d, e;
	int n = strlen(postexp);
	int *data = (int*)malloc(n * sizeof(int));	//data模拟运算数栈
	int top = -1;								//初始化运算数栈
	int i = 0;							  //i遍历postexp
	while (postexp[i])		                //postexp字符串未扫描完时循环
	{
		switch (postexp[i])
		{
		case '+':						//判定为'+'号
			a = data[top]; top--;			//出栈元素a
			b = data[top]; top--;			//出栈元素b
			c = b + a;						//计算c
			top++; data[top] = c;			//将计算结果c进栈
			break;

		case '-':						//判定为'-'号
			a = data[top]; top--;			//出栈元素a
			b = data[top]; top--;			//出栈元素b
			c = b - a;						//计算c
			top++; data[top] = c;			//将计算结果c进栈
			break;

		case '*':						//判定为'*'号
			a = data[top]; top--;			//出栈元素a
			b = data[top]; top--;			//出栈元素b
			c = b * a;						//计算c
			top++; data[top] = c;			//将计算结果c进栈
			break;

		case '/':						//判定为'/'号
			a = data[top]; top--;			//出栈元素a
			b = data[top]; top--;			//出栈元素b
			c = b / a;						//计算c
			top++; data[top] = c;			//将计算结果c进栈
			break;

		default:				//处理数字字符
			d = 0;				//将连续的数字字符转换成对应的数值存放到d中
			while (i < n && postexp[i] >= '0' && postexp[i] <= '9') //判定为数字字符
			{	d = 10 * d + postexp[i] - '0';
				i++;
			}
			top++; data[top] = d;		//将数值d进栈
			break;
		}
		i++;				//继续处理其他字符
	}
	e = data[top];			//取栈顶元素e
	free(data);		        //销毁栈
	return e;					//返回e
}

int calculate(char* s)
{
	if (strlen(s) == 1) return s[0] - '0';
	char* postexp;
	postexp = trans(s);
	return compvalue(postexp);
}
int main()
{
	char exp[] = "2147483647";
	char* postexp;
	postexp = trans(exp);
	printf("中缀表达式:%s\n", exp);
	printf("后缀表达式:%s\n", postexp);
	printf("表达式的值:%d\n", compvalue(postexp));
	return 0;
}
