//COUNT CHARACTERS WITHOUT USING LIBRARY FUNCTIONS
#include<iostream.h>                  //HEADER FILES INCLUDED
#include<stdio.h>
int length(char c[50])             //FUNCTION RETURNING INTEGER VALUES
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
 len=length(c);                       //FUNCTION CALL(CALL BY REFERENCE(STRING))
 cout<<"NUMBER OF CHARACTERS IN STRING IS "<<len;
}
