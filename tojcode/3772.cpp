#include <iostream>
using namespace std;

long long int n;
long long int a[10] = {0, 1, 3, 5, 8, 10};
long long int f(long long int m)
{
    if (m <= 5) return a[m];
    long long sum = 0;
    long long int i;
    for (i = 1; i * i <= m; ++i)
        sum += m / i - (i - 1);
    return sum * 2 - i + 1;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << f(n) << endl;
	}
}
