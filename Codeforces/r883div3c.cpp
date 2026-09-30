#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

int bns(long long *arr,int h,int n)
{
    int i=0,j=n-1,mid;
    while(i<=j){ mid=(i+j)/2;
        if(arr[mid]<=h) i=mid+1;
        else j=mid-1;
    }
    return i;
}
int main()
{
    int t,n,m,h;
    cin>>t;
    while(t--&&cin>>n>>m>>h){ long long val[n][m]; pair<int,pair<long long,int>> arr[n];
        for(int q=0;q<n;++q) for(int w=0;w<m;++w) cin>>val[q][w];
        for(int q=0;q<n;++q) sort(val[q],val[q]+m);
        for(int q=0;q<n;++q){
            for(int w=1;w<m;++w){
                val[q][w]+=val[q][w-1]; 
            }
        }
        for(int q=0;q<n;++q){ long long tmp=0;
            arr[q].first=bns(val[q],h,m);
            for(int w=0;w<bns(val[q],h,m);++w) tmp+=val[q][w];
            arr[q].second.first=tmp;
            arr[q].second.second=!q?1:0;
        }
        sort(arr,arr+n,[](auto a,auto b){
                    if(a.first!=b.first) return a.first>b.first;
                    else{
                        if(a.second.first!=b.second.first) return a.second.first<b.second.first;
                        else return a.second.second>b.second.second;
                    }
                });
        for(int q=0;q<n;++q){
            if(arr[q].second.second) cout << q+1 << "\n";
        }
    }
}

