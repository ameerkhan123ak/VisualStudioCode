#include<stdio.h>
int main()
{
    int v,w;
    scanf("%d %d",&v,&w);
    int tw = (w - 2*v)/2;
    int fw = v - tw;
    printf("four wheeler: %d\n",tw);
    printf("two wheeler: %d",fw);
}