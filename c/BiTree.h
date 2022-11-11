#pragma once
/*
* coding = utf-8
* @Author : Khalil Chen * @Created Time : 2022-11-01 20:55:07
* @Description : 
*/ #include "stdlib.h" 
#include "stdio.h" 
#include "S2Q.h" 
/*
* @Description: defination of tree
* @Arguments:
* @Return: 
*/
typedef struct TNode{
	int val;
	struct TNode *lchild;
	struct TNode *rchild;
}TNode, *Tree;

/*
* @Description: construct a bi tree
* @Arguments:
* @Return: Tree 
*/
void insert(Tree t, TNode *f, int d,int val){
	if(t == NULL){
		TNode *nnode = (TNode *)malloc(sizeof(TNode));
		nnode->val = val;
		if(d)f->rchild = nnode;
		else f->lchild = nnode;
		return;
	}

	if(val < t->val)insert(t->lchild, t, 0, val);
	else insert(t->rchild, t, 1, val);
	
}
Tree ConstructBiTree(){
	//没有虚拟头节点，所以只能多写
	Tree t = (TNode *)malloc(sizeof(TNode));
	int number;
	scanf("%d", &number);
	if(number != -1)t->val = number;

	scanf("%d", &number);
	while(number != -1){
		insert(t, NULL, 0, number);	
		scanf("%d", &number);
	}
	return t;

}

/*
* @Description: traverse the tree in 3 recurising ways * @Arguments: Tree
* @Return: 
*/
void InOrderTraverse(Tree t){

	if(t == NULL)return;
	//if preTraverse, pirnt here
	InOrderTraverse(t->lchild);
	printf("%d ",t->val);
	InOrderTraverse(t->rchild);
	//if PostTraverse, pirnt here
}
/*
* @Description: traverse the tree in level way
* @Arguments:
* @Return: 
*/
void LevelTraverse(Tree t){
	printf("ready to level Traverse!\n");

	queue *q = Queue();
	InQueue(q, t);
	while(q->front != q->near){
		TNode *cur = (TNode *)DeQueue(q); 
		printf("%d", cur->val);	

		if(cur->lchild)InQueue(q, cur->lchild);
		if(cur->rchild)InQueue(q, cur->rchild);
	}
}

/*
* @Description: InOrder traverse the tree by stack
* @Arguments:
* @Return: 
*/
void InOrderTraverseByStack(Tree t){
	stack *st = Stack();
	TNode *p = t;
	//p judgement is for NULL node
	while(p || st->top != -1){
		if(p){
			//if preorder traverse, print here
			Push(st, p);
			p = p->lchild;
		}else{
			p = Pop(st);
			//if inorder traverse, print here
			printf("%d", p->val);
			p = p->rchild;
		}

	}
	
}

/*
* @Description: find all the seaquence(from the root) if vals sum up to k 
* @Arguments: Tree, int
* @Return: 
*/
int track[10][10];//assuming that is enough for store the result
int kr = 0;
int trace[10];
int ti = 0;
void backtrace(Tree t, int k){
	//add in trace(judge in next process stack), in traverse, withdraw the trace
	if(k == 0){
		for(int i = 0; i < ti; i++){
			track[kr][i] = trace[i];
		}
		kr++;
		return;
	}
	
	//3 steps
	if(t->lchild){
		int lval = t->lchild->val;
		trace[ti++] = lval;
		k -= lval;
		backtrace(t->lchild, k);
		k += lval;
		ti--;
	}
	if(t->rchild){
		int rval = t->rchild->val;
		trace[ti++] = rval;
		k -= rval;
		backtrace(t->rchild, k);
		k += rval;
		ti--;
	}	
}
void Backtrace(Tree t, int k){
	//backtrace 预处理
	trace[ti++] = t->val;

	backtrace(t, k-t->val);
	printf("bakctrace is done!\n");
	for(int i = 0; i < kr; ++i){
		for(int j = 0; j < 10; ++j){
			printf("%d", track[i][j]);
		}
		printf("\n");
	}
}
/*
* @Description: find the father of specific node
* @Arguments: Tree, TNode * 
* @Return: 
*/
TNode *FF(Tree t, TNode *node){
	if(t == NULL)return NULL;	
	//traverse the tree, to find the lchild is node or rchild is node
	TNode *father;
	if(t->lchild == node || t->rchild == node)father = t;
	else{
		father = FF(t->lchild, node);
		if(!father)father = FF(t->rchild, node); 
	}
	return father;
}
/*
* @Description: find all ancestors of specific node
* @Arguments:Tree, int 
* @Return: 
*/
int printAncestor(Tree t, int x){
	if(!t)return 0;
	if(t->val == x)return 1;

	if(printAncestor(t->lchild, x) || printAncestor(t->rchild, x)){
		printf("%d ", t->val);
		return 1;
	}

	return 0;
}

/*
* @Description: find all ancestors of specific node index 
* @Arguments: int *,  int
* @Return: 
*/
void printAncestorStoredInArr(int *t, int indexX){
	int *p = t;
	//assuming that root index from 1, lchild = 2*index, rchild = lchild+1,then find the father is easy
	int index = indexX / 2; 
	while(index){
		printf("%d", *(p+index));
		index /= 2;

	}
	//if not knowing the index of specifc node,you need to find the index first by traverse the tree func below
}

/*
* @Description: traverse the tree if arr stored
* @Arguments: int *, int, int
* @Return: 
*/
int traverseStoredInArr(int *t, int x, int len){
	int index = 1;	
	stack *st = Stack();

	while(index < len || st->top != -1){
		if(index < len){
			printf("%d", t[index]);
			if(t[index] == x){
				return index;
			}
			Push(st, (void *)index);
			index *= 2;
		}else{
			int nindex = (int)Pop(st);
			index = nindex * 2 + 1;
		}

	}
	return -1;

}
/*
* @Description: find the common father of two nodes
* @Arguments: Tree, TNode, TNode
* @Return: 
*/

int CommonFather(Tree l, TNode *n1, TNode *n2){
	if(!l)return 0;
	if(l == n1 || l== n2)return 1;
	
	if(CommonFather(l->lchild, n1, n2) && CommonFather(l->rchild, n1, n2)){
		//it will print lowest ancestor of two nodes,if want all,  add "return 1" in if sentence
		printf("%d", l->val);
	}

	return 0;

}

/*
* @Description: pre to post 
* @Arguments:
* @Return: 
*/


/*
* @Description: pirnt BiTree inorder
* @Arguments:
* @Return: 
*/
void printBiTree(Tree t){
	InOrderTraverse(t);
	printf("\n");
}
