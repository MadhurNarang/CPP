//CHANGING THE VALUES ACCORDING TO EVEN ODD POSITIONS
#include<iostream.h>                                    //HEADER FILES INCLUDED
void main()
{
 int a1[200],a2[20],n,i;					            //DECLARING THE ARRAYS
 cout<<"ENTER NUMBER OF INTEGERS YOU WILL ENTER\n";
 cin>>n;
 cout<<"ENTER THE ARRAY\n";
 for(i=0;i<n;i++)
  {
	cin>>a1[i];                                         //INITIALISING THE ARRAY
  }
 for(i=0;i<n;i++)
  {
	if(i%2==0)
	 {
		a2[i]=a1[i]*2;
	 }                                           //CONDITION FOR CHANGING VALUES
	else
	 {
		a2[i]=a1[i]*3;
	 }
  }
 cout<<"\nCHANGED ARRAY(ODD POSITION*2 AND EVEN POSITION*3) IS:\n";
 for(i=0;i<n;i++)
  {                                                     //DISPLAYING THE ARRAY
	 cout<<a2[i]<<" ";
  }
}
