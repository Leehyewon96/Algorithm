#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int A, B, C, count = 0;
	int cnt[10] = {0};
	int a;
	scanf("%d %d %d", &A, &B, &C);

	int mul = A * B * C;

	while (mul != 0) //마지막 걸리는게 1
	{
		a = mul % 10;
	
		cnt[a] += 1;

		mul /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", cnt[i]);
	}

	return 0;
}