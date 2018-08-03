#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
int i,j,k,m,n;
int a[51];
scanf("%d",&n);
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
sort(a+1,a+n+1);
int sum=0;
while(1)
{
if(n==1){sum+=a[1];break;}
if(n==2){sum+=a[2];break;}
if(n==3){sum+=a[3]+a[1]+a[2];break;}
if(2*a[2]>a[1]+a[n-1])
sum+=a[n]+a[1]+a[n-1]+a[1];
else if(2*a[2]<a[1]+a[n-1])
sum+=a[2]+a[1]+a[n]+a[2];
else sum+=a[n]+a[1]+a[n-1]+a[1];
n-=2;
}
printf("%d\n",sum);
//while(1);
}