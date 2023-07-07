#include <iostream>
#include <iomanip>
#include <fstream>
#include <bits/stdc++.h>

//Developed by Suyash Kamat and Shrinidhi Alur

using namespace std;
class user;
class PhonePe;
class CustomerSupport;
class PhonePayHistory;
class PhonePayWallet;
class PaymentMethod;
class BankAccount;
class CreditCard;
class DebitCard;
class errorException;
class Transaction;
class MobileRecharge;
class payment;
class Donation;
class Rewards;
class cashback;

//Developed by Suyash Kamat and Shrinidhi Alur


class user{

private:
    static user* instance;
    user(){}
public:
    string firstname;
    string lastname;
    int mobilenumber;
    string username;
    string password;
    int upi_pin;
    int bankaccount_number;
    string ifsccode;
    int balance;
    static int usercount;
    user(string firstname,string lastname,int mobilenumber,string username,string password,int upi_pin,int bankaccount_number,string ifsccode,int balance){
        usercount++;
        this->firstname=firstname;
        this->lastname=lastname;
        this->mobilenumber=mobilenumber;
        this->username=username;
        this->password=password;
        this->upi_pin=upi_pin;
        this->bankaccount_number=bankaccount_number;
        this->ifsccode=ifsccode;
        this->balance=balance;
        }

    static user *getInstance()
    {
        if(!instance)
        {
            instance = new user();
        }
        return instance;
    }
    void printUserCount(){
        cout<<"Number of Users Created are : "<<usercount;
    }
    void user_getdata()
    {
        for(int i=0;i<usercount;i++){
        cout<<"Enter Your First Name : "<<endl;
        cin>>firstname;
        cout<<"Enter Your Last Name : "<<endl;
        cin>>lastname;
        cout<<"Enter Your Mobile Number : "<<endl;
        cin>>mobilenumber;
        cout<<"Enter Your User Name : "<<endl;
        cin>>username;
        cout<<"Enter Your Password : "<<endl;
        cin>>password;
        cout<<"Enter Your UPI Pin : "<<endl;
        cin>>upi_pin;
        cout<<"Enter Your Bank account number: "<<endl;
        cin>>bankaccount_number;
        cout<<"Enter Your IFSC Code: "<<endl;
        cin>>ifsccode;
        cout<<"Enter Your Balance : "<<endl;
        cin>>balance;
        }
    }
    void user_printdata()
    {
        for(int i=0;i<usercount;i++)
        {
            cout<<"First Name : "<<firstname<<endl;
            cout<<"Last Name : "<<lastname<<endl;
            cout<<"Mobile Number : "<<mobilenumber<<endl;
            cout<<"User Name : "<<username<<endl;
            cout<<"Password : "<<password<<endl;
            cout<<"UPI Pin : "<<upi_pin<<endl;
        }
    }
};
int user::usercount=0;
user *user::instance = 0;

class PhonePe
{
public:
    int upi_id;
    PaymentMethod* PaymentMethods;
    Transaction* Transactions;
    PhonePayHistory* History;
    CustomerSupport* CustSupport;
    PhonePayWallet* Wallet;
    void setUPI()
    {
        cout<<"Enter UPI Id : "<<endl;
        cin>>upi_id;
    }
};

class CustomerSupport:public PhonePe
{
public:
    void getProblem()
    {
        string problem;
        string typeofProblem;
        cout<<"Enter the type of problem : "<<endl;
        cin>>typeofProblem;
        cout<<"Enter the problem : "<<endl;
        cin>>problem;
        cout<<endl<<"Thank You for the response, We will get back to you in 5-6 Business Days.";
    }
};

class PhonePayWallet:public PhonePe
{
    public:
    double balance = 0.0;
};

class PaymentMethod:public PhonePe
{
public:
    void choice(){
        cout<<"Enter a Choice to pay and save it : "<<endl<<"1.Bank Account"<<endl<<"2.Credit Card"<<endl<<"3.Debit Card"<<endl;
        int paymentChoice;
        cin>>paymentChoice;
        }
};

class BankAccount:public PaymentMethod
{
public:
    int accno;
    string BankName;
    string IFSCcode;
    double acc_balance;
    BankAccount(int ac,string bn,string ifs,double ab)
    {
        accno=ac;
        BankName=bn;
        IFSCcode=ifs;
        acc_balance=ab;
    }
    void BankAccount_printdata()
    {
        cout<<"Account Number : "<<accno<<endl;
        cout<<"Bank Name : "<<BankName<<endl;
        cout<<"IFSC Code : "<<IFSCcode<<endl;
        cout<<"Enter Account Balance : "<<acc_balance<<endl;
    }
};

class CreditCard:public PaymentMethod
{
public:
    string ownerName;
    int cardNumber;
    int cvv;
    int expiryDate;
    string bankName;
    int creditCardPin;
    double minBalance=10000.0;

    CreditCard(string on,int cn,int cv,int ed,string bn,int ccp)
    {
        ownerName=on;
        cardNumber=cn;
        cvv=cv;
        expiryDate=ed;
        bankName=bn;
        creditCardPin=ccp;
    }
    void creditCard_printdata()
    {
        cout<<"Owner Name : "<<ownerName<<endl;
        cout<<"Card Number : "<<cardNumber<<endl;
        cout<<"CVV : "<<cvv<<endl;
        cout<<"Expiry Date: "<<expiryDate<<endl;
        cout<<"Bank Name : "<<bankName<<endl;
        cout<<"Credit Card Pin: "<<creditCardPin<<endl;
    }
};

class DebitCard:public PaymentMethod
{
public:
    string ownerName;
    int cardNumber;
    int cvv;
    int expiryDate;
    string bankName;
    int DebitCardPin;
    double balance;
    DebitCard(string on,int cn,int cv,int ed,string bn,int dcp,BankAccount* ba)
    {
        ownerName=on;
        cardNumber=cn;
        cvv=cv;
        expiryDate=ed;
        bankName=bn;
        DebitCardPin=dcp;
        balance=ba->acc_balance;
    }
    void DebitCard_printdata()
    {
        cout<<"Owner Name : "<<ownerName<<endl;
        cout<<"Card Number : "<<cardNumber<<endl;
        cout<<"CVV : "<<cvv<<endl;
        cout<<"Expiry Date: "<<expiryDate<<endl;
        cout<<"Bank Name : "<<bankName<<endl;
        cout<<"Debit Card Pin: "<<DebitCardPin<<endl;
    }
};

class errorException
{
    public:string error;
    errorException(string e)
    {
            error=e;
    }
    void showError()
    {
        cout<<"The error is : "<<error<<endl;
    }
};

class Transaction: public PhonePe
{
public:
    PhonePe* pp;
    void choice(){
    }
};

class cashback:public Transaction
{
public:
    double Amount=0.0;
};
class MobileRecharge:public Transaction
{
public:
    int mobileNumber;
    int rechargeAmount;
    string type;
    void selectBillerName(){
        cout<<"JIO, AIRTEL, VI AND BSNL"<<endl;
        cout<<"SELECT THE TYPE :"<<endl;
        cin>>type;
        }
    void recharge(int mn,BankAccount* ba)
    {
        int ra;
        cout<<"Enter the recharge amount : "<<endl;
        cin>>ra;


        if(ba->acc_balance>=ra)
            {
            ba->acc_balance-=ra;
            cout<<"Recharge done to the mobile number :  "<<mn<<endl;
            if(ra>500){
                ba->acc_balance+=100;
                cout<<"Congratulations you have recived Rs 100 Cashback."<<endl;
            }
            fstream file;
        file.open("history.txt",ios::out | ios::app);
        file<<"Avinash paid Rs."<<ra<<" using bank account to mobile number:"<<mn<<"\n";
        file.close();
                    }else{
                        throw errorException("Low amount balance to do mobile recharge.");
                    }

        }
     void recharge(int mn,CreditCard* cc)
     {
        int ra;
        cout<<"Enter the recharge amount : "<<endl;
        cin>>ra;
        if(cc->minBalance>=ra){
            cc->minBalance-=ra;
            cout<<"Recharge done to the mobile number :  "<<mn<<endl;
            fstream file;
            file.open("history.txt",ios::out | ios::app);
            file<<"Avinash paid Rs."<<ra<<" using Credit Card to mobile number:"<<mn<<"\n";
            file.close();
            if(ra>500){
                cc->minBalance+=100;
                cout<<"Congratulations you have recived Rs 100 Cashback."<<endl;
            }
            }else{
                throw errorException("Low amount balance to do mobile recharge.");

                }
        }

};

class payment:public Transaction
{
public:

    string UPIid;
    int BankAccountNo;
    int phoneNo;
    double Money;
    void PayUPI(string u,BankAccount* ba)
    {
        fstream file;
        file.open("history.txt",ios::out | ios::app);
        cout<<"Enter the money to be sent : "<<endl;
        cin>>Money;
        ba->acc_balance-=Money;
        cout<<"Money paid to UPI Id : "<<u;
        file<<"Avinash paid Rs."<<Money<<" using UPI to UPI Id:"<<u<<"\n";
        file.close();
    }
    void PayUPI(string u,CreditCard* ba)
    {
        fstream file;
        file.open("history.txt",ios::out | ios::app);
        cout<<"Enter the money to be sent : "<<endl;
        cin>>Money;
        ba->minBalance-=Money;
        cout<<"Money paid to UPI Id : "<<u;
        file<<"Avinash paid Rs."<<Money<<" using UPI to UPI Id:"<<u<<"\n";
        file.close();
    }
    void PayBankAccount(int u,CreditCard* ba)
    {
        fstream file;
        file.open("history.txt",ios::out | ios::app);
        cout<<"Enter the money to be sent : "<<endl;
        cin>>Money;
        ba->minBalance-=Money;
        cout<<"Money paid to Bank Account Number : "<<u;
        file<<"Avinash paid Rs."<<Money<<" to Bank Account Number:"<<u<<"\n";
        file.close();
    }
    void PayBankAccount(int u,BankAccount* ba)
    {
        fstream file;
        file.open("history.txt",ios::out | ios::app);
        cout<<"Enter the money to be sent : "<<endl;
        cin>>Money;
        ba->acc_balance-=Money;
        cout<<"Money paid to Bank Account Number : "<<u;
        file<<"Avinash paid Rs."<<Money<<" to Bank Account Number:"<<u<<"\n";
        file.close();
    }
    void PayPhoneNo(int u,BankAccount* ba)
    {
        fstream file;
        file.open("history.txt",ios::out | ios::app);
        cout<<"Enter the money to be sent : "<<endl;
        cin>>Money;
        ba->acc_balance-=Money;
        cout<<"Money paid to Phone Number : "<<u;
        file<<"Avinash paid Rs."<<Money<<" to Phone Number:"<<u<<"\n";
        file.close();
    }
    void PayPhoneNo(int u,CreditCard* ba)
    {
        fstream file;
        file.open("history.txt",ios::out | ios::app);
        cout<<"Enter the money to be sent : "<<endl;
        cin>>Money;
        ba->minBalance-=Money;
        cout<<"Money paid to Phone Number : "<<u;
        file<<"Avinash paid Rs."<<Money<<" to Phone Number:"<<u<<"\n";
        file.close();
    }
};

class Donation:public Transaction
{
public:
    string Donator;
    string reciever;
    double DonAmt;
    int rechargechoice;
    void getDonation(string d,string r,double da,BankAccount* ba)
    {
         if(ba->acc_balance>=da){
            fstream file;
            file.open("history.txt",ios::out | ios::app);
            ba->acc_balance-=da;
            cout<<"Thank You "<<d<<" for"<<da<<" from "<<r;
            file<<"Avinash paid Rs."<<da<<" as a donation to:"<<d<<"\n";
            file.close();
            }else{
                cout<<"You dont have sufficient balance."<<endl;
                }
    }

    void getDonation(string d,string r,double ra,CreditCard* cc)
    {
        if(cc->minBalance>=ra){
            fstream file;
            cc->minBalance-=ra;
            cout<<"Thank You "<<d<<" for"<<ra<<" from "<<r;
            file<<"Avinash paid Rs."<<ra<<" as a donation to:"<<d<<"\n";
            file.close();
            }else{
                cout<<"You dont have sufficient balance."<<endl;
                    }
        }
};
class PhonePeHistory:public PhonePe
{
public:
    void showHistory(){
        ifstream history;
        history.open("history.txt", ios::in);
        string line;
        while(getline(history, line))
        {
            cout << line << "\n";
        }
        history.close();
    }
};
class Rewards:public Transaction
{
public:
    void printRewards(){
        int random_integer;
        int lowest=1, highest=5;
        int range=(highest-lowest)+1;
        random_integer = lowest + int(range*rand()/(RAND_MAX + 1.0));
        if(random_integer==1)
            cout<<"Reward : 50% off on Shrinidhi Soaps."<<endl;
        else if(random_integer==2)
            cout<<"Reward : 50% off on Suyash Deodrants."<<endl;
        else if(random_integer==3)
            cout<<"Reward : 50% off on Avinash Phenyl."<<endl;
        else if(random_integer==4)
            cout<<"Reward : 50% off on Shashank Shampoos."<<endl;
    }
    void printAllRewards(){
        cout<<"Reward : 10% off on Shrinidhi Soaps."<<endl;
        cout<<"Reward : 20% off on Suyash Deodrants."<<endl;
        cout<<"Reward : 30% off on Avinash Phenyl."<<endl;
        cout<<"Reward : 40% off on Shashank Shampoos."<<endl;

    }
};


int main()
{
    int main_choice;
    PhonePe* pp;


    user u1("Avinash","Yuvaraj",80730325,"aviyuva","avinash69",1234,3265695,"SBI001234",5000);
    BankAccount ba1(3265695,"State Bank of India","SBI001234",5000);
    CreditCard cc("Avinash Yuvaraj",874737,1234,122,"State Bank of India",1313);
    MobileRecharge mr;
    payment pay;
    Donation don;
    Rewards rr;
    PhonePayWallet ppw;
    CustomerSupport cs;
    cashback cb;
    PhonePeHistory ph;



    cout<<setw(50)<<"WELCOME TO PHONE PAY";
    while(1){
    cout<<endl<<endl<<endl<<"Please choose one option in the below given options."<<endl;
    cout<<"1.User Details"<<endl<<"2.Mobile Recharge"<<endl<<"3.Payment(UPI,Bank Account,Phone Number)"<<endl;
    cout<<"4.PhonePay Wallet"<<endl<<"5.Donations"<<endl<<"6.Rewards"<<endl<<"7.Customer Support"<<endl<<"8.Check Bank Account Balance"<<endl;
    cout<<"9.Check Credit Card Balance"<<endl<<"10.PhonePe History"<<endl<<"11.Exit"<<endl;
    cin>>main_choice;

    switch(main_choice){

        case 1:{
            cout<<endl<<"-------------------User Details-------------------"<<endl;
            u1.user_printdata();
            break;
        }
        case 2:{
            cout<<endl<<"-------------------Mobile Recharge-------------------"<<endl;

            mr.selectBillerName();
            int choice;
            int number;
            cout<<"Enter the number you want to recharge to : "<<endl;
            cin>>number;
            cout<<"Choose the payment method : 1.bank account 2.Credit Card 3.Debit Card."<<endl;
            cin>>choice;
            try{
            if(choice==1 || choice==3){
                mr.recharge(number,&ba1);
            }
            else{
                mr.recharge(number,&cc);
                }
            }
            catch(errorException &E){
                E.showError();
            }
            break;
        }
        case 3:{
            cout<<endl<<"-------------------Payment-------------------"<<endl;

            int choice1;
            cout<<"Enter whom you want to pay to: 1.UPI Id 2.Bank Account 3.Phone Number."<<endl;
            cin>>choice1;

            if(choice1==1){
                int choice2;
                string upi;
                cout<<"Enter UPI Id : "<<endl;
                cin>>upi;
                cout<<"Choose how you want to pay 1.bank account 2. debit card 3.credit card"<<endl;
                cin>>choice2;
                if(choice2==1 || choice2==2){
                    pay.PayUPI(upi,&ba1);
                }
                else{
                    pay.PayUPI(upi,&cc);
                }
            }
            else if(choice1==2){
                int banaa;
                int choice2;
                cout<<"Enter Bank Account Number : "<<endl;
                cin>>banaa;
                cout<<"Choose how you want to pay 1.bank account 2. debit card 3.credit card"<<endl;
                cin>>choice2;
                if(choice2==1 || choice2==2)
                    pay.PayBankAccount(banaa,&ba1);
                else
                    pay.PayBankAccount(banaa,&cc);
            }else{
                int choice2;
                int phno;
                cout<<"Enter Phone Number : "<<endl;
                cin>>phno;
                cout<<"Choose how you want to pay 1.bank account 2. debit card 3.credit card"<<endl;
                cin>>choice2;
                if(choice2==1 || choice2==2){
                    pay.PayPhoneNo(phno,&ba1);
                }
                else{
                    pay.PayPhoneNo(phno,&cc);
                }
            }

            break;
            }

        case 4:{
            cout<<endl<<"-------------------PhonePay Wallet-------------------"<<endl;

            int c;
            cout<<"Balance in your phone pay wallet is "<<ppw.balance<<endl;
            cout<<"Do you want to put money in your wallet?(1=Yes/2=No)"<<endl;
            cin>>c;

            if(c==1){
                cout<<"How much money do you want to put in wallet?"<<endl;
                int money;
                cin>>money;
                int choice2;
                cout<<"Choose how you want to pay 1.bank account 2. debit card 3.credit card"<<endl;
                cin>>choice2;
                if(choice2==1 || choice2==2){
                    if(ba1.acc_balance>money){
                    ppw.balance+=money;
                    ba1.acc_balance-=money;
                    cout<<"PhonePe wallet added with "<<money<<endl;
                    }else
                    cout<<"Insufficient Funds."<<endl;
                    if(money>5000)
                    rr.printRewards();

                }
                else{
                    if(cc.minBalance>money){
                    ppw.balance+=money;
                    cc.minBalance-=money;
                    }else
                    cout<<"Insufficient Funds."<<endl;
                    if(money>5000)
                        rr.printRewards();
                }

            }
            else{
                cout<<"OK Balance is "<<ppw.balance<<endl;
            }
            break;
        }
        case 5:{
            cout<<endl<<"-------------------Donations-------------------"<<endl;

            string rec;
            string donn;
            int money;

            cout<<"Please enter your Name?"<<endl;
            cin>>donn;
            cout<<"Which orgransiation or NGO do you want to send money to?"<<endl;
            cin>>rec;
            cout<<"How much money do you want to send to which organistation or NGO?"<<endl;
            cin>>money;
            int choice;
            cout<<"Choose the option to send the money : 1.Bank account 2.Credit Card 3.Debit Card"<<endl;
            cin>>choice;

            if(choice==1 || choice==3){
                don.getDonation(donn,rec,money,&ba1);
            }
            else{
                don.getDonation(donn,rec,money,&cc);
            }
            break;
        }
        case 6:
            {
                cout<<endl<<"-------------------Rewards-------------------"<<endl;
            cout<<"The Available Rewards are : "<<endl;
            rr.printAllRewards();
            break;
        }
        case 7:
            {
                cout<<endl<<"-------------------Customer Support-------------------"<<endl;
            cs.getProblem();
            break;
        }
        case 8:
            {
                cout<<endl<<"-------------------Bank Account Balance-------------------"<<endl;
            cout<<"Bank Account Balance : "<<ba1.acc_balance<<endl;
            break;
        }
        case 9:{
            cout<<endl<<"-------------------Credit Card Balance-------------------"<<endl;
            cout<<"Credit Card Balance : "<<cc.minBalance<<endl;
            break;
        }
        case 10:{
            ph.showHistory();
            break;
        }
        case 11:{
            exit(1);
        }
        default:
            {
            cout<<"Invalid Number"<<endl;
            break;
        };

}
    }
}

//Developed by Suyash Kamat and Shrinidhi Alur

