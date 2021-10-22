#include<iostream.h>
#include<stdio.h>
#include<string.h>
void main()
{
 char c[30];
 cout<<"ENTER THE STRING\n";
 gets(c);
 int i=strlen(c);
 for(i=i-1;i>=0;i--)
  {
	cout<<c[i];
  }
}
