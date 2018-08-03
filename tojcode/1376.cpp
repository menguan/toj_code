#include<stdio.h>
int main()
{
  char time[30];
  int speed=0,nowspeed;
  double distance=0;
  double timeh=0,nowtimeh;int h,m,s;
  while(1) 
  {
    if (!fgets(time,90,stdin))
        break;
    if(sscanf(time,"%d:%d:%d",&h,&m,&s)==-1)
      break;
    if(sscanf(time+8,"%d",&nowspeed ) ==1==1)
    {
      nowtimeh=h+m/60.0+s/3600.0;
      distance+=(nowtimeh-timeh)*speed;
      timeh=nowtimeh;
      speed=nowspeed;
    }
    else
    {
      nowtimeh=h+m/60.0+s/3600.0;
      distance+=(nowtimeh-timeh)*speed;
      timeh=nowtimeh;
      for(int i=0;i<8;i++)
      {
        printf("%c",time[i]);
      }
      printf(" %.2f km\n",distance);
    }
  }
}         