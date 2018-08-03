#include<cstdio>
#include<cstring>
int main()
{
    int n;
    bool flag;
    double d;
    int id;
    char h,m1,m2,s1,s2;
    scanf("%d",&n);
    scanf("%lf",&d);
    while(scanf("%d",&id)!=EOF)
    {
        flag=true;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            getchar();
            scanf("%c:%c%c:%c%c",&h,&m1,&m2,&s1,&s2);
            if(h=='-') flag=false;
            if(flag==false)continue;
            sum+=(h-'0')*3600+((m1-'0')*10+(m2-'0'))*60+(s1-'0')*10+(s2-'0');
        }
        printf("%3d: ",id);
        if(flag==false)printf("-\n");
        else
        {
            int t=(int)(sum/d+0.5);
            printf("%d:%02d min/km\n",t/60,t%60);

        }
    }
}
