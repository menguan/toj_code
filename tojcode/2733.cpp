#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
    long long v,w,id;
    double ra;
    friend bool operator<(node aa,node bb)
    {
        return aa.ra>bb.ra;
    }
}a[100010];
int n,k;
double fun()
{
    int sv=0,sw=0;
    for(int i=1;i<=k;i++)
    {
        sv+=a[i].v;
        sw+=a[i].w;
    }
    return sv*1.0/sw;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].v>>a[i].w;
        a[i].id=i;
        a[i].ra=a[i].v*1.0/a[i].w;
    }
    double t1,t2=0;
    t1=fun();
    while(fabs(t1-t2)>0.00000001)
	{
		t2=t1;
		for(int i=1;i<=n;i++)
			a[i].ra=a[i].v-t2*a[i].w;
		sort(a+1,a+n+1);
		t1=fun();
	}
    for(int i=1;i<=k;i++)
    {
        if(i!=1)cout<<" ";
        cout<<a[i].id;
    }
    cout<<endl;
}
