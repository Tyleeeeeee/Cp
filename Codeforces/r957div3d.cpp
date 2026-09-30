#include<iostream>
#include<string>
using namespace std;

string s;
int n,m,k;
bool dfs(int i,int j,int lk)
{
    if(i>=j) return true;
    if(s[i]=='C') return false;
    if(s[i]=='L'){
        int tmp=i+m;
        while(tmp>i){
           if(tmp>=j) return true;
           if(s[tmp]=='L' && dfs(tmp,j,lk)) return true;
           tmp--;
        }
        return dfs(i+m,j,lk);
    }
    if(s[i]=='W' && lk>0){ lk--;
        if(k>0) return dfs(i+1,j,lk);
        else return false;
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--&&cin>>n>>m>>k>>s){ s.insert(0,1,'L');
        cout << (dfs(0,s.length(),k)?"YES":"NO") << "\n";
    }
}

