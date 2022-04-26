#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Fi(int N);

int main()
{
	int n;
	scanf("%d", &n);

	printf("%d", Fi(n));


	return 0;
}
int Fi(int n)
{
	int res;

	if (n == 0)
	{
		res = 0;
	}
	else if (n == 1)
	{
		res = 1;
	}
	else
	{
		res = Fi(n - 1) + Fi(n - 2);
	}

	return res;
	
}



