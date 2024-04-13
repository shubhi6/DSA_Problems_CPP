// ..................................Job Sequencing Problem | Greedy Approach.........................

// Problem: Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. 
// It is also given that every job takes a single unit of time, so the minimum possible deadline for any job is 1.
// How to maximize total profit if only one job can be scheduled at a time.

// Examples:
// Input: Four Jobs with following deadlines and profits
//   JobID    Deadline      Profit
//     a        4            20   
//     b        1            10
//     c        1            40  
//     d        1            30
// Output: Following is maximum profit sequence of jobs
//         c, a   

// Input: Five Jobs with following deadlines and profits
//    JobID     Deadline     Profit
//      a         2           100
//      b         1           19
//      c         2           27
//      d         1           25
//      e         3           15
// Output: Following is maximum profit sequence of jobs
//         c, a, e




// This is a standard Greedy Algorithm problem. Following is the greedy algorithm to solve the above problem:
// 1) Sort all jobs in decreasing order of profit.
// 2) Initialize the result sequence as the first job in sorted jobs.
// 3) Do following for remaining n-1 jobs
// .......a) If the current job can fit in the current result sequence 
//           without missing the deadline, add the current job to the result.
//           Else ignore the current job.




#include<iostream>
#include<algorithm>
using namespace std;

struct Job
{
    char id;
    int dead;
    int profit;
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n)
{
    sort(arr, arr+n, comparison);
    int result[n];
    bool slot[n];
    for (int i=0; i<n; i++)
        slot[i] = false;
    for (int i=0; i<n; i++)
    {
        for (int j=min(n, arr[i].dead)-1; j>=0; j--)
        {
            if (slot[j]==false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    for (int i=0; i<n; i++)
    if (slot[i])
        cout << arr[result[i]].id << " ";
}

int main()
{
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Maximum profit sequence of job: ";
    printJobScheduling(arr, n);
    return 0;
}

// Output:
//  Maximum profit sequence of job : c a e
