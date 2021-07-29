#include<iostream>

using namespace std;

#define SIZEOF(a) ( sizeof a / sizeof a[0] )

void array(int a[])
{
	cout<<"Enter the array"<<endl;
	for(int i= 0; i<=SIZEOF(a); i++)
	{
		cin>>a[i];
	}
}
int main()
{
	int size;
	cout<<"ENter the size of the array"<<endl;
	cin>>size;
	int a[size], i, o, p, t;
	cout<<"Enter the option\n\t1.Insert\n\t2.Delete\n"<<endl;
	cin>>o;
	if(o==1){
		array(a);
		cout<<"Enter the position  and item you want to insert the item"<<endl;
		cin>>p>>t;

		for(i =size; i >=p; i-- )
		{
			a[i]= a[i-1];//right shift the elements
		}
		a[i]= t;//place the item into the pos
		size++;

		cout<<"\n";
		for(int i = 0; i<size;i++)
		{
			cout<<a[i]<<endl;
		}
	}	
	else if(o==2){
		array(a);
		cout<<"Enter the position to delete the item "<<endl;
		cin>>p;
		for(i=p-1; i<size;i++)
		{
			a[i]= a[i+1];//left shift the arraylist
		}size--;//decrease the size of array
		cout<<"\n";
		for(int i = 0; i<size;i++)
		{
			cout<<a[i]<<endl;
		}
	}
	else
	{
		cout<<"Invalid input"<<endl;
	}
	

}

