#include<iostream.h>
void rev(int a[],int n)
{
 for(int i=0,l=n-1;i<n/2;i++,l--)
 {
  int k=a[i];
  a[i]=a[l];
  a[l]=k;
 }
}
void main()
{
 int n,i,a[20];
 cout<<"ENTER NO OF INTEGERS YOU WILL ENTER"<<endl;
 cin>>n;
 cout<<"NOW ENTER THE ARRAY\n";
 for(i=0;i<n;i++)
 {
  cin>>a[i];
 }
 rev(a,n);
	cout<<"REVERSED ARRAY IS ";

 for(i=0;i<n;i++)
 {
  cout<<a[i]<<" ";
 }
}





