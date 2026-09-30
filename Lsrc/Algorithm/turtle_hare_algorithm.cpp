//Assume that there is a one way linked list
//
//  1->2->3->4->5->6->7
//           ^       |
//           |       v
//           12      8
//           ^       |
//           |       v
//           11<-10<-9
//
//  turtle_hare_algorithm can help us to find is that exist a loop in the list,also count the length of the loop and the length of list which is not loop

//Find loop exist
//Assume turtle and hare and the same start point Sp,then simplify make hare go through 2 step and turtle go through 1 step,if they are meet mean that there is a loop else there is no loop.
//But let us have a think,why if hare go through 2 step and turtle go through 1 step then they will definitely meet?Let make a
//simple proof
//
//Assume that there is a loop inside the list,and the loop starting point be 0 ,and our turtle and hare start point be -T,and the c be the length of loop
//After T round,
//turtle reached -T+T=0,hare reached (-T+2T)%c (since there is a loop of c so the destination of hare cannnot greater or equal to c so we need to modulus c)
//By the previous result,(-T+2T)%c=T%c=c*k+r(k is a constant)
//Now let us assume that after T+x round (0<=x<c)(if we can find x mean that turtle can meet hare otherwise not)
//turtle reached q=(-T+T+x)%c=x%c(1) (similarly explanation above why %c)
//hare reached q=(-T+2(T+x))%c=(T+2x)%c(2)
//(2)-(1)
//(T+x)%c=0
//and from line 21 T%c=c*k+r,thus
//(T+x)%c=(c*k+r+x)%c=0
//       =(r+x)%c=0
//(r+x)%c=0
//x%c=(-r)%c (0<=x<c)
//x%c=(c-r)%c and also x%c=(2c-r)%c and .. x%c=(c*n-r)%c (n is const )k
//x=c-r
//
//We found x=c-r let assume that after T+(c-r) round 
//turtle reached (-T+T+(c-r))%c = (c-r)%c = c-r
//hare reached (-T+2T+2(c-r))%c = (T+2(c-r))%c = (c*k+r+2c-2r)%c = (c*k+2c-r)%c = (2c-r)%c = c-r
//Proved!
//
//
//If we want to find the loop length,we can simplify let hare move 1 step each round and turtle don't move after they first time meet,and the round required for they second times meet is the loop length
//How about if we want to find the chain length?(linked list which is not loop call chain)
//After turtle and hare meet,let the hare to the starting point -T and turtle stay at the meeting point c-r
//and then let them move 1 step each round ,after n round they will meet at the loop starting point and n is the chain lenght
//Proof:
//Assuem hare start at -T and turtle start at c-r
//after T round
//hare reached -T+T=0
//turtle reached (c-r+T)%c=(c-r+c*k+r)%c=(c*(k+1))%c=0
//Proved
