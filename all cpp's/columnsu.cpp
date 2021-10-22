//SUM OF ROWS AND COLUMNS IN 2D ARRAY
#include<iostream.h>                                   //HEADER FILES INCLUDED
void main()
{
 int a[10][10],r,c,sum=0,s[10],f,i;                        //2D ARRAY DECLARED
 cout<<"ENTER NO OF ROWS \n";
 cin>>r;
 cout<<"ENTER NO OF columns\n";
 cin>>c;
 cout<<"NOW INPUT 2D ARRAY\n";
 for( i=0;i<r;i++)
  {
	 for( f=0;f<c;f++)
		{
		  cin>>a[i][f];                              //INITIALISING THE 2D ARRAY
		}
  }
 cout<<"\nARRAY 1 ENTERED  IS\n";
 for(i=0;i<r;i++)
  {
	for(f=0;f<c;f++)
	  {
		 cout<<a[i][f]<<" ";                     //DISPLAYING THE ENTERED ARRAY
	  }
	cout<<endl;
  }
 for(f=0;f<c;f++)
  {
	for(i=0;i<r;i++)                                 //LOOP FOR SUM OF COLUMNS
	 {
	  sum+=a[i][f];
	 }
	s[f]=sum;
	cout<<"\nSUM OF NUMBERS IN COLUMN "<<f+1<<" IS "<<s[f]<<"\n";
	sum=0;
  }
 for(f=0;f<r;f++)
  {
	for(i=0;i<c;i++)
	 {                                                   //LOOP FOR SUM OF ROWS
		sum+=a[f][i];
	 }
	s[f]=sum;
	cout<<"\nSUM OF NUMBERS IN ROW "<<f+1<<" IS "<<s[f]<<"\n";
	sum=0;
  }
}