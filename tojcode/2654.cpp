#include<iostream>//求最小公倍数 
using namespace std;
long long lcm(long long a,long long b)
{
    if(a<b)
    {
      long long temp=b;
      b=a;
      a=temp;
    }  
    long long mul=a*b;
    long long r =a%b;
    while(r)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return mul/b; 
}

int main(){
    int t, n, i;
    long long ans, num;
    cin>>t;
    while(t --)
    {
        cin>>n;
        bool flag = 1;
        ans = 1;
        for(i = 0; i < n; i ++)
        {
            cin>>num;
            if(flag) ans = lcm(ans, num);
            if(ans > 1000000000) flag = 0;
        }
        if(!flag) 
          cout<<"More than a billion."<<endl;
        else 
          cout<<ans<<endl;
    }
    return 0;
}
