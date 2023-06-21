#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    int r;
    int digit;
    int sum=0;
    int  mul;
    scanf("%d%d",&r,&n);
    digit=n%10;
    sum+=digit;
    n=n/10;

    mul=sum*r;

    if (mul%9==0){
        printf("9");
    }
    else{
        printf("%d",mul%9);
    }
}
    