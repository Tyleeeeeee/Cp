#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int n,ans1,ans2;
    string s[2];
    cin>>n>>s[0]>>s[1];
    ans1=ans2=0;
    for(int q=0;q<2;++q) sort(s[q].begin(),s[q].end());
    int j,l;
    for(j=l=0;j<n&&l<n;){
        if(s[0][j]<=s[1][l]) ans1++,j++,l++;
        else l++;
    }
    int i,k;
    for(i=k=0;i<n&&k<n;){
        if(s[0][i]<s[1][k]) ans2++,i++,k++;
        else k++;
    }
    cout << n-ans1 << "\n" << ans2 << "\n";
}

