//MERGE SORT(AAA)
#include<iostream.h>                                    //HEADER FILES INCLUDED
void sort(int a[],int n,int b[],int m)
{                                             //FUNCTION DECLARED TO MERGE SORT
 int c[200],i,j,k=0;
 for(i=0,j=0;i<n&&j<m;)
  {
	 if(a[i]<b[j])
		c[k++]=a[i++];                                      //CODE FOR MERGE SORT
	 else
		c[k++]=b[j++];                                      //FUNCTION DEFINITION
  }
 while(i<n)
	c[k++]=a[i++];
 while(j<m)
	c[k++]=b[j++];
 cout<<"COMBINED SORTED ARRAY IS :  \n";
 for(i=0;i<m+n;i++)                         //DISPLAYING THE MERGE SORTED ARRAY
	cout<<c[i]<<" ";
}
void main()
{
 int a[100],b[100],i,n,m;                                      //ARRAY DECLARED
 cout<<"ENTER NUMBER OF INTEGERS   ";
 cin>>n;
 cout<<"ENTER THE ELEMENTS\n";
 for(i=0;i<n;i++)
  {
	 cin>>a[i];                                              //ARRAY INITIALISED
  }
 cout<<"ENTER NUMBER OF INTEGERS   ";
 cin>>m;
 cout<<"ENTER THE ELEMENTS\n";
 for(i=0;i<m;i++)
  {
	 cin>>b[i];
  }
 sort(a,n,b,m);                                               //FUNCTION CALLED
}
