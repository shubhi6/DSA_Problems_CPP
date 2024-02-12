// C-STYLE STRING

#include<iostream>
#include<cstring>
using namespace std;

// ..... print the string .....

int main()
{
	char str[]="really";
	cout<<str;
	return 0;
}

//......count the char in string.......

int main()
{
	char str[]="really";
	cout<<sizeof(str);
	return 0;
}

//.......strcmp function......

int main()
{
	char str1[]="abc";
	char str2[]="bcd";
	int res=strcmp(str1,str2);
	if(res>0)
	cout<<"GREATER";
	else if(res==0)
	cout<<"EQUAL";
	else
	cout<<"SMALLER";
	return 0;
}

//.....strcpy function.....

int main()
{
	char str[5];
    strcpy(str,"really");
	cout<<str;
	return 0;
}



