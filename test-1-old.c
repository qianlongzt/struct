#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
[[[
3

]]]
3

(((]]]
6

[][]
0

([[)]]
2

[(]
1

[)]
1

[((]))]
1

[(])
2
*/

/*for stack*/
void show();
void push(char);
void pop();
char end();
struct Lnode* StackEnd = NULL;

struct Lnode{
    char data;
    struct Lnode* next;
};

void show() {
    struct Lnode* p = StackEnd;
    int i = 0;
    while(p != NULL) {
        printf("%c", p->data);
        p = p->next;
    }
}

void push(char ch) {
    struct Lnode* elem = (struct Lnode *)malloc(sizeof(struct Lnode));
    if(elem == NULL) {
        printf("push malloc error");
        exit(2);
    } else {
        elem -> data = ch;
        if(StackEnd == NULL) {
            StackEnd = elem;
            elem -> next = NULL;
        } else {
            elem -> next = StackEnd ;
            StackEnd = elem;
        }
    }

}
//pop last element
void pop() {
    struct Lnode *tmp;
    tmp = StackEnd;
    if(StackEnd != NULL) {
        char ch= tmp -> data;
        StackEnd = StackEnd ->next;
        free(tmp);
    }
}

int popAll() {
    struct Lnode *next;
    int i = 0;
    while(StackEnd != NULL) {
        i++;
        pop();
    }
    return i;
}
//return last element
char end() {
    if(StackEnd != NULL) {
        return StackEnd -> data;
    } else {
        return 0;
    }
}

int check(char ch) {
	int count = 0;
	if(ch != end()) {
		count++;
		if(end() != 0) {
			count += check(ch);
		}
        
    } else {
		pop();
	}
    return count;
} 

int main() {
    char ch;
    int errCount = 0;
    while(scanf("%c", &ch) != EOF){
        if(ch != '\n') {
             switch(ch) {
                case '(':
                case '[':
                case '{':
                    push(ch);
                    break;
                case ')':
                    errCount += check('('); 
                    break;
                case ']':
                    errCount += check('['); 
                    break;
                case '}':
                    errCount += check('{'); 
                    break;
             }
        } else {
            printf("%d\n", errCount + popAll());
            errCount = 0;
        }
    }
    return 0;
}
