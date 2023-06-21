#include<stdio.h>
#include<string.h>

int implement_strstr(char s[],char x[])
{
    int index=0,place=-1;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]==x[index])
        {
            index++;
            if(index>=strlen(x)) return i-strlen(x)+1;
        }
        else index=0;
    }
    return -1;
}
int main()
{
    char s[] = "geeksforgeeks";
    char x[] = "for";
    printf("%d",implement_strstr(s,x));
}