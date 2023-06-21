#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    int maxContainers(int b,int c,int m)
    {
        int sol=0;
        n = b/c;
        sol += n;
        while(n>=m)
        {
            sol += n/m;
            n = m%m + m/n;
        }
        return sol;
    }  
};

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int n,cost,m;
        cin>>n>>cost>>m;
        Solution s;
        cout<<s.maxContainers(n,cost,m)<<endl;
    }
}

/*
1. Purchasing Supplies
A manufacturer purchases fragile components that must be shipped using expensive containers. The manufacturer agrees to provide customers with a free container of components for returning a certain number of containers. Determine the maximum number of containers a customer can receive given a budget, the cost per container, and the number of empty containers that must be returned for a free container. Assume each container is immediately emptied and returned for credit.

 

Example

n = 4

cost = 1

m = 2

Start with a budget n = 4 units of currency to buy containers at cost = 1 unit each. The number of empty containers to return for a free full container is m = 2. First, buy 4 containers with the entire budget. Turn in those 4 containers for 2 more containers. Turn in those 2 containers for one more. At this point, there are not enough funds or containers to receive another. In total, 4 + 2 + 1 = 7 containers were obtained.

 

Function Description 

Complete the function maximumContainers in the editor below.

 

maximumContainers has the following parameter(s):

    string scenarios[n]: each string contains three space-separated integers, starting budget, cost, and the number of containers to return for a full container.

 

Print

    int: For each test case the function must print an integer, the maximum number of containers the manufacturer can obtain, each on a new line. No return value is expected.

    

Constraints

1 ≤ n ≤ 103
2 ≤ starting budget ≤ 105
1 ≤ cost of a container in money ≤ starting budget
2 ≤ number of empty containers to return  ≤ starting budget
 

Input Format for Custom Testing


Sample Case 0
Sample Input 0

STDIN      Function
-----      --------
3       →  size of scenarios[] n = 3
10 2 5  →  scenarios = ['10 2 5', '12 4 4', '6 2 2']
12 4 4
6 2 2
 

Sample Output 0

6
3
5
 

Explanation 0

 

There are 3 test cases:

Spend 10 units currency on 5 containers at 2 units each. Turn in 5 containers for another one for a total of 6.
Spend 12 units on 3 containers at 4 units. There are not enough containers to turn in, so the total is 3.
Spend 6 units on 3 containers at 2 units. Turn in 2 of the containers for a 4th container leaving 1 old and 1 new container. Turn those 2 in for 1 more container making the total 5.
Sample Case 1




*/