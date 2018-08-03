#include<iostream>
using namespace std;
int main()
{
    int d,i,m,n;
    cin>>d;
    long long b[10]={0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<d;i++)
    {cin>>b[i];}
    
    
    
    for(int j=0;j<d;j++)
    {
    long long a[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(i=0;;i++)
    {
        a[i]=b[j]%2;
        b[j]=b[j]/2;
        if(b[j]==0)break;
    }
    for(n=0;n<=i;n++)
     {
        if(n!=i&&a[n]==1)
        cout<<n<<" ";
        else if(n==i)
        cout<<n;
     }
     cout<<endl;
     }
    
    return 0;
} 