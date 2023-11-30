#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Book class to represent a book
class Book
{
public:
    string title;
    string author;
    bool isAvailable;

    Book(string t, string a) : title(t), author(a), isAvailable(true) {}
};

// Library class to manage books
class Library
{
private:
    vector<Book> books;

public:
    void addBook(string title, string author)
    {
        books.push_back(Book(title, author));
        cout << "Book added successfully.\n";
    }

    void displayBooks()
    {
        cout << setw(20) << "Title" << setw(20) << "Author" << setw(15) << "Availability" << endl;
        for (const auto &book : books)
        {
            cout << setw(20) << book.title << setw(20) << book.author << setw(15)
                 << (book.isAvailable ? "Available" : "Borrowed") << endl;
        }
    }

    void borrowBook(string title)
    {
        for (auto &book : books)
        {
            if (book.title == title && book.isAvailable)
            {
                book.isAvailable = false;
                cout << "Book borrowed successfully.\n";
                return;
            }
        }
        cout << "Book not available for borrowing.\n";
    }

    void returnBook(string title)
    {
        for (auto &book : books)
        {
            if (book.title == title && !book.isAvailable)
            {
                book.isAvailable = true;
                cout << "Book returned successfully.\n";
                return;
            }
        }
        cout << "Book not available for returning.\n";
    }
};

int main()
{
    Library library;

    while (true)
    {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string title, author;
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author name: ";
            getline(cin, author);
            library.addBook(title, author);
            break;
        }
        case 2:
            library.displayBooks();
            break;
        case 3:
        {
            string title;
            cout << "Enter book title to borrow: ";
            cin.ignore();
            getline(cin, title);
            library.borrowBook(title);
            break;
        }
        case 4:
        {
            string title;
            cout << "Enter book title to return: ";
            cin.ignore();
            getline(cin, title);
            library.returnBook(title);
            break;
        }
        case 5:
            cout << "Exiting the program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
