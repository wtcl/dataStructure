#include <stdio.h>
#include <stdlib.h>

//节点结构
typedef struct Node{
    struct Node * prior;
    int data;
    struct Node * next;
}Node;

//双链表的创建函数
Node* initNode(Node * head);
//输出双链表的函数
void display(Node * head);
//添加元素 
Node * insertNode(Node * head,int data,int add);
//删除元素 
Node * delNode(Node * head,int data);
//查找元素 
int selectElem(Node * head,int elem);
//更新元素 
Node *amendElem(Node * p,int add,int newElem); 

int main() {
    //创建一个头指针
    Node * head=NULL;
    //调用链表创建函数
    head=initNode(head);
    //输出创建好的链表
    display(head);
    //显示双链表
    printf("链表中第 4 个节点的直接前驱是：%d\n",head->next->next->next->prior->data);
    head = insertNode(head, 999, 1);
    display(head);
    head = delNode(head, 999);
    display(head);
    int i = selectElem(head, 5);
	printf("你查找的数字的位置为%d\n",i);
	head=amendElem(head, 1,555);
	display(head); 
	return 0;
}

Node* initNode(Node * head){
    //创建一个首元节点，链表的头指针为head
    head=(Node*)malloc(sizeof(Node));
    //对节点进行初始化
    head->prior=NULL;
    head->next=NULL;
    head->data=1;
    //声明一个指向首元节点的指针，方便后期向链表中添加新创建的节点
    Node * list=head;
    for (int i=2; i<=5; i++) {
        //创建新的节点并初始化
        Node * body=(Node*)malloc(sizeof(Node));
        body->prior=NULL;
        body->next=NULL;
        body->data=i;

        //新节点与链表最后一个节点建立关系
        list->next=body;
        body->prior=list;
        //list永远指向链表中最后一个节点
        list=list->next;
    }
    //返回新创建的链表
    return head;
}

void display(Node * head){
    Node * temp=head;
    while (temp) {
        //如果该节点无后继节点，说明此节点是链表的最后一个节点
        if (temp->next==NULL) {
            printf("%d\n",temp->data);
        }else{
            printf("%d <-> ",temp->data);
        }
        temp=temp->next;
    }
}

Node * insertNode(Node * head,int data,int add){
    //新建数据域为data的结点
    Node * temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->prior=NULL;
    temp->next=NULL;
    //插入到链表头，要特殊考虑
    if (add==1) {
        temp->next=head;
        head->prior=temp;
        head=temp;
    }else{
        Node * body=head;
        //找到要插入位置的前一个结点
        for (int i=1; i<add-1; i++) {
            body=body->next;
        }
        //判断条件为真，说明插入位置为链表尾
        if (body->next==NULL) {
            body->next=temp;
            temp->prior=body;
        }else{
            body->next->prior=temp;
            temp->next=body->next;
            body->next=temp;
            temp->prior=body;
        }
    }
    return head;
}

//删除结点的函数，data为要删除结点的数据域的值
Node * delNode(Node * head,int data){
    Node *temp=head;
    //遍历链表
    while (temp) {
        //判断当前结点中数据域和data是否相等，若相等，摘除该结点
        if (temp->data==data) {
        	if (temp == head)
        	{
				head = head->next; 
				head->prior = NULL;
			}
			else
			{
				temp->prior->next=temp->next;
				temp->next->prior=temp->prior;
			}
			free(temp);
            return head;
        }
        temp=temp->next;
    }
    printf("链表中无该数据元素");
    return head;
}

//head为原双链表，elem表示被查找元素
int selectElem(Node * head,int elem){
//新建一个指针t，初始化为头指针 head
    Node * t=head;
    int i=1;
    while (t) {
        if (t->data==elem) {
            return i;
        }
        i++;
        t=t->next;
    }
    //程序执行至此处，表示查找失败
    return -1;
}

//更新函数，其中，add 表示更改结点在双链表中的位置，newElem 为新数据的值
Node *amendElem(Node * p,int add,int newElem){
    Node * temp=p;
    //遍历到被删除结点
    for (int i=1; i<add; i++) {
        temp=temp->next;
    }
    temp->data=newElem;
    return p;
}
