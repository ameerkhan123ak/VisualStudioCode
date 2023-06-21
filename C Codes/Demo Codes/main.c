#include<stdio.h>
#include<string.h>
int main()
{
    char s[] = "abbcccddddeeeee";
    int count=1;
    int ch;
    for(int i=0;i<strlen(s);i++)
    {
        ch = s[i];
        if(s[i]!=s[i+1])
        {
            printf("%c%d",s[i],count);
            count=1;
        }
        else if(s[i+1] =='\0') printf("%c%d",ch,count);
        else count++;
    }
}