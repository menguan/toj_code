#include<iostream>
using namespace std;
#define max 202
#define bignum 100000
int a[max][max];
void Read(int m,int n)
{
int i,j,v1,v2,weight;
for(i=0;i<m;i++)
for(j=0;j<m;j++)
if(i==j)a[i][j]=0;
else
                a[i][j]=bignum;
for(i=1;i<=n;i++)
{
                cin>>v1>>v2>>weight;
if(weight<a[v1][v2])
{
                    a[v1][v2]=weight;a[v2][v1]=weight;
}
}
}
void Floyd(int m)
{
int i,j,k;
for(k=0;k<m;k++)
for(i=0;i<m;i++)
for(j=0;j<m;j++)
if(a[i][k]+a[k][j]<a[i][j])
                    a[i][j]=a[i][k]+a[k][j];
}
int main()
{
int m,n,k,i,j;
int flag;
int answer;
while(cin>>m>>n,m!=0&&n!=0)
{
        Read(m,n);
        cin>>k;
        Floyd(m);
for(j=1;j<=k+1;j++)
{
            answer=bignum-1;
for(i=0;i<m;i++)
if(answer>a[0][i])
{
                    answer=a[0][i];
                    flag=i;
}
                a[0][flag]=bignum;
}
        cout<<flag<<endl;
}
return 0;
}
