#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
using namespace std;
struct inventory{
	string name;
	int id;
	float price;
	int qty;
	inventory*nptr;
};inventory*fptr=NULL;

inventory*idcheck(int id)
{  
    inventory*ptr=fptr;
    if(ptr==NULL)
    {  
      return NULL;
	}
	else 
	{ inventory*currentptr=fptr;
	 while(currentptr!=NULL)
	   {
		
	    if(currentptr->id==id)
	    return currentptr;
	    else
	    currentptr=currentptr->nptr;
	}
}
}
void insert(inventory*ptr,int id)
{
ptr=new inventory;
ptr->id=id;
cout<<"Enter Item Name: "<<endl;
cin.ignore();
getline	(cin,ptr->name);
cout<<"Enter Price PER Item: "<<endl;
cin>>ptr->price;
cout<<"Enter Quantity: "<<endl;
cin>>ptr->qty;
ptr->nptr=NULL;
if(fptr==NULL)
{  
   fptr=ptr;
}
else
{  
   if(fptr->id>ptr->id)
   {  
      ptr->nptr=fptr;
      fptr=ptr;
   }
   else
   {  
      inventory*currentptr=fptr;
      while(currentptr->nptr!=NULL){
	  
      if(currentptr->nptr->id>ptr->id)
      {  
         ptr->nptr=currentptr->nptr;
         currentptr->nptr=ptr;
         break;
	  }currentptr->nptr=ptr;
   }
   if(currentptr->nptr==NULL)
   {  
      currentptr->nptr=ptr;
   }
}
}
}
void deleteitem(inventory*currentptr,int id)

{ currentptr=fptr;
 
 while(currentptr!=NULL)
 {  
    if(id==fptr->id)
    {  
        fptr=fptr->nptr;
        break;
	}
	else
	{  
	   if(id==currentptr->nptr->id)
	   {  
	      currentptr->nptr=currentptr->nptr->nptr;
	      break;
	   }
	  currentptr=currentptr->nptr; 
	}
 }
    
	
}
 void display(inventory*ptr)
{while(ptr!=NULL)
{  
    cout<<"Item Name: "<<ptr->name<<endl;
	cout<<"Quantity: "<<ptr->qty<<endl;
	cout<<"Price Per Item:Rs. "<<ptr->price<<endl;
	ptr=ptr->nptr;
}
}
void stock(inventory*ptr)
{  
    while(ptr!=NULL)
    {   cout<<"Item Name: "<<ptr->name<<endl;
	    cout<<"Quantity: "<<ptr->qty<<endl;
	    cout<<"Stock Price:Rs. "<<ptr->qty*ptr->price<<endl;
       ptr=ptr->nptr;
	}
}
int main()
{  fstream file;
file.open("inventory.txt");
	string line;
	if(file){
		while(!file.eof()){
			getline(file,line);
			if(line == "&&"){
				int p;
				inventory*ptr = new inventory;
				string s1,s2,s3,s4;
				getline(file,s1);
				stringstream ss(s1);
				ss>>p;
				ptr->id = p;
				getline(file,s2);
				ptr->name = s2;
				getline(file,s3);
				stringstream ss1(s3);
				ss1>>p;
				ptr->price = p;
				getline(file,s4);
				stringstream ss2(s4);
				ss2>>p;
				ptr->qty = p;
				ptr->nptr = NULL;
				if(fptr == NULL ){
					fptr = ptr;
				}
				
				else{
					inventory*currentptr;
					currentptr = fptr;
					while(currentptr->nptr != NULL){
						currentptr = currentptr->nptr;
					}
					currentptr->nptr = ptr;
				}
			}
		}
		
		file.close();
	}
	else 
		cout<<"File not exist"<<endl;
	

int opt,id_check=0,id;
   while(1)
   {  
      cout<<"Main Menu\n1.Add Inventory System\n2.Update Inventory System\n3.Remove Entry System\n4.Display Inventory System\n5.Total Stock In Rupees\n6.Save Data Into File\n";
      cin>>opt;
      if(opt==1)
      { 
         
         	while(id_check==0)
         	{  
         	   cout<<"Enter ID: "<<endl;
         	   cin>>id;

         	   if(idcheck(id)!=NULL)
         	   {  
         	     cout<<"ID exists Already\n";
         	     id_check=0;
         	     
				}
				else 
				{  
				   
				    id_check=1;
				}}
				if(id_check==1)
				{  insert(fptr,id);
				
				}
				id_check=0;}
				
		if(opt== 2){
		
	      int option,quantity;
	      float price;
			int id;
			int check=0;
			while(check==0){
			cout<<"Enter Item Id: ";
		    cin>>id;
			if(idcheck(id)==NULL){
			cout<<"NO Record Found!";
          	check=0;
          	break;
			  }else if(idcheck(id)!=NULL){
			    check=1;
			inventory*print=idcheck(id);
			cout<<"Item Name: "<<print->name<<endl;
			cout<<"Quantity: "<<print->qty<<endl;
			cout<<"What do you want to update?\n1.Price\n2.Quantity\n";
			cin>>option;
			if(option==1)
			{  
			   cout<<"Enter New Price Per Item\n";
			   cin>>price;
			   print->price=price;
			   cout<<"Operation Successfull!";
			}
			if(option==2)
			{ 
			  cout<<"Enter New Quantity\n";
			  cin>>quantity;
			  print->qty=print->qty+quantity;
			  cout<<"Operation Successfull!";
		}	}
	}
}
  if(opt==3)
		{
				
			int icheck=0;
			while(icheck==0){
			cout<<"Enter Item Id: ";
		    cin>>id;
			if(idcheck(id)==NULL){
			cout<<"NO Record Found!";
          	icheck=0;
          	break;
			  }else if(idcheck(id)!=NULL){
			    icheck=1;
			inventory*print=idcheck(id);
			cout<<"Item Name: "<<print->name<<endl;
			cout<<"Quantity: "<<print->qty<<endl;
			deleteitem(fptr,id);
		cout<<"Deleted Successfully!"<<endl;
	}
	
}
}


if(opt== 4 )

		display(fptr);
	
if(opt==5)
         
		  stock(fptr);	
if(opt==6)		

{
file.open("inventory.txt",ios::out | ios::app);
		inventory *currentptr = fptr;
		while(currentptr != NULL){
			file<<"&&"<<endl;
			file<<currentptr->id<<endl;
			file<<currentptr->name<<endl;
			file<<currentptr->price<<endl;
			file<<currentptr->qty<<endl;
			
			currentptr = currentptr->nptr;
	}
		file.close();
	}
	
		
	  
   }
}
