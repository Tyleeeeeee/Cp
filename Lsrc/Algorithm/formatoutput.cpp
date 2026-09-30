#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    //              setfill is fill
    //              up the blank with
    //              your argument               fixed is used to fixed the precision
    cout << left << setfill('*') << setw(10) << fixed <<  setprecision(3) << 3.14159 << "\n";
    //   allign to                  setup the black         設置精度因為setprecision會進行
    //   lefthand side              used                    rounding因此若要輸出指定位數需要
    //   if want to                                         加上"fixed"
    //   righthandside use
    //   "right"
    //    
}

