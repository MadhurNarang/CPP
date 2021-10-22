#include<iostream.h>
void main()
{
 int a[10],b,f,j;
 cout<<"ENTER NO OF INTEGERS YOU WILL ENTER";
 cin>>f;
 for(int c=0;c<f;c++)
 {cin>>a[c];}
 if(f%2==0)
 {
  j=f;
 }
 else
 {
  j=f-1;
 }
 for(int i=0;i<j;i+=2)
	{
	 b=a[i];
	 a[i]=a[i+1];
	 a[i+1]=b;
	}

 for(c=0;c<f;c++)
 {cout<<a[c];}
}
