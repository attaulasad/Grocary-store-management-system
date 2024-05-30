//        ***************** [    Grocery management System       ] ************************

#include <iostream>
#include <fstream>//file handling
#include <string>
#include <vector>// container, a dynamic array that can grow in size.
#include <iomanip> // for setw() output formating
#include <cstdlib> //for cls
using namespace std;
// Global variables
vector<string> finalCartNames;//store the names of items that the user adds to their shopping cart 
vector<int> finalCartPrices;// stores the prices of the items in the shopping cart.
vector<int> finalCartQuantity;// stores the quantities of the items in the shopping cart.
int Amount_to_pay = 0;// is used to store the total amount to be paid for the items in the cart.
string phone_num = "1234567890";
string admin_phone ="987654321";
string username = "asad";       
string password = "007"; 
//The TreeNode class represents a node in the grocery store tree. Each node contains information about an item (name, price, quantity) and may have children nodes representing sub-items or categories.
class TreeNode {
public:
    string name;
    int price;
    int quantity;
    vector<TreeNode*> children;

    TreeNode(string n, int p, int q) : name(n), price(p), quantity(q) {}
};

//This class represents the entire grocery store hierarchy and includes functions to build and display the tree.
class GroceryStoreTree {
public:
    TreeNode* root;

    GroceryStoreTree() {
        root = new TreeNode("Grocery General Store", 0, 0);
        buildTree();
    }
    void buildTree();
    void displayCategories();
    TreeNode* getCategory(int choice);
    void displayProducts(TreeNode* category);
    TreeNode* getProduct(TreeNode* category, int choice);   
};
class LoginManager {
private:

    string username_entered;
    string password_entered;
public:
	
 void input_login()
    {
    	//	system("cls");
        cout<<"\n\n\t\t\tLOGIN PAGE\t\t\n\n";
        
        cout << "\t\t\tEnter Username : ";
        cin >> username_entered;
        
        try
        {
            cout << "\t\t\tEnter Password : ";
            cin >> password_entered;
            if(password_entered  != password){
                throw password_entered;     // wrong password is thrown in the corresponding catch block

            }
        }
        catch(string ex)
        {
            int forgot_password_var;
            string phone_num_entered_FP;
            cout<<endl<<ex<<" \t\t\tis wrong password !"<<endl;
            cout<<"\n\t\t\tForgot password ?\nIf Yes, Press 1. If NO, Press 0 : ";
            cin>>forgot_password_var;
            if(forgot_password_var == 1){
                cout<<"\t\t\tEnter your phone number : ";
                cin>>phone_num_entered_FP;
                if(phone_num_entered_FP == phone_num){
                    cout<<"\n\t\t\tThe password is : "<<password<<endl;
                }
                else{
                    cout<<"\t\t\tWrong Phone Number !"<<endl;
                }
            }

        }
        
    }
    int output_login()
    {
    //	system("cls");
        while (username != username_entered || password != password_entered)
        {
            cout << "Try again !" << endl<< endl;
            input_login();
             
            //	system("cls");
        }
        return 1;
    }
};
//& pass the actual value effect on actual value
// Function prototypes
void main_menu(GroceryStoreTree& tree);
void placeOrder(GroceryStoreTree& tree);
void cart(TreeNode* product);
void generateBill();
void displayEmployeeDetails(GroceryStoreTree& tree);
void chatWithCustomerCare(GroceryStoreTree& tree);
void manageBankAccounts(GroceryStoreTree& tree);
void displayBank1(GroceryStoreTree& tree);
void displayBank2(GroceryStoreTree& tree);
void aboutTheShop(GroceryStoreTree& tree);
void GroceryStoreTree::buildTree() {
	 // Building the tree with predefined categories and products
    TreeNode* chocolates = new TreeNode("Chocolates", 0, 0);
    chocolates->children.push_back(new TreeNode("Milk Chocolate", 120, 0));
    chocolates->children.push_back(new TreeNode("Hazelnut Chocolate", 180, 0));
    chocolates->children.push_back(new TreeNode("White Chocolate", 140, 0));
    chocolates->children.push_back(new TreeNode("Mint Chocolate", 160, 0));

    TreeNode* breads = new TreeNode("Breads", 0, 0);
    breads->children.push_back(new TreeNode("Sourdough Bread", 25, 0));
    breads->children.push_back(new TreeNode("Rye Bread", 30, 0));
    breads->children.push_back(new TreeNode("Whole Wheat Bread", 35, 0));

    TreeNode* ketchups = new TreeNode("Ketchups", 0, 0);
    ketchups->children.push_back(new TreeNode("Organic Ketchup", 50, 0));
    ketchups->children.push_back(new TreeNode("Spicy Ketchup", 55, 0));
    ketchups->children.push_back(new TreeNode("Sweet Ketchup", 45, 0));

    TreeNode* noodles_and_soups = new TreeNode("Noodles and Soups", 0, 0);
    noodles_and_soups->children.push_back(new TreeNode("Udon Noodles", 70, 0));
    noodles_and_soups->children.push_back(new TreeNode("Soba Noodles", 65, 0));
    noodles_and_soups->children.push_back(new TreeNode("Miso Soup", 30, 0));
    noodles_and_soups->children.push_back(new TreeNode("Chicken Noodle Soup", 45, 0));

    TreeNode* soap_and_detergent = new TreeNode("Soap and Detergent", 0, 0);
    soap_and_detergent->children.push_back(new TreeNode("Lavender Soap", 15, 0));
    soap_and_detergent->children.push_back(new TreeNode("Lemon Detergent", 60, 0));
    soap_and_detergent->children.push_back(new TreeNode("Herbal Soap", 20, 0));

    TreeNode* dry_fruits = new TreeNode("Dry Fruits", 0, 0);
    dry_fruits->children.push_back(new TreeNode("Walnut 250g", 350, 0));
    dry_fruits->children.push_back(new TreeNode("Dried Fig 250g", 400, 0));
    dry_fruits->children.push_back(new TreeNode("Pecan 250g", 375, 0));
    dry_fruits->children.push_back(new TreeNode("Hazelnut 250g", 360, 0));
    dry_fruits->children.push_back(new TreeNode("Dates 250g", 300, 0));

    TreeNode* cooking_oils = new TreeNode("Cooking Oils", 0, 0);
    cooking_oils->children.push_back(new TreeNode("Olive Oil 1L", 350, 0));
    cooking_oils->children.push_back(new TreeNode("Coconut Oil 1L", 300, 0));
    cooking_oils->children.push_back(new TreeNode("Sesame Oil 1L", 320, 0));
    cooking_oils->children.push_back(new TreeNode("Peanut Oil 1L", 310, 0));

    TreeNode* rice_and_sugar = new TreeNode("Rice and Sugar", 0, 0);
    rice_and_sugar->children.push_back(new TreeNode("Jasmine Rice 1kg", 100, 0));
    rice_and_sugar->children.push_back(new TreeNode("Arborio Rice 1kg", 150, 0));
    rice_and_sugar->children.push_back(new TreeNode("Cane Sugar 1kg", 90, 0));
    rice_and_sugar->children.push_back(new TreeNode("Raw Sugar 1kg", 80, 0));

    TreeNode* soft_drinks = new TreeNode("Soft Drinks", 0, 0);
    soft_drinks->children.push_back(new TreeNode("Lemonade", 40, 0));
    soft_drinks->children.push_back(new TreeNode("Root Beer", 45, 0));
    soft_drinks->children.push_back(new TreeNode("Ginger Ale", 50, 0));
    soft_drinks->children.push_back(new TreeNode("Sparkling Water", 35, 0));
    soft_drinks->children.push_back(new TreeNode("Iced Tea", 55, 0));

    TreeNode* ice_creams = new TreeNode("Ice Creams", 0, 0);
    ice_creams->children.push_back(new TreeNode("Mint Ice Cream", 60, 0));
    ice_creams->children.push_back(new TreeNode("Cookies and Cream Ice Cream", 70, 0));
    ice_creams->children.push_back(new TreeNode("Peach Ice Cream", 65, 0));
    ice_creams->children.push_back(new TreeNode("Mango Sorbet", 50, 0));
    ice_creams->children.push_back(new TreeNode("Blueberry Ice Cream", 75, 0));

    root->children.push_back(chocolates);
    root->children.push_back(breads);
    root->children.push_back(ketchups);
    root->children.push_back(noodles_and_soups);
    root->children.push_back(soap_and_detergent);
    root->children.push_back(dry_fruits);
    root->children.push_back(cooking_oils);
    root->children.push_back(rice_and_sugar);
    root->children.push_back(soft_drinks);
    root->children.push_back(ice_creams);
}

void GroceryStoreTree::displayCategories() { 
      cout << "\t\t\t\t\tAvailable Categories:\n";
        int count = 1;
        //root->children is a vector (or some other iterable container) containing pointers to the child nodes of the root node
        //auto:This keyword allows the compiler to automatically deduce the type of the variable 
        for (auto category : root->children) {
            cout << "\t\t\t\t\t" << count++<<")" << category->name << endl;
        }
}
TreeNode* GroceryStoreTree::getCategory(int choice) {
      if (choice < 1 || choice > root->children.size()) return nullptr;
      //user choices typically start from 1, but arrays and vectors in C++ are zero-indexed. So, choice - 1 is used to get the correct index.
        return root->children[choice - 1];
}

void GroceryStoreTree::displayProducts(TreeNode* category) { 
      if (!category) return;
        cout << "\t\t\t\t\tAvailable Products in " << category->name << ":\n";
        int count = 1;
        for (auto product : category->children) {
            cout<< "\t\t\t\t\t" << count++ << ")" << product->name << " : "<< "  $" << product->price << "/-\n";
        }
    }
TreeNode* GroceryStoreTree::getProduct(TreeNode* category, int choice) {
    if (!category || choice < 1 || choice > category->children.size()) return nullptr;
    return category->children[choice - 1];
}
int main() {
    GroceryStoreTree tree;
    LoginManager l;
    l.input_login();
     int login_var =l.output_login();// This line calls the output_login method on the LoginManager instance l and stores the result in the variable login_var.
     while (true) { // Loop to keep the program running
        main_menu(tree); // Display the main menu
    }
    return 0;
}

void main_menu(GroceryStoreTree& tree) {
    int choice;
cout << "\n\t\t\t##########################################################################";
cout << "\n\t\t\t######################### Grocery Store Management System ########################";
cout << "\n\t\t\t##########################################################################\n\n";

   cout << "\n\n\t\t\t\t\t----------------- MAIN MENU -----------------";
cout << "\n\n\n\t\t\t\t\t01. Place an order";
cout << "\n\t\t\t\t\t02. Generate the bill";
cout << "\n\t\t\t\t\t03. Show all Employee details";
cout << "\n\t\t\t\t\t04. Chat with customer care agent";
cout << "\n\t\t\t\t\t05. Check bank accounts";
cout << "\n\t\t\t\t\t06. About the shop";
cout << "\n\t\t\t\t\t07. Log Out";
cout << "\n\n\t\t\t\t\tSelect Your Option (1-7): ";

    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice) {
        case 1:
            placeOrder(tree);
            break;
         case 2:
            if (finalCartNames.empty()) {
                cout << "Your cart is empty. Please place an order first.\n";
            } else {
                generateBill();
            }
            break;
        case 3:
            displayEmployeeDetails(tree);
            break;
        case 4:
            chatWithCustomerCare(tree);
            break;
        case 5:
            manageBankAccounts(tree);
            break;
        case 6:
           aboutTheShop(tree);
          break;
        case 7: {
            string confirm;
            cout << "Are you sure you want to log out and exit the program? (YES/NO): ";
            cin >> confirm;
            if (confirm == "yes") {
                cout << "Logging out...\n";
                exit(0);
            } else if (confirm == "no") {
                main_menu(tree); // Corrected the call to include the tree argument
            } else {
                cout << "Invalid choice!\n";
            }
            break;
        }
        default:
            cout << "Invalid choice!\n";
            break;
    }
}
void placeOrder(GroceryStoreTree& tree) { 
    tree.displayCategories();
    int categoryChoice;
    cout << "Enter the category you want to browse: ";
    cin >> categoryChoice;
    TreeNode* category = tree.getCategory(categoryChoice);//This function returns a pointer to the category node if the choice is valid
    if (category) {
        tree.displayProducts(category);
        int productChoice;
        cout << "Enter the product you want to add to cart: ";
        cin >> productChoice;
        TreeNode* product = tree.getProduct(category, productChoice);//This function returns a pointer to the product node if the choice is valid,
        if (product) {
            cart(product);
            // After adding to cart, return to main menu
            main_menu(tree);
        } else {
            cout << "Invalid product choice!\n";
            // If product choice is invalid, return to main menu
            main_menu(tree);
        }
    } else {
        cout << "Invalid category choice!\n";
        // If category choice is invalid, return to main menu
        main_menu(tree);
    }
}
//It retrieves(fetch) the name and price of the product from the product pointer using product->name and product->price.
void cart(TreeNode* product) {
    int quantity;
    cout << "\nEnter the quantity of " << product->name << " : ";
    cin >> quantity;
    finalCartNames.push_back(product->name);
    finalCartPrices.push_back(product->price);
    finalCartQuantity.push_back(quantity);
    cout << product->name << " of  " << product->price << "/- and quantity = " << quantity << ", has been added to cart !!!\n";
}
void generateBill() {

    if (finalCartNames.empty()) {
        cout << "Your cart is empty. Please place an order first.\n";
    } else {
        cout << "-------------------------------------------INVOICE--------------------------------------------------\n";
        cout << "S.No.\t\t\tName\t\t\tQuantity\tRate\t    Net price\n";
        cout << "----------------------------------------------------------------------------------------------------\n";
        for (int i = 0; i < finalCartNames.size(); i++) {
            cout << "[" << i + 1 << "]\t" << setw(30) << finalCartNames[i] << "\t\t" << finalCartQuantity[i] << "\t\t" << finalCartPrices[i] << "\t\t" << finalCartPrices[i] * finalCartQuantity[i] << endl;
            Amount_to_pay += finalCartPrices[i] * finalCartQuantity[i];
        }
        cout << "----------------------------------------------------------------------------------------------------\n";
        cout << "NET AMOUNT PAYABLE : $ " << Amount_to_pay << "/-" << endl;
        cout << "----------------------------------------------------------------------------------------------------\n";
    }
   
}


void displayEmployeeDetails(GroceryStoreTree& tree) {
 char choice;
    system("cls");
    cout << "\n\t\t\tEMPLOYEE DETAILS\t\t\n\n";
    cout << "\t\t\t1.The Rock, Manager, Contact: 123-456-7890" << endl;
    cout << "\t\t\t2. steven salvatore, Cashier, Contact: 987-654-3210" << endl;
    cout << "\t\t\t3. John Smith, Stock Manager, Contact: 456-789-0123" << endl;

    do {
    	
        cout << "Press M to go back to main menu : ";
        cin >> choice;
        if (choice == 'M' || choice == 'm') {
            main_menu(tree); // Go back to the main menu
            return; // Exit the function after going back to the main menu
        } else {
            cout << "Wrong input !!!" << endl;
        }
    } while (true);   
    

}



void chatWithCustomerCare(GroceryStoreTree& tree) {
	system("cls"); 
    int customer_care_variable;
    string entered_phone_num;
    cout << "\n\n\t\t\t\tCUSTOMER CARE\n";
    cout << "\t\t=========================================================\n";
    cout << "\t\t\tHi, you are now chatting with a customer care agent.\n";
    cout << "\t\t\tPlease choose from the options below:\n";
    cout << "\t\t\t(1) I cannot login\n";
    cout << "\t\t\t(2) I cannot place orders\n";
    cout << "\t\t\t(3) I cannot generate bills\n";
    cout << "\t\t\t(4) My problem is not listed\n";
    cout << "\t\t\tEnter your choice:\n ";
    cout << "\t\t=========================================================\n";
    cin >> customer_care_variable;

    switch (customer_care_variable) {
        case 1: {
            cout << "Enter your phone number : ";
            cin >> entered_phone_num;
            if (entered_phone_num == phone_num) {
                char k;
                cout << "\nPhone number entered is correct !!!\n\n";
                cout << "Your Login Credentials are :-\n";
                cout << "Username = ( " << username << " )\n";
                cout << "Password = ( " << password << " )\n\n";
                cout << "Press M to go back to main menu : ";
                cin >> k;
                if (k == 'M' || k == 'm') {
                    main_menu(tree);
                }
            } else {
                cout << "\nWrong phone number entered !!! Please try again.\n";
                chatWithCustomerCare(tree); // Recursively call the function to retry
            }
            break;
        }
        case 2: {
            char k;
            cout << "\nIf you are unable to place any order, then go back to main menu and choose 1st option.\n";
            cout << "Press M to go back to main menu : ";
            cin >> k;
            if (k == 'M' || k == 'm') {
                main_menu(tree);
            }
            break;
        }
        case 3: {
            char k;
            cout << "If you are unable to generate bills, first add items to your cart and then go back to main menu and choose 2nd option.\n";
            cout << "Press M to go back to main menu : ";
            cin >> k;
            if (k == 'M' || k == 'm') {
                main_menu(tree);
            }
            break;
        }
        case 4: {
            char m;
            char k;
           cout << "IF YOUR PROBLEM IS NOT LISTED HERE, YOU CAN WRITE TO US AND WE WILL GET BACK TO YOU AS SOON AS POSSIBLE.\n";
           cout << "NOTE: YOUR MESSAGES WILL BE SAVED TO US IN THE (CONSUMER COMPLAINS) FILE. JUST OPEN THE FILE TO SEE YOUR COMPLAINTS.\n\n";
           cout << "IF YOU WANT TO WRITE TO US, PRESS W.\n";
           cout << "IF YOU WANT TO GIVE US A CALL, PRESS C.\n";
           cout << "ENTER YOUR CHOICE: ";
            cin >> m;
            cin.ignore();
            if (m == 'W' || m == 'w') {
                string complain_string;
                ofstream out("Consumer_complains_file_GSMS.txt"); // Open the file to write complaints
                cout << "Type your complaint here :- (Type (END) to complete the complaint) \n\n";
                while (out) {
                    getline(cin, complain_string);
                    if (complain_string == "end"||complain_string == "END") {
                        break;
                    }
                    out << complain_string << endl;
                }
                out.close();
                cout << "\nThank you! We will get back to you soon.\n";
                cout << "Press M to go back to main menu : ";
                cin >> k;
                if (k == 'M' || k == 'm') {
                    main_menu(tree);
                }
            } else if (m == 'C' || m == 'c') {
                cout << "\nOur phone number is : " << admin_phone << ". Just give us a missed call and we will get back to you.\nThank you!" << endl;
                cout << "Press M to go back to main menu : ";
                cin >> k;
                if (k == 'M' || k == 'm') {
                    main_menu(tree);
                }
            }
            break;
        }
        default: {
            cout << "Wrong Input !!!\n";
            break;
        }
    }
}


void manageBankAccounts(GroceryStoreTree& tree) {
	system("cls"); 
    int choice;
    cout << "Welcome to the Bank Account Management System.\n";
    cout << "Please select an option:\n";
    cout << "1. Display Bank 1 Account Details\n";
    cout << "2. Display Bank 2 Account Details\n";
    cout << "3. Go back to the main menu\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            displayBank1(tree);
            break;
        }
        case 2: {
            displayBank2(tree);
            break;
        }
        case 3: {
            main_menu(tree); // Pass the tree object to main_menu
            break;
        }
        default: {
            cout << "Invalid choice. Please try again.\n";
            manageBankAccounts(tree); // Recursively call the function to retry
            break;
        }
    }
}

void displayBank1(GroceryStoreTree& tree) {
	system("cls"); 
    char k;
    string BankName1 = "Wells Fargo";
    string Bank1AccountNo = "123456789012";
    string Bank1IFSCCode = "WF123456";
    string Bank1Branch = "Main Street";
    
    cout << "Your bank account details are as follows:-\n\n";
    cout << "Bank Name : " << BankName1 << endl;
    cout << "Bank Account Number : " << Bank1AccountNo << endl;
    cout << "Bank IFSC code : " << Bank1IFSCCode << endl;
    cout << "Bank branch name : " << Bank1Branch << endl << endl;
    cout << "Press M to go back to main menu : ";
    cin >> k;
    if (k == 'M' || k == 'm') {
        main_menu(tree);
    } else {
        cout << "Wrong input !!!" << endl;
    }
}

void displayBank2(GroceryStoreTree& tree) {
	system("cls"); 
    char k;
    string BankName2 = "Bank of America";
    string Bank2AccountNo = "987654321098";
    string Bank2IFSCCode = "BOA654321";
    string Bank2Branch = "Market Street";
    
    cout << "Your bank account details are as follows:-\n\n";
    cout << "Bank Name : " << BankName2 << endl;
    cout << "Bank Account Number : " << Bank2AccountNo << endl;
    cout << "Bank IFSC code : " << Bank2IFSCCode << endl;
    cout << "Bank branch name : " << Bank2Branch << endl << endl;
    cout << "Press M to go back to main menu : ";
    cin >> k;
    if (k == 'M' || k == 'm') {
        main_menu(tree);
    } else {
        cout << "Wrong input !!!" << endl;
    }
}


void aboutTheShop(GroceryStoreTree& tree) {
	  system("cls"); 
    char choice;
   
    cout << "\n\t\t\t\tABOUT OUR SHOP\n";
    cout << "\t\t=========================================================\n";
    cout << "\t\t\t\tWelcome to Our Shop!\n";
    cout << "\t\t\tWe provide a wide range of products to meet your needs.\n";
    cout << "\t\t\t\tOur shop is located at:\n";
    cout << "\t\t\t\tWalmart Grocary Store\n";
    cout << "\t\t\t\t702 SW 8th St\n";
    cout << "\t\t\t\tBentonville, AR 72716\n";
    cout << "\t\t\t\tUnited States of America\n";
    cout << "\t\t\tFor any inquiries, feel free to contact us at:\n";
    cout << "\t\t\t\tPhone: +1 479-273-4900\n";
    cout << "\t\t\t\tEmail: customerservice@walmart.com\n";
    cout << "\t\t=========================================================\n";
    cout << "Press M to go back to the main menu: ";
   
    cin >> choice;
    
    if (choice == 'M' || choice == 'm') {
        main_menu(tree); // Return to the main menu
    } else {
        cout << "Invalid choice!\n";
        aboutTheShop(tree); // Retry if the choice is invalid
    }
}

