#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int bns(int *arr,int st,int fn,int fd)
{
    int i,j,mid;
    i=st,j=fn;
    while(i<=j){
        mid=(i+j)/2;
        if(arr[mid]<=fd) i=mid+1;
        else j=mid-1;
    }
    return i-st;
}
void solve(int *arr,int n)
{
    int ans,tmp,ok;
    ans=0,tmp=ok=1;
    while(ok && tmp<=ceil((double)n/2)){
        //bns take index as argument return number of element
        int m,bob;
        bob=0,m=n;
        for(int q=0;q<tmp;++q){
            m=bns(arr,bob,bob+m-1,tmp-q);
            if(m<=0) {ok=0; break;}
            else bob++,m-=2;
        }
        if(ok){ans=max(ans,tmp),tmp++;}
    }
    cout << ans << "\n";
}
int main()
{
    int t,n;
    cin>>t;
    while(t--&&cin>>n){
        int arr[n];
        for(auto&v:arr)cin>>v;
        sort(arr,arr+n);
        solve(arr,n);
    }
}

