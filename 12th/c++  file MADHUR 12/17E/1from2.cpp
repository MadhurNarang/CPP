//GET ONE FROM TWO
#include<iostream.h>                                    //HEADER FILES INCLUDED
void main()
{
 int a1[200],a2[20],a3[40],n,l=0,m=0,i;					   //DECLARING THE ARRAYS
 cout<<"ENTER NUMBER OF INTEGERS YOU WILL ENTER\n";
 cin>>n;
 cout<<"ENTER THE FIRST ARRAY\n";
 for(i=0;i<n;i++)
  {
	cin>>a1[i];                                   //INITIALISING THE FIRST ARRAY
  }
 cout<<"ENTER THE SECOND ARRAY\n";
 for(i=0;i<n;i++)
  {
	cin>>a2[i];                                  //INITIALISING THE SECOND ARRAY
  }
 for(i=0;i<2*n;i++)
  {
	if(i%2==0)
	 {
		a3[i]=a1[l++];
	 }                                      //CONDITION FOR GETTING ONE FROM TWO
	else
	 {
		a3[i]=a2[m++];
	 }
  }
 cout<<"\nCOMBINED ARRAY IS:\n";
 for(i=0;i<2*n;i++)
  {                                                     //DISPLAYING THE ARRAY
	 cout<<a3[i]<<" ";
  }
}
