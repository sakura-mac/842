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

/*
* @Description: sort the list (odd numbers are ahead of even numbers)
* @Arguments: SqList
* @Return: 
*/
void swap(SqList l, int i, int j){
	int tmp = l->val[i];
	l->val[i] = l->val[j];
	l->val[j] = tmp;

}
void SortOddEven(SqList l){
	int po, pe;
	po = pe = 0;
	//find the even and odd index, swap
	while(1){
		while(pe < l->len && l->val[pe] % 2 != 0)pe++;
		while(po < l->len && l->val[po] % 2 == 0)po++;
		if(pe == l->len || po == l->len)break;
		if(pe < po){
			swap(l, po, pe);
		}else{
			int tmp = po;
			po = pe;
			pe = tmp;
		}
		po++;pe++;
	}

}

/*
* @Description: find index of given k by b search
* @Arguments: SqList, int 
* @Return: 
*/
void BSearch(SqList list, int k){
	//[)
	int l = 0;
	int r = list->len;

	while(l < r){
		//left tendency,need to push right
		int mid = l + (r-l)/2;
		if(list->val[mid] >= k)r = mid;
		else l = mid+1;
	}
	if(l == list->len || list->val[l] != k)printf("not found the k!\n");
	else printf("%d", l);

}
void printSqList(SqList);
int main(int argc, char *const* argv)
{

    //begin main code
	SqList l = ConstructSqList();
	printSqList(l);
	SortOddEven(l);
	printSqList(l);
    return 0;
}
void printSqList(SqList l){
	for(int i = 0; i < l->len; ++i)printf("%d", l->val[i]);
	printf("\n");
}
