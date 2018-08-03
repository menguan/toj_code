#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long cat[100];
void fun(int pos,int num)
{
    if(pos==1)
    {
        cout<<"X";
        return ;
    }
    if(num<=cat[pos-1])
    {
        cout<<"X(";
        fun(pos-1,num);
        cout<<")";
    }
    else if(num>cat[pos]-cat[pos-1])
    {
        cout<<"(";
        fun(pos-1,num-cat[pos]+cat[pos-1]);
        cout<<")X";
    }
    else
    {
        for(int i=pos-1;i>=0;i--)
        {
            if(cat[i]*cat[pos-i-1]<num)
                num-=cat[i]*cat[pos-i-1];
            else
            {
                cout<<"(";
                fun(pos-i-1,num/cat[i]+(num%cat[i]+cat[i]-1)/cat[i]);
                cout<<")X(";
                fun(i,(num-1)%cat[i]+1);
                cout<<")";
                break;
            }
        }
    }
}
int main()
{
    cat[0]=1;
    for(int i=1;i<=25;i++)
    {
        cat[i]=cat[i-1]*(4*i-2)/(i+1);
    }
    int n;
    while(cin>>n,n)
    {
        for(int i=1;i<=25;i++)
        {
            if(n>cat[i])
                n-=cat[i];
            else
            {
               fun(i,n);
               cout<<endl;
               break;
            }
        }
    }
}
