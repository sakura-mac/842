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
Tree BiTree(){
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
	printf("%d",t->val);
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
* @Arguments:
* @Return: 
*/
int trace[10];
void backtrace(Tree t){

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
* @Description: find all parents of specific node
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
int main(int argc, char *const* argv)
{
    //begin main code
	Tree t = BiTree();
//	InOrderTraverse(t);
	//LevelTraverse(t);
	InOrderTraverseByStack(t);
    return 0;
}
