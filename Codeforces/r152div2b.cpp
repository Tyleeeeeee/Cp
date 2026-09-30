#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    cin.tie(0),ios::sync_with_stdio(false);
    int n;
    string ans;

    cin>>n;
    if(n<3) ans="-1";
    else{
        if(n==3) ans="210";
        else {
        int r,tmp;
        r=10,tmp=n-1;
        while(--tmp){r*=10,r%=210;}
        r=210-r;
        while(r)ans.push_back((r%10)+'0'),r/=10;
        while(ans.size()<n-1) ans.push_back('0');
        ans.push_back('1');
        reverse(ans.begin(),ans.end());
        }
    }
    cout << ans << "\n";
}

