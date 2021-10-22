#include<iostream.h>
void main()
{
 int a[100],n,i,l,m,temp;
 cout<<"ENTER NO OF INTEGERS";
 cin>>n;
 for(i=0;i<n;i++)
 {
  cin>>a[i];
 }
 l=0;
 m=n-1;
 while(l<m)
 {
  while(a[l]%2==0)
		  l++;
  while(a[m]%2!=0)
		  m--;
  if(l<m)
  {
	temp=a[l];
	a[l]=a[m];
	a[m]=temp;
  }
 }
  cout<<"\nrequired array is  :  ";
  for(i=0;i<n;i++)
 {
  cout<<a[i];
 }
}