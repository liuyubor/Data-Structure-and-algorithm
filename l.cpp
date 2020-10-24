#include <iostream>
using namespace std;

typedef struct Node
{
	int date;
	Node *next;
} Node;

class LinkList
{
private:
	Node *Head;

public:
	void CreateList1(int n);	   //头插法
	void CreateList2(int n);	   //尾插法
	void ListInsert(int n, int e); //在第e个元素位置上插入i
	int ListDelete(int i);		   //删除第i个元素
	int GetElem(int i);			   //获取第i个元素的值
	int LocateElem(int e);		   //获取第e个元素的位置
};

void LinkList::CreateList1(int n)
{
	Node *p, *s;
	p = Head;
	cout << "请输入" << n << "个数据元素值：" << endl;
	for (int i = 0; i < n; i++)
	{
		s = new Node;
		cin >> s->date;
		s->next = p->next;
		s = p->next;
	}
}

void LinkList::CreateList2(int n)
{
	Node *p, *s;
	p = Head;
	cout << "请依次输入" << n << "的值：" << endl;
	for (int i = 1; i < n; i++)
	{
		s = new Node;
		cin >> s->date;
		p->next = s;
		s = p;
	}
}

int LinkList::GetElem(int i)
{
	Node *p;
	p = Head->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > 1)
	{
		cout << "位置异常";
		return -1;
	}
	else
		return p->date;
}

int LinkList::LocateElem(int e)
{
	Node *p;
	p = Head;
	int j = 1;
	while (p->date != e)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return 0;
	else
		return j;
}

int LinkList::ListDelete(int i)
{
	Node *p, *s;
	cout << i;
	p = Head;
	int j = 0;
	while (j < i - 1)
	{
		p = p->next;
		j++;
	}
	s = p;
	p->next = p->next->next;
	return s->date;
}

void LinkList::ListInsert(int i, int e)
{
	Node *p, *s;
	p = Head;
	int j = 0;
	cout << i;
	while (j < i - 1)
	{
		p = p->next;
		j++;
	}
	s = new Node;
	cin >> s->date;
	s->next = p->next;
	s = p->next;
}

int main()
{
	LinkList bt;
	bt.CreateList1(2);
	return 0;
}
