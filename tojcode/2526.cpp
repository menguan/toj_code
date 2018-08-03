#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double a,b;
    while(cin>>a>>b)
    {
        if(a==0&&b==0)
          return 0;
        double c=1;
        while(abs(pow(c,b)-a)>abs(pow(c+1,b)-a))
            c+=1;
        
        cout<<(int)c<<endl;
    }
    return 0;
} 