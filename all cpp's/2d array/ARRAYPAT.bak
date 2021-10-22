#include<iostream.h>
int f,c,i;
void change(int b[10][10],int a[10][10])
{for(int i=0;i<f;i++)
 {
  for(c=0;c<f;c++)
  {
  b[i][c]=a[i][c];}

 }
}
void main()
{
 int a[10][10],b[10][10];
 cout<<"ENTER NO OF ROWS AND COLUMNS  ";
 cin>>f;
 cout<<"\n\nENTER 2D ARRAY\n";
 for(i=0;i<f;i++)
 {
  for(c=0;c<f;c++)
  {
  cin>>a[i][c];
  }
 }
 change(b,a);
 cout<<"\nPATTERN 1\n";
 for(i=0;i<f;i++)
 {
  for(c=0;c<f;c++)
  {
	if(i<c)
	b[i][c]=0;
	cout<<b[i][c]<<" ";}cout<<endl;
 }
  change(b,a);
 cout<<"\nPATTERN 2\n";
 for(i=0;i<f;i++)
 {
  for(c=0;c<f;c++)
  {
	if(i>c)
	b[i][c]=0;
	cout<<b[i][c]<<" ";}cout<<endl;
  }
  change(b,a);
 cout<<"\nPATTERN 3\n";
 for(i=0;i<f;i++)
 {
  for(c=0;c<f;c++)
  {
	if(i+c>f-1)
	b[i][c]=0;
	cout<<b[i][c]<<" ";}cout<<endl;
 }
  change(b,a);
 cout<<"\nPATTERN 4\n";
 for(i=0;i<f;i++)
 {
  for(c=0;c<f;c++)
  {
	if(i+c<f-1)
	b[i][c]=0;
	cout<<b[i][c]<<" ";}cout<<endl;
 }
}