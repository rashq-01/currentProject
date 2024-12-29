#include<iostream>
#include<string>
#include<vector>
using namespace std;

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

int book::id = 0;

int main(){
    book b1;
    cout<<b1.getId();
    book b2;
    cout<<b2.getId();
    book b3;
    cout<<b3.getId();
}