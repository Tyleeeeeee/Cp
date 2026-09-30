#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int t,n,carry,st;
    while(cin >> t)
    {
        while(t-- && cin >> n)
        {
            st=carry=0;
            vector<int> num1(n,0),num2(n,0);
            for(int q=n-1;q>=0;--q)
            {
                cin >> num1[q] >> num2[q];
            }
            transform(num1.begin(),num1.end(),num2.begin(),num2.begin(),[&carry](int n1,int n2){
                            int ans=(n1+n2+carry)%10;
                            carry=(n1+n2+carry)>9?1:0;
                            return ans;
                    });
            if(carry) cout << carry ;
            for(int q=n-1;q>=0;--q)
            {
                cout << num2[q];
            }
            cout << "\n\n";
        }
    }
}

