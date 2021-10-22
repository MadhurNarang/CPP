#include<iostream.h>
#include<stdio.h>
#include<string.h>
void main()
{
 int  x,y;
 char c[30],d[30];
 cout<<"ENTER THE  first STRING\n";
 gets(c);
 cout<<"ENTER THE  second STRING\n";
 gets(d);
 x=strlen(c);
 y=strlen(d);
 if(x+y<=30)
 { strcat(c,d);
  cout<<"STRING 1  "<<c<<endl;
  cout<<"STRING 2  "<<d;
 }
else
 cout<<"ENTERED STRING CANT BE CONCATENATED";
}