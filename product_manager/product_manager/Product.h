#pragma once

#include <string>
#include <memory>
#include <vector>
using namespace std;

#include "Util.h"

class Category; // Forward declaration

class Product {
private:
    int _id;
    string _name;
    int _price;
    weak_ptr<Category> _category;
public:
    int id();
    string name();
    int price();
    weak_ptr<Category> category();

    void setId(int value);
    void setName(string value);
    void setPrice(int value);
    void setCategory(weak_ptr<Category> value);
public:
    Product();
    Product(int id, string name, int price);
    string toString();
    static vector<shared_ptr<Product>> find(Predicate f, void* args);

};