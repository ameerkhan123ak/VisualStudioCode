#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    char result[100];
    scanf("%s",s);
    int index=-1;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='A' && s[i]<='Z')
        {
            if(i!=0) result[++index] = ' ';
            s[i] += 32;
            result[++index] = s[i];
        }
        else  
        {
            result[++index] = s[i];
        }
    }
    result[++index] = '\0';
    printf("%s",result);
}
/*
input: ThisIsAnAutomation
output: this is an automation
*/