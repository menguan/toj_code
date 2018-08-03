#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a;
    cin>>a;
    kk:while(a--)
    {
        int b,c;
        cin>>b>>c;
        int d[c];
        for(int i=0;i<c;i++)
            cin>>d[i];
            
        sort(d,d+c);
        int sum=0;
        for(int i=0;i<c;i++)
        {
            sum+=d[i];
            if(sum>b)
            {
              cout<<i<<endl;
              goto kk;
            }
        }
        cout<<c<<endl;
     }
     return 0;
}