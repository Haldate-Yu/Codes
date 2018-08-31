#include<stdio.h>

//定义
typedef struct Node {
    int data;
    struct Node *next;
}LinkQueueNode;

typedef struct{
    LinkQueueNode *front;
    LinkQueueNode *rear;
}LinkQueue;

//初始化
int Initial(LinkQueue *q) {
    q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if(q->front != NULL){
        q->rear = q->front;
        q->front->next = NULL;
        return 1;
    }
    else return 0;
}

//入队
int Enter(LinkQueue *q,int *x) {
    LinkQueueNode *p;
    if(q->front == q->rear) return 0;
    p = q->front->next;
    q->front->next = p->next;
    if(q->rear == p)    q->rear = q->front;
    *x = p->data;
    free(p);
    return 1;
}

//出队
int Delete(LinkQueue *q,int *x) {
    LinkQueueNode *p;
    if(q->front == q->rear) return 0;
    p = q->front->next;
    q->front->next = p->next;   //队头元素p出队
    if(q->rear == p)    q->rear = q->front; //若队中只有一个元素p，则p出队后成为空队
    *x = p->data;
    free(p);
    return 1;
}
