//EXCHANGING COLUMN ELEMENTS IN AN INTEGER ARRAY
#include<iostream.h>                                    //HEADER FILES INCLUDED
void main()
{
 int n,i,m,k,a[20][20],f,g;                           //DECLARATION OF 2D ARRAY
 cout<<"ENTER NUMBER OF ROWS OF 2D ARRAY"<<endl;
 cin>>n;
 cout<<"ENTER NUMBER COLUMNS OF 2D ARRAY"<<endl;
 cin>>m;
 cout<<"NOW ENTER THE ARRAY\n";
 for(i=0;i<n;i++)
  {
	for(k=0;k<m;k++)
	 {
		cin>>a[i][k];                                //INITIALISATION OF 2D ARRAY
	 }
  }
 cout<<"ENTERED ARRAY IS\n";
 for(i=0;i<n;i++)
	{
	 for(k=0;k<m;k++)
	  {
		 cout<<a[i][k]<<" ";                        //DIPLAYING THE ENTERED ARRAY
	  }
	 cout<<endl;
	}
 for(f=0;f<n;f++)
  {
	for(i=0,g=m-1;i<m/2;i++,g--)
	 {
	  k=a[f][i];
	  a[f][i]=a[f][g];                  //CONDITION FOR SWAPPING COLUMN ELEMENTS
	  a[f][g]=k;
	 }
  }
 cout<<"\nSWAPPED ARRAY IS\n";
 for(i=0;i<n;i++)
  {
	for(k=0;k<m;k++)
	 {
		cout<<a[i][k]<<" ";
	 }                                            //DISPLAYING THE SWAPPED ARRAY
	cout<<endl;
  }
}




