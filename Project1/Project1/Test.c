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
	printf("������һ������:");

	scanf("%d", &num);
	
	if (num < 0)
	{
		printf("������һ���Ǹ�����");
	}
	else
	{
		int result = factorial(num);
		printf("%d �Ľ׳��� %d\n", num, result);
	}
	return 0;
}