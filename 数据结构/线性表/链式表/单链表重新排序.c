#include<stdio.h>

//定义
typedef struct Node {
    struct Node * next;
    int data;
}Node,*LinkList;

//初始化
void InitList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
}

void change(LinkList l) {
    Node *p,*q,*pl,*pre;
    if(l->next == NULL) return 0;
    pl = l->next;
    pre = pl;
    p = pl->next;
    //顺次检查所有节点,对比pl->data小的放在头节点后，大的不做处理
    while(p) {
        q = p->next;
        if(p->data >= pl->data) {pre = p;p = q;}
        else {pre->next = p->next;p->next = l->next;l->next = p;p = q;}
    }
}
