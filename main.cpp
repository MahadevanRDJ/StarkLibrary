#include <bits/stdc++.h>
#include <fstream>
#include <stdlib.h>

using namespace std;
typedef struct Library {
  int availability;
  int book_id;
  string book_name;
}Library;
Library Book[20];

string split(string s) {
  for (int i = 0; i < s[i]; ++i) {
    if (s[i] == 95) s[i] = 32;
  }
  return s;
}

void ViewListOfBooks(void) {
  for (int i = 0; i < 20; ++i) {
    if (Book[i].availability) {
      cout << Book[i].availability << "\t";
      cout << Book[i].book_id << "\t";
      cout << Book[i].book_name << "\t";
      cout << endl;
    }
    else cout << "There is no copies available to borrow in the ID of " << Book[i].book_id  << " and name of " << Book[i].book_name << endl; 
  }
}

void RequestBook(void) {
  int ID;
  cout << "Enter the Book ID :"; cin >> ID;
  if (ID < 20 && ID >=1) {
    if (Book[ID - 1].availability) {
      cout << "Congratulations Customer your book is allocated. Please collect it from the shelf." << endl;
      --Book[ID - 1].availability;  
    }
    else cout << "This book is presently not on our shelf.Please try later." << endl;
  }
  else cout << "Book ID is not correct. Please try again" << endl;
}

void ReturnBook(void) {
  int ID;
  cout << "Enter the Book ID :"; cin >> ID;
  if (ID < 20 && ID >=1) {
      cout << "Thank you Customer.Please place the book back on the shelf" << endl;
      ++Book[ID - 1].availability;  
    }
  else cout << "Book ID is not correct. Please try again" << endl;
}

int main() {
  int option, m, n, i = 0;
  string name;
  ifstream file("books_database.txt");
  if (file.is_open()) {
      while(file >> m >> n >> name && i < 20) {
        Book[i].availability = m;
        Book[i].book_id = n;
        Book[i].book_name = split(name);
        ++i;
      }
    file.close();
  }
  
  cout << "Hello Customer. Welcome to GoodWillLibrary" << endl;
  cout << "Please select one option from Menu, mentioned below :" << endl;
  do {
      cout << "\t\t\t\t\t1) View list of books on our shelves" << endl;
      cout << "\t\t\t\t\t2) Request for a new book" << endl;
      cout << "\t\t\t\t\t3) Return a book" << endl;
      cout << "\t\t\t\t\t4) Exit" << endl;

      cout << "\t\t\t\t\t\t Option :";cin >> option;
      switch(option) {
        case 1: ViewListOfBooks(); break;
        case 2: RequestBook(); break;
        case 3: ReturnBook(); break;
        case 4: exit(3);
        default: cout << "Error in choosing option.\nPlease select a valid option ";
        }
    } while (option <= 3);
}