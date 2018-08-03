#include<iostream>
using namespace std;
int main()
{
    int r,w,l,count=1;
    while(cin>>r,r)
    {
        cin>>w>>l;
        if(w*0.5*w*0.5+l*0.5*l*0.5<=r*r*1.0)
          cout<<"Pizza "<<count<<" fits on the table."<<endl;
        else
          cout<<"Pizza "<<count<<" does not fit on the table."<<endl;
        count++;
    }
    return 0;
} 