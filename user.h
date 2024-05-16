#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "Product.h"

using namespace std;

extern double totalPrice;
extern map<int, double> discounts;
extern int totalproducts;


class RegisteredCustomer {
    string nickname;
    string password;
    double balance = 0;
    string attempt;

public:
    string username;
    bool returns = true;

    RegisteredCustomer();

    void login(string user, string pass);
    vector<shared_ptr<Product>> viewItems(const vector<shared_ptr<Product>>& products) const;
    void addToCart(shared_ptr<Product> product);
    void makePurchase(const vector<shared_ptr<Product>>& cart);
    void applyDiscount(shared_ptr<Product> product, double discountPercentage);
    void checkout();
    void showBalance() const;
    void addBalance();
    void displayUserData();
    void forgetPassword();
};

class Administrator {
    string adminUsername = "admin";
    string adminPassword = "admin123";

public:
    vector<RegisteredCustomer> users;
    vector<shared_ptr<Product>> products;

    bool login();
    void addItem();
    void updateItemDetails(int productId, const string& newName, double newPrice, const string& newQuantity);
    void deleteProduct();
    void addUser();
    void viewUsers() const;
    void viewProducts() const;
    void setDiscountForProducts(int productId, double discountPercentage);
};

class Shop {
    vector<string> cartedItems;
    vector<int> cartedQuantity;
    vector<double> cartedPrice;

public:
    void addCart(string item, int quantity, double price);
    void displayCart() const;
};

void handleProductChoice(Shop& shop, vector<shared_ptr<Product>>& products);

#endif
