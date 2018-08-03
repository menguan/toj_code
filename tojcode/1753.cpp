#include<iostream>
using namespace std;
long long ham[1000000];
int main()
{
    long long a,b,c,temp1,temp2,temp3;
    int i,j,k,t,n;
    cin>>a>>b>>c>>n;
    ham[0]=1;k=0;
    i=0;j=0;t=0;
    temp1=ham[i]*a;
    temp2=ham[j]*b;
    temp3=ham[t]*c;
    while(k<=n)
    {
        //cout<<temp1<<" "<<temp2<<" "<<temp3<<endl;;
        if(temp1<temp2&&temp1<temp3)
        {
            k++;ham[k]=temp1;i++;
            temp1=ham[i]*a;
        }
        else if(temp2<temp1&&temp2<temp3)
        {
            k++;ham[k]=temp2;
            j++;temp2=ham[j]*b;
            while(temp2%a==0)
            {
                j++;temp2=ham[j]*b;
            }
        }
        else 
        {
            k++;ham[k]=temp3;
            t++;temp3=ham[t]*c;
            while(temp3%a==0||temp3%b==0)
            {
                t++;temp3=ham[t]*c;
            }
        }
    }
    cout<<ham[n]<<endl;
    //while(1);
}