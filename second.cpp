#define _CRT_SECURE_NO_WARNINGS
#include <fstream> 
#include <iostream> 
#include <string> 
#include <cstring> 

using namespace std;
struct PERSON
{
	char Name[20];
	float Balance;
};
void display(PERSON array[], int n)
{
	cout << "Name and Balance"<< endl;
	for (int i = 0; i < n; i++)
		cout << array[i].Name << " " << array[i].Balance << endl;
}
void findRichest(PERSON array[], int n)
{
	int i;
	float richest = 0.0;
	for ( i = 0; i < n; i++)
	{
		if (richest < array[i].Balance)
			richest = array[i].Balance;
	}
	for ( i = 0; i < n; i++)
	{
		if (richest == array[i].Balance)
			break;
	}
	cout << "The Highest balance customer's name is  " << array[i].Name<< endl;
}
void deposit(string customer, PERSON array[], int n)
{
	float amount = 0.0;
	int input = 1;
	int i;
	for (i = 0; i < n; i++)	{
		input = strcmp(customer.c_str(), array[i].Name);
		if (input == 0)			break;
	}	
		if (input == 0)	{
		cout << customer << "enter your deposit amount: " << endl;
		cin >> amount;
		array[i].Balance = amount + array[i].Balance;
		cout << "the New Balance :  " << array[i].Balance << endl;
		}
}

void newCopy(string file, PERSON array[], int n)
{
	ofstream filename(file.c_str());
	char name[20];
	float balance;
	for (int i = 0; i < n; i++)
	{
		strcpy(name, array[i].Name);
		balance = array[i].Balance;
		filename << name << " " << balance;
	}
	filename.close();
}
int main()
{
	int num = 0;
	string line;
	string fName;
	string lName;
	
	string customer;
	char name[20];
	float balance;
	string tempName;
	ifstream file("input.txt");
	while (getline(file, line))
		num++;
	PERSON array[20];
	file.close();
	ifstream file2("input.txt");
	if (file2.is_open())
	{
		for (int i = 0; i < num; i++)
		{
			file2 >> fName >> lName >> balance;
			tempName = fName + " " + lName;
			strcpy(array[i].Name, tempName.c_str());
			array[i].Balance = balance;
		}
	}
	file2.close();
	display(array, num);
	findRichest(array, num);
	cout << "Enter the name " << endl;
	getline(cin, customer);
	deposit(customer, array, num);
	newCopy("input.txt", array, num);
	system("PAUSE");
	return 0;
}
