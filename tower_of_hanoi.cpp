//You are given three pegs (towers i.e, A,B,C) and a number of disks of different sizes, which can slide onto any peg.
//The puzzle starts with the disks in a neat stack in ascending order of size on one peg, the smallest at the top, thus making a conical shape. 

//The objective of the puzzle is to move the entire stack to another peg, obeying the following simple rules:
// 1. Only one disk can be moved at a time.
// 2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty peg.
// 3. No disk may be placed on top of a smaller disk.



#include<iostream>
using namespace std;

void toh(int n,char a,char b,char c)
{
	if (n == 0) 
		return;
	
	
	toh(n-1,a,c,b);
	cout<<" move "<<n<<" from "<<a<<" to  "<<c<<endl;
	toh(n-1,b,a,c);
}


int main()
{
	int n; 
	cout<<"enter number of levels = ";
	cin>>n;
	toh(n, 'a', 'c', 'b');
}
