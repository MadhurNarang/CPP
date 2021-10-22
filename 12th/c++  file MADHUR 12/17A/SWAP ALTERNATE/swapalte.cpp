//EXCHANINGING ALTERNATE ELEMENTS IN AN ARRAY
#include<iostream.h>                           //HEADER FILE INCLUDED
void main()
{
 int a[10],b,f,j;                              //DECLARING THE INTEGER ARRAY
 cout<<"ENTER NO OF INTEGERS YOU WILL ENTER\n";
 cin>>f;
 cout<<"ENTER THGE ARRAY:\n";
 for(int c=0;c<f;c++)
  {
	cin>>a[c];                                  //INITIALISING THE ARRAY
  }
 if(f%2==0)
  {
	j=f;
  }
 else
  {
	j=f-1;
  }
 for(int i=0;i<j;i+=2)
  {
	 b=a[i];
	 a[i]=a[i+1];                                //SWAP USING THIRD VARIABLE
	 a[i+1]=b;
  }
 cout<<"SWAPPED ARRAY IS \n";
 for(c=0;c<f;c++)
  {
	cout<<a[c];                                 //DISPLAYING THE ARRAY
  }
}
