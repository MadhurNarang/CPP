//QUEUE USING LINKED LIST
#include<iostream.h>
struct node
{
  int roll;
  node *link;
};
class queue
{
  node *front,*rear;
 public:
  queue()
  {
	  front=rear=NULL;
  }
  void ins(),del(),disp();
};
void queue::ins()
{
  node *tmp=new node;
  cout<<"\nENTER THE ELEMENT TO INSERT\t";
  cin>>tmp->roll;
  tmp->link=NULL;
  if(rear==NULL)
		front=rear=tmp;
  else
  {
		rear->link=tmp;
		rear=tmp;
  }
}
void queue::del()
{
  if(front==NULL)
		cout<<"QUEUE UNDERFLOW";
  else
  {
		node *tmp=front;
		if(front==rear)
		{
			front=rear=NULL;
			cout<<"\nELEMENT DELETED";
		}
		else
		{
			front=tmp->link;
			cout<<"\nELEMENT DELETED";
		}
		delete tmp;
	}
}
void queue::disp()
{
  if(front==NULL)
		cout<<"QUEUE UNDERFLOW";
  else
  {
		cout<<"\nTHE QUEUE IS ";
		node *tmp=front;
		while(tmp!=NULL)
		{
			cout<<tmp->roll<<'\t';
			tmp=tmp->link;
		}
  }
}
void main()
{
	int c;
	char ch;
	queue s;
	do
	 {
		  cout<<"ENTER \n1 TO INSERT\n2 TO DELETE\n3 TO DISPLAY \t";
		  cin>>c;
		  switch(c)
		  {
				case 1: s.ins();break;
				case 2: s.del();break;
				case 3: s.disp();break;
				default: cout<<"\nINVALID ENTRY";break;
		  }
		  cout<<"\nDO YOU WANT TO CONTINUE Y/N\t";
		  cin>>ch;
	 }while((ch=='y')||(ch=='Y'));
}

