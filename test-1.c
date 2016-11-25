#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int check(ch) {
	if(end() == ch) {
		pop(); 
		return 1;
	} else {
		popAll();
		return 0;
	}
}

int nums[1000000];
char str[100000];

int main() {
	int times = 0;//当前字符串数 
	int count = 0;//有效个数 
	while(scanf("%d", &times) != EOF && times != 0)  {
		count = 0;
		getchar(); 
		memset(nums, 0, sizeof(nums));
		while(times--) {
			int flag = 1;
			gets(str);
			int len, i;
			len = strlen(str);
			for(i = 0; i < len && flag == 1; i++) {
				switch(str[i]) {
	                case '(':
	                case '[':
	                case '{':
	                    push(str[i]);
	                    break;
	                case ')':
	                    if (check('(') != 1) {
							flag = 0;
						}
	                    break;
	                case ']':
	                    if (check('[') != 1) {
							flag = 0;
						}
	                    break;
	                case '}':
	                    if (check('{') != 1) {
							flag = 0;
						}
	                    break;
	                default:
	                	flag = 0;
	                	break;
				}
			}
			
			if(flag != 0 && popAll() == 0 && len != 0) {
				nums[count++] = len;
			}
        }
        
		printf("%d\n", count);
        int i = 0;
		for(i = 0; i < count; i++) {
			printf("%d ", nums[i]);
		}
		printf("\n");
		
		int j = 0, tmp, min;
		for(i = 0; i < count - 1; i++) {
			min = i;
			for(j = i + 1; j < count; j++) {
				if(nums[min] > nums[j]) {
					min = j;
				}
			}
			tmp = nums[min];
			nums[min] = nums[i];
			nums[i] = tmp;
		}
		
		if(count % 2) {
			printf("%d\n", nums[count/2]);
		} else {
			printf("%d\n", (nums[count/2 - 1] + nums[count/2])/2);
		}
	}
    return 0;
}
