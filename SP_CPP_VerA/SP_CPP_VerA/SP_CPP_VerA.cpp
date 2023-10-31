#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
using namespace std;
//Functions declaration 
void signUp();
void signIn();
void information_user();
void information_book();
void search_book();
void buying_book();
void Report();
//This struct for data of librarians
struct librarians {
	string name_librarian;
	string password_librarian;
};
//This struct receive data of users and store it
struct users {
	string name_user;
	int id;
	string email;
	string password_user;
	string account_type;
	int Day;
	int Month;
	int Year;
	long long contact_numbers[3];
};
//This struct receive the information of books and store this information
struct books {
	string Title;
	int production_year;
	int Numberofcopies;
	string Category;
	int Edition;
};

//Glopal variables

//This variable array of struct called books which store data of librarians
librarians arr[4];
//This variable is a global counter
int cunt = 0;
//This variable is array of struct that store data of books
books book[1000];
//This is array of struct that store data of users
users user[1000];
//This variable is the input user named
string username;
//This variable is the input password of user
string Password;
//This variable glopal counter 
int c = 0;
int main() {
	system("Color F0");
	//calling functions
	signUp();
	signIn();
	information_user();
	information_book();
	search_book();
	buying_book();
	Report();

	return 0;

}
//This function takes information about librarians before log in step
void signUp() {
	//this loop takes the names of 4 librarians and the passwords before the step of log in
	for (int i = 0; i < 4; i++) {
		cout << "Enter librarians Name " << endl;
		cin >> arr[i].name_librarian;
		cout << "Enter librarians password " << endl;
		cin >> arr[i].password_librarian;
		cout << endl << endl << endl;
		cunt++;
	}cout << endl << endl << endl;
}
//This function asking librarians to enter name and password and compare them with sign up function
void signIn() {

	//Local varibles
		//This variables local counters that can only use in this function
	int a = 0, z;

	// the this loop asks librarians to enter the names and passwords and comparees input name with name which stored in sign up function
	// if name is true,massege will apper for the librarian that the says "welcome" and if name is not correct ,message will appear that the name is not correct
	// if the input password was equal the pasword which stored in sign up function
	// A message will apper to librarian that he enterd correct password
	// And if the input password was not equal the password which stored in sign up function 
	// A message will appear to librarian that he enterd incorrect password 
	for (int i = 0; i < 4; i++) {
		cout << "Enter user name please" << endl;
		cin >> username;
		for (int i = 0; i < 4; i++)
		{
			if (username == arr[i].name_librarian)
			{
				a++;
				z = i;
			}
		}
		if (a != 0) {
			cout << "Enter password please" << endl;
			cin >> Password;
			if (arr[z].password_librarian == Password) { cout << " welcome " << username << endl; }
			else { cout << "Incorrect password" << endl; i--; }
		}
		else {
			cout << "incorrect name" << endl;
			i--;
		}
		a = 0;
	}
}
//This function takes informtion about users
void information_user() {

	//Local variables
		//This variables to receive answer as character
	char answer;
	char result;
	//This variable is a local counter which can only use in this function
	int j = 0;

	/*in this loop a message appears to librarian to enter informtion about users like name,passeord,creation date,id,email,account type,then a meesge appers to the librarian
	if he want to add another contact number for user
	After takes information of user a massege appears to librarian that if he want to add inforamtion for another users
	*/


	for (int i = 0; i < 1000; i++) {


		cout << "Enter name of user please\n";
		cin >> user[i].name_user;
		cout << "Enter id of user\n";
		cin >> user[i].id;
		cout << "Enter email of user\n";
		cin >> user[i].email;
		cout << "Enter account type(student/staff/Guest)\n  ";
		cin >> user[i].account_type;
		cout << "Enter creation date please\n";
		cin >> user[i].Day >> user[i].Month >> user[i].Year;

		do {
			cout << "Enter contact number: ";
			cin >> user[i].contact_numbers[j];
			cout << "if you want to add contact write y and if you do not write n\n";
			cin >> answer;
			if ((answer != 'Y' && answer != 'y') && (answer != 'N' && answer != 'n'))
			{
				cout << "Invalid answer\n";
			}
			j++;

		} while ((answer == 'y' || answer == 'Y') && (j < 3));
		j = 0;
		cout << "do you want to enter another name\n";
		cin >> answer;
		if (answer == 'n' || answer == 'N') {
			break;
		}
	}
}
// This function stores information about books
void information_book() {
	//local variables
	//This variable is a boolean variable used to compare the result
	bool choice = true;
	//This variable used to check for answer
	char check;
	while (choice)
	{
		//this loop takes the information of books and print a message to librarians that if they want to add information about books
		//if answer was "yes" they can add the information and if answer was "no" they cannot add  the information
		//if answer was any character it will print a message to librarians that it is invalid character

		cout << "Enter title of book\n";
		cin >> book[c].Title;
		cout << "Enter category of book\n";
		cin >> book[c].Category;
		cout << "Enter number of copies\n";
		cin >> book[c].Numberofcopies;
		cout << "Enter production year\n";
		cin >> book[c].production_year;
		cout << "Enter edition\n";
		cin >> book[c].Edition;
		cout << "Do you want to add another book\n";
		cin >> check;
		if (check == 'n' || check == 'N') {
			choice = false;
		}
		else if (check != 'y' && check != 'Y') {
			do {
				cout << "Invalid character\n";
				cin >> check;
			} while ((check != 'Y' && check != 'y') && (check != 'N' && check != 'n'));
			if (check == 'n' || check == 'N') {
				choice = false;
			}
		}

		c++;

	}
}
//This function searches for books in library by using title of books or number of copies
void search_book() {

	//Local variables
		//This variable receive character and check for it
	char character;
	//This variable is alocal counter that can only use in this scope
	int flag = 0;
	//This variables to receive input title of books and production years of this books
	string title_Ofbook;
	int yearofProduction;

	/* This step about search for books
	the function shows a message to librarians to enter a character
	if character was equal 'p' or 'P' another message will appear to the liprarian to enter production year to search for the book
	And if character was equal 't' or 'T' another message will appear to the librarian to enter title of book to search for the book
	*/
	cout << "Enter character please to search for book\n";
	cin >> character;
	if (character == 'P' || character == 'p') {
		cout << "Enter production year\n";
		cin >> yearofProduction;
		for (int j = 0; j < 1000; j++) {
			if (yearofProduction == book[j].production_year) {
				cout << "book is founded" << endl << book[j].Title;
				flag++;
			}

		}
		if (flag == 0) { cout << "the book is not found\n"; }
	}
	else if (character == 'T' || character == 't') {
		cout << "Enter title of the book please\n";
		cin >> title_Ofbook;
		for (int j = 0; j < 1000; j++) {
			if (title_Ofbook == book[j].Title) {
				cout << "book is founded" << endl;
				cout << "the title of book is:" << endl << book[j].Title;
				flag++;
			}
		}
		if (flag == 0) { cout << "the book is not found\n"; }
	}
	else
	{
		cout << "Invalid character\n";
	}
}
//This function for buying books from library
void buying_book() {

	//Local varibles
	//This variable recieve character and check about this character
	char choice;
	//This variables to receive the input account type and names of books
	string accountType;
	string nameOfbook;

	/*this loop send a message to user if he want to buy abook
	if the user want buy abook,he should give the librarian account type
	if account type was equal staff ,the user can buy the book if the book was available
	if account type was equal student or guest , the user cannotbbuy the book if the book was available
	*/

	for (int i = 0; i < 1000; i++) {
		cout << "Do you want buy abook \n";
		cin >> choice;
		if (choice == 'n' || choice == 'N') { break; }
		else if (choice == 'y' || choice == 'Y') {
			cout << "Enter account type please\n";
			cin >> accountType;

			if (accountType == "student" || accountType == "Guest") { cout << "you can not buy the book\n "; }
			else if (accountType == "staff") {
				cout << "I will check for the avalibilaty of the book please wait\n";
				if (book[i].Numberofcopies > 0) {
					cout << "NOW,YOU can buy the book\n";
					cout << "ENTER name of the book \n";
					cin >> nameOfbook;
					for (int j = 0; j < 1000; j++) {
						if (nameOfbook == book[j].Title) {
							book[i].Numberofcopies--;
							cout << "you sold the book\n";
							cout << "NOW,number of copies are:" << book[i].Numberofcopies << endl;
						}

						else if (book[i].Numberofcopies <= 0) { cout << "the book is not avaliable\n"; }

					}
					
				}
			}
		}
	}

}
//This function shows all information of new users whose account where created in the last seven days
void Report() {
	//Local varibles
	//This variables to receive date as day,month,year 
	int day, month, year;

	/*this message asks the librarian to enter the day ,he want to start the report from it
	this loop shows the new users in each day before the date that the librarian has entered
	*/
	cout << "enter date\n";
	cin >> day >> month >> year;
	for (int j = 0; j < 7; j++) {
		for (int i = 0; i < 1000; i++) {
			if (day == user[i].Day && month == user[i].Month && year == user[i].Year) {
				cout << user[i].name_user << endl << user[i].id << endl << user[i].email << endl << user[i].account_type << endl << user[i].contact_numbers[0] << endl;
				cout << "the creation date : " << day << "/" << month << "/" << year;
				cout << endl << endl << endl;
			}
		}
		day--;

		if (day == 0) {
			month--;
			if (month == 0) { month = 12; }
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
				day == 31;
			}

			else if (month == 4 || month == 6 || month == 9 || month == 11) { day = 30; }
			else {
				day = 28;
				year--;
			}
		}
	}
}
