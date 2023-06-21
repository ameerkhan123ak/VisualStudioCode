#include<stdio.h>
int checkThumb(int n)
{
    int ans=5;
    while(ans<n)
    {
        ans = ans+8;
    }
    if(ans==n) return 1;
    return 0;
}
int checkIndex(int n)
{
    int ans=4;
    while(ans<n)
    {
        ans = ans+2;    
        if(ans==n) return 1;
        ans = ans+6;
        if(ans==n) return 1;
    }
    if(ans==n) return 1;
    else return 0;
}
int checkMiddle(int n)
{
    int ans=3;
    while(ans<n)
    {
        ans = ans+4;
        if(ans==n) return 1;
    }
    if(ans==n) return 1;
    else return 0;
}
int checkRing(int n)
{
    int ans = 2;
    while(ans<n)
    {
        ans = ans+6;
        if(ans==n) return 1;
        ans = ans+2;
        if(ans==n) return 1;
    }
    if(ans==n) return 1;
    else return 0;
}
int checkLittle(int n)
{
    int ans = 1;
    while(ans<n)
    {
        ans = ans +8;
        if(ans==n) return 1;
    }
    if(ans==n) return 1;
    else return 0;
}
int main()
{
    int n = 25;
    int thumb = checkThumb(n);
    int index = checkIndex(n);
    int middle = checkMiddle(n);
    int ring  = checkRing(n);
    int little = checkLittle(n);
    //printf("%d %d %d %d %d",thumb,index,middle,ring,little);
    if(thumb==1)printf("Thumb");
    else if(index==1) printf("index");
    else if(middle==1) printf("middle");
    else if(ring==1) printf("ring");
    else if(little==1) printf("little");
}