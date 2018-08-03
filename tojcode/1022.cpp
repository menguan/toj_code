#include<iostream>
using namespace std;
int a[7];
int main()
{
    while(cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6])
    {
        if(a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0)
          return 0;
          
        int re=0;
        re+=a[6];
        re+=a[5];
        re+=a[4];
        re+=((a[3]+3)/4);
        int left2=a[4]*5;
        switch(a[3]%4)
        {
            case 0:left2+=0;break;
            case 1:left2+=5;break;
            case 2:left2+=3;break;
            case 3:left2+=1;break;
            }
        if(left2<a[2])
          re+=((a[2]-left2+8)/9);                   
        int left1=re*36-a[6]*36-a[5]*25-a[4]*16-a[3]*9-a[2]*4;
        if(left1<a[1])
          re+=((a[1]-left1+35)/36);
        cout<<re<<endl;
        }
}  