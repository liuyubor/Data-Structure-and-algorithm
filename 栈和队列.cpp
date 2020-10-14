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

sqstack::push(){
    if (top-base == stacksize)
    {
        int *basel = new [stacksize + stackincrement];
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

sqstack::pop(int &e){
    if (top == base)
    {
        return;
    }
    e = *--top;

}

sqstack::emptystack(){
    if (top == base)return 1;
    else return 0;
}

sqstack::print(){

}

sqstack::convert(){
    int e;
    while (n)
    {
        push(n%8);
        n=n/d;
    }
    while (!stackempty())
    {
        pop(e);
        cout<<e<<"\t";
    }
    cout<<endl;
}