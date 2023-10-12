#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

#define MAXSIZE 20

typedef struct {
	int data[MAXSIZE];
	int length;
}SeqList;

void InitList(SeqList *l)
{
	l->length = 0;
}

// 建表 
int CreateList(SeqList *l, int a[], int n)
{
	if (n > MAXSIZE)
	{
		printf("空间不足，无法建立表");
		return 0; 
	}
	for (int k=0; k<n;k++)
	{
		l->data[k] = a[k];
	}
	l->length = n;
	return 1;
}

//  判空操作
int Empty(SeqList *l)
{
	if (l->length == 0)
	    return 1;
	else
	    return 0;
} 

// 求顺序表长度
int Length(SeqList *l)
{
	return l->length;
} 

void PrintList(SeqList *l)
{
	for (int i=0; i< l->length;i++)
	printf("%d\n", (l->data[i]));
}

int Locate(SeqList *l, int x)
{
	for (int i=0; i< l->length; i++)
	{
		if (l->data[i] == x)
		{
			return i+1; 
		}
		return 0;
	}
	return 1;
}

int Get(SeqList *l, int x, int *ptr)
{
	if(x<1 || x>l->length)
	{
		printf("查找位置非法，查找错误\n");
		return 0;
	}
	else
	{
		*ptr = l->data[x];
		return 1;
	}
}

int Insert(SeqList *l, int i, int x)
{
	if (l->length>MAXSIZE)
	{
		printf("上溢错误！");
		return 0;
	}
	if (i<1 || i>l->length)
	{
		printf("插入位置错误！");
		return 0;
	}
	for (int k=l->length;k>i;k--)
	{
		l->data[k] = l->data[k-1];
	}
	l->data[i]=x;
	l->length++;
	return 1;
}

int Delete(SeqList *l, int i, int *ptr)
{
	if(l->length == 0)
	{
		printf("发生下溢错误，即将访问顺序表之前的地址。\n");
		return 0; 
	}
	if (i> l->length || i<1)
	{
		printf("删除位置错误！\n");
		return 0;
	}
	*ptr = l->data[i-1];
	for (int j=i; j<l->length;j++)
	{
		l->data[j-1] = l->data[j];
	}
	l->length--;
	return 1;
}

int Modify(SeqList *l, int i, int x)
{
	if (i>l->length || i<1)
	{
		printf("位置错误！\n");
		return 0;
	}
	l->data[i] = x;
	return 1;
}

int main()
{
	int a[5] = {1,2,3,4,5};
	int x;
	SeqList list;
	InitList(&list);
	if (Empty(&list))
	{
		printf("初始化成功！\n");
	}
	printf("给顺序表赋值：1，2，3，4，5\n遍历并输出顺序表\n");
	CreateList(&list, a, 5);
	PrintList(&list);
	printf("\n在第三位后插入一个100;\n");
	Insert(&list, 3, 100);
	PrintList(&list);
	if (Modify(&list, 3, 50) == 1)
	{
		printf("\n把第三位改成50\n");
		PrintList(&list); 
	}
	if (Delete(&list, 4 , &x)==1)
	{
		printf("\n把第4位删除，删除的值是%d\n",x);
	}
	return 0;
}
