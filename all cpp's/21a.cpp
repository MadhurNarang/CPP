//BUBBLE SORT USING ARRAY
#include<iostream.h>                       //HEADER FILES INCLUDED
void bubble(int x[100],int y)           //FUNCTION FOR SORTING ARRAY ELEMENTS
{
 int i,j,temp;
 for(i=0;i<y;i++)
  {
  for(j=0;j<y-1-i;j++)
	{
	if(x[j]>x[j+1])
	 {
	  temp=x[j];
	  x[j]=x[j+1];                         //CODE FOR BUBBLE SORT
	  x[j+1]=temp;
	 }
	}
  }
 cout<<"\nSORTED ARRAY IS\n";
 for(i=0;i<y;i++)                         //PRINTING THE SORTED ARRAY
 cout<<x[i]<<'\t';
}
void main()
 {
  int k,sz,ar[1000];
  cout<<"ENTER THE SIZE OF ARRAY\t";
  cin>>sz;
  cout<<"ENTER THE ARRAY\n";
  for(k=0;k<sz;k++)
  cin>>ar[k];                                 //ACCEPTING ARRAY ELEMENTS
  bubble(ar,sz);                              //FUNCTION CALL
 }







