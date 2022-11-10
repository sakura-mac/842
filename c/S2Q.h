/*
* coding = utf-8
* @Author : Khalil Chen
* @Created Time : 2022-11-01 20:56:26
* @Description : */
#include "stdlib.h" 
#include "stdio.h" 
#define Maxsize 100
/*
* @Description: stack 
* @Arguments:
* @Return: 
*/
typedef struct{
	void *val[Maxsize];
	int top;
}stack;

stack *Stack(){
	stack *st = (stack *)malloc(sizeof(stack));
	st->top = -1;
	return st;

}
/*
* @Description: queue
* @Arguments:
* @Return: 
*/
typedef struct{
	void *val[Maxsize];
	int front, near;
}queue;

queue *Queue(){
	queue *q = (queue *)malloc(sizeof(queue));
	q->front = 0;
	q->near = 0;
	return q;
}
/*
* @Description: stack ops
* @Arguments:
* @Return: 
*/
void *Pop(stack *st){
	void *ret = 0;
	if(st->top == -1){
		printf("the stack is empty!\n"); 
	}
	else{
		ret = st->val[st->top];
		(st->top)--;
	} 

	return ret;
}

void  Push(stack *st, void *val){
	if(st->top == Maxsize-1)printf("the stack is full!\n");
	else st->val[++(st->top)] = val;
}

/*
* @Description: queue ops
* @Arguments:
* @Return: 
*/

void *DeQueue(queue *q){
	void *ret = 0;
	//[)
	if(q->front == q->near)printf("the queue is empty!\n");
	else{
		ret = q->val[q->front];
		if(q->front == Maxsize-1)q->front = 0;
		else (q->front)++;
	}
	return ret;
}

void InQueue(queue *q, void *val){
	//留一个空好判断满，否则无法区分满还是空
	if((q->near+1)%Maxsize == q->front){
		printf("the queue is full!\n");
	}else{
		q->val[q->near] = val;
		q->near = (q->near+1)%Maxsize;
	}
}
