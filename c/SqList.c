/*
* coding = utf-8
* @Author : Khalil Chen
* @Created Time : 2022-11-01 20:55:57
* @Description : 
*/
#include "stdlib.h" 
#include "stdio.h" 

/*
* @Description: defination of SqList
* @Arguments:
* @Return: 
*/
#define MAXSIZE 100
typedef struct {
	int val[MAXSIZE];
	int len;
}*SqList;

/*
* @Description: construct a SqList
* @Arguments:
* @Return: SqList
*/
SqList ConstructSqList(){
	SqList ret = (SqList)malloc(sizeof(SqList));
	int number;
	scanf("%d", &number);
	int i = 0;
	while(number != -1){
		ret->val[i++] = number;
		scanf("%d", &number);
	}
	ret->len = i;

	return ret;
}

/*
* @Description: remove e into SqList
* @Arguments: SqList, int
* @Return: 
*/
void RemoveSqList(SqList l, int e){
	//find the index
	int i = 0;
	for(;i < l->len; ++i){
		if(l->val[i] == e)break;
	}
	//move 1 slot from e to end
	if(i != l->len)for(; i < l->len-1; ++i)l->val[i] = l->val[i+1]; 
	l->len--;
}

/*
* @Description: insert e from SqList
* @Arguments: SqList, int
* @Return: 
*/

void InsertSqList(SqList l, int index, int e){
	//move the SqList
	for(int i = l->len-1; i >= index; --i){
		l->val[i+1] = l->val[i];	
	}	

	//insert
	l->val[index] = e;
	l->len++;
}

void printSqList(SqList);
int main(int argc, char *const* argv)
{
    //begin main code
	SqList l = ConstructSqList();
	printSqList(l);
	InsertSqList(l, 0, 9);
	printSqList(l);
	RemoveSqList(l, 9);
	printSqList(l);
    return 0;
}
void printSqList(SqList l){
	for(int i = 0; i < l->len; ++i)printf("%d", l->val[i]);
	printf("\n");
}
