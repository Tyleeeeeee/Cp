#include<iostream>
using namespace std;

int main()
{
    int t,n,maxid,ct;
    long long tmp,sum,cur,max,sc;
    cin>>t;
    while(t--&&cin>>n){ maxid=ct=cur=max=sum=0,sc=-1e9-1;
        for(int q=0;q<n;++q){
            cin>>tmp;
            sc=tmp>sc?tmp:sc;
            sum+=tmp;
            cur+=tmp;
            cur=cur>0?cur:0;
            ct=cur>0?ct+1:0;
            if(cur>max) max=cur,maxid=ct;
        }
        if(!max)max=sc;
        cout << ((sum>max)||(maxid==n)?"YES":"NO") << "\n";
    }
}

