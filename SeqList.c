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

// ���� 
int CreateList(SeqList *l, int a[], int n)
{
	if (n > MAXSIZE)
	{
		printf("�ռ䲻�㣬�޷�������");
		return 0; 
	}
	for (int k=0; k<n;k++)
	{
		l->data[k] = a[k];
	}
	l->length = n;
	return 1;
}

//  �пղ���
int Empty(SeqList *l)
{
	if (l->length == 0)
	    return 1;
	else
	    return 0;
} 

// ��˳�����
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
		printf("����λ�÷Ƿ������Ҵ���\n");
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
		printf("�������");
		return 0;
	}
	if (i<1 || i>l->length)
	{
		printf("����λ�ô���");
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
		printf("����������󣬼�������˳���֮ǰ�ĵ�ַ��\n");
		return 0; 
	}
	if (i> l->length || i<1)
	{
		printf("ɾ��λ�ô���\n");
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
		printf("λ�ô���\n");
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
		printf("��ʼ���ɹ���\n");
	}
	printf("��˳���ֵ��1��2��3��4��5\n���������˳���\n");
	CreateList(&list, a, 5);
	PrintList(&list);
	printf("\n�ڵ���λ�����һ��100;\n");
	Insert(&list, 3, 100);
	PrintList(&list);
	if (Modify(&list, 3, 50) == 1)
	{
		printf("\n�ѵ���λ�ĳ�50\n");
		PrintList(&list); 
	}
	if (Delete(&list, 4 , &x)==1)
	{
		printf("\n�ѵ�4λɾ����ɾ����ֵ��%d\n",x);
	}
	return 0;
}
