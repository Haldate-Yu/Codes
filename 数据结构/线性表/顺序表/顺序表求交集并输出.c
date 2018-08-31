#include<stdio.h>
#define max 100

//定义
typedef struct {
    int data[max];
    int last;
}SeqList;

//查找
int Locate(SeqList *L,int e) {
    int i=0;
    while((i <= (*L).last)&&((*L).data[i] != e)){
        i++;
    }
    if(i <= (*L).last)
        return 1;
    else
        return 0;
}

//删除
int Delete(SeqList *L,int e) {
    int i = 0,j;
    while(i < (*L).last&&(*L).data[i]!=e) {
        i++;
    }
    for(j = i + 1;j < (*L).last;j++) {
        (*L).data[i++] = (*L).data[j];
    }
    (*L).last = i;
}

int main() {
    SeqList a,b,c,cross;
    a.last = 0;
    b.last = 0;
    c.last = 0;
    cross.last = 0;
    int count,sum_a,sum_b,sum_c;

    //a表元素输入
    printf("Input numbers of elements in Seqlist a:");
    scanf("%d",&sum_a);
    printf("Input elements in a:\n");
    for(count = 0;count < sum_a;count++) {
        scanf("%d",&a.data[count]);
        a.last++;
    }

    //b表元素输入
    printf("Input numbers of elements in Seqlist b:");
    scanf("%d",&sum_b);
    printf("Input elements in b:\n");
    for(count = 0;count < sum_b;count++) {
        scanf("%d",&b.data[count]);
        b.last++;
    }

    //c表元素输入
    printf("Input numbers of elements in Seqlist c:");
    scanf("%d",&sum_c);
    printf("Input elements in c:\n");
    for(count = 0;count < sum_c;count++) {
        scanf("%d",&c.data[count]);
        c.last++;
    }

    //b,c表交集
    for(count = 0;count <= sum_b;count++) {
        if(Locate(&c,b.data[count])) {cross.data[cross.last] = b.data[count];cross.last++;}
    }

    //a表删除
    for(count = 0;count < sum_a;count++) {
            if(Locate(&cross,a.data[count])) Delete(&a,a.data[count]);
    }

    //a表输出
    for(count = 0;count < a.last;count++) {
        printf("%d ",a.data[count]);
    }

    return 0;
}
