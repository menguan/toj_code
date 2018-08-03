#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n;
    while(cin>>n,n)
    {
        int odd=0;int t;
        for(int i=0;i<n;i++)
        {
            cin>>t;
            if(t%2==1)odd++;
        }
        if(odd>n-odd&&n%2==1)cout<<"Justice will prevail over evil."<<endl;
        else if(odd<n-odd&&n%2==0)cout<<"While the priest climbs a post, the devil climbs ten."<<endl;
        else cout<<"I love this world."<<endl;
    }

}
