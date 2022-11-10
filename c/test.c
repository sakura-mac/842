/*
* coding = utf-8
* @Author : Khalil Chen
* @Created Time : 2022-11-02 20:34:11
* @Description : 
*/
#include "stdlib.h" 
#include "stdio.h" 
#include <math.h>
struct str1{
	char c[5];
	char *s;

};
int main(int argc, char *const* argv)
{
    //begin main code
	struct str1 s1[2] = {{"a","b"}, {"IJK","LMN"}};
	struct str1 *p[2];
	p[1] = &s1[1];
	printf("%s", ++p[1]->s);
    return 0;
}
