/*
* coding = utf-8
* @Author : Khalil Chen
* @Created Time : 2022-08-21 16:56:10
* @Description : 
*/
#include "stdlib.h" 
#include "stdio.h" 
#define N  10
#define ri record[i].
struct score{
    char sports[100]; //name of sports
    int athlete; //number of athlete
    char college[50];
    int place;
    float result;
};


int main(int argc, char *const* argv)
{
    //begin main code
	for(int i=1; i < 3; ++i){
		if(i == 1)continue;
		printf("%d", i);

	}
      return 0;
    
}
