#include<stdio.h>
int ans[128]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,23,76,102,15,85,65,138,91,12,117,120,345,35,37,217,114,110,105,378,126,6270,12,513,1116,770,86,51,30,693,180,930,559,858,495,11067,714,455,378,84,105,12,236,7095,255,60,4524,3848,1530,1955,268,714,25389,1155,9360,2006,805,4446,1122,540,36,570,1026,11033,1218,6580,312,301,3367,42780,2550,550,1365,6630,105,861,4514,291,3960,1464,1577,4284,5187,126,17094,15330,1785,43890,25872,5762,3325,204,3420,78120,1224,776,273,108855,174,14430,80080,2415};
int main()
{
    int n;
   while(~scanf("%d",&n)&&n)
   {
      printf("%d balls cycle after %d days.\n",n,ans[n]);                      
   }
}          
