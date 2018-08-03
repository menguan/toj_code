#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        int time,t1,t2;
        cin>>time>>t1>>t2;
        int fish[time];
        int sum=0;
        for(int i=0;i<time;i++)
        {
            cin>>fish[i];
            sum+=fish[i];
        }
        int max=0;
        
        for(int i=0;i<time-t2-t1+1;i++)
        {
            for(int j=i+t1;j<time-t2+1;j++)
            {
                int k=0;
                for(int ii=i;ii<i+t1;ii++)
                {
                    k+=fish[ii];
                }
                for(int jj=j;jj<j+t2;jj++)
                {
                    k+=fish[jj];
                } 
                int k_=sum-k;
                if(k_>max)
                  max=k_;
            }
        }
        cout<<max<<endl;
    }
    return 0;
} 