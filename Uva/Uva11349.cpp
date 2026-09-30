#include<vector>
#include<iostream>
using namespace std;

int main()
{
    char c;
    int t,N,ans,counter;
    while(cin >> t)
    {
        cin.get();
        counter=0;
        while(t-- && cin >> c >> c >> N)
        {
           ans=1;
           vector<vector<long long int> > vc(N,vector<long long int>(N)); 
           for(int i=0;i<N;++i)for(int j=0;j<N;++j){cin>>vc[i][j]; if(vc[i][j]<0) ans=0;}
           if(ans)
           {
                for(int i=0;i<(N+1)/2;++i)
                {
                    for(int j=0;j<N;++j)
                    {
                        if(vc[i][N-1-j] != vc[N-1-i][j]) ans=0;
                    }
                }
           }
           cout << "Test #" << ++counter <<": ";
           cout << (ans?"Symmetric.\n":"Non-symmetric.\n");
        }
    }
}

