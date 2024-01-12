//Our Task: The cost of a stock on each day is given in an array. Find the maximum profit that you can make by buying and selling on those days.
//If the given array of prices is sorted in decreasing order, then profit cannot be earned at all.

//Examples:

//Input: arr[] = {100, 180, 260, 310, 40, 535, 695}
//Output: 865
//Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210
                     //  Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655
                    //   Maximum Profit  = 210 + 655 = 865
//Input: arr[] = {4, 2, 2, 2, 4}
//Output: 2
//Explanation: Buy the stock on day 1 and sell it on day 4 => 4 – 2 = 2
                       //Maximum Profit  = 2

#include<iostream>
#include<cmath>
using namespace std;

int maxprofit(int price[], int n)
{

	int i=1,profit=0;
	for(i=1;i<n;i++)
	{
		if(price[i]>price[i-1])
		profit+=(price[i]-price[i-1]);
	}
	return profit;
	
}   


int main()
{
	int j,n,arr[n],d;
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
    cout<<"Maximum profit is = "<<maxprofit(arr,n);
 
}
