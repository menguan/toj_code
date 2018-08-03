#include<cstring>
#include<iostream>
#define M 10003
using namespace std;
int a[M];
int main()
{
 int i,n,m,j,d,mm1,mm2,ma;
 while(cin>>n>>m)
 {
  if(n==0&&m==0) break;
  ma=0;
  memset(a,0,sizeof(a));
  for(i=0;i<n;i++)
  {
   for(j=0;j<m;j++)
   {
    cin>>d;
    if(d>ma) ma=d;
    a[d-1]++;
   }
  }
  if(a[0]>a[1]) {mm1=a[0];mm2=a[1];}
  else {mm2=a[0];mm1=a[1];}
  for(i=2;i<ma;i++)
  {
   if(a[i]>mm2)
   {
    if(a[i]>mm1)
    {
     mm2=mm1;mm1=a[i];
    }
    else mm2=a[i];
   }
  }
  for(i=0;i<ma;i++)
   if(a[i]==mm2)
  cout<<i+1<< " ";
  cout<<endl;
 }
 return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<set>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<string>

using namespace std;

struct my
{
	int id;
	int rank;
}
 r[10010];

bool cmp(my a,my b)
{
	if  (a.rank!=b.rank)
			return a.rank>b.rank;
	else
		return a.id<b.id;
}

int main()
{
	freopen("in.txt","r",stdin);
	int i,j,k;
	int n;
	int m;
	while (cin>>n>>m,n+m)
	{
		memset(r,0,sizeof(r));
		for (i=0;i<10001;i++)
			r[i].id=i;
		
		for (i=0;i<n*m;i++)
		{
			cin>>k;
			r[k].rank++;
		}

		sort(r,r+10001,cmp);
		//cout<<r[1].id<<' '<<r[1].rank<<endl;
		for (i=1;i<10001;i++)
			if (r[i].rank!=r[i-1].rank)
				break;
		cout<<r[i].id<<' ';

		k=r[i].rank;
		for (i++;i<10001&&r[i].rank==k;i++)
			cout<<r[i].id<<' ';
		
		cout<<endl;
	}
}*/
