/*
* coding = utf-8
* @Author : Khalil Chen
* @Created Time : 2022-08-21 16:56:10
* @Description : 
*/
#include "stdlib.h" 
#include "stdio.h" 

struct s 
{
    int n;
    struct s *next;
};
int main(int argc, char *const* argv)
{
    //begin main code
    struct s a[3] = {10, &a[1], 5, &a[2], 9, '\0'}, *p;
    p = &a[0];
    printf("hello world! \n");
    printf("%d %d", p++->n, ++p->n);

    return 0;
    
}
