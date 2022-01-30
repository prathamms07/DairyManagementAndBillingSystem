#include<bits/stdc++.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class Item{
	private:
		char *name;
        char *name1;
		int *price;
		int *quantity;
		int *rating;
	public:
		Item()
		{
			name=new char[20];
            name1=new char[20];
		    price=new int;
			quantity=new int;
			rating=new int;
		}
		void addNewItem();
		void buyItem();
        bool searchByName(char na[20]);
		void showItems();
		bool isPopularItem();
		
};
void Item::addNewItem()
{
	cin.ignore();
	cout<<"Enter Name of an Supplier: ";cin.getline(name,20);
    cout<<"Enter Name of an item: ";cin.getline(name1,20);
	cout<<"Enter price of an item: ";cin>>*price;
	cout<<"Enter quantity : ";cin>>*quantity;
	cout<<"Enter rating of an item out of 5: ";cin>>*rating;
	
	
}


bool Item::searchByName(char na[20])
{
	if(strcmp(na,name1)==0)
	return true;
	
	else
	return false;
}
void Item::showItems()
{
    cout<<"supplier Name: "<<name<<endl;
    cout<<"Supplied Product Name: "<<name1<<endl;
	cout<<"Price: "<<*price<<endl;
	cout<<"Quantity availabel: "<<*quantity<<endl;
	cout<<"Rating out of 5: "<<*rating<<endl;
}
bool Item::isPopularItem()
{
	if(*rating>=4)
	return true;
	
	else
	return false;
}
void Item::buyItem()
{
	int money,q;
	
	cout<<"\nQuantity Available : "<<*quantity<<"\nQuantity Required? ";cin>>q;
	cout<<"Amount to be paid: "<<(*price)*q<<"\n";
	cout<<"Please pay the amount : ";cin>>money;
	
	if(money==((*price)*q) && *quantity!=0)
	{
		cout<<"\n------- Item bought!!---------"<<endl;
		cout<<"\n-----Details of item bought------\n";
		cout<<" Name: "<<name<<"    "<<"Quantity: "<<q<<"  "<<"Amount paid: "<<money<<endl;
		*quantity=*quantity-q;
	}
	
	else
	cout<<"\nSorry item cannot be bought\n";
}
int login()
{
      char username[20];
      string pass; 
      int i;

      printf("Enter your User Name : ");
      scanf("%s",username);

      printf("Enter your password : ");
      cin>>pass;
    
      if(username=="prathamesh"  && pass=="12345")
     {
          printf("\n\nLogged In Successful\n");
          return 1;
     }

     else
    {
      
	   printf("\n\n\t\t  Logged In Successfully\n");
       
        return 0;
    }
}
int main()
{
    login();
   Item *I[20];
   cout<<"<--------------------WELCOME USER-------------------->"<<"\n"<<"\n"<<"\n";
   
   int i=0,choice,no;
   char na[20];
   
   while(choice!=5)
   {
   	
   	 cout<<"\n\t\t1.ADD SUPPLIERS STOCK DETAILS\n\t\t2.Buy Item\n\t\t3.DISPLAY ALL SUPPLIERS\n\t\t4.Premium Products Available\n\t\t5.Exit\n";
   	 cout<<"\n\n\t\tEnter choice from above: ";
   	 cin>>choice;
   	 switch(choice)
   	 {
   	 	case 1:
   	 		{
   	 			I[i]=new Item;
   	 			I[i]->addNewItem();
   	 			i++;
   	 			break;
			}
		case 2:
			{
				cin.ignore();
				int f=0;
				cout<<"\nEnter name of an item to buy: ";
				cin.getline(na,20);
				for(int t=0;t<i;t++)
				{
					if(I[t]->searchByName(na))
					{
						I[t]->buyItem();
						f=1;
						break;
					}
				}
				if(f==0)cout<<"\nItem not found!!\n";
				break;
			}
				
		case 3:
			{
				cout<<"\n----------All Suppliers Record------------\n\n ";
				for(int t=0;t<i;t++)
				{
					I[t]->showItems();
					cout<<"\n";
				}
				break;
			}
		case 4:
			{
				cout<<"\n-----------Premium Dairy Products--------------\n";
				cout<<"\n";
				for(int t=0;t<i;t++)
				{
					if(I[t]->isPopularItem())
					{
						I[t]->showItems();
						cout<<"\n";
					}
				}
			}
			case 5:
				exit(0);
				break;
			default:
				cout<<"\nEnter a valid choice\n";
				
		}
   }
	return 0;
}