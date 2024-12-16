#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
using namespace std;

class Account{
	public:
		string account_number;
		string name;
		string password;
		double balance;
		Account* next;
		
};
class bankManagementSystem{
	private:
		Account* head;
	public:
		bankManagementSystem(): head(nullptr) {}
	// Add Account
	void addAccount(){
		Account* new_account = new Account;
		cout<<"Enter the Account number :  ";
		cin>>new_account->account_number;
		if(isaccount_numberUnique(new_account->account_number)){
			cout<<"Enter the name : ";
			cin.ignore();
			getline(cin,new_account->name);
			cout<<"Set your account password : ";
			cin>>new_account->password;
			cout<<"Enter the Balance : ";
			cin>>new_account->balance;
			
			new_account->next = nullptr;
			if(head == nullptr){
				head = new_account;
			}
			else{
				Account* temp = head;
				while(temp->next != nullptr){
					temp = temp->next;
				}
				temp->next = new_account;
			}
		}
	}
	// check uniqueness 
	bool isaccount_numberUnique(string& account_number){
		Account* temp = head;
		while(temp != nullptr){
			if(temp->account_number == account_number){
				return false; // Account number is already exit.
			}
			temp = temp->next;
		}
		return true;
	}
	// Search Account
	void searchAccount(){
		string account_number, password;
		cout<<"Enter Account Number :  ";
		cin>>account_number;
		cout<<"Enter Password of This Account :  ";
		cin>>password;
		
		Account* account = findAccount(account_number, password);
		// check condition that Account is found or not 
		if(account != nullptr){
			cout<<"Account Number : "<<account->account_number<<endl;
			cout<<"Holder Name : "<<account->name<<endl;
			cout<<"Current Balance : "<<account->balance<<endl;
		}
		else{
			cout<<"The Account is NOT Found! "<<endl;
			delete account;
		}
	}
	// helper Fuction that searching the Account 
	Account* findAccount(string& account_number, string& password){
		Account* temp = head;
		while(temp != nullptr){
			if(temp->account_number == account_number && temp->password == password){
				return temp;
			}
			temp = temp->next;
		}
		return nullptr;
	}
	// Deposite the fund.
	void depositeFund(){
		string account_number,password;
		cout<<"Enter Account Number :  ";
		cin>>account_number;
		cout<<"Enter Password of This Account :  ";
		cin>>password;
		
		Account* account = findAccount(account_number, password);
		if(account != nullptr){
			double d_amount;
			cout<<"Enter the amount : ";
			cin>>d_amount;
			account->balance += d_amount;
			cout<<"Deposite Amount are successfully."<<endl;
		}
		else{
			cout<<"Invalid Password ,The Account is NOT Found!  "<<endl;
			delete account;
		}
	}
	// Withdraw the Money 
	void withdrawFund(){
		string account_number, password;
		cout<<"Enter Account Number :  ";
		cin>>account_number;
		cout<<"Enter Password of This Account :  ";
		cin>>password;
		
		Account* account = findAccount(account_number, password);
		if(account != nullptr){
			double w_amount;
			cout<<"Enter Withdrawal Amount :  ";
			cin>>w_amount;
			if(w_amount > account->balance){
				cout<<"Current Balance "<<account->balance<<" ,But you excceed the Limit!\n Please enter valid Withdrawal Amount "<<endl;
			}
			else if(w_amount < account->balance){
				account->balance -= w_amount;
				cout<<"Withdraw successfully."<<endl;
				cout<<"\n-----------------------\n"<<endl;
				cout<<"Current Balance : "<<account->balance<<endl;
			}
		}
	}
	// Display All Acounts 
	void display(){
		Account* current = head;
		while(current != nullptr){
			cout<<"Account Number : "<<current->account_number<<endl;
			cout<<"Holder Name : "<<current->name<<endl;
			cout<<"Current Balance : "<<current->balance<<endl;
			current = current->next;
		}
		cout<<endl;
	}
};
int main(){
	bankManagementSystem bms;
	int choice;
	while(true){
		cout<<"\n*==*WELCOME TO BANK MANAGEMENT SYSTEM *==*"<<endl;
		cout<<"=========================================="<<endl;
		cout<<"Press 1. Add Account "<<endl;
		cout<<"Press 2. Search Account "<<endl;
		cout<<"Press 3. Deposite Fund "<<endl;
		cout<<"Press 4. Withdraw Fund "<<endl;
		cout<<"Press 5. Display All Acount "<<endl;
		cout<<"Press 6. Exit Program "<<endl;
		cout<<"=========================================="<<endl;
		cout<<"Enter Your Choice : ";
		cin>>choice;
		cout<<"\n---------------------"<<endl;
		switch(choice){
			case 1:{
				bms.addAccount();
				break;
			}
			case 2:{
				bms.searchAccount();				
				break;
			}
			case 3:{
				bms.depositeFund();
				break;
			}
			case 4:{
				bms.withdrawFund();
				break;
			}
			case 5:{
				bms.display();
				break;
			}
			case 6:{
				cout<<"Program successfully Terminated!"<<endl;
				exit(0);
				break;
			}
			default:{
				cout<<"Invalid Choice!"<<endl;
				cout<<"Please Enter valid Choice "<<endl;
				break;
			}
		}
		
	}
	
	return 0;
}