//GET TWO FROM ONE
#include<iostream.h>                       //HEADER FILES INCLUDED
void main()
{
 int a[10],even[10],odd[10],n,l=0,m=0;     //DECLARING THE ARRAYS
 cout<<"ENTER NUMBER OF INTEGERS YOU WILL ENTER\n";
 cin>>n;
 cout<<"ENTER THE ARRAY\n";
 for(int i=0;i<n;i++)
  {
	cin>>a[i];                              //INITIALISING THE FIRST ARRAY
  }
 for(i=0;i<n;i++)
  {
	if(a[i]%2==0)
	 {
		even[l++]=a[i];
	 }                                      //CONDITION FOR GETTING TWO FROM ONE
	else
	 {
		odd[m++]=a[i];
	 }
  }
 cout<<"\nEVEN ELEMENTS ARRAY IS:\n";
 for(i=0;i<l;i++)
  {
	 cout<<even[i]<<" ";
  }                                        //DISPLAYING THE ARRAYS
 cout<<"\nODD ELEMENTS ARARAY IS:\n";
 for(i=0;i<m;i++)
  {
	 cout<<odd[i]<<" ";
  }
}
