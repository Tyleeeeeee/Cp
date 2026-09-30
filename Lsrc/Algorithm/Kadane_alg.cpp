#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[]={1,2,3,-4,-5,10,12,13};
    int cur,Max;
    cur=Max=0;
    for(int q=0;q<8;++q)
    {
        cur+=arr[q];
        cur=max(cur,0);
        Max=max(Max,cur);
    }
}

// Kadane's algorithm 用於計算陣列中最長的連續subarray！

