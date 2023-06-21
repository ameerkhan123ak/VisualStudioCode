#include<stdio.h>
#include<string.h>
int main()
{
    char s[] = "PROGRAM";
//     printf("Enter the string: ");
//    scanf("%s",s);
    int n = strlen(s);
    int i1=0,i2=n-1;
    for(int i=0;i<n;i++)
    {
        for(int i=0;i<n;i++)
        {
            if(i1==i || i2==i) printf("%c",s[i]);
            else printf("  ");
        }
        i1++;
        i2--;
        printf("\n");
    }
}