  #include<iostream.h>
  void main()
  {
	int a,b,r,c=0;
	cout<<"ENTER THE NUMBER NOT ENDING WITH 0\n";
	cin>>a;
	b=a;
	while(b!=0)
	{
    r=b%10;
	 c=10*c+r;
	 b/=10;
	}
	if(c==a)
	 cout<<"PALINDROME";
	else
	 cout<<"NOT PALINDROME";
  }