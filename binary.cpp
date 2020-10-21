#include <iostream>
using namespace std;

typedef struct bitnode
{
    char data;
    bitnode *lchild;
    bitnode *rchild;
} bitnode;

class binary
{
private:
    bitnode *bt;
    void creat(bitnode *&t);
    int count_leaf(bitnode *t);
    int count_high(bitnode *t);
    bitnode *search(bitnode *t, char x);
    void exchange();
    int count_node();

public:
    void recreat();
    int recount_leaf();
    int recount_high();
    bitnode *research(char x);
    void reexchange();
    int recount_ndoe();
};

void binary::creat(bitnode *&t)
{
    char ch;
    cin >> ch;
    if (ch == '.')
        t = NULL;
    else
    {
        t = new bitnode;
        t->data = ch;
        creat(t->lchild);
        creat(t->rchild);
    }
}

void binary::recreat()
{
    bitnode *t;
    creat(t);
    bt = t;
}

int binary::count_leaf(bitnode *t)
{
    if (t = NULL)
        return 0;
    else
    {
        int m = count_leaf(t->lchild);
        int n = count_leaf(t->rchild);
        if (m + n == 0)
            return 0;
        else
        {
            return m + n;
        }
    }
}
int binary::recount_leaf()
{
    bitnode *t = bt;
    return count_leaf(t);
}
int binary::count_high(bitnode *t)
{
    if (t = NULL)
        return 0;
    else
    {
        int m = 1 + count_high(t->lchild);
        int n = 1 + count_high(t->rchild);
        if (m >= n)
            return m;
        else

            return n;
    }
}

int binary::recount_high()
{
    bitnode *t = bt;
    return count_high(t);
}

bitnode *binary::search(bitnode *t, char x)
{
    if (t == NULL)
        return t;
    else
    {
        if (t->data == x)
            return t;
        bitnode *p = search(t->lchild, x);
        if (p)
            return p;
        return search(t->rchild, x);
    }
}
bitnode *binary::research(char x)
{
    bitnode *t = bt;
    return search(t, x);
}

void binary::exchange()
{

}

int binary::count_node()
{
    
}


int main()
{
    binary bt;
    char x;
    bt.recreat();
    cout << bt.recount_leaf() << endl;
    cout << bt.recount_high() << endl;
    cin >> x;
    cout << bt.research(x) << endl;
}
