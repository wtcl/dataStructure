#include<stdio.h>
#include<stdlib.h>
//�����н��ṹ
typedef struct QNode{
	int data;
	struct QNode *next;
}QNode;
//�����нṹ
typedef struct LiQueue{
	QNode *front;
	QNode *rear;
}LiQueue;
//����������
LiQueue initQueue(){
	LiQueue *lq=(LiQueue *)malloc(sizeof(LiQueue));
//	if(lq ==NULL){
//		return;
//	}
	lq->front=lq->rear=NULL;
	return *lq;
}
//�ж��������Ƿ�Ϊ��
int isEmpty(LiQueue *lq){
	if(lq->front==NULL || lq->rear==NULL){
		return 0;
	}else{
		return 1;
	}
}
//Ԫ�ؽ�������
void enQueue(LiQueue *lq,int x){
	QNode *p;
	p=(QNode *)malloc(sizeof(QNode));
	p->data=x;
	p->next=NULL;
	if(lq->rear==NULL){
		lq->front=lq->rear=p;//�����һ�β���������ͷָ���βָ��Ϊp
	}else{
		lq->rear->next=p;//�����е�β������p
		lq->rear=p;//���������е�βָ��ָ��p
	}
}
//Ԫ�س�������
int deQueue(LiQueue *lq,int *y){
	QNode *p=lq->front;
	if(lq->rear==NULL || lq->front==NULL){
		return 0;
	}
	if(lq->front==lq->rear){
		lq->front=lq->rear=NULL;
	}else{
		lq->front=lq->front->next;
	}
	*y=p->data;
	free(p);
	return 1;
}
//��ӡ������
void printQueue(LiQueue lq){
	if(lq.front==NULL || lq.rear==NULL){
		return;
	}
	while(lq.front!=NULL){
		printf("%d\n",lq.front->data);
		lq.front=lq.front->next;
	}
}
void main(){
	int y=0;
	LiQueue lq=initQueue();
	enQueue(&lq,1);
	enQueue(&lq,2);
	enQueue(&lq,3);
	enQueue(&lq,4);
	enQueue(&lq,5);
	deQueue(&lq,&y);
	printQueue(lq);
	printf("������Ԫ��=%d\n",y);
}
