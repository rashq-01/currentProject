#include<iostream>
using namespace std;

class coffeeMachine{
    public: 
    virtual void makeCoffee() = 0;
    virtual void addMilk() = 0;
    virtual void heatWater() = 0;

//Non-Abstract Method

    virtual void displayMenu(){
        cout<<"Welcome to the coffee Machine........"<<endl;
        cout<<" 1. Make Coffee\n 2. Add Milk\n 3. Heat Water\n 4. Exit"<<endl;
    }
    virtual ~coffeeMachine(){
        cout<<"Coffee Machine Shutting Down......"<<endl;
    }
};

//Derived Class implementing the abstract methods

class basicCoffee : public coffeeMachine{
    public:
    void makeCoffee() override {
        cout<<"Grinding Coffee beans.... Brewing coffee...."<<endl;
    }
    void addMilk() override {
        cout<<"Adding milk to your coffee...."<<endl;
    }
    void heatWater() override {
        cout<<"Heating water for your coffee"<<endl;
    }
};

//Another Derived Class implementig the abstract methods
class AdvancedCoffee : public coffeeMachine{
    public:
    void displayMenu(){
        cout<<"Welcome to the coffee Machine........"<<endl;
        cout<<" 1. Make Coffee\n 2. Make Cuppuccino\n 3. Add Milk\n 4. Heat Water\n 5. Exit"<<endl;
    }
    void makeCoffee() override{
        cout<<"Brewing a premium espresso with freshly ground beans....."<<endl;
    }
    void addMilk() override {
        cout<<"Frothing and adding milk for a latte...."<<endl;
    }
    void heatWater() override {
        cout<<"Boiling water with precise temperature control..."<<endl;
    }

//Additional feature specific to Advanced machines
    void makeCuppuccino(){
        cout<<"Making a cuppuccino with perfect foam....."<<endl;
    }
};



int main(){
    // int coffeeChoose;
    // cout<<"Welcome.........."<<endl<<endl;
    // cout<<"1. Basic Coffee\n2. Advanced Coffee"<<endl;
    // cin>>coffeeChoose;
    // if(coffeeChoose == 1){

    // }
    coffeeMachine* advance = new AdvancedCoffee;
    coffeeMachine* basic = new basicCoffee;
    int n;
    do
    {
    cout<<endl<<endl;

    cout<<"---------------Welcome To Coffe Machine---------------"<<endl<<endl;

    cout<<endl<<"Choose The Coffee Type...\n 1. Basic Coffee \n 2. Advance Coffee \n 3. Exit"<<endl;
    cin>>n;

    if(n==1){
        cout<<endl;
        int m = 0;
        do
        {
            basic->displayMenu();
            cin>>m;
            if(m==1){
                basic->makeCoffee();
                m=4;
            }
            else if(m==2){
                basic->addMilk();
                m=4;
            }
            else if(m==3){
                basic->heatWater();
                m=4;
            }
        } while (m != 4);
        
    }
    else if (n == 2) {
        int o;
        do {
            advance->displayMenu();
            cin >> o;
            if (o == 1){
                advance->makeCoffee();
                o=5;
            }
            else if (o == 2) {
                auto adv = dynamic_cast<AdvancedCoffee*>(advance);
                         //OR
                // AdvancedCoffee* adv = dynamic_cast<AdvancedCoffee*>(advance);
                if (adv){
                    adv->makeCuppuccino();
                    o=5;
                }
            }
            else if (o == 3){
                advance->addMilk();
                o=5;
            }
            else if (o == 4){
                advance->heatWater();
                o=5;
            }
        } while (o != 5);
    }


    } while (n !=3);
    






    // coffeeMachine* basicMachine = new basicCoffee;

    

    // cout<<"        Dispalying Menu"<<endl;
    // basicMachine->displayMenu(); //Displaying Menu
    // cout<<"      Making Coffee"<<endl;
    // basicMachine->makeCoffee();  //Making Coffee
    // cout<<"       Adding Milk"<<endl;
    // basicMachine->addMilk();     //Adding Milk to Coffee
    // cout<<"     Heating Water"<<endl;
    // basicMachine->heatWater();   //Heating Water
    // cout<<endl;
    // cout<<endl;

    // //Using an Advanced Coffee Machine
    // coffeeMachine* advancedMachine = new AdvancedCoffee;
    // cout<<endl;
    // cout<<"           Making Advanced Coffee"<<endl;
    // advancedMachine->makeCoffee();   //Making coffee
    // cout<<"             Adding Milk to advanced coffee"<<endl;
    // advancedMachine->addMilk();    //Adding Milk
    // cout<<"              Heating Water"<<endl;
    // advancedMachine->heatWater();  //Heating Water
    // //Specific Feature of adanced machine (Need to cast)

    // cout<<"       Making cuppuccino"<<endl;
    // dynamic_cast<AdvancedCoffee*>(advancedMachine)->makeCuppuccino();

    // //Cleaning UP Memory

    delete basic;
    delete advance;
    return 0 ;







}