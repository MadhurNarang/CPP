#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
 int i=0;;
 char c[100],d,e;
 cout<<"ENTER THE NAME\n";
 gets(c);
 e=toupper(c[0]);
 cout<<e;
 for(;c[i]!='\0';i++)
  {
	if(c[i]==' ')
	{d=toupper(c[i+1]);
	 cout<<"."<<d
	}
  }
}


