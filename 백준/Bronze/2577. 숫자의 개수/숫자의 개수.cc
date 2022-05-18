#include<iostream>

using namespace std;

int main()
{
	int iArr[10] = {0};
	int A, B, C;
	int iSum;
	int i = 1;
	int N;
	
	cin >> A >> B >> C;

	iSum = A * B * C;

	while (iSum/i != 0)
	{
		N = iSum % (i * 10);
		N /= i;
		iArr[N] +=1;
		i *= 10;
	}

	for (int j = 0; j < 10; ++j)
	{
		cout << iArr[j] << endl;
	}
}