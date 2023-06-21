#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    char s[] = "ABC";
    int l = pow(2,strlen(s))-1;
    for(int i=1;i<=l;i++)
    {
        int t = i;
        int index=0;
        while(t)
        {
            int digit=t%2;
            t/=2;
            if(digit==1) printf("%c",s[index]);
            index++;
        }
        printf("\n");
    }
}