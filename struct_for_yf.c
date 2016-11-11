#include <stdio.h>
#include <stdlib.h>

struct Lnode{
    double data;
    struct Lnode* next;
};

struct Lnode* ListHead = NULL;
struct Lnode* ListTail = NULL;

void show() {
    struct Lnode* p = ListHead->next;
    int i = 0;
    while(p != NULL) {
        printf("%d: %f\n", i, p->data);
        p = p->next;
        i++;
    }
}
void init() {
    ListHead = (struct Lnode *)malloc(sizeof(struct Lnode));
    printf("%p\n", ListHead);
    if(ListHead == NULL) {
        printf("init malloc error");
        exit(2);
    }

    ListHead->data = 0.0;
    ListHead->next = NULL;
    ListTail = NULL;
}

void add(double num) {
    struct Lnode* elem = (struct Lnode *)malloc(sizeof(struct Lnode));
    if(elem == NULL) {
        printf("add malloc error");
        exit(2);
    }
    elem->data = num;
    elem->next = NULL;
    if(ListTail !=  NULL) {
        ListTail ->next = elem;
    } else {
        ListHead -> next = elem;
    }
    ListTail = elem;
}

void delRange(double mink, double maxk) {
    struct Lnode* p = ListHead->next, *last = ListHead, *mark  = NULL;
    while(p != NULL) {
        if(p -> data > mink && p ->data < maxk) {
            mark = p;
            last->next = mark -> next;
            free(mark);
        } else {
            if(p->data >= maxk) {
                break;
            }
            last = p;
        }
        p = p->next;
    }
}

int main() {
    init();
    int i = 0;
    for(i=0;i<20;i++){
        add(i);
    }
    show();
    double mink, maxk;
    scanf("%lf%lf", &mink, &maxk);
    delRange(mink, maxk);
    show();
    return 0;
}
