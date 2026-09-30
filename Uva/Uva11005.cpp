#include<iostream>
#include<vector>
using namespace std;

int countPr(int based,int N,vector<int> &pr)
{
    int ans=0;
    while(N)
    {
        ans+=pr[N%based];
        N/=based;
    }
    return ans;
}
int main()
{
    int t,counter,cs,based,N;
    long long int min;
    while(cin >> t)
    {
        counter=0;
        while(t--)
        {
            vector<int> pr(36);
            for(int i=0;i<36;++i) cin>>pr[i];
            cin >> cs;    
            cout << "Case " << ++counter << ":\n";
            while(cs--)
            {
                cin >> N;
                min=2000000000;
                vector<int> cost(36);
                for(based=36;based>=2;--based)
                {
                    cost[based-1]=countPr(based,N,pr);
                    if(countPr(based,N,pr)<min) min=countPr(based,N,pr);
                }
                                cout << "Cheapest base(s) for number " << N << ":";
                for(int i=1;i<36;++i)
                {
                    if(cost[i]==min) cout << " " << i+1;
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }
}

