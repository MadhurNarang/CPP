#include<iostream.h>
void main()
{
 int a[10],even[10],odd[10],n,l=0,m=0;
 cout<<"ENTER NO OF INTERGERS";
 cin>>n;
 cout<<"ENTER ARRAY A\n";
 for(int i=0;i<n;i++)
 {
  cin>>a[i];
 }
 for(i=0;i<n;i++)
 {
  if(i%2==0)
  {
	even[l++]=a[i];
  }
  else
  {
  odd[m++]=a[i];
  }
 }
 cout<<"even\t";
 for(i=0;i<l;i++)
 {
  cout<<even[i]<<" ";
 }
 cout<<"\nodd \t";
 for(i=0;i<m;i++)
 {
  cout<<odd[i]<<" ";
 }
 int h=0,g=0;
 for(i=0;i<m;i++)
  {
	if(i%2==0)
	{
	 a[i]=even[h];h++;
	}
  else
	{a[i]=odd[g];g++;}

  }
 cout<<"\nA= ";
	for( i=0;i<2*l;i++)
 {
  cout<<a[i]<<" ";
 }
}
