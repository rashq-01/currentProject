#include<iostream>
#include<string>
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

            cout<<endl<<endl<<"Book Added successfully...."<<endl;


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

            //File Handling

            fstream myfile;
            myfile.open("members/rollNo.txt",ios::app);
            if(myfile.is_open()){
                myfile<<rollNo<<"\n";
                myfile.close();
            }
            else{
                cout<<"Error in opening rollNo.txt";
            }

            myfile.open("members/name.txt",ios::app);
            if(myfile.is_open()){
                myfile<<name<<"\n";
                myfile.close();
            }
            else{
                cout<<"Error in opening name.txt";
            }

            myfile.open("members/address.txt",ios::app);
            if(myfile.is_open()){
                myfile<<address<<"\n";
                myfile.close();
            }
            else{
                cout<<"Error in opening address.txt";
            }

            myfile.open("members/phone.txt",ios::app);
            if(myfile.is_open()){
                myfile<<phone<<"\n";
                myfile.close();
            }
            else{
                cout<<"Error in opening phone.txt";
            }

            myfile.open("members/phone.txt",ios::app);
            if(myfile.is_open()){
                myfile<<phone<<"\n";
                myfile.close();
            }
            else{
                cout<<"Error in opening phone.txt";
            }

            myfile.open("members/email.txt",ios::app);
            if(myfile.is_open()){
                myfile<<email<<"\n";
                myfile.close();
            }
            else{
                cout<<"Error in opening email.txt";
            }
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

    public:
        void addBook(){
            string title;
            string author;
            string genre;
            int publishedYear;
            int avl = true;
            cin.ignore();
            cout<<"Enter the title of the book: ";
            getline(cin,title);
            cout<<"Enter the author of the book: ";
            getline(cin,author);
            cout<<"Enter the genre of the book: ";
            getline(cin,genre);
            cout<<"Enter the published year of the book: ";
            cin>>publishedYear;
            cin.ignore();
            book(title, author, genre, publishedYear, avl);
            

        }

        void addBook(string title, string author, string genre, int publishedYear, int avl = true){
            book(title, author, genre, publishedYear, avl);
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
            member(roll,name, address, phone, email);
        }

        void addmember(string roll, string name, string address, string phone, string email){
            member(roll,name, address, phone, email);
        }

        int totalLineFinder(const string &filename){
            ifstream file(filename);
            if(!file.is_open()){
                cout<<"Error in opening File !"<<endl;
                return 0;
            }

            string line;
            int total_line = 1;
            while(getline(file,line)){
                total_line++;
            }
            return total_line;
            file.close();
        }

        int lineFinder(const string &filename, string info){
            ifstream file(filename);
            if(!file.is_open()){
                cout<<"Error in opening file! "<<endl;
            }

            string line;
            int currline = 0;
            while(getline(file,line)){
                currline++;
                if(line == info){
                    return currline;
                    file.close();
                }
            }
        }

        void displayFunction(const string &filename, string info, int line){
            ifstream file(filename);
            if(!file.is_open()){
                cout<<"Error in opening "<<endl;
                file.close();
            }
            else{
                string data;
                int templine = 0;
                while(getline(file,data)){
                    templine++;
                    if(templine == line){
                        cout<<info<<" : "<<data<<endl;
                    }
                    

                }
                file.close();
            }

        }

        int displayAvailability(const string &filename, string info, int line){
            ifstream file(filename);
            if(!file.is_open()){
                cout<<"Error in opening "<<endl;
                file.close();
            }
            else{
                string data;
                int templine = 0;
                while(getline(file,data)){
                    templine++;
                    if(templine == line){
                        if(data == "1"){
                            cout<<info<<" : "<<"True"<<endl;
                        }
                        else{
                            cout<<info<<" : "<<"False"<<endl;
                        }
                    }
                    

                }
                file.close();
            }

        }

        void searchBook(){
            string r;
            cin.ignore();
            cout<<"Enter Book Title: ";
            getline(cin,r);
            cout<<r;
            int line = lineFinder("books/title.txt",r);
            cout<<endl<<endl<<endl;
            cout<<"------------------------Book Detail-------------------------"<<endl<<endl;

            //Id
            displayFunction("books/id.txt","ID",line);

            //title
            displayFunction("books/title.txt","Title",line);

            //author
            displayFunction("books/author.txt","Author",line);

            //genre
            displayFunction("books/genre.txt","Genre",line);

            //publishedYear
            displayFunction("books/publishedYear.txt","Published Year",line);

            //isAvailable
            displayAvailability("books/isAvailable.txt","Availability",line);

            cout<<endl<<endl;
        }

        void searchMember(){
            string r;
            cout<<"Enter Member RollNo: ";
            cin>>r;
            int line = lineFinder("members/rollNo.txt",r);
            cout<<endl<<endl<<endl;
            cout<<"-------------------------Member Detail-------------------------"<<endl<<endl;

            //Name
            displayFunction("members/name.txt","Name",line);
            //RollNo
            displayFunction("members/rollNo.txt","RollNo",line);
            //address
            displayFunction("members/address.txt","Address",line);
            //phone
            displayFunction("members/phone.txt","Phone Number",line);
            //email
            displayFunction("members/email.txt","Email",line);
            cout<<endl;
            cout<<endl;


        }
            
        void displayAllBooks(){
            cout<<endl<<endl<<endl;
            int totalNum = totalLineFinder("books/id.txt");
            cout<<endl<<"There are total "<<totalNum-1<<" Books."<<endl<<endl;
            for(int i=1;i<totalNum;i++){
                cout<<"--------------------Book "<<i<<"--------------------"<<endl<<endl;
                
                //Id
                displayFunction("books/id.txt","ID",i);

                //Title
                displayFunction("books/title.txt","Title",i);

                //Author
                displayFunction("books/author.txt","Author",i);

                //genre
                displayFunction("books/genre.txt","Genre",i);

                //PublishedYear
                displayFunction("books/publishedYear.txt","Published Year",i);

                //Availability
                displayAvailability("books/isAvailable.txt","Availibility",i);
            }
        }
           
        void displayAllMembers(){
            cout<<endl<<endl<<endl;
            int totalNum = totalLineFinder("members/rollNo.txt");
            cout<<"There are total "<<totalNum-1<<" Members."<<endl<<endl;
            for(int i=1;i<totalNum;i++){
                cout<<"--------------------Member "<<i<<"--------------------"<<endl<<endl;
            //Name
            displayFunction("members/name.txt","Name",i);
            //RollNo
            displayFunction("members/rollNo.txt","RollNo",i);
            //address
            displayFunction("members/address.txt","Address",i);
            //phone
            displayFunction("members/phone.txt","Phone Number",i);
            //email
            displayFunction("members/email.txt","Email",i);
            cout<<endl<<endl;
            }
            cout<<endl<<endl;
        }
      
};
//Global Declaration
int book::idGenerator = 0;

int main(){
    library l;
    int main;
    do
    {
        cout<<endl<<endl<<"--------------------Welcome To the Library--------------------"<<endl<<endl<<endl;
        cout<<"Are you a Admin or Member....\n 1.Admin\n 2.Member\n 3.Exit\n ";
        cin>>main;
        if(main == 1){
            int adminPanel;
            do
            {
                cout<<endl<<endl<<"----------Admin Panel----------\n\n Choose the option\n\n 1.Manage Books\n 2.Manage Members\n 3.Issue Books\n 4.Receive Returned Books\n 5.Return to Library Panel\n ";
                cin>>adminPanel;
                if(adminPanel == 1){
                    int managebook;
                    do
                    {
                        cout<<endl<<endl<<"Choose the option\n\n 1.Add Book\n 2.Search Book\n 3. View all Books\n 4.Return to Admin Panel\n ";
                        cin>>managebook;
                        if(managebook == 1){
                            l.addBook();
                        }
                        else if(managebook == 2){
                            l.searchBook();
                        }
                        else if(managebook == 3){
                            l.displayAllBooks();
                        }
                    } while (managebook != 4);
                    
                }
                else if(adminPanel == 2){
                    int managemember;
                    do
                    {
                        cout<<endl<<endl<<"Choose the option\n\n 1.Add Member\n 2.View Member Detail\n 3.View All Member\n 4. Return to Admin Panel\n ";
                        cin>>managemember;
                        if(managemember == 1){
                            l.addmember();
                        }
                        else if(managemember == 2){
                            l.searchMember();
                        }
                        else if(managemember == 3){
                            l.displayAllMembers();
                        }

                    } while (managemember != 3);
                    
                }

                else if(adminPanel == 3){
                    cout<<"This Feature is comming soon..."<<endl;
                }
                else if(adminPanel == 4){
                    cout<<"This feature is comming soon...."<<endl;
                }

            } while (adminPanel != 5);
            


        }


        else if(main == 2){
            int memb;
            do
            {
                cout<<endl<<endl<<"----------Member Panel----------\n\n Choose the option\n\n 1.Search Book\n 2.Borrow Books\n 3.Return Books\n 4.Pay Fine\n 5.Return to Library Panel\n ";
                cin>>memb;
                if(memb == 1){
                    l.searchBook();
                }
                else if(memb == 2){
                    cout<<"This feature is Comming soon....."<<endl;
                }
                else if(memb == 3){
                    cout<<"This feature is comming soon....."<<endl;
                }
                else if(memb == 4){
                    cout<<"This features is Comming soon....."<<endl;
                }
            } while (memb != 6);
            
        }
    } while (main!=3);
    

    // l.addBook("Pride and Prejudice", "Jane Austen", "Romance", 1813, true);
    // l.addBook("The Catcher in the Rye", "J.D. Salinger", "Fiction", 1951, false);
    // l.addBook("The Hobbit", "J.R.R. Tolkien", "Fantasy", 1937, true);
    // l.addBook("Moby-Dick", "Herman Melville", "Adventure", 1851, false);
    // l.addBook("Brave New World", "Aldous Huxley", "Dystopian", 1932, true);
    // l.addBook("The Shining", "Stephen King", "Horror", 1977, true);
    // l.addBook("Dune", "Frank Herbert", "Science Fiction", 1965, false);
    // l.addBook("Crime and Punishment", "Fyodor Dostoevsky", "Psychological Fiction", 1866, true);
    // l.addBook("Frankenstein", "Mary Shelley", "Gothic Horror", 1818, false);
    // l.addBook("The Road", "Cormac McCarthy", "Post-Apocalyptic", 2006, true);
    // l.addBook("The Martian", "Andy Weir", "Science Fiction", 2011, false);
    // l.addBook("Harry Potter and the Sorcerer’s Stone", "J.K. Rowling", "Fantasy", 1997, true);
    // l.addBook("The Book Thief", "Markus Zusak", "Historical Fiction", 2005, false);
    // l.addBook("The Da Vinci Code", "Dan Brown", "Thriller", 2003, true);
    // l.addBook("Gone Girl", "Gillian Flynn", "Mystery", 2012, false);

    // l.addmember("2478A05326", "Rajesh Pandit", "Bishrampur-03, Bara, Nepal", "980922xxxxx", "rashq122@gmail.com");
    // l.addmember("3487B01234", "Amit Sharma", "Lakeside-07, Pokhara, Nepal", "9812345678", "amit.sharma123@gmail.com");  
    // l.addmember("5623C07890", "Priya Karki", "Kumaripati-02, Lalitpur, Nepal", "9845678901", "priya.karki99@yahoo.com");  
    // l.addmember("1245A05678", "Suresh Thapa", "Baneshwor-10, Kathmandu, Nepal", "9801122334", "suresh.thapa@outlook.com");  
    // l.addmember("9876D03456", "Manisha Rai", "Biratnagar-05, Morang, Nepal", "9811223344", "manisha.rai@mail.com");  
    // l.addmember("4567E09876", "Deepak Bista", "Dhangadhi-01, Kailali, Nepal", "9856677889", "deepak.bista@gmail.com");  
    // l.addmember("6789F04567", "Anjali Tamang", "Dillibazar-04, Kathmandu, Nepal", "9803344556", "anjali.tamang123@gmail.com");  
    // l.addmember("2345G01234", "Bikash Shrestha", "Lagankhel-06, Lalitpur, Nepal", "9811223344", "bikash.shrestha98@yahoo.com");  
    // l.addmember("8901H07890", "Ramesh Adhikari", "Bharatpur-11, Chitwan, Nepal", "9841122334", "ramesh.adhikari@mail.com");  
    // l.addmember("3456I05678", "Sarita Poudel", "Butwal-03, Rupandehi, Nepal", "9806677889", "sarita.poudel@outlook.com"); 
    // l.findMemberDetail();


}