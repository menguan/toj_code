#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t;
    int x[4],y[4];
    cin>>t;
    while(t--)
    {
        for(int i=0;i<4;i++)
            cin>>x[i]>>y[i];
        if(x[0]<=x[2]&&y[0]<=y[2]&&x[1]>=x[3]&&y[1]>=y[3])
            cout<<"A surrounds B"<<endl;
        else if(x[0]>=x[2]&&y[0]>=y[2]&&x[1]<=x[3]&&y[1]<=y[3])
            cout<<"B surrounds A"<<endl;
        else if(x[0]>=x[3]||y[0]>=y[3]||x[2]>=x[1]||y[2]>=y[1])
            cout<<"A and B do not overlap"<<endl;
        else
            cout<<"A and B overlap"<<endl;
    }
}
