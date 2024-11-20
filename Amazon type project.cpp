#include <bits/stdc++.h>
// here in this libray , all type of libraries are available.
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
// Node for each product in a sub-category
class Product{
	public:
		string name;
		string description;
		string brand;
		float price;
		Product* p_next;
		//contructor 
		Product(string name, string description = "", string brand = "", float price = 0.0){
			this->name = name;
			this->description = description;
			this->brand = brand;
			this->price = price;
			this->p_next = nullptr;
		}
		
};
// Node for sub-categories (e.g., "Men" under "Shoes")
class subCategories{
	public:
		string name;
		int item_Sold;
		int item_Remaining;
		subCategories* sub_next;
		Product* p_head;

		
		subCategories(string name, int item_Remaining = 0){
			this->name = name;
			this->item_Sold = 0;
			this->item_Remaining = item_Remaining;
			this->sub_next = nullptr;
			this->p_head = nullptr;
		}
		// Add a product to this sub-category
		void addProduct(string pname, string description, string brand, float price){
			Product* new_prod = new Product(pname, description, brand, price);
			new_prod->p_next = p_head;
			p_head = new_prod;
			item_Remaining++;
		}
		// display all Product in this sub categorie
		void display_product(){
			Product* temp = p_head;
			cout<<"=> Product in : "<<name<<"\n";
			cout<<"================================"<<endl;
			while(temp != nullptr){
			cout << "Name : " << temp->name << endl;
            cout << "Description : " << temp->description << endl;
            cout << "Brand : " << temp->brand << endl;
            cout << "Price : $ " << temp->price << endl;
            cout << "--------------------------------" << endl;
            temp = temp->p_next;
			}
		}
		
};
// Node for main categories (e.g., "Shoes" or "Jewelry")
class Categories{
	public:
		string name;
		int item_Sold;
		int item_Remaining;
		Categories* cat_next;
		subCategories* sub_head;

		Categories(string name, int item_Remaining = 0){
			this->name = name;
			this->item_Sold = 0;
			this->item_Remaining = item_Remaining;
			this->cat_next = nullptr;
			this->sub_head = nullptr;
		}
		// Add a sub-category to this category
		void addSubCategories(string sub_name, int item_Remaining = 0){
			subCategories* new_sub_prod = new subCategories(sub_name, item_Remaining);
			new_sub_prod->sub_next = sub_head;
			sub_head = new_sub_prod;
		}
		// Display all sub-categories and their products
		void display_subCategories(){
			subCategories* temp = sub_head;
			cout<<"Sub Categories Product : "<<name<<endl;
			cout<<"================================"<<endl;
			while(temp != nullptr){
				cout<<temp->name<<endl;
				cout<<temp->item_Sold<<endl;
				cout<<temp->item_Remaining<<endl;
				// cout<<temp->name<<endl;
				temp->display_product();
				temp = temp->sub_next;
			}
		}
};
// Main system class to manage all categories
class inventrySystem{
	private:
		Categories* cat_head;
	public:
		inventrySystem(){
			cat_head = nullptr;
		}
		void addCategories(string cname, int item_remaining = 0){
			Categories* new_cat = new Categories(cname, item_remaining);
			new_cat->cat_next = cat_head;
			cat_head = new_cat;
		}
		// search the categories by name 
		Categories* find_categorie(string cname){
   			Categories* temp = cat_head;
    		while(temp != nullptr){
    		    if(temp->name == cname){
        	    return temp;
        		}
       			temp = temp->cat_next;
    		}
    	return nullptr;
		}

		// Display all categories
		void display_Categories(){
			Categories* temp = cat_head;
				if (!temp) {
        		cout << "No categories available." << endl;
        		return;
    			}
    		while(temp != nullptr){
    			cout<<"Categories are : "<<endl;
				cout<<"========================"<<endl;
				cout<<"Category Name : "<<temp->name<<endl;
				cout<< "Sold : " <<temp->item_Sold<<endl;
				cout<< "Remaining : " <<temp->item_Remaining<<endl;
				temp->display_subCategories();
				temp = temp->cat_next;
			}		
		}
};
void menu_system(inventrySystem& system){
	int choice;
	do{
		cout<<"**==> Inventry System Menu <==**"<<endl;
		cout<<"================================"<<endl;
		cout<<"\tPress 1. Add Categorie "<<endl;
		cout<<"\tPress 2. Display Categorie "<<endl;
		cout<<"\tPress 3. Add Sub-Categorie "<<endl;
		cout<<"\tPress 4. Add Products in sub categorie"<<endl;
		cout<<"\tPress 5. Search Categorie "<<endl;
		cout<<"\tPress 6. Exit Program "<<endl;
		cout<<"================================"<<endl;
		cout<<"Enter your choice : "<<endl;
		cin>>choice;
		if(choice == 1){
			string cname;
			cout<<"Enter the Categorie name : ";
			cin>>cname;
			system.addCategories(cname);
		}
		else if(choice == 2){
			system.display_Categories();
		}
		else if(choice == 3){
			string cname, sub_name;
			cout<<"Enter the Categorie name to add Sub-Category to : ";
			cin>>cname;
			Categories* cat = system.find_categorie(cname);
			if(cat != nullptr){
				cout<<"Enter the sub-Categorie name : ";
				cin>>sub_name;
				cat->addSubCategories(sub_name);
			}else{
				cout<<"Categorie not found."<<endl;
			}
		}
		else if(choice == 4){
			string cname, sub_name, pname, description, brand;
            float price;
            cout << "Enter the Category name to add Product to: ";
            cin >> cname;
            Categories* cat = system.find_categorie(cname);
            if (cat != nullptr) {
                cout << "Enter the Sub-Category name: ";
                cin >> sub_name;
                subCategories* sub = cat->sub_head;
                while (sub != nullptr && sub->name != sub_name) {
                    sub = sub->sub_next;
                }
                if (sub != nullptr) {
                    cout << "Enter Product name: ";
                    cin >> pname;
                    cout << "Enter Description: ";
                    cin >> description;
                    cout << "Enter Brand: ";
                    cin >> brand;
                    cout << "Enter Price: ";
                    cin >> price;
                    sub->addProduct(pname, description, brand, price);
                } else {
                    cout << "Sub-Category not found." << endl;
                }
            } else {
                cout << "Category not found." << endl;
            }
		}
		else if (choice == 5) {
            string cname;
            cout << "Enter the Category name: ";
            cin >> cname;
            Categories* cat = system.find_categorie(cname);
            if (cat) {
                cout << "Category " << cname << " found." << endl;
                cat->display_subCategories();
            } else {
                cout << "Category not found." << endl;
            }
        }	
	}while(choice != 6);
}
int main(){
	inventrySystem system;
	menu_system(system);	
	return 0;
}