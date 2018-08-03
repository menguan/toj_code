#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
#define PI acos(-1.0)
int main()
{
	int t;bool flag;
	double a, b, x, y;
	double i, rad;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf", &a, &b, &x, &y);

		if (a < b) swap(a, b);
		if (x < y) swap(x, y);
		flag = 0;
		for (i = 0; i <= 90; i += 0.1)
		{
			rad = PI * i / 180;
			if ((x * cos(rad) + y * sin(rad) < a) && (x * sin(rad) + y * cos(rad) < b))
			{
				puts("Escape is possible.");
				flag = 1;
				break;
			}
		}
		if (!flag) puts("Box cannot be dropped.");
	}
}
