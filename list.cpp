//array implementation of list

#include<stdio.h>


#define CAPACITY 3

//global declaration
int size = 0,i;
int arraylist[CAPACITY];


//funtion declaration
bool isEmpty();
bool isFull();
bool isAvailable(int );
void insert(int);
void insertAt(int, int);
void deleteAt(int);
void update(int,int);
void display();

// isEmpty funtion
bool isEmpty()
{
	return size==0;
}
// isFull funtion
bool isFull()
{
	return (size ==CAPACITY);//return true if size==CAPACITY
}
// isAvailable funtion
bool isAvailable(int pos)
{
	return (pos<=size&&pos>0);//return true if pos<=size

}
// insert funtion
void insert(int item)
{
	if(isFull())//check full condtion
	{
		printf("Array is full\n");
	}
	else
	{
		arraylist[size]= item; //assign item into arraylist[size] and increment size
		size++;
	}
}
//insertat function
void insertAt(int item, int pos)
{
	if(isFull())//check full condition
	{
		printf("Array is full");
	}else if(isAvailable(pos))//check available condition
	{
		for(i =size; i >=pos; i-- )
		{
			arraylist[i]= arraylist[i-1];//right shift the elements
		}arraylist[i]= item;//place the item into the pos
		size++;
	}else
	{
		printf("Position not available\n");
	}
	
	
}
// deleteAt funtion
void deleteAt(int pos)
{
	if(isAvailable(pos))//check available condition
	{
		for(i=pos-1; i<size;i++)
		{
			arraylist[i]= arraylist[i+1];//left shift the arraylist
		}size--;//decrease the size of array
	}
	else
	{
		printf("Position not available\n");
	}
	
}

// update funtion
void update(int pos, int item)
{
	if(isAvailable(pos))
	{
		arraylist[pos-1]=item;//assign thev value of item into index
	}else
	{
		printf("Position not available\n");
	}
	
}
// display funtion
void display()
{
	if(isEmpty())//check empty
	{
		printf("Nothing to display\n");
	}
	else
	{
		for(i= 0; i<size; i++)
		{
			printf("%d |", arraylist[i]);//display the arraylist from index 0 to size-1
		}
		printf("\n");
	}
}

// Main funtion
int main()
{
	int a, item, pos;
	
	while(a!=9)
	{
	printf("Enter an option\n1.insert\n2.delete at\n3.insert at\n4.check available\n5.check empty\n6.check full\n7.display\n8.update at\n9.exit\n");
	scanf("%d", &a);
	switch(a)
	{
		case(1):
			printf("Enter the value: ");
			scanf("%d", &item);//imput the value to be inserted
			insert(item);//pass item to insert function
			break;
		case(2):
			printf("Enter the pos \n");
			scanf("%d", &pos);
			deleteAt(pos);
			break;
		case(3):
			printf("Enter the pos and the item\n");
			scanf("%d %d", &pos, &item);
			insertAt(pos, item);
			break;	
		case(4):
			printf("Enter the pos");
			scanf("%d", &pos);
			if(isAvailable(pos))//check isAvailable condition
			{
					printf("Available\n");
			}else{
			
				printf("Not Available\n");	
			} 
		 	break;
		case(5):
			if(isEmpty())
				printf("Empty\n");
			else printf("Not Empty\n");	
			break;
		case(6):
			if(isFull())
				printf("Full\n");
			else printf("Not full\n");
			break;
		case(7):
			display();
			break;
		case(8):
			printf("Enter the pos and the item\n");
			scanf("%d %d", &pos, &item);
			update(pos, item);
			break;	
		case(9):
			break;
		default:
			printf("Enter a valid input\n");
			break;						
		}
	}
}
