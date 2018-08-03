#include<stdio.h>//又学了一个法雷数列 
int n;
bool ok;
void dfs(int a,int b,int c,int d)
{
   if(b+d>n)
    return ;
   int ac=a+c;
   int bd=b+d;
   dfs(a,b,ac,bd); 
   if(ok)
   {
    printf(",%d/%d",ac,bd);
   }
   else
   {
    ok=true;
    printf("%d/%d",ac,bd);
   }
   dfs(ac,bd,c,d); 

}
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
    ok=false;
    scanf("%d",&n);
    dfs(0,1,1,1);
    printf("\n");
   }
   return 0;
} 