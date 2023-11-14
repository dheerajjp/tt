//Header files
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<cstring>
//#include<conio.h>
#include<ctime>
using namespace std;
//FSTREAM VARIABLE
fstream fin;
/*------------------------------------------------------------------------------------------------------ CLASS
CANCELL----------------------*/
class cancell {
public:
long pnr;
long tno;
char tname[100];
char bp[20];
char dest[20];
char name[10][200];
int age[10];
int d, m, y;
int nos;
int amt;
 char clas;
 void get();
void screen();
};
//MEMBER FUNCTION TO GET PNR DETAILS
void cancell::get()
{
cout << "\nEnter the details as follows: ";
cout << "\nEnter PNR number: ";
cin >> pnr;
}
//MEMBER FUNCTION TO SHOW CANCELL DETAILS
void cancell::screen()
{
cout << "\nPNR number: " << pnr;
cout << "\nTrain number: " << tno;
cout << "\nTrain Name: " << tname;
cout << "\nBoarding station: " << bp;
cout << "\nDestination station: " << dest;
17
cout << "\nNumber of seat: " << nos;
cout << "\n Your Class: "
if (clas == 'f')
{
cout << "\tFirst Class";
}
else if(clas=='s')
{
cout << "\tSecond class";
}
for (int i = 0;i < nos;i++) {
cout << "\nName of Passenger: " << name[i];
cout << "\n Age: " << age[i];
}
cout << "\nDate of cancellation: " << d << "/" << m << "/" << y;
cout << "\nYou can collect: " << amt-250;
}
/*------------------------------------------------------------------------------------------------------------ CLASS
RESERVE ---------------------------
----------------------------------------------------------------------------*/
class reserve
{
public:
long tno;
int nof;
long pnr;
char tname[100];
char bd[100];
char dest[100];
int age[100];
char name[10][200];
int amc;
char clas;
int d, m, y;
int sno;
int ret()
{
return pnr;
}
18
//MEMBER FUNCTION TO COPY DETAILS
void ca()
{
cancell a;
a.pnr = pnr;
a.tno = tno;
strcpy(a.tname,tname);
strcpy(a.bp, bd);
strcpy(a.dest, dest);
a.d = d;
a.m = m;
a.y = y;
a.clas = clas;
a.amt = amc;
a.nos = nof;
for (int i = 0;i < nof;i++)
{
strcpy(a.name[i], name[i]);
a.age[i] = age[i];
}
a.screen();
}
 //MEMBER FUNCTION TO SHOW DETAILS
 void show()
{
int i;
ofstream f2;
f2.open("cancell.dat", ios::out|ios::app);
f2 << tname << endl << tno << endl << bd << endl <<
 dest << endl << d << " " << m << " " << y << "\n";
for (i = 0;i < nof;i++)
{
f2 << name[i] << "\t" << age[i] << "\t" << pnr <<
 "\t" << sno << "\n";
}
f2.close();
ca();
}

//MEMBER FUNCTION TO SEARCH IN FILE
void search(int x)
19
{
cancell k;
int i;
ifstream f1;
f1.open("rseservation.dat", ios::in);
if (!f1)
{
cout << "Ticket Cancelled\n";
}
else
{
fin.read((char*)this, sizeof(*this));
while (!f1.eof())
{
if (x == pnr)
{
show();
}
else {
cout << "\nyou have not done your reservation till: ";
}
f1.read((char*)this, sizeof(*this));
}
f1.close();
}
}
//MEMBER FUNCTION TO GET DETAIL FOR RESERVATION
void getdata()
{
cout << "~~~~~RESERVATION~~~~~";
cout << "\nEnter Train Number: ";
cin >> tno;
cin.ignore();
cout << "\nEnter train name: ";
cin.getline(tname, 20);
cout << "\nEnter Boarding Station: ";
cin.getline(bd, 20);
cout << "\nEnter Destination: ";
cin.getline(dest, 20);
cout << "\nEnter number of seats to be booked: ";
cin >> nof;
 cout << "\nEnter the date(dd mm yyyy)";
cin >> d >> m >> y;
20
cin.ignore();
for (int i = 0;i < nof;i++)
{
cout << "\nEnter Name: ";
cin.getline(name[i], 20);
cout << "\nEnter age: ";
cin >> age[i];
cin.ignore();
}
cout << "\nEnter first-class or second class(f/s): ";
cin >> clas;
cout << "--------------------------------------------";
cout << "end of reservation";

cout << "--------------------------------------------";
if ((clas == 'f')||clas=='F')
{
amc = 2500 * nof;
}
else if ((clas == 's'||clas=='S'))
{
amc = 1200 * nof;
}
}
//MEMBER FUNCTION TO SHOW RESERVATION DETAILS
void putu()
{
int i;
srand(time(NULL));
fin.open("reservation.dat", ios::app|ios::out);
cout << "\nTrain Name: " << tname;
cout << "\nTrain number: " << tno;
cout << "\nboarding station: " << bd;
cout << "\ndestination: " << dest;
cout << "\nperson information: ";
cout << "\nTravelling date" << d << "/" << m << "/" <<
 y;
pnr = rand() % 9000000 + 1000000;
cout << "\tPNR: " << pnr;
for ( i = 0;i < nof;i++)
{
 cout << "\nName: " << name[i];
cout << "\tage" << age[i];
21
sno = rand() % 64 + 1;
cout << "\tseat number: " <<sno ;
}
cout << "\nTotal Fare" << amc;
fin << tname << endl << tno << endl << bd << endl <<
 dest << endl << d << " " << m << " " << y<<"\n";
for (i = 0;i < nof;i++)
{
fin << name[i] << "\t" << age[i] << "\t" << pnr <<
 "\t" << sno<<"\n";
}
fin.close();
}
//MEMBER FUNCTION FOR ENQUIRY
void enquiry(int n)
{
int pl;
int h, m;
int t1, t2,m1,m2;
t1 = rand() % 24 + 1;
m1 = rand() % 59 + 1;
m2 = rand() % 59 + 1;
pl = rand() % 6 + 1;
h = rand() % 2 + 0;
m = rand() % 60 + 0;
cout << "\ntrain will arrive in Platform Number" << pl;
cout << "\nTrain is late by " << h << " hours and " <<
 m << " minutes";
cout << "\nActual Arrival time :- " << t1 << ":" << m1;
cout << "\nArrival time" << h + t1 << ":" << m;
cout << "\nDeparture time" << t1 + h + 20 << m2;
}
};
//MAIN FUNCTION
int main()
22
{
reserve r2;
cancell o;
int z=0;
ifstream f1;
ofstream f2;
char *id="ADMIN";
char *password = "12345678";
char n[50];
char pass[50];
int ch;
cout << "~~~~~~~~~~~~Welcome TO INDIAN RAILWAY~~~~~~~~~~~~~~~~~~~~";


h:
cout << "\n Enter your id";
cin >> n;
cout << "\nEnter password";
 cin >> pass;
if ((strcmp("ADMIN", n) != 0) && (strcmp(password,
 pass) != 0))
{
cout << "\n\nWrong Password\n\nPlease Enter The Correct password";
goto h;
}
else
{
k:
cout << "\n\n\n\nENTER YOUR
CHOICE\n1)RESERVATION\n2)CANCELLATION\n3)ENQUIRY\n4)EXIT";
 cin >> ch;
 switch (ch)
{
case 1:
r2.getdata();
r2.putu();
goto k;
break;
case 2:
cout << "---------------------------- CANCELLATION----------------------
-----------------"<<endl;
cout << "Enter the pnr : ";
cin >> z;
23
r2.search(z);
goto k;
break;
case 3:
cout << "Enter the pnr : ";
cin >> z;
r2.enquiry(z);
goto k;
Break;
case 4:
exit(0);
}
}
return 0;
}