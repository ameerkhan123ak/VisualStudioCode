#include<stdio.h>
#include<string.h>
void reverse(char *s,int start,int end)
{
    while(start < end)
    {
        char t = s[start];
        s[start] = s[end];
        s[end] = t;
        start++;
        end--;
    }
}
int main()
{
    char s[100];
    scanf("%[^\n]s",s);
    int start=0;
    int end = strlen(s)-1;
    reverse(s,start,end);
    start=0;
    end=0;
    for(int i=0;;i++)
    {
        if(s[i]==' ')
        {
            reverse(s,start,end-1);
            start = i+1;
            end = i;
        }
        if(s[i]=='\0')
        {
            reverse(s,start,end-1);
            break;
        }
        end++;
    }
    printf("%s",s);
}