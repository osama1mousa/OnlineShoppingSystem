# OnlineShoppingSystem
This is a C++ project implementing a basic online shopping system. It allows users to browse products, add them to a cart, and make purchases. Administrators can manage products, users, and discounts.

# Features
User Authentication:
Customers can create accounts and log in securely.
Administrators have a separate login for managing the system.
Product Catalog:
View a list of available products with details (ID, name, price, quantity).
Search and filter products (not yet implemented in the current code).
Shopping Cart:
Add products to the cart with desired quantities.
View cart contents and the total price.
Apply discounts (if available).
Checkout:
Securely complete purchases with password confirmation.
Account balance is updated after successful purchases.
Admin Panel:
Add, update, and delete products.
Add new users.
View lists of users and products.
Set discounts for specific products.

# Project Structure

main.cpp: The main entry point of the application. Contains the core logic for user interaction, product display, and admin functions.
user.h: Defines classes for RegisteredCustomer, Administrator, and Shop to model user interactions and shopping cart functionality.
product.h: Defines the Product base class and the GeneralProduct derived class to represent products in the system.
Getting Started
Compilation:

Make sure you have a C++ compiler (e.g., g++) installed.
Compile the code using a command like: g++ main.cpp user.cpp product.cpp -o shopping_system (assuming you have user.cpp and product.cpp files for the implementations).
Running:

Execute the compiled binary: ./shopping_system
# Usage
Customer Mode:

Choose option 1 from the main menu.
Follow the prompts to view products, add them to your cart, and checkout.
Admin Mode:

Choose option 2 from the main menu.
Log in with the admin credentials.
Use the admin panel options to manage products, users, and discounts.
Future Enhancements
Improved User Interface: Implement a graphical user interface (GUI) for a more user-friendly experience.
Data Persistence: Store product and user data in a database or file to make it persistent.
Enhanced Security: Implement password hashing for storing user passwords securely.
Advanced Search and Filtering: Add more sophisticated search and filtering options for products.
Order Tracking: Allow customers to track their order status and history.
More Product Types: Introduce different product categories or types (e.g., digital products, subscriptions).
Payment Integration: Integrate with a payment gateway to handle real transactions.


# License
This project is licensed under the MIT License.
