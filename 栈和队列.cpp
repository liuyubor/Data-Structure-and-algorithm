#include<iostream>
using namespace std;

#define initstacksize 100
#define stackincrement 10

class sqstack
{
private:
    int *base;
    int stacksize;
    int *top;
public:
    sqstack();
    void push(int e);
    void pop(int &e);
    int emptystack();
    void print();
    void convert(int n);
};

sqstack::sqstack(){
    base = new int[initstacksize];
    stacksize =initstacksize;
}

void sqstack::push(int e){
    if (top-base == stacksize)
    {
        int *basel = new int[stacksize + stackincrement];
        for (int i = 0; i < stacksize; i++)
        {
            basel[1]=base[i];
        }
        delete basel;
        base = basel;
        top = base+stacksize;
        stacksize+=stackincrement;
    }
    *top++ = e;
}

void sqstack::pop(int &e){
    if (top == base)
    {
        return;
    }
    e = *--top;

}

int sqstack::emptystack(){
    if (top == base)return 1;
    else return 0;
}


// void sqstack::convert(int n){
//     while (n)
//     {
//         push(n%8);
//         n=n/d;
//     }
//     while (!emptystack())
//     {
//         pop(e);
//         cout<<e<<"\t";
//     }
//     cout<<endl;
// }