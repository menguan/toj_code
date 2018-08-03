#include <stdio.h>
#include <math.h>
#include <algorithm>
int a[30000],stack[30000],num[30000];
int main()
{char ch;
 int i,top,sum=1;
 while (scanf("%d%c",&a[sum],&ch)!=EOF)
 {
     if (ch==' ') ++sum;
     else
     {
       top=1; stack[1]=a[1]; num[1]=0;
    for (i=2;i<=sum;i++)
    {
       if (a[i]+stack[top]==0)
       {--top;
        num[top]=num[top]+abs(a[i]);
        if (top&&(num[top]>=abs(stack[top])))
        {printf(":-( Try again.\n"); goto there;}
       }
       else
       {++top;
        stack[top]=a[i];
        num[top]=0;
       }
    }
     if (top)  printf(":-( Try again.\n");
       else  printf(":-) Matrioshka!\n");
    there :;
    sum=1;
   }
 }
 return 0;
}
