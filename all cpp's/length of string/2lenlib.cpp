//COUNT CHARACTERS WITHOUT USING LIBRARY FUNCTIONS
#include<iostream.h>
#include<stdio.h>
int length(char c[50])
{
 int i;
 for(i=0;c[i]!='\0';i++);
 return(i);
}

void main()
{
 int len;
 char c[50];
 cout<<"ENTER THE STRING \n";
 gets(c);
 len=length(c);
 cout<<"NUMBER OF CHARACTERS IN STRING IS "<<len;
}
