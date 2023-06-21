#include<stdio.h>
#include<math.h>
int main()
{
    int r1,r2,n,min;
    scanf("%d %d %d %d",&r1,&n,&r2,&min);
    int hr = ceil(min/60);
    if(hr<=n)
      printf("%0.f",hr*r1);
    else 
      printf("%d",(n*r1)+(hr-n)*r2);
}