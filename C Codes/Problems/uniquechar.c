#include<stdio.h>
int main()
{
    char str[] = "abcd";
    int n = sizeof(str);
    int arr[50] = {0}; 
    int flag=1;
    for(int i=0;i<n;i++)
    {
        int val = str[i];
        if(arr[val])
        {
            flag=0;
            break;
        }
        arr[val] = 1;
    }
    if(flag==1) printf("TRUE");
    else printf("FALSE");
}