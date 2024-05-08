#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


enum Weekday
{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};
int main()
{
	enum Wednesday today;

	//给枚举变量赋值
	today = Wednesday;
	printf("Today is %d\n", today);
	
	return 0;
}