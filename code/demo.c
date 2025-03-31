#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void test(){
    // int i = 1;
    // switch(i%3){
    //     case 0: printf("zero\n");
    //     case 1: printf("one\n");
    //     case 2: printf("two\n");
    // }
    // int count = 100;
    // while(count>=0){
    //     count--;
    //     printf("count:%d\n",count);
    // }
    // printf("do it\n");

    // 猜数
    int number;
    int count = 0;
    srand(time(0));
    int random = rand()%100+1;
    printf("已想好一个1-100内的数字\n");
    do{
        printf("猜一个1-100内的数\n");
        scanf("%d",&number);
        count++;
        if(number>random){
            printf("max\n");
        }else if(number<random){
            printf("s\n");
        }
    }while(number!=random);
    printf("你用了%d次猜中答案\n",count);
}
int main(){
    test();
    return 0;
}