#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a;
    cin>>a;
    int y=1;
    while(a--)
    {
        int b;
        cin>>b;
        long long m[b];
        long long n[b];
        for(int i=0;i<b;i++)
        {
            cin>>m[i];
        }
        for(int i=0;i<b;i++)
        {
            cin>>n[i];
        }
        sort(m,m+b);
        sort(n,n+b);
        long long sum=0;
        for(int i=0,j=b-1;i<b;i++,j--)
        {
            sum+=(m[i]*n[j]);
        }
        cout<<"Case #"<<y<<": ";
        y++;
        cout<<sum<<endl;
     }
     return 0;
}     
   