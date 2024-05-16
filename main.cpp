#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <algorithm>
#include "Product.h"
#include "User.h"


using namespace std;

map<int, double> discounts;
double totalPrice = 0;
int totalproducts = 0;

RegisteredCustomer::RegisteredCustomer() {
    cout << "\n\t\t\tWelcome to Online Shopping System" << endl;
    cout << "\t\tPlease create an Account to continue Shopping" << endl;
    cout << "Enter Your username: ";
    getline(cin, username);
    cout << "Enter Your Password: ";
    getline(cin, password);
    cout << "Enter a nickname(This will be used to reset password): ";
    getline(cin, nickname);
    cout << "Add some balance to buy products:  ";
    cin >> balance;
    cin.ignore();
}

void RegisteredCustomer::login(string user, string pass) {
    if (username == user && password == pass) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Login failed!" << endl;
    }
}

vector<shared_ptr<Product>> RegisteredCustomer::viewItems(const vector<shared_ptr<Product>>& products) const {
    return products;
}

void RegisteredCustomer::addToCart(shared_ptr<Product> product) {
    // Implementation of adding product to cart
}

void RegisteredCustomer::makePurchase(const vector<shared_ptr<Product>>& cart) {
    // Implementation of making a purchase
}

void RegisteredCustomer::applyDiscount(shared_ptr<Product> product, double discountPercentage) {
    // Implementation of applying discount
}

void RegisteredCustomer::checkout() {
    string checkpass;
trypassagain:
    cout << endl << "Enter your password to confirm Checkout or (Type 0 to return Main Menu): ";
    getline(cin, checkpass);
    if (checkpass == "0") {
        returns = false;
    } else if (checkpass == password) {
        if (balance < totalPrice) {
            cout << "\nInsufficient Balance!!" << endl;
            cout << "Please add balance from (My Account and balance)" << endl << endl;
            returns = false;
        } else {
            balance -= totalPrice;
            cout << "\n\n\t\t-------------------------------------------" << endl;
            cout << "\t\t\t    Purchase Successful !!! " << endl;
            cout << "\t\t     Your current balance is " << balance << " Turkish Lira" << endl;
            cout << "\t\t-------------------------------------------\n\n\n" << endl;
            cout << "\t\t******************************************* ";
            cout << endl << "\t\t* Thank You For shopping with Online Shopping System *" << endl;
            cout << "\t\t*      Hope you Have a lovely day!!!      *" << endl;
            cout << "\t\t*******************************************\n\n\n" << endl;
            returns = true;
        }
    } else {
        cout << endl << "Wrong Password!!! " << endl;
        cout << "If forgot password Please go My Account and Balance to Reset Password " << endl;
        goto trypassagain;
    }
}

void RegisteredCustomer::showBalance() const {
    cout << "\n\t\t\t  Your balance is " << balance << " Turkish Lira" << endl;
    cout << "\t\t-----------------------------------------" << endl;
}

void RegisteredCustomer::addBalance() {
    int extraBalance;
    cout << "Enter amount to add: ";
    cin >> extraBalance;
    balance += extraBalance;
    cout << "\t\t\t " << extraBalance << " Turkish Lira added successfully " << endl;
    cout << "\t\t\tCurrent Balance is " << balance << " Turkish Lira" << endl;
    cout << "\t\t-----------------------------------------" << endl;
}

void RegisteredCustomer::displayUserData() {
attemptagain:
    cout << "Enter Your password: ";
    getline(cin, attempt);
    if (attempt == password) {
        cout << "\n\t\t\tYour UserName is " << username << endl;
        cout << "\t\t\tYour nickname is " << nickname << endl;
        cout << "\t\t\tYour Balance is " << balance << " Turkish Lira" << endl;
        cout << "\t\t-----------------------------------------" << endl;
    } else {
        cout << "Wrong password!!! Try Again!!!" << endl;
        goto attemptagain;
    }
}

void RegisteredCustomer::forgetPassword() {
    string forgetNick;
forgetNickname:
    cout << "Enter your nickname: ";
    getline(cin, forgetNick);
    if (forgetNick == nickname) {
        cout << "Enter your new Password: ";
        getline(cin, password);
        cout << "Password reset Successful....." << endl;
    } else {
        cout << "Wrong Nickname!!! Try Again!!!" << endl;
        goto forgetNickname;
    }
}

// Definitions for Administrator methods

bool Administrator::login() {
    string username, password;
    cout << "Enter Admin Username: ";
    getline(cin, username);
    cout << "Enter Admin Password: ";
    getline(cin, password);
    if (username == adminUsername && password == adminPassword) {
        cout << "Login successful!" << endl;
        return true;
    } else {
        cout << "Login failed!" << endl;
        return false;
    }
}

void Administrator::addItem() {
    int id;
    string name;
    double price;
    string quantity;
    cout << "Enter Product ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Product Name: ";
    getline(cin, name);
    cout << "Enter Product Price: ";
    cin >> price;
    cin.ignore();
    cout << "Enter Product Quantity: ";
    getline(cin, quantity);

    products.push_back(make_shared<GeneralProduct>(id, name, price, quantity));
    cout << "Product added successfully!" << endl;
}

void Administrator::updateItemDetails(int productId, const string& newName, double newPrice, const string& newQuantity) {
    for (auto& product : products) {
        if (product->getId() == productId) {
            product = make_shared<GeneralProduct>(productId, newName, newPrice, newQuantity);
        }
    }
}

void Administrator::deleteProduct() {
    int productId;
    cout << "Enter Product ID to delete: ";
    cin >> productId;
    cin.ignore();
    products.erase(
        remove_if(products.begin(), products.end(), [&](shared_ptr<Product> &p) { return p->getId() == productId; }),
        products.end()
    );
    cout << "Product deleted successfully!" << endl;
}

void Administrator::addUser() {
    RegisteredCustomer newUser;
    users.push_back(newUser);
    cout << "User added successfully!" << endl;
}

void Administrator::viewUsers() const {
    cout << "\n\nList of Users:\n" << endl;
    for (const auto &u : users) {
        cout << "Username: " << u.username << endl;
    }
}

void Administrator::viewProducts() const {
    cout << "\n\nList of Products:\n" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "ID     Name               Price        Quantity" << endl;
    cout << "-----------------------------------------------------------" << endl;
    for (const auto &p : products) {
        p->display();
    }
    cout << "-----------------------------------------------------------" << endl;
}

void Administrator::setDiscountForProducts(int productId, double discountPercentage) {
    if (discountPercentage < 0 || discountPercentage > 100) {
        cout << "Invalid discount percentage! Please enter a value between 0 and 100." << endl;
        return;
    }
    discounts[productId] = discountPercentage;
    cout << "Discount set successfully for product ID: " << productId << endl;
}

// Definitions for Shop methods

void Shop::addCart(string item, int quantity, double price) {
    cartedItems.push_back(item);
    cartedQuantity.push_back(quantity);
    cartedPrice.push_back(price);
    cout << item << " Added to the cart!!!" << endl;
}

void Shop::displayCart() const {
    cout << "\n\nItems in the cart:\n" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Quantity      Name                               Price" << endl;
    cout << "-----------------------------------------------------------" << endl;
    for (size_t i = 0; i < cartedItems.size(); ++i) {
        cout << "  " << cartedQuantity[i];
        cout << "\t     " << cartedItems[i];
        cout << "\t     \t\t" << cartedPrice[i] << " Turkish Lira " << endl;
    }
    cout << endl << "-----------------------------------------------------------" << endl;
    cout << "\tTotal price is: \t\t\t" << totalPrice << " Turkish Lira" << endl;
}

void handleProductChoice(Shop& shop, vector<shared_ptr<Product>>& products) {
    int choice, quantity;
    cout << "Enter a Product ID: ";
    cin >> choice;
    cout << "Enter quantity: ";
    cin >> quantity;

    for (auto &p : products) {
        if (p->getId() == choice) {
            double finalPrice = p->getPrice();
            if (discounts.find(choice) != discounts.end()) {
                cout << "You have a " << discounts[choice] << "% discount for Product " << p->getName() << "." << endl;
                cout << "Do you want to apply the discount? (1 for yes, 2 for no): ";
                int applyDiscount;
                cin >> applyDiscount;
                if (applyDiscount == 1) {
                    double discountedPrice = finalPrice - (finalPrice * discounts[choice] / 100);
                    cout << "Original Price: " << finalPrice << " Turkish Lira" << endl;
                    cout << "Discounted Price: " << discountedPrice << " Turkish Lira" << endl;
                    finalPrice = discountedPrice;
                }
            }
            shop.addCart(p->getName(), quantity, finalPrice * quantity);
            totalPrice += finalPrice * quantity;
            cout << "\nCurrent total is " << totalPrice << " Turkish Lira" << endl;
            cout << "***************************" << endl;
            totalproducts++;
            break;
        }
    }
}
// Definitions for GeneralProduct methods

GeneralProduct::GeneralProduct(int id, string name, double price, string quantity)
    : id(id), name(name), price(price), quantity(quantity) {}

int GeneralProduct::getId() const { return id; }
string GeneralProduct::getName() const { return name; }
double GeneralProduct::getPrice() const { return price; }
string GeneralProduct::getQuantity() const { return quantity; }

void GeneralProduct::display() const {
    cout << "  " << id << "\t     " << name << "\t" << price << " Turkish Lira " << "\t" << quantity << endl;
}

void displayProducts(const vector<shared_ptr<Product>>& products) {
    cout << "-----------------------------------------------------------" << endl;
    cout << "ProductID     Name               Price        Quantity" << endl;
    cout << "-----------------------------------------------------------" << endl;
    for (const auto& p : products) {
        p->display();
    }
    cout << "-----------------------------------------------------------" << endl;
}
int main() {
    vector<shared_ptr<Product>> products;
    Administrator admin;

    while (true) {
        int option = 0;
        cout << "\n\t\t\t     Welcome to EazyMart!!!" << endl;
        cout << "\t\t\t  Are you a customer or an admin?" << endl;
        cout << "1. Customer" << endl;
        cout << "2. Admin" << endl;
        cout << "Enter an option: ";
        cin >> option;
        cin.ignore();

        if (option == 1) {
            RegisteredCustomer user;
            Shop shop;
            while (true) {
                cout << "\n\t\t\t     Welcome to EazyMart!!!" << endl;
                cout << "\t\t\t  What would you like to buy?" << endl << endl;
                cout << "1. View Products" << endl;
                cout << "2. My Account and Balance" << endl;
                cout << "3. Show my carted Products and Checkout" << endl;
                cout << "Enter an option: ";
                cin >> option;
                cin.ignore();

                switch (option) {
                    case 1:
                        displayProducts(products);
                        handleProductChoice(shop, products);
                        break;
                    case 2:
                        int userChoice;
                        cout << endl << "1. Check Balance " << endl;
                        cout << "2. Add More Balance " << endl;
                        cout << "3. Show my all data " << endl;
                        cout << "4. Reset password " << endl;
                        cout << "5. Return to Main Menu " << endl;
                        cin >> userChoice;
                        cin.ignore();
                        if (userChoice == 1)
                            user.showBalance();
                        else if (userChoice == 2)
                            user.addBalance();
                        else if (userChoice == 3)
                            user.displayUserData();
                        else if (userChoice == 4)
                            user.forgetPassword();
                        break;
                    case 3:
                        shop.displayCart();
                        user.checkout();
                        if (!user.returns) continue;
                        else exit(0);
                    default:
                        cout << "Invalid Option!!!" << endl;
                }
            }
        } else if (option == 2) {
            if (!admin.login()) continue;
            while (true) {
                cout << "\n\t\t\tAdmin Panel" << endl;
                cout << "1. Add Product" << endl;
                cout << "2. Delete Product" << endl;
                cout << "3. Add User" << endl;
                cout << "4. View Users" << endl;
                cout << "5. View Products" << endl;
                cout << "6. Set Discount" << endl;
                cout << "7. Return to Main Menu" << endl;
                cout << "Enter an option: ";
                cin >> option;
                cin.ignore();

                if (option == 7) {
                    break; // Exit to main menu
                }

                switch (option) {
                    case 1:
                        admin.addItem();
                        products = admin.products;
                        break;
                    case 2:
                        admin.deleteProduct();
                        products = admin.products;
                        break;
                    case 3:
                        admin.addUser();
                        break;
                    case 4:
                        admin.viewUsers();
                        break;
                    case 5:
                        admin.viewProducts();
                        break;
                    case 6: {
                        int productId;
                        double discountPercentage;
                        cout << "Enter Product ID to set discount: ";
                        cin >> productId;
                        cout << "Enter discount percentage (e.g., 10 for 10%): ";
                        cin >> discountPercentage;
                        admin.setDiscountForProducts(productId, discountPercentage);
                        break;
                    }
                    default:
                        cout << "Invalid Choice!!!" << endl;
                }
            }
        } else {
            cout << "Invalid Option!!!" << endl;
        }
    }

    return 0;
}
