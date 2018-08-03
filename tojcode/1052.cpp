#include<cstdio>//模拟退火法  新学的算法
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define sqr(x) (x)*(x)
using namespace std;

int n,dir[4][2]={0,1,0,-1,1,0,-1,0};
struct point
{
	double x,y;
	point()
	{x=y=0;}
	point(double a,double b)
	{x=a;y=b;}
}p[1005],ans,tmp,st;
double dis(point a)
{
	double s=1e9;
	for(int i=0;i<n;i++)
		s=min(s,sqr(a.x-p[i].x)+sqr(a.y-p[i].y));
	return s;
}
int main()
{
	int i,f;
	double x,y,xx,yy;
	scanf("%*d");
	while(~scanf("%lf%lf%d",&x,&y,&n))
	{
		double step=200,mid=0,t;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		st=p[0];
		while(step>0.01)
		{
			f=1;
			while(f)
			{
				ans=st;
				for(f=0,i=0;i<4;i++)
				{
					xx=st.x+step*dir[i][0];
					yy=st.y+step*dir[i][1];
					if(xx<0||yy<0||xx>x||yy>y)
						continue;
					tmp=point(xx,yy);
					t=dis(tmp);
					if(t>mid)
					{

						mid=t;
						f=1;
						ans=tmp;
					}
				}
				st=ans;
			}
			step*=0.8;
		}
		printf("The safest point is (%.1f, %.1f).\n",ans.x+0.005,ans.y+0.005);
	}
}
