// Consider a big party where a log register for guest's entry and exit times is maintained. Find the time at which there are maximum guests in the party. 
// Note that entries in register are not in any order.
// Example : 

// Input: arrl[] = {1, 2, 9, 5, 5}
//        exit[] = {4, 5, 12, 9, 12}
// First guest in array arrives at 1 and leaves at 4, 
// second guest arrives at 2 and leaves at 5, and so on.

// Output: 5
// There are maximum 3 guests at time 5. 

#include<iostream>
#include<algorithm>
using namespace std;

void findMaxGuests(int arrl[], int exit[], int n)
{
   
   sort(arrl, arrl+n);
   sort(exit, exit+n);

   
   int guests_in = 1, max_guests = 1, time = arrl[0];
   int i = 1, j = 0;

   while (i < n && j < n)
   {
     
      if (arrl[i] <= exit[j])
      {
          guests_in++;

          if (guests_in > max_guests)
          {
              max_guests = guests_in;
              time = arrl[i];
          }
          i++;  
      }
      else {
          guests_in--;
          j++;
      }
   }

   cout << "Maximum Number of Guests = " << max_guests
        << " at time " << time;
}

int main()
{
    int j, n;
    cout << "Enter size of array = ";
    cin >> n;
    cout << "Enter arrival time = ";
    int arrl[n];
    for (j = 0; j < n; j++)
    cin >> arrl[j];
    cout << "Enter exit time = ";
    int exit[n];
    for (j = 0; j < n; j++)
    cin >> exit[j];
    
    findMaxGuests(arrl, exit, n);
    return 0;
}


// Consider the above example. 

//     arr[]  = {1, 2, 10, 5, 5}
//     dep[]  = {4, 5, 12, 9, 12}

// Below are all events sorted by time.  Note that in sorting, if two
// events have same time, then arrival is preferred over exit.
//  Time     Event Type         Total Number of Guests Present
// ------------------------------------------------------------
//    1        Arrival                  1
//    2        Arrival                  2
//    4        Exit                     1
//    5        Arrival                  2
//    5        Arrival                  3   
//    5        Exit                     2
//    9        Exit                     1
//    10       Arrival                  2 
//    12       Exit                     1
//    12       Exit                     0    

