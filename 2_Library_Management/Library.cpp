#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Books class

class book{
    private:
        static int id;
        string title;
        string author;
        string genre;
        int publishedYear;
        bool isAvailable;
        int borrowerId;

    public:
        book(){
            id++;
            title = "";
            author = "";
            genre = "";
            publishedYear = 0;
            isAvailable = 0;
            borrowerId = 0;
        }
        void addBook(){
            cout<<"Enter the title of the book: ";
            cin>>title;
            cout<<"Enter the author of the book: ";
            cin>>author;
            cout<<"Enter the genre of the book: ";
            cin>>genre;
            cout<<"Enter the published year of the book: ";
            cin>>publishedYear;
            isAvailable = true;
            borrowerId = 0;

        }
        book(string titl, string auth, string gen, int pubYear, bool avaib, int bId){
            id++;
            title = titl;
            author = auth;
            genre = gen;
            publishedYear = pubYear;
            isAvailable = avaib;
            borrowerId = bId;
        }
        int getId(){
            return id;
        }
        string getTitle(){
            return title;
        }
        string getAuthor(){
            return author;
        }
        string getGenre(){
            return genre;
        }
        int getPublishedYear(){
            return publishedYear;
        }
        bool getisAvailable(){
            return isAvailable;
        }
        int getBorrowerId(){
            return borrowerId;
        }
    
};



//Member class

class member{
    private:
        string rollNo;
        string name;
        string address;
        string phone;
        string email;
        int borrowedBookId;

    public:
        member(){
            rollNo = "";
            name = "";
            address = "";
            phone = "";
            email = "";
            borrowedBookId = 0;
        }
        void addMember(){
            cout<<"Enter the roll number of the member: ";
            cin>>rollNo;
            cout<<"Enter the name of the member: ";
            cin>>name;
            cout<<"Enter the address of the member: ";
            cin>>address;
            cout<<"Enter the phone number of the member: ";
            cin>>phone;
            cout<<"Enter the email of the member: ";
            cin>>email;
            borrowedBookId = 0;
        }
        member(string roll, string nam, string add, string ph, string em){
            rollNo = roll;
            name = nam;
            address = add;
            phone = ph;
            email = em;
            borrowedBookId = 0;
        }
        string getRollNo(){
            return rollNo;
        }
        string getName(){
            return name;
        }
        string getAddress(){
            return address;
        }
        string getPhone(){
            return phone;
        }
        string getEmail(){
            return email;
        }
        int getBorrowedBooks(){
            return borrowedBookId;
        }

};

//Library class

class library{
    private:
        vector<book> books;
        vector<member> members;

    public:
        void addBook(){
            string title;
            string author;
            string genre;
            int publishedYear;
            int avl = true;
            int brrwId = 0;
            cout<<"Enter the title of the book: ";
            cin>>title;
            cout<<"Enter the author of the book: ";
            cin>>author;
            cout<<"Enter the genre of the book: ";
            cin>>genre;
            cout<<"Enter the published year of the book: ";
            cin>>publishedYear;
            books.push_back(book(title, author, genre, publishedYear, avl, brrwId));

        }
        void displayAllBooks(){
            cout<<endl<<endl<<endl;
            cout<<"-----------------Books in the library-----------------"<<endl<<endl;
            for(int i = 0; i<books.size(); i++){
                cout<<"Book ID: "<<books[i].getId()<<endl;
                cout<<"Title: "<<books[i].getTitle()<<endl;
                cout<<"Author: "<<books[i].getAuthor()<<endl;
                cout<<"Genre: "<<books[i].getGenre()<<endl;
                cout<<"Published Year: "<<books[i].getPublishedYear()<<endl;
            }
        }

        void addmember(){
            string roll;
            string name;
            string address;
            string phone;
            string email;
            cout<<"Enter the name of the member: ";
            cin>>name;
            cout<<"Enter the address of the member: ";
            cin>>address;
            cout<<"Enter the phone number of the member: ";
            cin>>phone;
            cout<<"Enter the email of the member: ";
            cin>>email;
            members.push_back(member(roll,name, address, phone, email));
        }

        
};



int book::id = 0;

int main(){
    library l;
    l.addBook();
    l.displayAllBooks();

}