
# Online Shopping System

## Description
This project is an online shopping system that sells PC parts, desktop accessories. It supports a diverse product range including electronics, clothing, and groceries.

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

## Features
- Diverse product categories
- Dynamic discount system
- Tax and shipping calculations
- User-friendly checkout process

  ## Configuration

The Online Shopping System can be customized by modifying certain configuration files and settings. Below are the key files and parameters you may need to adjust:

### product.h
The `product.h` file defines the product structure and related functionalities. You can configure the product attributes and methods as needed.

```cpp
// product.h

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    double price;
    int quantity;

public:
    Product(std::string name, double price, int quantity);
    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;
    void setQuantity(int quantity);
};

#endif // PRODUCT_H


## Contributing
We welcome contributions! Please fork the repository and submit pull requests. Follow the contributing guidelines provided in CONTRIBUTING.md.

### Credits
- Osama Almousa- Developer
- Mohammad Alfath Bnshe - Developer
- Ibrahim Hilvani - Developer

### Contact
- Osama Almousa- (eosama.almousa@std.hku.edu.tr)
- Mohammad Alfath Bnshe - (malfath.bnshe@std.hku.edu.tr)
- Ibrahim Hilvani - (ibrahim.hilvani@std.hku.edu.tr)

# Thank you 💻🤗🛒
