#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct f
{
    int x,y;
}car[3000];
int now[100];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int h,l;
        int cnt=0;
        memset(now,0,sizeof(now));
        cin>>h>>l;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<l;j++)
            {
                int y;
                cin>>y;
                if(y!=-1)
                {
                    car[y].x=i;
                    car[y].y=j;
                    cnt++;
                }
            }
        }
        int ans=0;
        int dd=cnt;
        for(int i=1;i<=dd;i++)
        {
            cnt=i;
            ans+=car[cnt].x*20;
            int tt=min(abs(car[cnt].y-now[car[cnt].x]),l-abs(car[cnt].y-now[car[cnt].x]));
            ans+=tt*5;
            now[car[cnt].x]=car[cnt].y;
            //cnt--;
        }
        cout<<ans<<endl;
    }
}
