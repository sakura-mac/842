/*
* coding = utf-8
* @Author : Khalil Chen
* @Created Time : 2022-11-01 20:52:32
* @Description : 
*/
#include "stdlib.h" 
#include "stdio.h" 


/*
* @Description:Define LinkList
* @Arguments:
* @Return: 
*/
typedef struct LNode{
	int val;
	struct LNode *next;
}LNode, *LinkList;

/*
* @Description: construct LinkList with head node by HeadInsert
* @Arguments:
* @Return: head node
*/
LinkList HeadInsert(){
	LNode *l = (LNode *)malloc(sizeof(LNode));//head node,no data
	l->next = NULL;
	int number;
	scanf("%d", &number);
	while(number != -1){
		LNode *p = (LNode *)malloc(sizeof(LNode));
		p->val = number;
		p->next=l->next;
		l->next = p;
		scanf("%d", &number);
	}
	return l;
}


/*
* @Description: construct LinkList with head node by TailInsert
* @Arguments:
* @Return: head node
*/
LinkList TailInsert(){
	LNode *l = (LNode *)malloc(sizeof(LNode));
	l->next = NULL;
	LNode *t; 
	t = l;
	int number;
	scanf("%d", &number);
	while(number != -1){
		LNode *p = (LNode *)malloc(sizeof(LNode));
		p->val = number;
		p->next = NULL;

		t->next = p;
		t = p;
		scanf("%d", &number);
	}
	return l;
}

/*
* @Description: print LinkList in order
* @Arguments:
* @Return: 
*/
void printLinkList(LinkList l){
	LNode *p = l->next;
	while(p){
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}
/*
* @Description: search LinkList in order
* @Arguments: LinkList, int
* @Return: 1 or 0 
*/
int SearchByForward(LinkList l, int val){
	LNode *p = l;
	while(p){
		if(p->val == val)return 1;
		p = p->next;
	}
	return 0;
}

/*
* @Description: print LinkList in reversed order
* @Arguments: LinkList
* @Return: 
*/
void SearchByBackward(LinkList l){
	if(l == NULL)return;
	SearchByBackward(l->next);
	printf("%d", l->val);
}

/*
* @Description: search Linklist back k val,k >= 1
* @Arguments: LinkList, int
* @Return: 
*/
int cnt = 0;
int recurse(LinkList l, int k){
	if(l == NULL)return -1;

	int val = recurse(l->next, k);
	cnt++;
	if(k == cnt)return l->val;
	return val;
}
void SearchKVal(LinkList l){
	int k = 0;
	scanf("%d", &k);
	int val = recurse(l, k);
	printf("%d", val);
}

/*
* @Description: find the middle of the LinkList
* @Arguments: LinkList
* @Return: 
*/
int MiddleOfLinkList(LinkList l){
	if(l == NULL)return -1;

	LNode *s,*f;
	s = f = l;
	while(f && f->next){
		f = f->next->next;
		s = s->next;
	}
	return s->val;//if odd, s = middle, if even, s = len/2 + 1
	
}

/*
* @Description: find the intersection of two LinkLists * @Arguments: LinkList, LinkList
* @Return: 
*/
int Intersection(LinkList l1, LinkList l2){
	int val = -1;
	//m:m+p+n = n:n+p+m
	LNode *l,*r;
	l = l1;
	r = l2;
	int cnt = 0;
	while(r != l){
		if(cnt == 2)return -1;//no intersection

		if(l->next == NULL){l = l2;cnt++;}
		else l = l->next;
		
		if(r->next == NULL)r = l1;
		else r = r->next;
	}
	val = r->val;
	return val;
}

/*
* @Description: insert node into LinkList
* @Arguments:LinkList, int, int
* @Return: 
*/
void insertNode(LinkList l, int index, int val){//index from 0
	LNode *p = l;
	if(l == NULL){
		LNode *node = (LNode *)malloc(sizeof(LNode));
		l = node;
		return;
	}
	//find the pre node, insert
	while(p && --index){
		p = p->next;
	}
	//insert
	LNode *node = (LNode *)malloc(sizeof(LNode));
	node->next = p->next;
	p->next = node;
}

/*
* @Description: delete node from LinkList
* @Arguments:LinkList, int
* @Return: 
*/
void deleteNode(LinkList l, int index){//index from 0
	LNode *p = l;
	if(l == NULL)return;
	//find the pre node, delete
	while(p && --index){
		p = p->next;
	}
	if(p->next)p->next = p->next->next;
}

/*
* @Description: find the longest dup list in the LinkList
* @Arguments:LinkList 
* @Return: 
*/
int FLU(LinkList l){
	if(l == NULL)return -1;

	int val = l->val;
	int len = 1;
	int cnt = 1;
	//find the longest dup
	LNode *p = l;
	while(p->next){
		if(l->val != l->next->val){
			if(len > cnt){
				val = l->val;
				cnt = len;
			}
			len = 0;
		}
		p = p->next;
		len++;
	}
	return val;
}

/*
* @Description: merge two LinkList 
* @Arguments:LinkList, LinkList
* @Return: 
*/
LNode * createNode(){
	LNode *node = (LNode *)malloc(sizeof(LNode));
	node->next = NULL;
	return node;
}
void fillList(LinkList px){
	while(px){
		LNode *nnode = createNode();
		nnode->val = px->val;
		px = px->next;
	}
}
LinkList merge2L(LinkList l1, LinkList l2){
	LNode *p1 = l1;
	LNode *p2 = l2;
	if(l1 == NULL && l2 == NULL)return NULL;

	LNode *node = createNode();
	LNode *p = node;
	while(p1 && p2){
		LNode *nnode = createNode(); 
		p->next = nnode;
		p = nnode;

		nnode->val = p1->val;
		if(p2->val < p1->val){
			nnode->val = p2->val;
			p2 = p2->next;
			continue;
		}
		p1 = p1->next;
	}
	if(p1 == NULL)fillList(p2);
	else fillList(p1);

	return node;
}

/*
* @Description: reverse LinkList
* @Arguments:LinkList
* @Return: LinkList 
*/
LinkList reverse(LinkList l){
	//rever node by node in order
	//tmp = cur->next; cur->next = pre; pre = cur; cur = tmp
	LNode *cur = l;
	LNode *pre = NULL;

	while(cur){
		LNode *tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	return pre;
}

/*
* @Description: bubble sort the LinkList
* @Arguments:LinkList
* @Return: 
*/
void  bsort(LinkList l){//increasing order, with head node
	//head node will not change, it is good to syn with index
	
	if(l->next == NULL)return ;

    LNode *p = l->next;
	//get the len
	int len = 0;
	while(p){
		len++;
		p = p->next;
	}
	//2 loop
	int ocnt = 0;
	while(ocnt < len-1){//out loop i is unused
		LNode *pre = l;
		int icnt = 0;
		while(icnt < len-1-ocnt){
			LNode *cur = pre->next;
			//exchange logic:
			if(cur->val > cur->next->val){
				LNode *tmp = cur->next;
				cur->next = tmp->next;
				tmp->next = cur;
				pre->next = tmp;
			}
			//
			pre = pre->next;
			icnt++;
		}
		ocnt++;
	}
}

