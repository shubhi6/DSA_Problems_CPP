//Largest subarray with 0 sum

//Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

//Example 1:

//Input:
//N = 8
//A[] = {15,-2,2,-8,1,7,10,23}
//Output: 5
//Explanation: The largest subarray with
//sum 0 will be -2 2 -8 1 7.

//Your Task:
//You just have to complete the function maxLen() which takes two arguments an array A and n,
//where n is the size of the array A and returns the length of the largest subarray with 0 sum.


 class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
       
  
    unordered_map<int, int> hashmap;
    int max_length = 0;
    int current_sum = 0;

    for (int i = 0; i < n; ++i) {
        current_sum += arr[i];

        if (current_sum == 0) {
            max_length = i + 1;
        }

        if (hashmap.find(current_sum) != hashmap.end()) {
            max_length = max(max_length, i - hashmap[current_sum]);
        } else {
            hashmap[current_sum] = i;
        }
    }

    return max_length;
}
        
     
};
