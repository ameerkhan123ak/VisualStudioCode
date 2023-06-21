#include<stdio.h>
#include<string.h>

void flames(char *a,char *b)
{
    char f[] = "flames";
    int l=1,sc=0,tc,rc,fc=5,k;
    int n = strlen(a);
    int m = strlen(b);
    tc = n+m;
    for(int i=0;i<n;i++)
    {
        char t = a[i];
        for(int j=0;j<m;j++)
        {
            if(t==b[j])
            {
                a[i] = -1;
                b[j] = -1;
                sc = sc+2;
                break;
            }
        }
    }
    rc = tc - sc;
    for(int i=0;;i++)
    {
        if(l==rc)
        {
            for(k=i;f[k]!='\0';k++)
            {
                f[k] = f[k+1];
            }
            f[k+1] = '\0';
            i--;
            fc--;
            l=0;
        }
        if(i==fc) i=-1;
        if(fc==0) break;
        l++;
    }
    if(f[0]=='f') printf("friend");
    if(f[0]=='l') printf("lover");
    if(f[0]=='a') printf("attract");
    if(f[0]=='m') printf("marry");
    if(f[0]=='e') printf("enemy");
    if(f[0]=='s') printf("sister");
}
int main()
{
    char a[100],b[100];
    printf("Enter the name: ");
    scanf("%s",a);
    printf("Enter the name: ");
    scanf("%s",b);
    flames(a,b);
}