#include<iostream.h>
#include<stdio.h>
#include<string.h>
void main()
{
 char c[30],a;
 int b,d,i;
 cout<<"ENTER THE STRING";
 gets(c);
 i=strlen(c);
 for(b=i-1,d=0;b>=i/2;b--,d++)
 {
  a=c[b];
  c[b]=c[d];
  c[d]=a;
 }
 cout<<c;
}
