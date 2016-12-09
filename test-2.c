#include <stdio.h>
#include <stdlib.h>

typedef struct bitNode{
    int data;
    char status; //status 0 tree point, 1 root node 2 other node
    struct bitNode *lChild;// if status is 0 then lChild point to root node
    struct bitNode *rChild;
}bitNode;

bitNode *createBitTree() {
    bitNode *tmp = (bitNode *)malloc(sizeof(bitNode));
    if(tmp == NULL) {
        exit(1);
    }
    tmp->data = 0;
    tmp->status = 0;
    tmp->lChild = NULL;
    tmp->rChild = NULL;
    return tmp;
}
void freeNode(bitNode* tree) {
	if(tree == NULL) {
		return;
	}
    if(tree -> lChild != NULL) {
        freeNode(tree->lChild);
    }
    if(tree -> rChild != NULL) {
        freeNode(tree->rChild);
    }
    free(tree);
}
bitNode* addNode(bitNode *tree, int data, int place) {
    bitNode *tmp = (bitNode *)malloc(sizeof(bitNode));
    if(tmp == NULL) {
        exit(1);
    }
    tmp->data = data;
    tmp->status = tree ->status == 0 ? 1:2;
    tmp->lChild = NULL;
    tmp->rChild = NULL;
    if(tree->status == 0 || place == 0) {
        if(tree -> lChild != NULL) {
            freeNode(tree->lChild);
        }
        tree -> lChild = tmp;
    } else {
        if(tree -> rChild != NULL) {
            freeNode(tree->rChild);
        }
        tree -> rChild = tmp;
    }
    return tmp;
}
void showTree(bitNode *tree) {
	if(tree == NULL) {
		printf("0 ");
		return;
	} else {
		if(tree->status == 0) {
			tree = tree->lChild;
		}
		printf("%d ", tree->data);
		showTree(tree->lChild);
		showTree(tree->rChild);
	}
}
void create(bitNode* node,int place) {
	int num;
	bitNode *tmp;
	if(scanf("%d", &num) == EOF) {
		exit;
	}
	if(num != 0) {
		tmp = addNode(node, num, place);
		create(tmp, 0);
		create(tmp, 1);
	}
}

int s[10000];
int count = 0 ;
int sum = 0;

int max(int a, int b) {
	return a>b?a:b; 
}

int search2(bitNode* node, int status) {
	if(node == NULL) {
		return 0;
	} else {
		if(status == 0) {
			return max(
						max(
							search2(node->lChild, 0) + search2(node->rChild, 0),
							search2(node->lChild, 0) + search2(node->rChild, 1)
						),
						max(
							search2(node->lChild, 1) + search2(node->rChild, 0),
							search2(node->lChild, 1) + search2(node->rChild, 1)
						)
					);
		} else {
			return node->data + search2(node->lChild, 0) + search2(node->rChild, 0);
		}
	}
}


int main() {
    while(1) {
    	bitNode *tree = createBitTree();
    	count = 0;
	    create(tree, 0); 
		int m;
		m = max(search2(tree->lChild, 0), search2(tree->lChild, 1));
		printf("%d\n", m);
		freeNode(tree);
	} 
    return 0;
}
