//EXCHANGING HALF SIDE ELEMENTS IN AN INTEGER ARRAY
#include<iostream.h>                                 //HEADER FILES INCLUDED
void main()
{
 int a[10],b,f,j;                                   //INTEGER ARRAY DECLARED
 cout<<"ENTER NO OF INTEGERS YOU WILL ENTER\n";
 cin>>f;
 cout<<"ENTER THE ARRAY:\n";
 for(int c=0;c<f;c++)
  {
	cin>>a[c];                                     //ARRAY IS INITIALISED
  }
 if(f%2==0)
  {
	j=f/2;
  }
 else
  {
	j=f/2+1;
  }
 for(int i=0,d=j;i<f/2;i++,d++)
  {
	 b=a[i];
	 a[i]=a[d];                                  //SWAPPING USING THIRD VARIABLE
	 a[d]=b;
  }
 cout<<"SWAPPED ARRAY IS:\n";
 for(c=0;c<f;c++)
  {
	cout<<a[c];                                 //DISPLAYING THE SWAPPED ARRAY
  }
}

