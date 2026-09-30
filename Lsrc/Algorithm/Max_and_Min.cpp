#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> vc({1,2,3,4,5});
    cout << *max_element(vc.begin(),vc.end()) << "\n";
}

// max(argument1,argument) max({arg1,arg2,..,argn}) max_element(container.begin(),container.end()) max和min函數是class template也就是說不管什麼數據都可以比但是對於非basic type例如object則需要如下函數 max(obj1,obj2,compare comp) 其中comp是任何可調用對象包括了函數，函數指針，functor，closure object！min函數和max函數是一樣的原型故不贅訴


