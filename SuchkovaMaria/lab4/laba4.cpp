#include "stdafx.h"
#include <iostream>
using namespace std;
struct list
{
	int info;
	list *next, *prev;
};
list *init()
{
	list *p=new list;
	p->info=0;
	p->next=NULL;
	p->prev=NULL;
	return p;
}
list*push(list *p, int a)
{
	if (p->info==0)
	{
		p->info=a;
		return p;
	}
	else
	{
		list *q=init();
		q->info=a;
		q->prev=p;
		p->next=q;
		return q;
	}
}
list *search(list *p, int a)
{
	while (p->next!=NULL)
	{
		if (p->info==a) return p;
		p=p->next;
	}
	if (p->info==a) return p;
	return NULL;
}
list *pop(list *&p)
{
	list *q1=p; list *q2=p;
	q1=q1->prev;
	q2=q2->next;
	bool k=0;
	if (q1) q1->next=q2;
	if (q2) {q2->prev=q1; if (!q1) k=1;}
	delete p;
	if (k) 
		return q2;
	else
	{
		while (q1->prev)
			q1=q1->prev;
		
		return q1;
	}

}
void print(list *p)
{
	while (p->next!=NULL)
	{
		cout<<p->info<<' ';
		p=p->next;
	}
	cout<<p->info<<'\n';
}
void sort(list *&p)
{
	int k=1;
	list *q=p;
	list *qn=p->next;
	list *w=p;
	while (p->next) 
	{
		k++; 
		p=p->next;
	}
	for (int i=1;i<k-1;i++)
	{
		for (int j=1;j<k-i;j++)
		{
			if (q->info>qn->info)	
			{
				int temp=q->info;
				q->info=qn->info;
				qn->info=temp;
			}
			if (qn->next)qn=qn->next;
		}
		if (q->next)
		{
			q=q->next;
			qn=q->next;
		}
	}
	p=w;
}
int main()
{
	cout<<"Enter number"<<"\n";
	int n;
	cin>>n;
	list *p=init();
	list *q=new list;
	p=push(p,n);
	q=p;
	cout<<"Enter number"<<"\n";
	cin>>n;
	bool k=0;
	do
	{
		p=push(p,n);
		cout<<"Enter number"<<"\n";
		cin>>n;
		
	}
	while (n!=0);
	sort(q);
	print(q);
	cout<<"Enter element, which you want to delete"<<"\n";
	int DelEl;
	cin>>DelEl;
	list *w=new list;
	w=search(q,DelEl);
	if (w) 
	{
		q=pop(w);
		print(q);
	}
	else cout<<"Error";
	system ("pause");
}