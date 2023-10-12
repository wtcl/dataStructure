#include <stdio.h>
#include <stdlib.h>

//�ڵ�ṹ
typedef struct Node{
    struct Node * prior;
    int data;
    struct Node * next;
}Node;

//˫����Ĵ�������
Node* initNode(Node * head);
//���˫����ĺ���
void display(Node * head);
//���Ԫ�� 
Node * insertNode(Node * head,int data,int add);
//ɾ��Ԫ�� 
Node * delNode(Node * head,int data);
//����Ԫ�� 
int selectElem(Node * head,int elem);
//����Ԫ�� 
Node *amendElem(Node * p,int add,int newElem); 

int main() {
    //����һ��ͷָ��
    Node * head=NULL;
    //��������������
    head=initNode(head);
    //��������õ�����
    display(head);
    //��ʾ˫����
    printf("�����е� 4 ���ڵ��ֱ��ǰ���ǣ�%d\n",head->next->next->next->prior->data);
    head = insertNode(head, 999, 1);
    display(head);
    head = delNode(head, 999);
    display(head);
    int i = selectElem(head, 5);
	printf("����ҵ����ֵ�λ��Ϊ%d\n",i);
	head=amendElem(head, 1,555);
	display(head); 
	return 0;
}

Node* initNode(Node * head){
    //����һ����Ԫ�ڵ㣬�����ͷָ��Ϊhead
    head=(Node*)malloc(sizeof(Node));
    //�Խڵ���г�ʼ��
    head->prior=NULL;
    head->next=NULL;
    head->data=1;
    //����һ��ָ����Ԫ�ڵ��ָ�룬�������������������´����Ľڵ�
    Node * list=head;
    for (int i=2; i<=5; i++) {
        //�����µĽڵ㲢��ʼ��
        Node * body=(Node*)malloc(sizeof(Node));
        body->prior=NULL;
        body->next=NULL;
        body->data=i;

        //�½ڵ����������һ���ڵ㽨����ϵ
        list->next=body;
        body->prior=list;
        //list��Զָ�����������һ���ڵ�
        list=list->next;
    }
    //�����´���������
    return head;
}

void display(Node * head){
    Node * temp=head;
    while (temp) {
        //����ýڵ��޺�̽ڵ㣬˵���˽ڵ�����������һ���ڵ�
        if (temp->next==NULL) {
            printf("%d\n",temp->data);
        }else{
            printf("%d <-> ",temp->data);
        }
        temp=temp->next;
    }
}

Node * insertNode(Node * head,int data,int add){
    //�½�������Ϊdata�Ľ��
    Node * temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->prior=NULL;
    temp->next=NULL;
    //���뵽����ͷ��Ҫ���⿼��
    if (add==1) {
        temp->next=head;
        head->prior=temp;
        head=temp;
    }else{
        Node * body=head;
        //�ҵ�Ҫ����λ�õ�ǰһ�����
        for (int i=1; i<add-1; i++) {
            body=body->next;
        }
        //�ж�����Ϊ�棬˵������λ��Ϊ����β
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

//ɾ�����ĺ�����dataΪҪɾ�������������ֵ
Node * delNode(Node * head,int data){
    Node *temp=head;
    //��������
    while (temp) {
        //�жϵ�ǰ������������data�Ƿ���ȣ�����ȣ�ժ���ý��
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
    printf("�������޸�����Ԫ��");
    return head;
}

//headΪԭ˫����elem��ʾ������Ԫ��
int selectElem(Node * head,int elem){
//�½�һ��ָ��t����ʼ��Ϊͷָ�� head
    Node * t=head;
    int i=1;
    while (t) {
        if (t->data==elem) {
            return i;
        }
        i++;
        t=t->next;
    }
    //����ִ�����˴�����ʾ����ʧ��
    return -1;
}

//���º��������У�add ��ʾ���Ľ����˫�����е�λ�ã�newElem Ϊ�����ݵ�ֵ
Node *amendElem(Node * p,int add,int newElem){
    Node * temp=p;
    //��������ɾ�����
    for (int i=1; i<add; i++) {
        temp=temp->next;
    }
    temp->data=newElem;
    return p;
}
