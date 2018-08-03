#include <iostream>
#include <cmath>
#include <cstdio>
#define eps 1e-7
using namespace std;

double cx, cy, R, x1, y11, x2, y2, x3, y3, dis, l1, l2;
double dist(double xx1, double yy1, double xx2, double yy2)
{
	return sqrt((xx1 - xx2) * (xx1 - xx2) + (yy1 - yy2) * (yy1 - yy2));
}

bool side()
{
	double ex1 = x1 - x3; 
	double ey1 = y11 - y3;
	double ex2 = x2 - x3;
	double ey2 = y2 - y3;
	return (ex1 * ex2 + ey1 * ey2) < 0;
}
bool ok()
{
	if ((l1 < R && l2 > R) || (l1 > R && l2 < R)) return true;
	if (l1 >= R && l2 >= R && dis < R && side()) return true;
	return false;
}

int main()
{
	int cas, flag;
	
	cin >> cas;
	while (cas--)
	{
		cin >> cx >> cy >> R >> x1 >> y11 >> x2 >> y2;
		l1 = dist(cx, cy, x1, y11);
		l2 = dist(cx, cy, x2, y2);
		if (l1 <= R && l2 <= R)
		{
			cout<<"All in"<<endl;
			continue ;
		}
		if (abs(x1 - x2) < eps) x3 = x1, y3 = cy;
		else 
		{
			double k = (y2 - y11) / (x2 - x1);
			double b = y11 - k * x1;
			x3 = (k * cy + cx - k * b) / (k * k + 1);
			y3 = k * x3 + b;
		}
		dis = dist(cx, cy, x3, y3);
		if (ok()) cout<<"Part in"<<endl;
		else cout<<"All out"<<endl;
	}
} 
