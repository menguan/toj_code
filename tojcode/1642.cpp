#include <stdio.h>
int main()
{
    double a;
    int cas=1;
    while(scanf("%lf",&a)!=EOF,a)
    {
        printf("File #%d\nJohn needs %d floppies.\n\n",cas++,(int)(a*0.75/1860000+1));
    }
}
