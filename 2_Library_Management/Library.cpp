#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cctype>
using namespace std;

//Books class

class book{
    private:
        static int idGenerator;
        int id;
        string title;
        string author;
        string genre;
        int publishedYear;
        bool isAvailable;
        string borrowerId;

    public:
        book(string titl, string auth, string gen, int pubYear, bool avaib){
            id = ++idGenerator;
            title = titl;
            author = auth;
            genre = gen;
            publishedYear = pubYear;
            isAvailable = avaib;
            borrowerId = "";
            
            //File handling

            fstream myfile;
            myfile.open("books/id.txt",ios::app);
            if(myfile.is_open()){
                myfile<<id<<"\n";
                myfile.close();
            }
            else{
                cout<<"Error in opening id.txt";
            }

            myfile.open("books/title.txt",ios::app);
            if(myfile.is_open()){
                myfile<<title<<"\n";
                myfile.close();
            }
            else{
                cout<<"Error in opening title.txt";
            }

            myfile.open("books/author.txt",ios::app);
            if(myfile.is_open()){
                myfile<<author<<"\n";
                myfile.close();
            }
            else{
                cout<<"Error in opening author.txt";
            }

            myfile.open("books/genre.txt",ios::app);
            if(myfile.is_open()){
                myfile<<genre<<"\n";
                myfile.close();
            }
            else{
                cout<<"Error in opening genre.txt";
            }

            myfile.open("books/publishedYear.txt",ios::app);
            if(myfile.is_open()){
                myfile<<publishedYear<<"\n";
                myfile.close();
            }
            else{
                cout<<"Error in opening publishedYear.txt";
            }

            myfile.open("books/isAvailable.txt",ios::app);
            if(myfile.is_open()){
                myfile<<isAvailable<<"\n";
                myfile.close();
            }
            else{
                cout<<"Error in opening isAvailable.txt";
            }

            myfile.open("books/borrowerId.txt",ios::app);
            if(myfile.is_open()){
                myfile<<borrowerId<<"\n";
                myfile.close();
            }
            else{
                cout<<"Error in opening borrowerId.txt";
            }


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
        string getBorrowerId(){
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
            cout<<"Enter the title of the book (lower Case): ";
            getline(cin,title);
            cout<<"Enter the author of the book (lower Case): ";
            getline(cin,author);
            cout<<"Enter the genre of the book (lower Case): ";
            getline(cin,genre);
            cout<<"Enter the published year of the book: ";
            cin>>publishedYear;
            books.push_back(book(title, author, genre, publishedYear, avl));
            

        }


        void addBook(string title, string author, string genre, int publishedYear, int avl = true){
            books.push_back(book(title, author, genre, publishedYear, avl));
            

        }


        void addmember(){
            string roll;
            string name;
            string address;
            string phone;
            string email;
            cout<<"Enter the roll No (lower Case): ";
            getline(cin,roll);
            cout<<"Enter the name of the member (lower Case): ";
            getline(cin,name);
            cout<<"Enter the address of the member (lower Case): ";
            getline(cin,address);
            cout<<"Enter the phone number of the member (lower Case) : ";
            getline(cin,phone);
            cout<<"Enter the email of the member (lower Case): ";
            getline(cin,email);
            members.push_back(member(roll,name, address, phone, email));
        }

        void addmember(string roll, string name, string address, string phone, string email){
            members.push_back(member(roll,name, address, phone, email));
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
                cout<<endl<<endl;
            }
        }

        void findBook(){
            int BOOKID;
            string BOOKNAME;
            cout<<"Enter the Book ID: ";
            cin>>BOOKID;
            cin.ignore();
            cout<<"Enter the Book Titlea (lower Case) :";
            getline(cin,BOOKNAME);
            cout<<endl;
            int orgLine;



            fstream idFile;
            fstream titleFile;
            idFile.open("books/id.txt",ios::in);
            titleFile.open("books/title.txt",ios::in);
            int id;
            int title;
            
            









            // for(int i=0;i<books.size();i++){
            //     int bookId = books[i].getId();
            //     string bookName = books[i].getTitle();
            //     if(bookId==BOOKID || bookName==BOOKNAME){
            //     cout<<"Book ID: "<<books[i].getId()<<endl;
            //     cout<<"Title: "<<books[i].getTitle()<<endl;
            //     cout<<"Author: "<<books[i].getAuthor()<<endl;
            //     cout<<"Genre: "<<books[i].getGenre()<<endl;
            //     cout<<"Published Year: "<<books[i].getPublishedYear()<<endl;
            //     int availability = books[i].getisAvailable();
            //     if(availability){
            //         cout<<"Book Availability: True"<<endl;
            //     }
            //     else{
            //         cout<<"Book Availability: False"<<endl;
            //     }
            //     break;
            //     }
            // }
        }


        
};



int book::idGenerator = 0;

int main(){
    library l;
    l.addBook("Pathfinder","Rajesh","Nothing",2023,true);
    l.addBook("Math","Sanjog","Nothing",2019,true);
    l.addBook("Physics","Suraj","Nothing",2018,true);
    l.addBook("Chemistry","Bhaskar","Nothing",2022,true);
    l.addBook("ITP","Kapil","Nothing",2020,true);
    l.addBook("BCME","Raju","Nothing",2025,true);
    l.addBook("English","Resam","Nothing",2017,true);
    l.addBook("Nepali","Aashif","Nothing",2020,true);
    l.addBook("Biology","Shivam","Nothing",2021,true);
    l.addBook("Computer","Dhiraj","Nothing",2024,true);
    l.addBook("Aptitude","Niraj","Nothing",2021,true);
    l.addBook("Reasoning","Ganesh","Nothing",2022,true);
    l.displayAllBooks();


}