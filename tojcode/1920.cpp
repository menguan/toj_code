#include<iostream>
using namespace std;
int main()

{
    long double a;
    while(cin>>a&&a!=0.00)
    {
        long double sum=0;
        for(int i=1;i<1000;i++)
        {
            sum+=1.0/(i+1);
            if(sum>=a)
            {
              cout<<i<<" card(s)"<<endl;
              break;
            }
        }
    }
    return 0;
}  