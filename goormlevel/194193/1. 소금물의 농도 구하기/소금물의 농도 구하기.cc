#include <iostream>
#include <cmath>

using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	double salt = 0.07 * N;
	double saltWater = N + M;
	double density = (salt / saltWater) *100;
	double ans = floor(density * 100) / 100;
	cout << fixed;
	cout.precision(2);
	cout << ans;
	
	return 0;
}