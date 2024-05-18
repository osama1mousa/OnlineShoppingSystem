# Online Shopping System

## Description
This project is an online shopping system that sells PC parts and desktop accessories. It supports a diverse product range including electronics, clothing, and groceries. The system is implemented in C++ and comprises multiple classes that handle various functionalities of the system. These include customer management, product management, shopping cart operations, and administrative tasks. The system provides a console-based interface for interaction, making it straightforward to use for both customers and administrators.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Configuration](#configuration)
- [Contributing](#contributing)
- [Credits](#credits)
- [Contact](#contact)

## Installation
### Prerequisites
- C++ compiler (e.g., GCC, Clang)
- Git (optional, for cloning the repository)

### Steps
1. Clone the repository:
    ```bash
    git clone https://github.com/online-shopping-system-cpp/OnlineShoppingSystem
    ```
2. Navigate to the project directory:
    ```bash
    cd OnlineShoppingSystem
    ```
3. Compile the project:
    ```bash
    g++ -o OnlineShoppingSystem main.cpp
    ```

## Usage
Run the compiled executable:
```bash
./OnlineShoppingSystem
```

## Features
- **User Registration and Login:**
  - Customers can create an account with a username, password, nickname, and initial balance.
  - Secure login functionality.

- **Product Management:**
  - Administrators can add, update, and delete products.
  - Products have attributes like ID, name, price, and quantity.

- **Discount Management:**
  - Administrators can set discounts on products.
  - Customers can view and apply available discounts during purchase.

- **Shopping Cart:**
  - Customers can add products to their cart.
  - The cart displays the items, their quantities, and the total price.
  - Checkout functionality processes the purchase and updates the customer’s balance.

- **Balance Management:**
  - Customers can check and add to their balance.

- **Account Management:**
  - Customers can view and update their account details.
  - Password reset functionality using a nickname.

- **Administrative Functions:**
  - Administrators can view all registered customers and products.
  - Ability to set discounts on products.

## Configuration
The system can be configured by modifying the following files:

- **main.cpp: Contains the main program logic.**
- **Product.h and Product.cpp: Define the Product class and its functionalities.**
- **User.h and User.cpp: Define the User class (including Customer and Administrator) and their functionalities.**

## Credits
- **Osama Almousa - Developer**
- **Mohammad Alfath Bnshe - Developer**
- **Ibrahim Hilvani - Developer**

## Contact
- **Osama Almousa:** osama.almousa@std.hku.edu.tr
- **Mohammad Alfath Bnshe:** malfath.bnshe@std.hku.edu.tr
- **Ibrahim Hilvani:** ibrahim.hilvani@std.hku.edu.tr

# Thank you ✨✨
