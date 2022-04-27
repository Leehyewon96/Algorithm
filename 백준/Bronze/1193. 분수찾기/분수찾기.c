#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int X;
	scanf("%d", &X);

	int cnt = 0, sum = 0; // cnt 줄수, sum X보다 작은수
	for (int i = 1; sum < X; i++)
	{
		sum += i;
		cnt++;
	}
	
	if ((cnt - 1) % 2 != 0)
	{
		printf("%d/%d", X - sum + cnt, sum - X + 1);
	}
	else
	{
		printf("%d/%d", sum - X + 1, X - sum + cnt);
	}
	return 0;
}
