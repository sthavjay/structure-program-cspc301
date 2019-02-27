#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

struct person {
  char Name[20];
  float Balance;
};

void display ( person a[], int N){
  cout<<display<<endl;
for (int i= 0; i<N; i++){
cout <<a[i].Name  <<" "<<a[i].Balance<<endl;
}
return;
}

void FindRichest(person a[], int N){
  float amt = 0;
  string rich = a[0].Name;
 for (int i =0; i<N;i++ ) {
 if (a[i].Balance > amt)
  amt = a[i].Balance;
  rich = a[i].Name;
}
cout << "the richest person  is" <<rich<< " " << amt<< endl;
}


void Deposit(string custname, person*a, int N){
  float amount;
  int match=0;
  cout<< "enter the full name of deposite amount :"<<name<< " "<<endl;
  cin>>"enter the new amount to  deposite">> amount>> endl;

  for (int i = 0; i<N; i++){
    if (a[i].Name == custname)
    {
      a[i].Balance += amount;
      cout << "the new total balance is "<<a[i].Name <<" "<<a[i].Balance<< endl;
    }
      return;
    }
}

void NewCopy(string filename, person *a, int N)// here we have to use write fucntion ofstream, to make a copy in array.
{
  char x[20];
  float bal;
  ofstream file; // to write file into text file.
  file.open(filename.c_str()); // open a file to write at first

  for (int i=0; i<N; i++){
  strcpy (x, a[i].Name);
  bal = a[i].Balance;
 file<<x<<y<<bal<<"\n"; // format of output in the new text file.
}
  file.close();
}

int main() {

int N =0;
string x;
string y;
string name;
float bal;
person  arr[10];
char menu;
 for (int i =0, i<n ,i++ )
 {
   cout<< x << y << bal<< endl;
 }
fstream myfile; // to read the file
myfile.open("data.txt"); // file open to  read the file.

if(myfile.is_open()){
while (myfile>>x>>y>>bal){
  cout << x <<" "<<" "<<y <<" "<< bal <<endl;

}
myfile.close();

while ( menu != '0')
{
  cout << "D:Display: "<<"F: Richest "<< "D: Deposit"<< "N: NewCopy"<< " Q: quit ";
  cin>> menu;
  switch(menu)
{
  case'D' :
  display(arr,10);
  break;
  case'F':
  FindRichest(arr,N);
  break;
  case 'D':
  Deposit(name,arr,N);
  break;
  case 'N':
  NewCopy("data.txt",arr,N);
  break;
  */
  case 'Q':
  return 0;
  break;
  default:
  cout<<"enter a correct option, please! :";
  break;
}
}
return 0;
}
