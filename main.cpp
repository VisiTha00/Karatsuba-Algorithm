#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int karatsuba(int x, int y){

   if(x < 10 && y < 10){
    return x*y;
   }
   int n,m,xH,xL,yH,yL,a,b,c;
   n = max(to_string(x).length(),to_string(y).length());
   m = ceil(n/2);
   xH = floor(x/pow(10,m));
   xL = x % (int)pow(10,m);
   yH = floor(y/pow(10,m));
   yL = y % (int)pow(10,m);
   a = karatsuba(xH,yH);
   b = karatsuba(xL,yL);
   c = karatsuba(xH+xL,yH+yL) - a - b;
   return int(a*pow(10,(m*2)) + c*pow(10,m) + b);
}

int main()
{
    cout << karatsuba(14562,78236) << endl;
    return 0;
}
