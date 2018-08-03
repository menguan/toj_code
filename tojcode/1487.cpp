#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    long long p;
    while(cin>>p,p)
    {
        if(p==2)
        {
            cout<<"Impossible\n";
            continue;
        }
        vector<int> v(p,1);
        for(long long i=1;i<p;++i) {
            v[i*i%p]=0;
        }
        for(int i=1;i<p;i++)  cout<<v[i];
        cout<<"\n";
    }
}
