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
