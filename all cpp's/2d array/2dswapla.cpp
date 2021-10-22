                                               #include<iostream.h>
void main()
{
 int a[10][10],f,g,k,i,c,l;
 cout<<"ENTER NO OF ROWS \n";
 cin>>f;
 cout<<"\nENTER NO OF COLUMNS";
 cin>>g;
 cout<<"\n\nENTER 2D ARRAY\n";
 for(i=0;i<f;i++)
 {
  for(c=0;c<g;c++)
  {
  cin>>a[i][c];
  }
 }
 cout<<"\nENTERED ARRAY IS\n";
 for(i=0;i<f;i++)
 {
  for(c=0;c<g;c++)
  {
	cout<<a[i][c]<<" ";
  }
 cout<<endl;
 }
 for(i=0;i<f;i++)
 {
 k=a[i][0];
	a[i][0]=a[i][g-1];
	a[i][g-1]=k;
 }
 cout<<"\nSWAPPED ARRAY IS\n";
 for(i=0;i<f;i++)
 {
  for(c=0;c<g;c++)
  {
	cout<<a[i][c]<<" ";
  }
 cout<<endl;
 }
}