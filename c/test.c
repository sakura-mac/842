/*
* coding = utf-8 
* @Author : Khalil Chen 
* @Created Time : 2022-11-02 20:34:11 
* @Description : 
*/
#include "stdlib.h" 
#include "stdio.h" 
#include <math.h>
#include "BiTree.h"
#include "LinkList.h"
#include "Sort.h"
#include "SqList.h"

struct str1{
	char c[5];
	char *s;

};
void LinkListTest();
void SqListTest();
void BiTreeTest();
void GraphTest();
int main(int argc, char *const* argv)
{
    //begin main code
	//LinkList();
	//SqListTest();
	//BiTreeTest();
	//GraphTest();
    return 0;
}

void LinkListTest(){
	printf("Test LinkList function:---------------\n");
	LinkList l = TailInsert();
	printLinkList(l);
	//test function
	bsort(l); 
	//pirnt the result
	printLinkList(l);
	printf("Test LinkList finished:---------------\n");

}
void SqListTest(){
	printf("Test SqList function:---------------\n");
	SqList l = ConstructSqList();
	printSqList(l);
	//test function
	SortByBipolar(l); 
	//pirnt the result
	printSqList(l);
	printf("Test SqList finished:---------------\n");
}
void BiTreeTest(){
	printf("Test BiTree function:---------------\n");
	Tree t = ConstructBiTree();
	printBiTree(t);
	//test function
	backtrace(t, 5);
	//pirnt the result
	printf("Test BiTree finished:---------------\n");
}
void GraphTest(){

}

