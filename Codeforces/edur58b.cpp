#include<iostream>
#include<string>
using namespace std;

int main()
{
    int ans,i,j,k,l;
    string s;
    ans=-1;
    cin>>s;
    i=s.find('['),j=s.rfind(']');
    if(i!=string::npos && j!=string::npos && i<j){ 
        k=s.find(':',i),l=s.rfind(':',j);
        if(k!=string::npos && l!=string::npos && k<l){ ans=0;
            ans=i+s.length()-1-j+k-1-i+j-1-l;
            for(int q=k+1;q<l;++q){
                if(s[q]!='|') ans++;
            }
            ans=s.length()-ans;
        }
    }
    cout << ans << "\n";
}

