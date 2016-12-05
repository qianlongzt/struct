#include <stdio.h>
#include <stdlib.h>

typedef struct bitNode{
    char data;
    char status; //status 0 tree point, 1 root node 2 other node
    struct bitNode *lChild;// if status is 0 then lChild point to root node
    struct bitNode *rChild;
    struct bitNode *parent;
}bitNode;

bitNode *createBitTree() {
    bitNode *tmp = (bitNode *)malloc(sizeof(bitNode));
    if(tmp == NULL) {
        printf("malloc error in createBitTree()\n");
        exit(1);
    }
    tmp->data = 0;
    tmp->status = 0;
    tmp->lChild = NULL;
    tmp->rChild = NULL;
    tmp->parent = NULL;
    return tmp;
}
void freeNode(bitNode* tree) {
    if(tree -> lChild != NULL) {
        freeNode(tree->lChild);
    }
    if(tree -> rChild != NULL) {
        freeNode(tree->rChild);
    }
    free(tree);
}
bitNode* addNode(bitNode *tree, char data, int place) {
    bitNode *tmp = (bitNode *)malloc(sizeof(bitNode));
    if(tmp == NULL) {
        printf("malloc error in addNode()\n");
        exit(1);
    }
    tmp->data = data;
    tmp->status = tree ->status == 0 ? 1:2;
    tmp->lChild = NULL;
    tmp->rChild = NULL;
    tmp->parent = tree;
    if(tree->status == 0 || place == 0) {
        if(tree -> lChild != NULL) {
            printf("tree lChild not empty\n");
            freeNode(tree->lChild);
        }
        tree -> lChild = tmp;
    } else {
        if(tree -> rChild != NULL) {
            printf("tree lChild not empty\n");
            freeNode(tree->rChild);
        }
        tree -> rChild = tmp;
    }
    return tmp;
}
void showTree(bitNode *tree) {
    if(tree->status == 0 ) {
        if(tree->lChild == NULL) {
            printf("empty tree\n");
        } else {
            printf("id          data   status          pid       place\n");
            showTreeWorker(tree->lChild, 0);
        }
    } else {
        printf("id          data   status          pid       place\n");
        showTreeWorker(tree, 0);
    }
}
void showTreeWorker(bitNode *tree, int place) {
    printf("%p    %5c    %3d       %p      %s\n", tree, tree->data, tree -> status, tree->parent, tree -> status <= 1?"root":place?"right":"left");
    if(tree -> lChild != NULL) {
          showTreeWorker(tree->lChild, 0);
    }
    if(tree -> rChild != NULL) {
          showTreeWorker(tree->rChild, 1);
    }
}



int main() {
    bitNode *tree = createBitTree();
    int num, normal, zero;
    while(scanf("%d", &num)) {
		if(0 == num) {
			zero++;
		} else {
			normal++;
		}
		if(normal + 1 == zero) {
			
			freeNode(tree->lChild);
		} else {
    		bitNode *node = addNode(tree, num, 0);
		}
	}
    return 0;
}
