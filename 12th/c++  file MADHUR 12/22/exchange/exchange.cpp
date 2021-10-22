//EXCHANGE SELECTION SORT
#include<iostream.h>                           //HEADER FILES INCLUDED
void exchange(int a[],int n)                   //FUNCTION TO SORT BY EXCHANGING
{
 int temp,i,j,small,pos;
 for(i=0;i<n-1;i++)
  {
	small=a[i];                                 //FUNCTION DEFINITION
	pos=i;                                      //CODE TO SORT BY EXCHANGING
	for(j=i+1;j<n;j++)
	 {
		if(small>a[j])
		 {
			small=a[j];
			pos=j;
		 }
	 }
	a[pos]=a[i];
	a[i]=small;
  }
}
void main()
{
 int a[100],i,n;                               //INTEGER ARRAY DECLARED
 cout<<"ENTER NUMBER OF INTEGERS   ";
 cin>>n;
 cout<<"ENTER THE ELEMENTS\n";
 for(i=0;i<n;i++)
  {
	 cin>>a[i];                                 //INTEGER ARRAY INITIALISED
  }
 exchange(a,n);                                //FUNCTION CALL
 cout<<"SORTED ARRAY IS :  ";
 for(i=0;i<n;i++)
  {
	 cout<<a[i]<<" " ;                          //DISPLAYING THE SORTED ARRAY
  }
}
