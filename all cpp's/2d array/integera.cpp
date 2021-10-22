#include<iostream.h>
void main()
{
 int a[10],b,f;
 cout<<"ENTER NO OF INTEGERS";
 cin>>f;
 for(int c=0;c<f;c++)
 {cin>>a[c];}
 for(int i=0,d=f-1;i<f/2;i++,d--)
 {
  b=a[i];
  a[i]=a[d];
  a[d]=b;
 }
 for(c=0;c<f;c++)
 {cout<<a[c];}
}


