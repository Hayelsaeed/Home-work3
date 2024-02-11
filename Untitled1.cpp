#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
 using namespace std;
 
class Products
{
private:
	int PNo;
	string PName;
	float PPrice,PQty;
public:
	void Creat_Product()
	{
	cout<<"\n Enter The Product Number :"; cin>>PNo;
	cout<<" Enter The Product Name :"; cin>>PName;
	cout<<" Enter The Product Price :"; cin>>PPrice;
	cout<<" Enter The Product Quantity:"; cin>>PQty;	
		
	}
	void Show_Info()
	{
	cout<<"\n The Product Number Is \t :"<<PNo;
	cout<<"\n The Product Name Is \t :"<<PName;
	cout<<"\n The Product Price Is \t :"<<PPrice;
	cout<<"\n The Product Quantity Is \t:"<<PQty;
	}
	
	int Pnum()
	{return PNo;}
	
	string Pname()
	{return PName;}
	
	float Pprice()
	{return PPrice;}
};

Products pro;
fstream fp;

void Write_Products()
{
	fp.open("Shop.txt",ios::out|ios::app);
	pro.Creat_Product();
	fp.write((char*)&pro , sizeof(Products));
	fp.close();
	cout<<"\n\n The Product Created";
	getch();
}

void Display_Products()
{
    cout<<"\n All The Products Information : \n \n ";
    fp.open("Shop.txt",ios::in);
    while(fp.read((char*)&pro,sizeof (Products)))
    {
    pro.Show_Info();
	cout<<"\n\n =========================================== \n ";
	getch();
		
	}
    fp.close();
    getch();
}
void Search_Products(int num)
{
	int flag = 0;
 	fp.open("Shop.txt",ios::in);
	while(fp.read((char*)&pro,sizeof (Products)))
   {
		if (pro.Pnum()==num )
		{
			pro.Show_Info();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	{
		cout<<"\n \nProduct Not Stored \n";
		getch();
	}
	
}

void Delete_Products()
{
	int num;
	cout<<"\n\n Please Enter the Product Want To Deleted : "; cin>>num;
	fp.open("Shop.txt",ios::in|ios::out);
	fstream fp2;
	fp2.open("Replace.txt",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&pro,sizeof (Products)))
	{
		if (pro.Pnum()!=num )
		{
	     	fp2.write((char*)&pro ,sizeof(Products));	
		}
    }
    fp2.close();
    fp.close();
    remove("Shop.txt");
    cout<<"\n\n The Product Deleted " ;
    getch();
    
}

void intro()
{
	cout<<"\t\t\t SUPER MARKET ";
	cout<<"PROJECT ";
	cout<<"\n\n \t\t\t MADE BY  :  Hayel Saeed ";
	cout<<"\n\n \t\t    ********** Good Luck ********** ";
	getch();
}

int main()
{
	char ch;
	intro();
	do
	{
		cout<<"\n\n\n     Main MENU";
		cout<<"\n\n\t1.CREATE PRODCUT";
		cout<<"\n\n\t2.DISPLAY ALL PRODUCTS";
		cout<<"\n\n\t3.SEARCH ";
		cout<<"\n\n\t4.DELETE PRODUCT";
		cout<<"\n\n\t5.VIEW PRODUCT MENU";
		cout<<"\n\n\t6.EXIT";
		cout<<"\n\n\tPleas Enter your Choice(1-6) ";
		ch=getche();
		switch(ch)
		{
		
		   case'1':
		   	  Write_Products();
		   	  break;
		   	  
		   case'2':
		   	  Display_Products();
		   	  break;
		   	  
		   case'3':
		      int Num;
		      cout<<"\n Enter The Num To search : \t"; cin>>Num;
		      Search_Products(Num);
		      break;
		      
		   case'4':
		      Delete_Products();
		      break;
		      
		   case'5':
		      exit(0);
		      
		    default:
		      cout<<"Error";
		      exit(0);
	   }
   	} while(ch!=5);
}

