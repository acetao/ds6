#include "linklist.cpp"			//包括单链表基本运算算法

//单链表选择排序算法
void Sort(LinkNode* h)
{
	if (h->next == NULL || h->next->next == NULL)
		return;								//空表或者只有一个结点时返回
	LinkNode *p, *minp, *q;
	int minv;
	p = h->next;
	while (p != NULL)						//用指针p遍历h的所有结点
	{
		minv = p->data;
		minp = p;
		for (q = p->next; q != NULL; q = q->next)	//从结点p开始找到最小值的结点minp
			if (q->data < minv)
			{
				minp = q;
				minv = q->data;
			}
		if (minp != p)
		{
			int tmp = p->data;				//交换结点p和minp的结点值
			p->data = minp->data;
			minp->data = tmp;
		}
		p = p->next;
	}
}

int main()
{
	int a[] = {3, 4, 5, 2, 1};
	int n = sizeof(a) / sizeof(a[0]);
	LinkNode* L;
	CreateListR(L, a, n);
	printf("L: "); DispList(L);
	Sort(L);
	printf("L: "); DispList(L);
	DestroyList(L);
	return 0;
}

