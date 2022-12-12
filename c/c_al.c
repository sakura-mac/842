/*
* coding = utf-8
* @Author : Khalil Chen
* @Created Time : 2022-08-21 16:56:10
* @Description : 
*/
#include "stdlib.h" 
#include "stdio.h" 
#include "math.h"
#define N  10
#define ri record[i].
struct score{
    char sports[100]; //name of sports
    int athlete; //number of athlete
    char college[50];
    int place;
    float result;
};

float f(int x, int n){

	float s= 0;
	if(n == 0)s=x;
	else if(x==0)s=0;
	else s=f(x,n-1)+x*f(x,n-1);
	return s;

}
void caculate(){
	printf("input n\n");
	int n;
	scanf("%d", &n);
	int s = 0;
	int pre = 1;
	for(int i = 1; i <= n; i++){
		int tmp = 1;
		for(int j = 0; j < i; j++){
			tmp = tmp*(pre+j);
		}
		printf("no.%d, tmpsum = %d ", i, tmp);
		pre += i;
		s += tmp;
	}

}

/*
* @Description: put file 
* @Arguments:
* @Return: 
*/
void PutFile(){
	FILE *fp;
	char buf;
	int count = 0;
	fp = fopen("1.txt", "r");
	if(fp == NULL){
		printf("no file\n");
		exit(0);
	}

	while(fscanf(fp, "%c", &buf) > 0){
		count++;
		printf("%c", buf);
		if(buf != '\n'){
			count = 0;
			continue;
		}
		if(count % 30 == 0){
			printf("\n");
		}
		fclose(fp);
	}
}
int main(int argc, char *const* argv)
{
    //begin main code
    return 0;
    
}
