#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int ta=0;
        int tb=0;
        int n;
        int tmp;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            if(tmp)
            {
                if(i%2) ta++;
                else tb++;
            }
        }
        if(n%2||abs(ta-tb)<=1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
