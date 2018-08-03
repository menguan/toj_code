#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
 double x1, y1, x2, y2, x3, y3;
 cin >> x1 >> y1 >> x2 >> y2;
 cout.precision(3);
 while(cin >> x3 >> y3)
   if(4*((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1)) < (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2)){
    cout << "The gopher can escape through the hole at (" << fixed << x3 << ',' << y3 << ").\n";
    return 0;
   }
 cout << "The gopher cannot escape.\n";
 return 0;
}