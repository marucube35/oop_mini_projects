#include "Category.h"


int Category::id() { return _id; }
string Category::name() { return _name; }
void Category::setId(int value) { _id = value; }
void Category::setName(string value) { _name = value; }

Category::Category() {
    _id = 0;
    _name = "";
}

Category::Category(int id, string name) {
    _id = id;
    _name = name;
}

string Category::toString() {
    stringstream builder;

    builder << "   ID=" << _id << "; Name=" << _name;

    string result = builder.str();
    return result;
}

vector<shared_ptr<Product>> Category::products() {
    vector<shared_ptr<Product>> result;

    return result;
}

vector<shared_ptr<Category>> Category::getAll() {
    vector<shared_ptr<Category>> result;

    // TODO: Đọc lên từ tập tin
    result.push_back(make_shared<Category>(4, "Tablet"));
    result.push_back(make_shared<Category>(5, "Speaker"));
    result.push_back(make_shared<Category>(6, "VGA"));
    result.push_back(make_shared<Category>(7, "Monitor"));

    return result;
}

vector<shared_ptr<Category>> Category::find(Predicate satisfy, void* args)
{
    vector<shared_ptr<Category>> categories;

    // TODO: Đọc lên từ tập tin
    categories.push_back(make_shared<Category>(4, "Tablet"));
    categories.push_back(make_shared<Category>(5, "Speaker"));
    categories.push_back(make_shared<Category>(6, "VGA"));
    categories.push_back(make_shared<Category>(7, "Monitor"));

    vector<shared_ptr<Category>> result;
    for (shared_ptr<Category> category : categories)
    {
        if (satisfy(category, args))
        {
            result.push_back(category);
        }
    }
	
    return result;
}



