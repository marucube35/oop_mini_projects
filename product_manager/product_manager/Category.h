#pragma once
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "Util.h"
using namespace std;

class Product; // Forward declaration

class Category {
private:
    int _id;
    string _name;
public:

public:
    int id();
    string name();
    void setId(int value);
    void setName(string value);
    vector<shared_ptr<Product>> products();

public:
    Category();
    Category(int id, string name);
    string toString();
public:
    static vector<shared_ptr<Category>> getAll();
    static vector<shared_ptr<Category>> find(Predicate f, void* args);
};