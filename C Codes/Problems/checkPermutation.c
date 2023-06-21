#include<stdio.h>
#include<string.h>
void sort(char *s)
{
    int n = strlen(s);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(s[i]>s[j])
            {
                char t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
    }
}
int main()
{
    char s1[] = "apple";
    char s2[] = "elppa";
    sort(s1);
    sort(s2);
    int n = strlen(s1);
    int flag=1;
    for(int i=0;i<n;i++)
    {
        if(s1[i]!=s2[i]) 
        {
            flag=0;
            break;
        }
    }
    if(flag) printf("YES");
    else printf("NO");
}