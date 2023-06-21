/*Jack id always excited about sunday. it is favourite day when he gets to play all day. and goes to cycling wtih his friends 
so everytime when the months starts he counts the number of sundays he wil get to enjoy. considering the month can start with any day
br it sunday, monday
count the number of sunday jack will get within n number of days
example1 :
intput:
mon -> input string denoting the start of the month
13 -> input integer denoting the number of days from the start of the month
output: 
2 -> number of days within 13 days
Explanation:
the month start with mon. so the upcoming sunday will arrive in next sunday. and then next 7 days so on*/
#include<stdio.h>
#include<string.h>
int main()
{
    char days[3];
    int num;
    scanf("%s%d",days,&num);
    if(strcmp(days,"mon")==0) num += 1;
    else if(strcmp(days,"tue")==0) num += 2;
    else if(strcmp(days,"wed")==0) num += 3;
    else if(strcmp(days,"thu")==0) num += 4;
    else if(strcmp(days,"fri")==0) num += 5;
    else if(strcmp(days,"sat")==0) num += 6;
    else num += 0;

    printf("%d",num/7);
}