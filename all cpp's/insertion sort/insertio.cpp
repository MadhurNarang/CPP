#include<iostream.h>
void sort(int a[],int n)
{
 int i,j,temp;
 for(i=1;i<n;i++)
 {
  temp = a[i];
  j=i-1;
  while(temp<a[j]&&j>=0)
  {
	a[j+1]=a[j];
	j--;
  }
  a[j+1]=temp;
 }
}

void main()
{
 int a[100],i,n;
 cout<<"ENTER NUMBER OF INTEGERS   ";
 cin>>n;
 cout<<"ENTER THE ELEMENTS\n";
 for(i=0;i<n;i++)
 {
  cin>>a[i];
 }


 sort(a,n);
 cout<<"SORTED ARRAY IS\n";
 for(i=0;i<n;i++)
 {
  cout<<a[i]<<" ";
 }
}