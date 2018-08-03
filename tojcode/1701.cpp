#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a,count=1;
    cin>>a;
    while(a--)
    {
        int m,n;
        cin>>m>>n;
        int nn[n];
        for(int i=0;i<n;i++)
        {
            cin>>nn[i];
        }
        
        sort(nn,nn+n);
        
        int sum=0;
        for(int i=n-1;i>=0;i--)
        {
            sum+=nn[i];
            if(sum>=m)
            {
              cout<<"Scenario #"<<count<<":"<<endl<<n-i<<endl<<endl;
              break;
            }
            else if(i==0)
              cout<<"Scenario #"<<count<<":"<<endl<<"impossible"<<endl<<endl;
        }
        count++;
    }
    return 0;
}