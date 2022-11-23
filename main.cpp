#include <bits/stdc++.h>
#include <fstream>
#include <stdlib.h>
using namespace std;
class Library{
  public:
    int availability;
    int book_id;
    string book_name;
    static void Introduction();
    static void ViewListOfBooks();
    static void RequestBook();
    static void ReturnBook();
};
Library Book[20];

string split(string s) {
  for (int i = 0; i < s[i]; ++i) {
    if (s[i] == 95) s[i] = 32;
  }
  return s;
}
void Library::Introduction () {
   cout << " A library is a collection of materials, books or media that are accessible for use and not just for display purposes. \n"
   "A library provides physical or digital access materials, and may be a physical location or a virtual space, or both. \n" 
   "A library's collection can include printed materials and other physical resources in many formats such as DVD, CD and cassette as well as access to information, music or other content held on bibliographic databases.\n";
}
void Library::ViewListOfBooks(void) {
  for (int i = 0; i < 20; ++i) {
    if (Book[i].availability) {
      cout << Book[i].availability << "\t";
      cout << Book[i].book_id << "\t";
      cout << Book[i].book_name << "\t";
      cout << endl;
    }
    else cout << "There is no copies available to borrow in the ID of " << Book[i].book_id  << " and in the name of [" << Book[i].book_name << "]" << endl; 
  }
}

void Library::RequestBook(void) {
  int ID;
  cout << "Enter the Book ID :"; cin >> ID;
  if (ID < 20 && ID >=1) {
    if (Book[ID - 1].availability > 0) {
      cout << "Congratulations Customer your book is allocated. Please collect it from the shelf." << endl;
      --Book[ID - 1].availability;  
    }
    else cout << "This book is presently not on our shelf.Please try later." << endl;
  }
  else cout << "Book ID is not correct. Please try again" << endl;
}

void Library::ReturnBook(void) {
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
        case 0: Library::Introduction(); break;
        case 1: Library::ViewListOfBooks(); break;
        case 2: Library::RequestBook(); break;
        case 3: Library::ReturnBook(); break;
        case 4: exit(3);
        default: cout << "Error in choosing option.\nPlease select a valid option ";
        }
    } while (option <= 3);
}