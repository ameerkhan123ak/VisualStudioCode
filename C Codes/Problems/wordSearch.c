#include<stdio.h>
#include<math.h>

int main()
{
    char str[100],word[100],a[100][100];
    int i,j,k,c,index,rc,n;
    printf("Enter the String: ");
    scanf("%s",str);

    for(n=0;str[n];n++); //length

    if(n=sqrt(n)*sqrt(n)) rc = sqrt(n)+1; //dimension of 2d array
    else n=sqrt(n);

    for(index=0,i=0;i<rc;i++) // store data in 2d array
    {
        for(j=0;j<rc && str[index]!='\0';j++)
        {
            a[i][j] = str[index++];
        }
    }

    for(i=0;i<rc;i++) //print data
    {
        for(j=0;j<rc;j++)
        {
            printf("%c ",a[i][j]);
        }
        printf("\n");
    }
    printf("Enter the word: ");
    scanf("%s",word);

    for(i=0;i<rc;i++)
    {
        for(j=0;j<rc;j++)
        {
            if(a[i][j]==word[0])
            {
                for(k=j,c=0;a[i][k]==word[c] && word[c]!='\0';k++,c++);
                if(str[c]=='\0')
                {
                    printf("\nstart index <%d %d> end index <%d %d>",i,j,i,k-1);
                }
            }
        }
    }
    for(i=0;i<rc;i++)
    {
        for(j=0;j<rc;j++)
        {
            if(a[j][i]==word[0])
            {
                for(k=j,c=0;a[k][i]==word[c] && word[c]!='\0';k++,c++);
                if(word[c]=='\0')
                {
                    printf("start index <%d %d> end index <%d %d>",j,i,k-1,i);
                }
            }
        }
    }
}