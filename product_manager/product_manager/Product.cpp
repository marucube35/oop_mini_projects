#include "Product.h"
#include <sstream>

int Product::id() { return _id; }
string Product::name() { return _name; }
int Product::price() { return _price; }
weak_ptr<Category> Product::category() { return _category; }

void Product::setId(int value) { _id = value; }
void Product::setName(string value) { _name = value; }
void Product::setPrice(int value) { _price = value; }
void Product::setCategory(weak_ptr<Category> value) { _category = value; }

Product::Product() {
    _id = 0;
    _name = "";
    _price = 0;
}

Product::Product(int id, string name, int price) {
    _id = id;
    _name = name;
    _price = price;
}


string Product::toString() {
    stringstream builder;

    builder << "ID=" << _id << ", Name=" << _name
        << ", Price=" << _price;

    string result = builder.str();
    return result;
}


vector<shared_ptr<Product>> Product::find(Predicate satisfy, void* args) {
    vector<shared_ptr<Product>> a; //Doc tu tap tin
    a.push_back(make_shared<Product>(3, "iPad Air 5 64GB", 17000000));
    a.push_back(make_shared<Product>(4, "iPad Mini 6 128GB", 20000000));
    a.push_back(make_shared<Product>(5, "iPad Pro 11\"64GB", 23000000));
    a.push_back(make_shared<Product>(6, "iPad Pro 12.9\"128GB", 30000000));
    a.push_back(make_shared<Product>(7, "Samsung Pro 12.9\"128GB", 40000000));
    a.push_back(make_shared<Product>(8, "Huawei Pro 12.9\"64GB", 40000000));

    // Loc lai dua tren ham kiem tra
    vector<shared_ptr<Product>> result;

    for (int i = 0; i < a.size(); i++) {
        if (satisfy(a[i], args)) {
            result.push_back(a[i]);
        }
    }

    return result;
}