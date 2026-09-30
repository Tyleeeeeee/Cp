#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    int n,arr[3];
    string s;
    cin>>n>>s;
    memset(arr,0,sizeof(arr));
    for(int q=0;q<s.length();++q){
        if(s[q]=='B') arr[0]++;
        else if(s[q]=='G') arr[1]++;
        else arr[2]++;
    }
    if((arr[0]>=1&&arr[1]>=1&&arr[2]>=1)||(arr[0]>1 && arr[1]>1)||(arr[1]>1 && arr[2]>1)||(arr[0]>1 && arr[2]>1)) cout << "BGR";
    else if(arr[0]>1 && (arr[1]==1||arr[2]==1)) cout << "GR";
    else if(arr[1]>1 && (arr[2]==1||arr[0]==1)) cout << "BR";
    else if(arr[2]>1 && (arr[0]==1||arr[1]==1)) cout << "BG";
    else if(arr[0]==1&&arr[1]==1) cout << "R";
    else if(arr[1]==1&&arr[2]==1) cout << "B";
    else if(arr[0]==1&&arr[2]==1) cout << "G";
    else if(arr[0]) cout << "B";
    else if(arr[1]) cout << "G";
    else if(arr[2]) cout << "R";
    cout << "\n";
}

