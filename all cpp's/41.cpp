//QUEUE USING ARRAYS
#include<iostream.h>
#define size 3
class queue
{
  int ar[size],front,rear;
 public:
  queue()
  {
	 front=rear=-1;
  }
  void ins(),del(),disp();
};
void queue::ins()
{
  int n;
  if(rear==size-1)
	  cout<<"QUEUE OVERFLOW";
  else
  {
	 cout<<"\nENTER THE ELEMENTS TO INSERT\t";
	 cin>>n;
	 if(rear==-1)
	 {
		 front=rear=0;
		 ar[rear]=n;
	 }
	 else
		 ar[++rear]=n;
  }
}
void queue::del()
{
  int n;
  if(front==-1)
	  cout<<"\nQUEUE UNDERFLOW";
  else
  {
	  if(front==rear)
	  {
		 n=ar[front];
		 cout<<"\nTHE DELETED ELEMENT IS"<<n;
		 rear=front=-1;
	  }
	 else
	 {
		n=ar[front];
		cout<<"\nTHE DELETED ELEMENT IS"<<n;
		front++;
	 }
  }
}
void queue::disp()
{
  if(rear==-1)
		cout<<"\nQUEUE UNDERFLOW";
  else
  {
	 cout<<"\nTHE ARRAY IS \t";
	 for(int i=front;i<=rear;i++)
		  cout<<ar[i]<<'\t';
  }
}
void main()
{
  int a;
  char t;
  queue v;
  do
  {
	  cout<<"ENTER \n1 TO INSERT\n2 TO DELETE\n3 TO DISPLAY \t";
	  cin>>a;
	  switch(a)
	  {
			case 1: v.ins();break;
			case 2: v.del();break;
			case 3: v.disp();break;
			default: cout<<"\nINVALID ENTRY";break;
  }
  cout<<"\nDO YOU WANT TO CONTINUE Y/N\t";
  cin>>t;
 }while((t=='y')||(t=='Y'));
}
