#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    cin>>t;
    double l1,l2,v1,v2;
    while(t--)
    {
        cin>>l1>>l2>>v1>>v2;

        if(l1<=10) { cout<<0<<endl;continue;}
        double l3=v2*cos(1.0)*1.55741*(l1-10)/v1/sin(1.0);
        l3=min(l2,l3);
        printf("%.0f\n",l3);
    }
}
