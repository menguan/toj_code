#include <iostream>
#include <algorithm>
using namespace std;
int grades[6];
int main()
{
    int i,sum;
    double ave;
    while (cin>>grades[0]>>grades[1]>>grades[2]>>grades[3]>>grades[4]>>grades[5])
    {
          if (grades[0] == 0 && grades[1] == 0 && grades[2] == 0 && grades[3] == 0 && grades[4] == 0 && grades[5] == 0)  break;
          sum=0;
          sort(grades, grades+6);
          for (i = 1; i < 5; i++)
              sum += grades[i];
          ave=sum*1.0/4*1.0;
          cout<<ave<<endl;
    }
    
    
}
