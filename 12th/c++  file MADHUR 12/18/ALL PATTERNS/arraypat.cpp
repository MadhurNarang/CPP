//DIAGONAL PATTERNS IN 2D ARRAY
#include<iostream.h>                                   //HEADER FILES INCLUDED
int f,c,i;
void change(int b[10][10],int a[10][10])    //FUNCTION TO RE-INITIALISE ARRAY
{
 for(int i=0;i<f;i++)
 {
  for(c=0;c<f;c++)                                      //FUNCTION DEFINITION
	{
	  b[i][c]=a[i][c];
	}
 }
}
void main()
{
 int a[10][10],b[10][10];                         //2D INTEGER ARRAY DECLARED
 cout<<"ENTER NO OF ROWS AND COLUMNS  ";
 cin>>f;
 cout<<"\n\nENTER 2D ARRAY\n";
 for(i=0;i<f;i++)
  {
	for(c=0;c<f;c++)
	 {
		cin>>a[i][c];                                    //2D ARRAY INITIALISED
	 }
  }
 change(b,a);                                                 //FUNCTION CALL
 cout<<"\nPATTERN A: UPPER HALF OF LEFT DIAGONAL\n";
 for(i=0;i<f;i++)
  {
	for(c=0;c<f;c++)
	 {
	  if(i<c)                                        //CONDITION FOR PATTERN A
		 b[i][c]=0;
	  cout<<b[i][c]<<" ";
	 }
	cout<<endl;
  }
 change(b,a);                                                 //FUNCTION CALL
 cout<<"\nPATTERN B: LOWER HALF OF LEFT DIAGONAL\n";
 for(i=0;i<f;i++)
  {
	for(c=0;c<f;c++)
	 {
		if(i>c)                                       //CONDITION FOR PATTERN B
			b[i][c]=0;
		cout<<b[i][c]<<" ";
	 }
	cout<<endl;
  }
 change(b,a);                                                  //FUNCTION CALL
 cout<<"\nPATTERN C: UPPER HALF OF RIGHT DIAGONAL\n";
 for(i=0;i<f;i++)
  {
	for(c=0;c<f;c++)
	 {
		if(i+c<f-1)                                    //CONDITION FOR PATTERN C
			b[i][c]=0;
		cout<<b[i][c]<<" ";
	 }
	cout<<endl;
  }
 change(b,a);                                                  //FUNCTION CALL
 cout<<"\nPATTERN D: LOWER HALF OF RIGHT DIAGONAL\n";
 for(i=0;i<f;i++)
  {
	for(c=0;c<f;c++)
	 {
		if(i+c>f-1)                                     //CONDITION FOR PATTERN D
			b[i][c]=0;
		cout<<b[i][c]<<" ";
	 }
	cout<<endl;
  }
}