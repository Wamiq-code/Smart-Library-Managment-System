#include<iostream>
#include<string>
#include<fstream>
#include<limits>
using namespace std;
class Person {
protected:
	string name;
public:
	virtual void display() = 0;
};
class Student :public Person
{
protected:
	int rollno;
public:
	Student(int rollno, string name) {
		this->rollno = rollno;
		this->name = name;
	}
	void display()
	{
		cout << "Name :" << " " << name << " " << "Rollno :" << " " << rollno << endl;
	}

	string getname() {
		return name;
	}
	int getRollno() {
		return rollno;
	}

};
class Libriran :public Person
{
protected:
	int eid;
public:
	Libriran(int eid, string name) {
		this->eid = eid;
		this->name = name;
	}
	void display() {
		cout << "Name :" << " " << name << " " << "Rollno :" << " " << eid;
	}

};
struct Record {
	int Rollno;
	int BookId;
};
class Book {
protected:
	int Bookid, quantity = 0;
	string Title, Author;
public:
	Book(int Bookid, int quantity, string Title, string Author) {
		this->Bookid = Bookid;
		this->quantity = quantity;
		this->Title = Title;
		this->Author = Author;
	}
	Book& operator++() {
		this->quantity++;
		return *this;
	}
	Book& operator--() {
		if (this->quantity > 0) {
			this->quantity--;
		}
		return *this;
	}
	int getquantity() {
		return quantity;
	}
	string gettitle() {
		return Title;

	}
	string getauthor() {
		return Author;
	}

	void increse(int amount) {
		quantity += amount;
	}
	int getid() {
		return Bookid;
	}
};
class Library {
public:
	int Maxstudent = 5;
	int MaxBooks = 5;
	int studnetcount = 0;
	int recordcount = 0;
	int bookcount = 0;
	Book* books[5] = { nullptr };
	Student* studnets[5] = { nullptr };
	Record records[10] = { 0 };
protected:
	Student* findstudent(int rollno)
	{
		for (int i = 0; i < studnetcount; i++) {
			if (studnets[i]->getRollno() == rollno) {
				return studnets[i];

			}


		}
		return nullptr;
	}
	Book* findBook(int id)
	{
		for (int i = 0; i < bookcount; i++) {
			if (books[i] != nullptr && books[i]->getid() == id) {
				return books[i];
			}
		}
		cout << "Book Not Found " << endl;
		return nullptr;

	}


public:
	void addstudent() {
		try {
			if (studnetcount >= Maxstudent) {
				throw "The Maximum amount of Studnet Reached";
			}
		}
		catch (const char* msg) {
			cout << msg << endl;
		}

		string name;
		int rollno;
		cout << "Enter The name:";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, name);
		cout << "Enter the Roll no:";
		cin >> rollno;
		studnets[studnetcount] = new Student(rollno, name);
		studnetcount++;

	}
	void addbook() {
		if (bookcount < MaxBooks) {
			int id; int quantity;
			string author, title;
			cout << "Enter the Title: ";
			getline(cin, title);
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter the Author :";
			getline(cin, author);
			cout << "Enter the Id :";
			cin >> id;
			cout << "Enter the Quantity :";
			cin >> quantity;
			books[bookcount] = new Book(id, quantity, title, author);
			bookcount++;


		}
	}
	void issueBook() {
		int rollno, id;
		cout << "Enter the Studnt Roll no: ";
		cin >> rollno;
		cout << "Enter the id of Book: ";
		cin >> id;
		Book* book = findBook(id);
		Student* student = findstudent(rollno);
		if (student != nullptr && book != nullptr) {
			if (book->getquantity() > 0) {
				--(*book);
				records[recordcount].Rollno = rollno;
				records[recordcount].BookId = id;
				recordcount++;
			}
			else {
				cout << "Quantity Finished" << endl;
			}
		}
		else {
			cout << "Book or Student not Found" << endl;
		}


	}
	void displaystudent() {
		for (int i = 0; i < studnetcount; i++) {
			if (studnets[i] != nullptr) {
				studnets[i]->display();
			}
			else {
				cout << "Student Not Found";

			}
		}
	}
	void displayrecord() {
		for (int i = 0; i < recordcount; i++) {
			if (records[i].Rollno != 0 && records[i].BookId != 0) {
				cout << "Rollno: " << records[i].Rollno << ", ID: " << records[i].BookId << endl;
			}
			else {
				cout << "Record not found";
			}
		}
	}
	void returnBook() {
		int rollno;
		int id;
		cout << "Enter the Student Roll no";
		cin >> rollno;
		cout << "Enter the id of Book";
		cin >> id;
		bool found = false;
		for (int i = 0; i < recordcount; i++) {
			if (records[i].Rollno == rollno && records[i].BookId == id) {
				found = true;
				Book* book = findBook(id);
				Student* student = findstudent(rollno);
				if (book != nullptr && student != nullptr) {
					++(*book);
					records[i].Rollno = 0;
					records[i].BookId = 0;
					cout << "Book Returned Successfully" << endl;
					return;
				}


			}
		}
		try {
			if (!found) {
				throw "Book or Student Not Found";
			}
		}
		catch (const char* msg) {
			cout << msg << endl;
		}
	}
	void displayBooks() {
		for (int i = 0; i < bookcount; i++) {
			if (books[i] != nullptr) {
				cout << "ID: " << books[i]->getid() << ", Title: " << books[i]->gettitle() << ", Author: " << books[i]->getauthor() << ", Quantity: " << books[i]->getquantity() << endl;
			}
			else {
				cout << "Book Not Found ";
			}

		}

	}
	void writedata()
	{
		cout << "Writing Data to Files..." << endl;
		ofstream Bookfile("Text.txt");
		ofstream Studentfile("Text1.txt");
		ofstream Recordfile("Text2.txt");
		if (Studentfile.is_open()) {
			for (int i = 0; i < studnetcount; i++) {
				if (studnets[i] != nullptr) {
					Studentfile << "Name : " << studnets[i]->getname() << " Rollno: " << studnets[i]->getRollno() << endl;
				}

			}
			Studentfile.close();
		}
		if (Bookfile.is_open()) {
			for (int i = 0; i < bookcount; i++) {
				if (books[i] != nullptr) {
					Bookfile << " ID: " << books[i]->getid() << " Title: " << books[i]->gettitle() << " Author: " << books[i]->getauthor() << " Quantity: " << books[i]->getquantity() << endl;
				}

			}
			Bookfile.close();
		}
		try {
			if (!Bookfile) {
				throw "File is not opening";
			}
		}
		catch (const char* msg) {
			cout << msg << endl;
		}
		if (Recordfile.is_open()) {
			for (int i = 0; i < recordcount; i++) {
				if (records[i].Rollno != 0 && records[i].BookId != 0) {
					Recordfile << "ID: " << records[i].BookId << " Rollno: " << records[i].Rollno << endl;
				}

			}
		}
		Recordfile.close();
	}
	template<typename T>
	int findIndex(T* arr[], int size, int value) {
		for (int i = 0; i < size; i++) {
			if (arr[i] != nullptr && arr[i]->getid() == value) {
				return i;
			}
		}
		return -1;
	}
	~Library()
	{
		for (int i = 0; i < studnetcount; i++) {
			delete studnets[i];
		}
		for (int i = 0; i < bookcount; i++) {
			delete books[i];
		}
	}
};


int main()
{
	cout << "Welcome to Library Management System" << endl;
	Library library;
	cout << "Following are the options you can choose from: " << endl;
	cout << "1. Add Student" << endl;
	cout << "2. Add Book" << endl;
	cout << "3. Issue Book" << endl;
	cout << "4. Return Book" << endl;
	cout << "5. Display Students" << endl;
	cout << "6. Display Books" << endl;
	cout << "7. Display Records" << endl;
	cout << "8.Write Data to File" << endl;
	cout << "9. Find Book Index" << endl;
	cout << "10. Exit" << endl;
	cout << "**********************" << endl;
	int choice;
	int index;
	int result;
	do {
		cout << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			library.addstudent();
			break;
		case 2:
			library.addbook();
			break;
		case 3:
			library.issueBook();
			break;
		case 4:
			library.returnBook();
			break;
		case 5:
			library.displaystudent();
			break;
		case 6:
			library.displayBooks();
			break;
		case 7:
			library.displayrecord();
			break;
		case 8:
			library.writedata();
			break;
		case 9:

			cout << "Enter the id of book to find index: ";
			cin >> index;
			result = library.findIndex(library.books, library.bookcount, index);
			if (result != -1) {
				cout << "Book found at index: " << result << endl;
			}
			else {
				cout << "Book not found." << endl;
			}
			break;
		case 10:
			cout << "Exiting the program. Goodbye!" << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		
		}
	} while (choice != 10);
}