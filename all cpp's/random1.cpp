//ARRAY
#include<iostream.h>
void main()
{
  int a[40],n,i=0,j=0,k;
  cout<<"ENTER THE NUMBER OF ELEMENTS   ";
  cin>>n;
  cout<<"ENTER THE INTEGER ARRAY   \n";
  for(i=0;i<n;i++)
  {
	 cin>>a[i];
  }
  cout<<"THE NEW ARRAY IS\n";
  for(i=0;i<n-1;i++)
  {
	if(a[i]%5==0)
	 {
		a[i];
		a[i]=a[i+1];
		i++;
	}
 }
 for(i=0;i<n;i++)
  {
	cout<<a[i]<<" ";
  }
}










