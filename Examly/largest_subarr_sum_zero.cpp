/*Given an array arr[] of length N, find the length of the longest sub-array with a sum equal to 0.

Examples:

Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23}
Output: 5
Explanation: The longest sub-array with elements summing up-to 0 is {-2, 2, -8, 1, 7}

Input: arr[] = {1, 2, 3}
Output: 0
Explanation: There is no subarray with 0 sum
*/
#include<bits/stdc++.h>
using namespace std;
int zeroSubArray(int arr[],int n)
{
    int maxlen = 0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum += arr[j];
            if(sum==0) maxlen = max(maxlen,j-i+1);
        }
    }
    return maxlen;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<zeroSubArray(arr,n);
}