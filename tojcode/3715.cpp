#include<iostream>
#include<cstring>
#include<stdio.h>;
using namespace std;
long long a[100000];
int pre[100000];
int main()
{
    int n;
    char c;int num;
    while(cin>>n)
    {
        a[0]=-1;
        pre[0]=-1;
        for(int i=1;i<=n;i++)
        {
            cin>>c;
            if(c=='a')
            {
                cin>>num;
                a[i]=num;
                pre[i]=i-1;
            }
            else if(c=='s')
            {
                a[i]=a[pre[i-1]];
                pre[i]=pre[pre[i-1]];
            }
            else if(c=='t')
            {
                cin>>num;
                a[i]=a[num-1];
                pre[i]=pre[num-1];
            }
            cout<<a[i]<<endl;
        }
    }
}
