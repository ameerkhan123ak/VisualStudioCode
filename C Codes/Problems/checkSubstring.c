#include<stdio.h>
#include<string.h>
int main()
{
    char a[100] = "abcd";
    char b[100] = "cdabcdab";
    char t[100];
    strcpy(t,a);
    int n = strlen(b);
    int count=1;
    while(n--)
    {
        if(strstr(a,b)) break;
        strcat(a,t);
        count++;
    }
    printf("%d",count);
}