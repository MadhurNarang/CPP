//COMPARE AND CONCATENATE STRINGS USING LIBRARY FUNCTIONS
#include<iostream.h>
#include<string.h>
#include<stdio.h>
void main()
{
  int i;
  char str1[50],str2[50],str3[100];
  cout<<"ENTER THE FIRST STRING  ";
  gets(str1);
  cout<<"ENTER THE SECOND STRING  ";
  gets(str2);
  i=strcmp(str1,str2);
	if(i==0)
	 cout<<"\nENTERED STRINGS ARE EQUAL";
	else
	 cout<<"\nENTERED STRINGS ARE NOT EQUAL";
  strcat(str1,str2);
  cout<<"\n\nCOMBINED STRING IS ";
  puts(str1);
}
