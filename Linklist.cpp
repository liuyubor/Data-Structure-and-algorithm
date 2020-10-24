#include <iostream>
using namespace std;

typedef struct ndoe
{
    int data;
    ndoe *next;
} ndoe;

class linklist
{
private:
    ndoe *head;

public:
    linklist();          //创建空表
    void creat(int n);   //正序创建n个元素的链表(尾插法)
    void print();        //显示链表中的值
    void evennum();      //计算链表中偶数的节点个数
    void delete_same();  //删除链表中值相同的多余节点
    int delete_x(int x); //删除值等于X的所有节点，若成功返回1，否则返回0
};

linklist::linklist()
{
    head = new ndoe;
    head->next = NULL;
}

void linklist::creat(int n)
{
    ndoe *rear = head, *s;
    cout << "请依次输入" << n << "个数据元素" << endl;
    for (int i = 0; i < n; i++)
    {
        s = new ndoe;
        cin >> s->data;
        rear->next = s;
        rear = s;
    }
    s->next = NULL;
}

void linklist::print()
{
    ndoe *p = head->next;
    while (p)
    {
        cout << p->data << " " << endl;
        p = p->next;
    }
}

void linklist::evennum()
{
    ndoe *p = head->next;
    int evennum = 0;
    while (p)
    {
        if (p->data % 2 == 0)
        {
            evennum++;
        }
        p = p->next;
    }
    cout << evennum;
}

void linklist::delete_same()
{
    ndoe *p = head, *qr, *q;
    if (p == head && p->next == NULL) //判断空表或者只有一个节点
        return;
    p = p->next;
    while (p != NULL)
    {
        qr = p;
        q = p->next;
        while (q->next != NULL)
        {
            if (p->data != q->data)
            {
                qr = q;
                q = q->next;
            }
            else
            {
                qr->next = q->next;
                delete q;
                q = qr->next;
            }
        }
    }
}

int linklist::delete_x(int x)
{
    ndoe *p = head, *pr;
    int i = 0;
    pr = p;
    p = p->next;
    while (p != NULL)
    {
        if (p->data == x)
        {
            pr->next = p->next;
            delete p;
            i++;
            p = pr->next;
        }
        else
        {
            p = p->next;
            pr = pr->next;
        }
    }
    if (p->data == x)
    {
        delete p;
        i++;
        pr->next = NULL;
    }
    if (i != 0)
        return 1;
    else
        return 0;
}

int main()
{
    linklist a;
    a.creat(3);
    a.print();
    a.evennum();
    a.delete_same();
    a.delete_x(1);
    a.print();
    return 0;
}