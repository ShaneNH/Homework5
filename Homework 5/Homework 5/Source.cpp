#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

//ex05_01
template<typename A>
A linearSearch( A list[],  A key, int arraySize);
//ex05_02
template<typename T>
bool isSorted(T list[], int size);

//ex05_03
template<typename T>
class Vector
{
public:
	Vector();
	void push_back(T element);
	void pop_back();
	unsigned int size();
	T at(int index);
	bool empty();
	void clear();
	void swap(Vector v2);

private:
	T elements[50];
	int vectorSize;
};

template<typename T>
Vector<T>::Vector()
{
	vectorSize = 0;
}

template<typename T>
bool Vector<T>::empty()
{
	return vectorSize = 0;
}

template<typename T>
void Vector<T>::push_back(T v)
{
	elements[vectorSize++] = v;
}

template<typename T>
void Vector<T>::pop_back()
{
	return elements[--vectorSize];
}

template<typename T>
unsigned int Vector<T>::size()
{
	return vectorSize;
}

template<typename T>
T Vector<T>::at(int k)
{
	return elements[k];
}

template<typename T>
void Vector<T>::clear()
{
	vectorSize = 0;
}


template<typename T>
void Vector<T>::swap(Vector v2);

//ex05_04
template<typename T>
void shuffle(vector<T>& v);

//ex05_05
class Date
{
private:
	int year;
	int month;
	int day;

public:
	Date()
	{
		setDate(time(0));
	}

	Date(int elapseTime)
	{
		setDate(elapseTime);
	}

	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}

	void setDate(int elapseTime)
	{
		long seconds = elapseTime;
		long minutes = seconds / 60;
		long hours = minutes / 60;
		day = hours / 24;

		year = 1970;
		while (day >= (isLeapYear(year) ? 366 : 365))
		{
			day = day - (isLeapYear(year) ? 366 : 365);
			year++;
		}

		month = 1;
		while (day >= getNumberOfDaysInMonth(year, month))
		{
			day = day - getNumberOfDaysInMonth(year, month);
			month++;
		}
	}

	int getYear()
	{
		return year;
	}

	int getMonth()
	{
		return month;
	}

	int getDay()
	{
		return day;
	}

private:
	bool isLeapYear(int year)
	{
		return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
	}

	int getNumberOfDaysInMonth(int year, int month)
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 ||
			month == 8 || month == 10 || month == 12)
			return 31;

		if (month == 4 || month == 6 || month == 9 || month == 11)
			return 30;

		if (month == 2) return isLeapYear(year) ? 29 : 28;

		return 0;
	}
};
class Transaction{
private:
	char type;
	double amount;
	double balance;
	string description;
	Date date;
public:
	void Printinfo();
	Transaction(){
		type = ' ';
		amount = 0;
		balance = 0;
		description = "";
	}
	Transaction(char newtype, double newamount, double newbalance, string newdescription){
		type = newtype;
		amount = newamount;
		balance = newbalance;
		description = newdescription;
	}
	char gettype(){
		return type;
	}
	void settype(char type){
		this->type = type;
	}
	double getamount(){
		return amount;
	}
	void setamount(double amount){
		this->amount = amount;
	}
	double getbalance(){
		return balance;
	}
	void setbalance(double balance){
		this->balance = balance;
	}
	string getdescription(){
		return description;
	}
	void setdescription(string description){
		this->description = description;
	}
};
class Account{
private:
	int id;
	double balance;
	static double annualInterestRate;
	string name;
	vector<Transaction> transactions;
public:
	Account(){
		name = "";
		id = 0;
		balance = 0;
		annualInterestRate = 1.5;
	}
	Account(string newname, int newid, double newbal){
		name = newname;
		id = newid;
		balance = newbal;
		
	}
	string getname(){
		return name;
	}
	int getid(){
		return id;
	}
	double getbalance(){
		return balance;
	}

	void withdraw(double amount){
		balance -= amount;
		transactions.push_back(Transaction('W', amount, balance, "Withdrawal"));
	}
	
	void deposit(double amount){
		balance += amount;
		transactions.push_back(Transaction('D', amount, balance, "Deposit"));
	}

	void printinfo(){
		for (int i = 0; i < transactions.size(); i++){
			cout << transactions[i].gettype() << " ";
			cout << "$" << transactions[i].getamount() << " ";
			cout << "$" << transactions[i].getbalance() << " ";
			cout << transactions[i].getdescription() << " " << endl;
		}
	}
};


int main(){
	//ex05_01
	int list1[] = { 1, 2, 3, 4, 5 };
	double list2[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	string list3[] = { "A", "B", "C", "D", "E" };
	cout << linearSearch(list1, 3, 5) << endl;
	cout << linearSearch(list2, 3.0, 5) << endl;
	cout << linearSearch(list3, static_cast<string>("C"), 5) << endl;

	//ex05_02
	int list4[] = { 1, 4, 3, 7, 5 };
	int list5[] = { 1, 2, 3, 4, 5 };
	cout << "is list4 sorted? " << isSorted(list1, 5) << endl;
	cout << "is list5 sorted? " << isSorted(list2, 5) << endl;

	//ex05_03
	Vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	Vector<int> v2;
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	v1.swap(v2);

	for (int i = 0; i < v1.size(); i++){
		cout << v1.at(i) << " ";
	}

	cout << endl;
	
	//ex05_04
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);
	a.push_back(7);
	a.push_back(8);
	a.push_back(9);
	a.push_back(10);

	cout << "Unshuffled Vector: ";
	for (int i = 0; i < a.size(); i++){
		cout << a[i] << " ";
	}

	cout << endl;
	shuffle(a);

	cout << "Shuffled Vector: ";
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";

	cout << endl << endl;


	//ex05_05
	Account A1("George", 1122, 1000);
	A1.deposit(30);
	A1.deposit(40);
	A1.deposit(50);
	A1.withdraw(5);
	A1.withdraw(4);
	A1.withdraw(2);

	cout << "Account Name: " << A1.getname() << endl;
	cout << "ID #" << A1.getid() << endl;
	cout << "Current Balance: $" << A1.getbalance() << endl << endl;

	cout << "Transactions" << endl;

	A1.printinfo();
}



//ex05_01
template<typename A>
A linearSearch( A list[],  A key, int arraySize){
	for (int i = 0; i < arraySize; i++){
		if (key == list[i])
			cout << i << " ";
	}
	return key;
}

//ex05_02
template<typename T>
bool isSorted(T list[], int size){
	int templist[100];
	for (int b = 0; b < size; b++){
		templist[b] = list[b];
	}
		for (int i = 0; i < size; i++){
			T curMin = list[i];
			int curMinIn = i;
			for (int j = i + 1; j < size; j++){
				if (curMin > list[j]){
					curMin = list[j];
					curMinIn = j;
				}
			}
			if (curMinIn != i){
				list[curMinIn] = list[i];
				list[i] = curMin;
			}
		}
	
	int l = 0;
	for (int k = 0; k < size; k++){

		if (templist[k] != list[k]){
			l++;
		}
	}
	if (l != 0){
		return 0;
	}
	else
		return 1;

}

//ex05_03
template<typename T>
void Vector<T>::swap(Vector v2){
	T temp[50];
	int tempSize = v2.size();
	for (int i = 0; i < v2.size(); i++)
		temp[i] = v2.at(i);

	v2.clear();
	for (int i = 0; i < size(); i++)
		v2.push_back(at(i));

	clear();
	for (int i = 0; i < tempSize; i++)
		push_back(temp[i]);
}

//ex05_04
template<typename T>
void shuffle(vector<T>& v){
	srand(time(NULL));
	for (int i = 0; i < v.size(); i++)
	{
		int k = rand() % v.size();
		T temp = v[k];
		v[k] = v[i];
		v[i] = temp;
	}
}