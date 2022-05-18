#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N = 0, M = 0, Max = 0;

	scanf("%d %d", &N, &M);
	int* arr = (int*)calloc(N, sizeof(arr));

	for (int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (j != k && k != i && i != j)
				{
					if (Max < (arr[i] + arr[j] + arr[k]) && (arr[i] + arr[j] + arr[k] <= M))
					{
						Max = arr[i] + arr[j] + arr[k];
					}
				}
			}
			
		}
	}
	printf("%d", Max);
	free(arr);

	return 0;
}