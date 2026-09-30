#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;

int arr[200000];
int main()
{
    cin.tie(0),ios::sync_with_stdio(false);
    int m;
    string s;
    cin>>s>>m;
    int tmp,n;
    n=s.length();
    memset(arr,0,sizeof(arr));
    for(int q=0;q<m;++q){
        cin>>tmp;
        arr[tmp-1]++,arr[n-tmp]++;
    }
    int cnt=0;
    for(int q=0;q<n;++q){
        if(q<ceil(n/2) && arr[q]) cnt+=arr[q];
        if(cnt%2) cout << s[n-q-1];
        else cout << s[q];
        if(q>=ceil(n/2) && arr[q]) cnt-=arr[q];
    }
    cout << "\n";
}

