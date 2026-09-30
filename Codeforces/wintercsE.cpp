#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    int k,a,b,n;
    cin>>k>>a>>b>>s;
    n=s.length();
    if(n<k*a || n>k*b) cout << "No solution" << "\n";
    else{
       int lef=n%k;
       int arr[k];
       for(auto&v:arr)v=n/k;
       for(int q=0;q<lef;++q) arr[q]++;
       for(int q=0,i=0,j=0;q<s.length();++q,i++){
            if(i==arr[j]) {
                i=0,j++;
                cout << "\n";
            }
            cout << s[q];
       }
       cout << "\n";
    }
}

