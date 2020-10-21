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
    int countleaf(bitnode *t);
    int counthigh(bitnode *t);
    bitnode *search(bitnode *t, char x);

public:
    void recreat();
    int recountleaf();
    int recounthigh();
    bitnode *research(char x);
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

int binary::countleaf(bitnode *t)
{
    if (t = NULL)
        return 0;
    else
    {
        int m = countleaf(t->lchild);
        int n = countleaf(t->rchild);
        if (m + n == 0)
            return 0;
        else
        {
            return m + n;
        }
    }
}
int binary::recountleaf()
{
    bitnode *t = bt;
    return countleaf(t);
}
int binary::counthigh(bitnode *t)
{
    if (t = NULL)
        return 0;
    else
    {
        int m = 1 + counthigh(t->lchild);
        int n = 1 + counthigh(t->rchild);
        if (m >= n)
            return m;
        else

            return n;
    }
}

int binary::recounthigh()
{
    bitnode *t = bt;
    return counthigh(t);
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

int main()
{
    binary bt;
    char x;
    bt.recreat();
    cout << bt.recountleaf() << endl;
    cout << bt.recounthigh() << endl;
    cin >> x;
    cout << bt.research(x) << endl;
}