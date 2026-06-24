#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;


struct book {
    int id;
    string title;
    string author;
    int year;
    bool isIssued;
};

//Prototypes
void addBook(vector<book>& books, const book& newBook);
void issueBook(vector<book>& books, int id, const string& issuedBy);
void returnBook(vector<book>& books, int id);
vector<string> listBooksbyAuthor(const vector<book>& books, const string& author);
void displayBooksInOrder(const vector<book>& books);
void groupBooksbyYear(vector<book>& books);
void saveBooksToFile(const vector<book>& books);
bool isAvailable(const vector<book>& books, string title);
bool idExists(const vector<book>& books, int id);



int main() {
    vector<book> books;
    int choice;
    ifstream file("books.csv");

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string cell;
            book b;
            getline(ss, cell, ',');
            b.id = stoi(cell);
            getline(ss, cell, ',');
            b.title = cell;
            getline(ss, cell, ',');
            b.author = cell;
            getline(ss, cell, ',');
            b.year = stoi(cell);
            getline(ss, cell);
            b.isIssued = (cell == "true");
            books.push_back(b);
        }
        file.close();
    }


    do {
        cout << "Library Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Issue Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. List Books by Author" << endl;
        cout << "5. Display Books in Order" << endl;
        cout << "6. Group Books by Year" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                book newBook;
                cout << "Enter Book ID: ";
                cin >> newBook.id;
                cin.ignore(); // Ignore newline character
                cout << "Enter Book Title: ";
                getline(cin, newBook.title);
                cout << "Enter Book Author: ";
                getline(cin, newBook.author);
                cout << "Enter Publication Year: ";
                cin >> newBook.year;
                newBook.isIssued = false;
                addBook(books, newBook);
                saveBooksToFile(books);
                break;
            } 
            case 2: {
                int id;
                string issuedBy;
                cout << "Enter Book ID to issue: ";
                cin >> id;
                cin.ignore(); // Ignore newline character
                cout << "Enter Issued By: ";
                getline(cin, issuedBy);
                issueBook(books, id, issuedBy);
                saveBooksToFile(books);
                break;
            }
            case 3: {
                int id;
                cout << "Enter Book ID to return: ";
                cin >> id;
                returnBook(books, id);
                saveBooksToFile(books);
                break;
            }
            case 4: {
                string author;
                cout << "Enter Author Name: ";
                cin.ignore(); // Ignore newline character
                getline(cin, author);
                vector<string> titles = listBooksbyAuthor(books, author);
                if (!titles.empty()) {
                    cout << "Books by " << author << ":" << endl;
                    for (const auto& title : titles) {
                        cout << title << endl;
                    }
                } else {
                    cout << "No books found by this author." << endl;
                }
                break;
            }
            case 5:
                displayBooksInOrder(books);
                break;
            case 6:
                groupBooksbyYear(books);
                cout << "Books grouped by year." << endl;
                break;
            case 7:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

}


// Function Definitions
void saveBooksToFile(const vector<book>& books)
{
    ofstream file("books.csv");

    file << "book_id,title,author,year,isIssued\n";

    for(const auto& b : books)
    {
        file << b.id << ","
             << b.title << ","
             << b.author << ","
             << b.year << ","
             << (b.isIssued ? "true" : "false")
             << "\n";
    }
}

bool isAvailable(const vector<book>& books, string title) {
    for (const auto& b : books) {
        if (b.title == title) {
            return true;
        }
    }
    return false;
}

vector<string> listBooksbyAuthor(const vector<book>& books, const string& author) {
    vector<string> titles;
    for (const auto& b : books) {
        if (b.author == author) {
            titles.push_back(b.title);
        }
    }
    return titles;
}

void addBook(vector<book>& books, const book& newBook) {
    if (!isAvailable(books, newBook.title) && !idExists(books, newBook.id)) {
        books.push_back(newBook);
        cout << "Book added successfully." << endl;
    } else {
        cout << "Book with title " << newBook.title << " or ID " << newBook.id << " already exists." << endl;
    }
}

void issueBook(vector<book>& books, int id, const string& issuedBy) {
    for (auto& b : books) {
        if (b.id == id) {
            if (!b.isIssued) {
                b.isIssued = true;
                cout << "Book issued successfully." << endl;
            } else {
                cout << "Book is already issued." << endl;
            }
            return;
        }
    }
    cout << "Book with ID " << id << " not found." << endl;
}

void returnBook(vector<book>& books, int id) {
    for (auto& b : books) {
        if (b.id == id) {
            if (b.isIssued) {
                b.isIssued = false;
                cout << "Book returned successfully." << endl;
            } else {
                cout << "Book was not issued." << endl;
            }
            return;
        }
    }
    cout << "Book with ID " << id << " not found." << endl;
}


void displayBooksInOrder(const vector<book>& books){
    cout <<"Book ID\t\t Title\t\t Author\t\t year\t isIssued" << endl;
    for(auto& b: books){
        cout << b.id << "\t\t|" << b.title << "\t\t|" << b.author << "\t\t|" << b.year << "\t\t|" << (b.isIssued ? "Yes" : "No") << endl;
    }
}

void groupBooksbyYear(vector<book>& books)
{
    sort(books.begin(), books.end(),
         [](const book& a, const book& b)
         {
             return a.year < b.year;
         });

    int currentYear = books[0].year;

    cout << "\nYear: " << currentYear << "\n";

    for(const auto& b : books)
    {
        if(b.year != currentYear)
        {
            currentYear = b.year;
            cout << "\nYear: " << currentYear << "\n";
        }

        cout << b.title << '\n';
    }
}

bool idExists(const vector<book>& books, int id)
{
    for(const auto& b : books)
    {
        if(b.id == id)
            return true;
    }
    return false;
}


