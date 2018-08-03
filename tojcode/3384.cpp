#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n,p,q;
    while(cin>>n>>p>>q)
    {
         if(n%(p+q)&&n%(p+q)<=p)
           cout<<"LOST"<<endl;
         else
           cout<<"WIN"<<endl;
    }
}
                           
