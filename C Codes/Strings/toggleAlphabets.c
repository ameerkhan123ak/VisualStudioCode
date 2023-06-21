#include<stdio.h>
#include<string.h>
int strlength(char *str)
{
	int count=0;
	while(str[count]!='\0') count++;
	return count;
}
void stringCopy(char* str1,char* str2)
{
	int l = strlength(str1);
	int i=0;
	for(i=0;i<str1[i]!='\0';i++) str1[i] = str2[i];
	str1[i] = '\0';
	printf("%s",str1);
}
int stringPalindrome(char* str)
{
	int l = strlength(str);
	char temp[l];
	int j=-1;
	for(int i=l-1;i>=0;i--) temp[++j] = str[i];
	for(int i=0;i<l;i++)
	if(temp[i] != str[i]) return 0;
	return 1;
}
void stringReverse(char *str)
{
	int l = strlength(str);
	int start=0;
	int end=l-1;
	while(start<end)
	{
		char c = str[start];
		str[start] = str[end];
		str[end] = c;
		start++;
		end--;
	}
	for(int i=0;i<l;i++) printf("%c",str[i]);
}
void stringCat(char *str1,char *str2)
{
	int l1 = strlength(str1);
	int l2 = strlength(str2);
	char arr[l1+l2];
	int j=-1;
	for(int i=0;i<l1;i++) arr[i] = str1[i];
	for(int i=l1;i<l1+l2;i++) arr[i] = str2[++j];
	arr[l1+l2] = '\0';
	for(int i=0;i<l1+l1;i++) printf("%c",arr[i]);
} 
int stringComparison(char *str1,char *str2)
{
	int l1 = strlength(str1);
	int l2 = strlength(str2);
	if(l1<l2 || l2<l1) return 0;
	for(int i=0;i<l1;i++) if(str1[i] != str2[i]) return 0;
	return 1;
}
int stringCharacter(char *str,char c)
{
	int l = strlength(str);
	for(int i=0;i<l;i++)
	if(str[i]==c) return 1;
	return 0;
}
void substring(char* str1,int start,int end)
{
	int l = end - start;
	char arr[l];
	int j=-1;
	for(int i=start;i<end;i++)
	arr[++j] = str1[i];
	arr[++j] = '\0';
	printf("%s",arr);
	//for(int i=0;i<l;i++) printf("%c",arr[i]);
}
int substr2(char* str1,int start,int end,char *str2)
{
	int l = end - start;
	char arr[l];
	int j=-1;
	for(int i=start;i<end;i++)
	arr[++j] = str1[i];
	arr[++j] = '\0';
	//printf("%s",arr);
	for(int i=0;i<strlength(arr);i++)
	{
		if(arr[i]!=str2[i]) return 0;
	}
	return 1;
	//for(int i=0;i<l;i++) printf("%c",arr[i]);
}
int  checkSubstring(char* str1, char* str2)
{
	int l1 = strlength(str1);
	int l2 = strlength(str2)-1;
	for(int i=0;i<=l1-l2;i++)
	{
		if(substr2(str1,i,i+l2,str2)) return 1;
	}
	return 0;
}
char nonRepeatingCharacter(char *str)
{
	char ans = '\0';
	int l = strlength(str);
	for(int i=0;i<l;i++)
	{
		//printf("%c ",ans);
		ans = ans ^ str[i];
	}
	return ans;
}
int countWord(char* str)
{
	int count=1;
	for(int i=0;i<strlength(str);i++)
	{
		if(str[i]==' ') count++;
	}
	return count;
}
void reverse(char *start,char *end)
{
	while(start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}
void wordReverse(char *str)
{
	char *start = str;
	char *temp = str;
	while(*temp)
	{
		temp++;
		if(*temp=='\0') reverse(start,temp-1);
		else if(*temp==' ')
		{
			reverse(start,temp-1);
			start = temp+1;
		}
	}
	reverse(str,temp-1);
	printf("%s",str);
}
void sort(char *str)
{
	int l = strlength(str);
	for(int i=0;i<l-1;i++)
	{
		for(int j=i+1;j<l;j++)
		{
			if(str[i]>str[j])
			{
				char temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
	//for(int i=0;i<l;i++) printf("%c",str[i]);
}
int anagram(char *str1,char *str2)
{
	sort(str1);
	sort(str2);
	int l1 = strlength(str1);;
	int l2 = strlength(str2);
	//for(int i=0;i<l1;i++) printf("%c",str1[i]);
	//for(int i=0;i<l2;i++) printf("%c",str2[i]);
	if(l1<l2 || l2<l1) return 0;
	for(int i=0;i<l1;i++)
	if(str1[i]!=str2[i]) return 0;
	return 1;
}
void toggle(char* str)
{
	for(int i=0;i<strlength(str);i++)
	{
		if(str[i]>=65 && str[i]<=93)
		str[i] = str[i] + 32;
		else if(str[i]>=95 && str[i]<=122)
		str[i] = str[i] - 32;
	}
	for(int i=0;i<strlength(str);i++) printf("%c",str[i]);
} 
int main()
{
	char str1[] = "ThIS iS a TesT SeNTeNCe";
	toggle(str1);
}