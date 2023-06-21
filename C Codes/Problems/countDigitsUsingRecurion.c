#include<stdio.h>
void leftTraversal(int n)
{
	if(n==0) return;
	leftTraversal(n/10);
	printf("%d ",n%10);
}
void rightTraversal(int n)
{
	if(n==0) return;
	printf("%d ",n%10);
	rightTraversal(n/10);
}
void leftArrayTraversal(int *arr,int n)
{
	if(n==0) return;
    printf("%d ",*arr);
	leftArrayTraversal(arr+1,--n);
}
void rightArrayTraversal(int *arr,int n)
{
	if(n==0) return;
	rightArrayTraversal(arr+1,--n);
    printf("%d ",*arr);
}
int countDigits(int n)
{
	if(n==0) return 0;
	return 1 + countDigits(n/10);
}
int main()
{
	int n = 123067;
	int ans = countDigits(n);
	printf("%d",ans);
}
