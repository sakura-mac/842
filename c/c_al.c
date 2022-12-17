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

int FirstIndex(char *p1, char *p2, int len2){
	int ret = -1;
	int i = 0;
	//find every first letter *(p1+i) and  *(p2)
	  //for every letter, cmp *(p1+i+k) and *(p2+k)
	    //if yes, ret = i;break;
		//if no, k = 1; continue loop
	for( ; p1[i] != '\0'; i++){
		if(p1[i] == p2[0] ){
			int k = 1;
			for( ; k < len2; k++){
				if(p1[i+k] != p2[k]){
					break;
				}
			}

			if(k != len2){
				k = 1;
			}else{
				ret = i;
				break;
			}
		}
	}
	return ret;
}
void Copy(char **ret, char *p1, int i){
	if(i == -1){
		//fill all
		while(*p1 != '\0'){
			**(ret) = *p1++;
			*ret += 1;
		}
	}else{
		//fill [p1, p1+i)
		for(int k = 0; k < i;(*ret)++, k++){
			**(ret) = *(p1+k);
		}	

	}
}
char *delstring(char *str1, char *str2){
	char *ret = (char *)malloc(sizeof(char)*100);
	char *p0 = ret;
	char *p1 = str1;
	char *p2 = str2;
	//len2
	int len2 = 0;
	while(*p2 != '\0'){
		p2++;
		len2++;
	}
	p2 = str2;
	while(1){
		int i = FirstIndex(p1, p2, len2);//relative i
	//	printf("this i: %d\n", i);
		if(i != -1){
			Copy(&p0, p1, i);//
			p1 = p1+i+len2;
		}else{
			Copy(&p0, p1, i);
			break;
		}
	}
	return ret;
}
void moveOddsBeforeEvens(int *arr, int size) {
  int i = 0, j = size - 1;

  while (i < j) {
    // 如果 arr[i] 是奇数，就继续遍历
    if (arr[i] % 2 == 1) {
      i++;
      continue;
    }

    // 如果 arr[j] 是偶数，就继续遍历
    if (arr[j] % 2 == 0) {
      j--;
      continue;
    }

    // 将 arr[i] 和 arr[j] 交换位置
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}
int main(int argc, char *const* argv)
{
    //begin main code
	int arr[] = {2, 3, 4, 2, 5, 3, 4, 6, 2, 1, 3};
	int size = sizeof(arr) / sizeof(arr[0]);
	moveOddsBeforeEvens(arr, size);

	// 输出执行后的数组
	for (int i = 0; i < size; i++) {
  		printf("%d ", arr[i]);
	}
    return 0;
    
}
