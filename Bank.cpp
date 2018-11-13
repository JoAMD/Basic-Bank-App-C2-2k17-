#include<dos.h>
#include<string.h>
#include<ctype.h>
#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void clearline(int y)
{
 gotoxy(1,y);
 for(int i=0;i<80;++i)
  cout<<" ";
}
struct Date
{
 int date,month,year;
};
class Bank
{
 float AccNo,Balance;
 char UserName[30],Name[30],Address[50],Password[30],AccType[10],Gender;
 Date DOB;
 public: void Input();
	 void SetPassword();
	 void Transaction();
	 char* getUserName()
	 {
	  return UserName;
	 }
	 float getAccNo()
	 {
	  return AccNo;
	 }
	 char* getPassword()
	 {
	  return Password;
	 }
	 void Display();
	 float getBalance()
	 {
	  return Balance;
	 }
	 void AddToBalance(float a)
	 {
	  Balance+=a;
	 }
	 void SubtractFromBalance(float a)
	 {
	  Balance-=a;
	 }
	 void Modify();
	 void Insert();
	 void ModifyPassword();
}B;
void Bank::SetPassword()
{
 int f1=0,f2=0,f3=0,f4=0;
 while(f1==0||f2==0||f3==0||f4==0)
 {
  f1=f2=f3=f4=0;
  gotoxy(5,21);
  cout<<"Enter Password:";
  gotoxy(35,21);
  gets(Password);
  int i=0;
  clearline(21);
  clearline(23);
  clearline(24);
  clearline(25);
  clearline(26);
  while(Password[i]!='\0')
  {
   if(isalnum(Password[i])==0)
   {
     f1=1;
   }
   if(isupper(Password[i])!=0)
   {
     f2=1;
   }
   if(islower(Password[i])!=0)
   {
     f3=1;
   }
   if(strlen(Password)>=8)
   {
    f4=1;
   }
   if(f1==1&&f2==1&&f3==1&&f4==1)
    break;
   ++i;
  }
  int l=0;
  if(f1==0)
  {
   gotoxy(5,23);
   cout<<"Password should contain atleast one special character ";
   ++l;
  }
  if(f2==0)
  {
   gotoxy(5,23+l);
   cout<<"Password should contain atleast one uppercase letter ";
   ++l;
  }
  if(f3==0)
  {
   gotoxy(5,23+l);
   cout<<"Password should contain alteast one lowercase character ";
   ++l;
  }
  if(f4==0)
  {
   gotoxy(5,23+l);
   cout<<"Password should contain atleast 8 characters ";
   ++l;
  }
 }
}
void Bank::ModifyPassword()
{
 int f1=0,f2=0,f3=0,f4=0;
 while(f1==0||f2==0||f3==0||f4==0)
 {
  f1=f2=f3=f4=0;
  gotoxy(15,21);
  cout<<"Enter Password:";
  gotoxy(35,21);
  gets(Password);
  int i=0;
  clearline(23);
  clearline(24);
  clearline(25);
  clearline(26);
  while(Password[i]!='\0')
  {
   if(isalnum(Password[i])==0)
   {
     f1=1;
   }
   if(isupper(Password[i])!=0)
   {
     f2=1;
   }
   if(islower(Password[i])!=0)
   {
     f3=1;
   }
   if(strlen(Password)>=8)
   {
    f4=1;
   }
   if(f1==1&&f2==1&&f3==1&&f4==1)
    break;
   ++i;
  }
  int l=0;
  if(f1==0)
  {
   gotoxy(15,23);
   cout<<"Password should contain atleast one special character ";
   ++l;
  }
  if(f2==0)
  {
   gotoxy(15,23+l);
   cout<<"Password should contain atleast one uppercase letter ";
   ++l;
  }
  if(f3==0)
  {
   gotoxy(15,23+l);
   cout<<"Password should contain alteast one lowercase character ";
   ++l;
  }
  if(f4==0)
  {
   gotoxy(15,23+l);
   cout<<"Password should contain atleast 8 characters ";
   ++l;
  }
 }
}
void Bank::Input()
{
 clrscr();
 gotoxy(20,3);
 cout<<"Enter the details of the account holder";
 gotoxy(5,5);
 cout<<"Enter account number";
 gotoxy(35,5);
 cin>>AccNo;
 gotoxy(5,7);
 cout<<"Enter the username";
 gotoxy(35,7);
 gets(UserName);
 gotoxy(5,9);
 cout<<"Enter the name ";
 gotoxy(35,9);
 gets(Name);
 gotoxy(5,11);
 cout<<"Enter the address ";
 gotoxy(35,11);
 gets(Address);
 gotoxy(5,13);
 cout<<"Enter the gender (M/F)";
 gotoxy(35,13);
 cin>>Gender;
 gotoxy(5,15);
 cout<<"Enter the account type";
 gotoxy(35,15);
 gets(AccType);
 gotoxy(5,17);
 cout<<"Enter the date of birth";
 gotoxy(35,17);
 cin>>DOB.date;
 gotoxy(38,17);
 cin>>DOB.month;
 gotoxy(41,17);
 cin>>DOB.year;
 SetPassword();
}
void Bank::Insert()
{
 ifstream fin("Bank.dat",ios::binary);
 ofstream fout("temp.dat",ios::binary);
 int flag=0;Bank B1;
 while(!fin.eof())
 {
  fin.read((char*)&B1,sizeof(Bank));
  if(fin.eof())
   break;
  if(AccNo==B1.getAccNo())
  {
   clrscr();
   gotoxy(15,25);
   cout<<"Account Number already exists";
   getch();
   B.Input();
  }
  if(UserName==B1.getUserName())
  {
   clrscr();
   gotoxy(15,25);
   cout<<"Username already exists";
   getch();
   B.Input();
  }
 }
 fin.seekg(0);
 while(!fin.eof())
 {
  fin.read((char*)&B1,sizeof(B1));
  if(fin.eof())
   break;
  if(AccNo<B1.getAccNo())
  {
   Balance=1000;
   fout.write((char*)this,sizeof(Bank));
   fout.write((char*)&B1,sizeof(B1));
   flag=1;
   break;
  }
  else
   fout.write((char*)&B1,sizeof(B1));
 }
 if(flag==0)
 {
  Balance=1000;
  fout.write((char*)this,sizeof(Bank));
 }
 else
  while(!fin.eof())
  {
   fin.read((char*)&B1,sizeof(B1));
   if(fin.eof())
   break;
   fout.write((char*)&B1,sizeof(B1));
  }
 fin.close();
 fout.close();
 remove("Bank.dat");
 rename("temp.dat","Bank.dat");
}
void NAME()
{
 clrscr();int i=1;
 while(i<38)
 {
  gotoxy(i,16);
  cout<<"                      *";
  gotoxy(i,17);
  cout<<"                      **";
  gotoxy(i,18);
  cout<<"                      ***";
  gotoxy(i,19);
  cout<<"                      ****";
  gotoxy(i,20);
  cout<<"  ///////////////********************          ";
  gotoxy(i,21);
  cout<<"  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*                   *         ";
  gotoxy(i,22);
  cout<<"  ///////////////*                    *        ";
  gotoxy(i,23);
  cout<<"  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*                     *       ";
  gotoxy(i,24);
  cout<<"  ///////////////*                      *      ";
  gotoxy(i,25);
  cout<<"  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*                       *     ";
  gotoxy(i,26);
  cout<<"  ///////////////*                        *    ";
  gotoxy(i,27);
  cout<<"    JIJ BANK     *       JIJ BANK          *   ";
  gotoxy(i,28);
  cout<<"  ///////////////*                        *    ";
  gotoxy(i,29);
  cout<<"  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*                       *     ";
  gotoxy(i,30);
  cout<<"  ///////////////*                      *      ";
  gotoxy(i,31);
  cout<<"  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*                     *       ";
  gotoxy(i,32);
  cout<<"  ///////////////*                    *        ";
  gotoxy(i,33);
  cout<<"  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*                   *         ";
  gotoxy(i,34);
  cout<<"  ///////////////*                  *          ";
  gotoxy(i,35);
  cout<<"  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*******************           ";
  gotoxy(i,36);
  cout<<"                      ****";
  gotoxy(i,37);
  cout<<"                      ***";
  gotoxy(i,38);
  cout<<"                      **";
  gotoxy(i,39);
  cout<<"                      *";
  delay(150);
  clrscr();
  ++i;
 }
}

void Loading()
{
 clrscr();int i=1;
 while(i<38)
 {
  gotoxy(i,16);
  cout<<"                      *";
  gotoxy(i,17);
  cout<<"                      **";
  gotoxy(i,18);
  cout<<"                      ***";
  gotoxy(i,19);
  cout<<"                      ****";
  gotoxy(i,20);
  cout<<"  ///////////////********************          ";
  gotoxy(i,21);
  cout<<"  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*                   *         ";
  gotoxy(i,22);
  cout<<"  ///////////////*                    *        ";
  gotoxy(i,23);
  cout<<"  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*                     *       ";
  gotoxy(i,24);
  cout<<"  ///////////////*                      *      ";
  gotoxy(i,25);
  cout<<"  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*                       *     ";
  gotoxy(i,26);
  cout<<"  ///////////////*                        *    ";
  gotoxy(i,27);
  cout<<"    JIJ BANK     *       LOADING...        *   ";
  gotoxy(i,28);
  cout<<"  ///////////////*                        *    ";
  gotoxy(i,29);
  cout<<"  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*                       *     ";
  gotoxy(i,30);
  cout<<"  ///////////////*                      *      ";
  gotoxy(i,31);
  cout<<"  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*                     *       ";
  gotoxy(i,32);
  cout<<"  ///////////////*                    *        ";
  gotoxy(i,33);
  cout<<"  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*                   *         ";
  gotoxy(i,34);
  cout<<"  ///////////////*                  *          ";
  gotoxy(i,35);
  cout<<"  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*******************           ";
  gotoxy(i,36);
  cout<<"                      ****";
  gotoxy(i,37);
  cout<<"                      ***";
  gotoxy(i,38);
  cout<<"                      **";
  gotoxy(i,39);
  cout<<"                      *";
  delay(150);
  clrscr();
  ++i;
 }
}
void AccDel()
{
 ifstream fin("Bank.dat",ios::binary);
 ofstream fout("TEMP.dat",ios::binary);
 gotoxy(25,25);
 cout<<"Enter your Account number";
 float AccNo1;
 gotoxy(25,27);
 cin>>AccNo1;Bank B1;
 while(!fin.eof())
 {
  fin.read((char*)&B1,sizeof(Bank));
  if(fin.eof())
   break;
  if(AccNo1!=B1.getAccNo())
   fout.write((char*)&B1,sizeof(Bank));
 }
 fin.close();
 fout.close();
 remove("Bank.dat");
 rename("TEMP.dat","Bank.dat");

}
void Bank::Transaction()
{
 Bank B1,B2;
 float AccNo2;
 gotoxy(20,20);
 cout<<"Enter the amount to be transferred";
 float Amt;
 gotoxy(20,22);
 cin>>Amt;
 gotoxy(5,25);
 cout<<"Enter the Account No of the account to which you wish to transfer funds";
 gotoxy(5,27);
 cin>>AccNo2;
 fstream f("Bank.dat",ios::binary|ios::in|ios::out);
 B.SubtractFromBalance(Amt);
 f.seekg(0);int p,q;
 while(!f.eof())
 {
  p=f.tellg();
  f.read((char*)&B2,sizeof(Bank));
  if(f.eof())
   break;
  if(B2.getAccNo()==B.AccNo)
  {
   f.seekp(p);
   f.write((char*)&B,sizeof(Bank));
  }
  f.close();
  f.open("Bank.dat",ios::binary|ios::in|ios::out);
  while(!f.eof())
  {
   q=f.tellg();
   f.read((char*)&B1,sizeof(Bank));
   if(f.eof())
    break;
   B1.AddToBalance(Amt);
   if(B1.getAccNo()==AccNo2)
   {
    f.seekp(q);
    f.write((char*)&B1,sizeof(B1));
   }
  }
 }
 f.close();
}
void Bank::Display()
{
 gotoxy(20,5);
 cout<<"Account Holder Information";
 gotoxy(5,9);
 cout<<"Account Number";
 gotoxy(35,9 );
 cout<<AccNo;
 gotoxy(5,11);
 cout<<"Name ";
 gotoxy(35,11);
 cout<<Name;
 gotoxy(5,13);
 cout<<"Address ";
 gotoxy(35,13);
 cout<<Address;
 gotoxy(5,15);
 cout<<"Gender";
 gotoxy(35,15);
 cout<<Gender;
 gotoxy(5,17);
 cout<<"Account Type";
 gotoxy(35,17);
 cout<<AccType;
 gotoxy(5,19);
 cout<<"Date of Birth";
 gotoxy(35,19);
 cout<<DOB.date<<" "<<DOB.month<<" "<<DOB.year;
}
void LogIN()
{
 clrscr();Bank B1;
 ifstream fin("Bank.dat",ios::binary);
 char ch[20],pw[20];
 gotoxy(20,20);
 cout<<"Enter Username: ";
 gets(ch);int k=0,j=3,a=0;
 while(!fin.eof())
 {
  fin.read((char*)&B1,sizeof(Bank));
  if(fin.eof())
   break;
  if(strcmp(ch,B1.getUserName())==0)
  {
   a=1;
   break;
  }
 }
 if(a==0)
 {
  gotoxy(20,25);
  cout<<"Username does not exist \n";
  getch();
  exit(0);
 }
 while(k==0&&j>0)
 {
  gotoxy(20,22);
  cout<<"Enter Password:              ";
  gotoxy(18,25);
  cout<<"You have "<<j<<" attempts remaining";
  gotoxy(36,22);
  gets(pw);
  j--;
  if(strcmp(B1.getPassword(),pw)==0)
  {
   k=1;
   gotoxy(22,30);
   cout<<"Password Correct ";
   getch();
   break;
  }
  if(j==0)
  {
   clrscr();
   gotoxy(20,28);
   cout<<"Terminating.... ";
   delay(3000);
   exit(0);
  }
 }
 fin.close();
 B=B1;
}
void Bank::Modify()
{
 int a;
 gotoxy(20,17);
 cout<<"1.Address";
 gotoxy(20,19);
 cout<<"2.Password";
 gotoxy(20,21);
 cout<<"3.Exit";
 gotoxy(20,24);
 cout<<"Enter the option to modify    ";
 cin>>a;
 clrscr();
 switch(a)
 {
  case 1: gotoxy(20,25);
	  cout<<"Enter new address    ";
	  char a[50];
	  gets(a);
	  strcpy(Address,a);
	  break;

  case 2: ModifyPassword();
	  break;

  case 3: //go to main menu after login;
	  return;
  default:cout<<"Invalid input\n";
 }

 int p;Bank B1;
 fstream f("Bank.dat",ios::binary|ios::in|ios::out);
 while(!f.eof())
 {
  p=f.tellp();
  f.read((char*)&B1,sizeof(B1));
  if(f.eof())
   break;
  if(B1.getAccNo()==AccNo)
  {
   f.seekp(p);
   f.write((char*)this,sizeof(Bank));
  }
 }
 f.close();
}
void main()
{
 textcolor(YELLOW);
 int ch1,ch2,a;
 NAME();
 do
 {
  a=0;
  clrscr();
  gotoxy(20,20);
  cout<<"1. Sign Up ";
  gotoxy(20,22);
  cout<<"2. Log In ";
  gotoxy(20,24);
  cout<<"3. Exit ";
  gotoxy(20,26);
  cout<<"Enter your choice   ";
  cin>>ch1;
  clrscr();
  if(ch1==1)
  {
   B.Input();
   B.Insert();
  }
  else if(ch1==2)
   LogIN();
  else
   exit(0);
  do
  {
   a=1;
   clrscr();
   gotoxy(20,15);
   cout<<"What do you want to do ?\n";
   gotoxy(10,18);
   cout<<"1.View Account Balance \n";
   gotoxy(10,20);
   cout<<"2.View Account details";
   gotoxy(10,22);
   cout<<"3.Modify details ";
   gotoxy(10,24);
   cout<<"4.Transaction ";
   gotoxy(10,26);
   cout<<"5.Delete Account";
   gotoxy(10,28);
   cout<<"6.Log Out";
   gotoxy(10,30);
   cout<<"Enter your choice   ";
   cin>>ch2;
   clrscr();
   Loading();
   clrscr();
   switch(ch2)
   {
    case 1: gotoxy(20,25);
	    cout<<"Your current account balance is "<<B.getBalance();
	    getch();
	    break;
    case 2: B.Display();
	    getch();
	    break;
    case 3: B.Modify();
	    clrscr();
	    B.Display();
	    getch();
	    break;
    case 4: B.Transaction();
	    break;
    case 5: AccDel();
	    a=0;
	    break;
    case 6: gotoxy(25,25);
	    cout<<"Logging Out....";
	    a=0;
	    delay(3000);
	    break;
    default: gotoxy(25,25);
	     cout<<"Invalid Input ";
   }
  }while(a==1);
 }while(a==0);
 getch();
}
