/*
URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the "true"
length of the string. (Note: if implementing in Java, please use a character array so that you can
perform this operation in place.)
EXAMPLE
Input: "Mr John Smith ", 13
Output: "Mr%20John%20Smith"
*/
#include<stdio.h>
#include<string.h>
void replaceSpaces(char str[],int n)
{
    int spaceCount=0,index;
    for(int i=n-1;i>=0;i--)
    {
        if(str[i]!=' ') break;
        else 
        {
            str[i]='\0';
            n--;
        }
    }
    for(int i=0;i<n;i++) if(str[i]==' ') spaceCount++;
    index = n + spaceCount * 2;
    for(int i=n-1;i>=0;i--)
    {
        if(str[i]==' ')
        { 
            str[index-1] = '0';
            str[index-2] = '2';
            str[index-3] = '%';
            index = index-3;
        }
        else 
        {
            str[index-1] = str[i];
            index--;
        }
    }
    printf("%s",str);
}
int main()
{
    char str[100];
    scanf("%[^\n]s",str);
    int n = strlen(str);
    replaceSpaces(str,n);
}