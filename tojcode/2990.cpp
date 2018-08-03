#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        int m;
        cin>>m;
        int mm[m];
        for(int i=0;i<m;i++)
            cin>>mm[i];
        int n;
        cin>>n;
        int nn[n];
        for(int i=0;i<n;i++)
            cin>>nn[i];
        int sum=0;
        for(int i=0;i<m;i++)
        {
          for(int j=0;j<n;j++)
          {
              if(mm[i]+nn[j]==0)
              sum++;
          }
        }
        cout<<sum<<endl;
     }
     return 0;
} 