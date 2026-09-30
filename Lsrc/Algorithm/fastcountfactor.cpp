
vector<vector<int>> dvs(M_A_X,vector<int>());
//O(NlogN)
for(int q=2;q<M_A_X;++q)
    for(int w=q;w<M_A_X;w+=q)
            dvs[w].push_back(q);

//this is a faster way to count factor within time complexity O(nlogn)
//the total number for the loop is when q=i,inner loop will process MAX/i times , so we can get a harmonic summation
//which is MAX/1+MAX/2+MAX/3+...+MAX/MAX=MAX(1/1+1/2+1/3+...+1/MAX) approximate MAX*ln(MAX)+constant thus time 
//complexity become O(nlogn)
  

