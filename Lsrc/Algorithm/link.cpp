#include<iostream>
using namespace std;
// (single)
// new type or new class/struct type() Ex:int *ptr=new int ,Ex:Node *ptr=new Node() 
//                                                          For class type c++ allow using 
//                                                          constructor when using new allocate
//                                                          memory space!
// (multiple)
// new type or new class/struct type[] Ex:int *ptr=new int[3], Ex:Node *ptr=new Node[3]
//                                      new int[3] is obviously     Similarly explanation,
//                                      mean create 3 memory space  create 3 memory space of
//                                      of int and assign to ptr    Node and assign to ptr

// (single)
// delete pointer Ex:int *ptr=new int; Ex:Node *ptr=new Node()
//                   delete ptr;          delete ptr;
//                   using delete keyword can free the memery space create by new keyword!
//
// (multiple)
// delete[] pointer Ex:int *ptr=new int[10]; Ex:Node *ptr=new Node[10]
//                     delete[] ptr;            delete[] ptr;
//                     ptr=NULL;                ptr=NULL;
//                     delete[] is a built in syntax which mean delete all the memory space
//                     which link to the pointer and does not require any argument!Don't 
//                     forget setup ptr=NULL after delete!

class Node{
    public:
        int dat;
        Node *nextPtr=NULL;
        Node(int Dat):dat(Dat){}
};
typedef Node* NodePtr;

void insertLink(NodePtr *start,int val)
{
    NodePtr newPtr=new Node(val);
    NodePtr prePtr=NULL;
    NodePtr currentPtr=*start;
    while(currentPtr!=NULL)
    {
        prePtr=currentPtr;
        currentPtr=currentPtr->nextPtr;
    }
    if(prePtr==NULL)
    {
        *start=newPtr;
    }
    else {
        prePtr->nextPtr=newPtr;
        newPtr->nextPtr=currentPtr;
    }
}
void delLink(NodePtr *start,int val)
{
    NodePtr tmpPtr=NULL;
    NodePtr prePtr=NULL;
    NodePtr currentPtr=*start;
    if(currentPtr->dat == val)
    {
        tmpPtr=currentPtr;
        currentPtr=currentPtr->nextPtr;
        *start=currentPtr;
        delete tmpPtr;
    }
    else{
        while(currentPtr!=NULL && currentPtr->dat!=val)
        {
            prePtr=currentPtr;
            currentPtr=currentPtr->nextPtr;
        }
        if(currentPtr!=NULL)
        {
            tmpPtr=currentPtr;
            currentPtr=currentPtr->nextPtr;
            prePtr->nextPtr=currentPtr;
            delete tmpPtr;
        }
    }
}
void listlink(NodePtr start)
{
    while(start!=NULL)
    {
        cout << start->dat << " ";
        start=start->nextPtr;
    }
    cout << "\n";
}
int main()
{
    NodePtr start=NULL;
    insertLink(&start,10);
    insertLink(&start,20);
    insertLink(&start,30);
    listlink(start);
    delLink(&start,20);
    listlink(start);
    delLink(&start,100);
    listlink(start);
    delete[] start;
    start=NULL;
    if(start==NULL) cout << "Link is empty!\n";
}

