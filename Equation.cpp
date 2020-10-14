#include <iostream>
using namespace std;

typedef struct pnode //typedef [struct (pnode)] pndoe  括号内叫什么不重要
{
    int coef; //系数
    int exp; //指数
    pnode *next;
} pnode;

class poly
{
private:
    pnode *head;

public:
    poly()
    {
        head = new pnode;
        head->next = NULL;
    }
    void creat(int n); 
    void print();
    int comp(int a, int b);
    void addpoly(poly &ha, poly hb);
};

void poly::creat(int n) //输入n项式
{
    pnode *s,*rear;
    s = new pnode;
    rear = head;
    for (int i = 0; i < n; i++)
    {
        cin >> s->coef >> s->exp; //输入系数和指数
        rear = head; //rear始终指向表尾
        rear->next = s; 
        rear = s;
    }
    rear->next = NULL;
}

void poly::print()
{
    pnode *p = head->next;
    while (p)
    {
        cout << p->coef << " " << p->exp << " ";
        p = p->next;
    }
    cout << endl;
}

int poly::comp(int a, int b)
{
    if (a > b)
        return -1;
    else if (a == b)
        return 0;
    else
        return 1;
}

void poly::addpoly(poly &ha, poly hb)
{
    pnode *pa = ha.head->next, *q = ha.head, *pb = hb.head->next, *r;
    while (pa && pb)
        switch (comp(pa->exp, pb->exp))
        {
        case -1:
            q = pa, pa = pa->next;
            break;
        case 1:
            r = new pnode;
            r->coef = pb->coef;
            r->exp = pb->exp;
            r->next = pa;
            q->next = r;
            q = r;
            pb = pb->next;
            break;
        case 0:
            pa->coef += pb->coef;
            if (pa->coef == 0)
            {
                q->next = pa->next;
                delete pa;
                pa = q;
            }
            else
                q = pa;
            pa = pa->next;
            pb = pb->next;
            break;
        }
    while (pb)
    {
        r = new pnode;
        r->coef = pb->coef;
        r->exp = pb->exp;
        r->next = NULL;
        q->next = r;
        q = r;
        pb = pb->next;
    }
}
int main()
{
    void creat();
    void print();
    return 0;
}