//catalan number
//2nCn * (1/(n+1))
//first lemma:imagine there is a grid with n*n the ways you reached (i,j) is equal to (j,i) 
//second lemma:no matter where you are assuem that you make x move up and y move down,the ways are same
//proof: 
//Assume that i is the ) moves and j is the ( moves then when i>j means that there is non valid let says the 
//location is (j+1,j) and we left n-j-1 ) and n-j ( ,according to first lemma the ways to (j,j+1) is same to (j+1,j)
//and according to second lemma no matter where you are the number of moves are same then the ways is same so
//(j,j+1) after move will become (j+n-j-1,j+1+n-j) ,(n-1,n+1) in otherword the end point is at (n-1,n+1) which 
//lead to 2*nCn-1 non valid move
//(x1,y1)->(x2,y2) the ways is same as (y1,x1)->(y2,x2) since their are symmetry
