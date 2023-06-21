#include<stdio.h>
#include<string.h>
int main()
{
    char s[100],t[100];
    scanf("%[^\n]%*c %[^\n]%*c",s,t);
    int count=0;
    while(1)
    {
        if(strcmp(s,t)==0) 
        {
            break;
        }
        else 
        {
            for(int i=0;i<strlen(s);i++)
            {
                if(s[i]!='a') s[i] -= 1;
            }
            count++;
        }
    }
    printf("%d",count);
}