#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int factorial(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return n * factorial(n - 1);
	}
}

int main()
{
	int num;
	printf("请输入一个整数:");

	scanf("%d", &num);
	
	if (num < 0)
	{
		printf("请输入一个非负整数");
	}
	else
	{
		int result = factorial(num);
		printf("%d 的阶乘是 %d\n", num, result);
	}
	return 0;
}