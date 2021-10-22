//INSERTION SORT
#include<iostream.h>                      //HEADER FILES INCLUDED
void sort(int a[],int n)                  //FUNCTION TO SORT ARRAY BY INSERTION
{
 int i,j,temp;
 for(i=1;i<n;i++)
  {                                       //FUNCTION DEFINITION
	 temp=a[i];
	 j=i-1;
	 while(temp<a[j]&&j>=0)
	  {
		 a[j+1]=a[j];                       //CODE TO SORT ARAY BY INSERTION
		 j--;
	  }
	 a[j+1]=temp;
  }
}
void main()
{
 int a[100],i,n;                          //INTEGER ARRAY DECLARED
 cout<<"ENTER NUMBER OF INTEGERS   ";
 cin>>n;
 cout<<"ENTER THE ELEMENTS\n";
 for(i=0;i<n;i++)
  {
	 cin>>a[i];                            //INITIALISING THE ARRAY
  }
 sort(a,n);                               //FUNCTION CALL
 cout<<"SORTED ARRAY IS\n";
 for(i=0;i<n;i++)
  {
	 cout<<a[i]<<" ";                     //DISPLAYING THE SORTED ARRAY
  }
}