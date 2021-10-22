//REVERSING AN INTEGER ARRAY
#include<iostream.h>                           //HEADER FILES INCLUDED
void rev(int a[],int n)                        //FUNCTION TO REVERSE THE ARRAY
{
 for(int i=0,l=n-1;i<n/2;i++,l--)              //SWAPPING CONDITION
 {
  int k=a[i];
  a[i]=a[l];                                  //FUNCTION DEFINITION
  a[l]=k;                                     //SWAPPING USING THIRD VARIABLE
 }
}
void main()
{
 int n,i,a[20];                              //INTEGER ARRAY DECLARED
 cout<<"ENTER NO OF INTEGERS YOU WILL ENTER"<<endl;
 cin>>n;
 cout<<"NOW ENTER THE ARRAY:\n";
 for(i=0;i<n;i++)
  {
	cin>>a[i];                                //INITIALISING THE ARRAY
  }
 rev(a,n);                                   //FUNCTION CALL
 cout<<"REVERSED ARRAY IS :\n";
 for(i=0;i<n;i++)
  {
	cout<<a[i]<<" ";                         //DIPLAYING THE ARRAY
  }
}





