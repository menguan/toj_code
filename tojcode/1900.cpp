#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int h[1000];
int main()
{
    int cas=1;int m,n;double water;
    while(cin>>n>>m&&(m+n))
    {
        n*=m;
        for(int i=0;i<n;i++)
        {

                cin>>h[i];

        }
        cin>>water;
        sort(h,h+n);
        double nowh=h[0];
        int s=0;
        if(water>0)
        {
            for(s=1;s<n;s++)
            {
                while(s<n&&h[s]==h[s-1])
                    s++;
                if(s==n||water<=s*100*(h[s]-h[s-1]))
                    break;
                water-=s*(h[s]-h[s-1])*100;
            }
            nowh=h[s-1];
        }
       // if(water>0)
        //{

       //while(s<n&&h[s]==h[s-1])
         //           s++;
           nowh+=water/(s*100.0);
        //}
        //cout<<s<<""<<n<<endl;
        printf("Region %d\n",cas++);
        printf("Water level is %.2f meters.\n%.2f percent of the region is under water.\n\n",nowh,100.0*s/n);
    }
}
