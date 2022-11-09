#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include <fstream>
#include <regex>
#include <string>
using namespace std;

#include "Product.h"
#include "Category.h"

class Choice {
public:
    static const int quit = 0;
    static const int displayAllCategories = 1;
    static const int findProductByName = 2;
    static const int findProductByPriceRange = 3;
    static const int findCategoryByName = 4;
};

void displayMenu() {
    cout << "What do you want to do?" << endl;
    cout << "1. Display all categories" << endl;
    cout << "2. Find products by name" << endl;
    cout << "3. Find products by price range" << endl;
    cout << "4. Find categories by name" << endl;
    cout << endl;
    cout << "0. Quit" << endl;

    cout << "Please enter your choice: ";
}

tuple<bool, int, string, int> getChoice() {
    const string choicePattern = "[01234]";
    bool success = true;
    int errorCode = 0;
    string message = "";
    int choice = 0;

    string buffer;
    getline(cin, buffer);

    if (buffer.length() == 0) {
        success = false;
        errorCode = 1;
        message = "Input string cannot be empty.";
    }
    else {
        bool isValid = regex_match(buffer, regex(choicePattern));

        if (isValid) {
            success = true;
            choice = stoi(buffer);
        }
        else {
            success = false;
            errorCode = 2;
            message = "Invalid format.";
        }
    }

    auto result = make_tuple(success, errorCode, message, choice);
    return result;
}

bool productNameShouldContains(shared_ptr<void> item, void* args) {
    auto product = static_pointer_cast<Product>(item);
    auto keyword = *((string*)args); // void* -> string* --> string

    bool found = product->name().find(keyword) != string::npos;

    return found;
}

void findProductByName() {
    string keyword;
    bool shouldRepeat = false;

    do {
        cout << "Nhap tu khoa de tim kiem: ";
        getline(cin, keyword);

        if (keyword.length() == 0) {
            cout << "Tu khoa khong duoc de trong." << endl << endl;
            shouldRepeat = true;
        }
        else {
            auto products = Product::find(productNameShouldContains, (void*)&keyword);

            cout << "Found " << products.size() << " product(s)." << endl;
            for (int i = 0; i < products.size(); i++) {
                cout << "   " << products[i]->toString() << endl;
            };

            cout << endl;
            cin.get();

            shouldRepeat = false;
        }
    } while (shouldRepeat);

}

bool priceShouldBeIn(shared_ptr<void> item, void* args) { // object
    int min;
    int max;
    tie(min, max) = *((tuple<int, int>*) args);
	auto product = static_pointer_cast<Product>(item);

    bool result = product->price() >= min && product->price() <= max;

    return result;
}

void findProductByPriceRange() {
    int min = 20000000;
    int max = 30000000;
    tuple<int, int> range = make_tuple(min, max);

    auto products = Product::find(priceShouldBeIn, (void*)&range);

    cout << "Found " << products.size() << " product(s)." << endl;
    for (int i = 0; i < products.size(); i++) {
        cout << "   " << products[i]->toString() << endl;
    };

    cout << endl;
    cin.get();
}

bool categoryNameShouldContains(shared_ptr<void> item, void* args) {
    auto category = static_pointer_cast<Category>(item);
    auto keyword = *((string*)args); // void* -> string* --> string

    bool found = category->name().find(keyword) != string::npos;

    return found;
}

void findCategoryByName() {
    string keyword;
    bool shouldRepeat = false;

    do {
        cout << "Nhap tu khoa de tim kiem: ";
        getline(cin, keyword);

        if (keyword.length() == 0) {
            cout << "Tu khoa khong duoc de trong." << endl << endl;
            shouldRepeat = true;
        }
        else {
            auto categories = Category::find(categoryNameShouldContains, (void*)&keyword);

            cout << "Found " << categories.size() << " category(s)." << endl;
            for (int i = 0; i < categories.size(); i++) {
                cout << "   " << categories[i]->toString() << endl;
            };

            cout << endl;
            cin.get();

            shouldRepeat = false;
        }
    } while (shouldRepeat);

}

struct {
    vector<shared_ptr<Category>> categories;
} state;

int main()
{
    bool shouldContinue = true;

    bool success = true;
    int errorCode = 0;
    string message = "";
    int choice = 0;

    do {
        displayMenu();

        tie(success, errorCode, message, choice) = getChoice();

        if (success) {
            if (Choice::quit == choice) {
                shouldContinue = false;
            }
            else if (Choice::displayAllCategories == choice) {
                state.categories = Category::getAll();
                cout << endl;
                cout << "Found " << state.categories.size() << " category(s)." << endl;

                for (int i = 0; i < state.categories.size(); i++) {
                    cout << state.categories[i]->toString() << endl;
                }

                cin.get();

                shouldContinue = true;
            }
            else if (Choice::findProductByName == choice) {
                findProductByName();
                shouldContinue = true;
            }
            else if (Choice::findProductByPriceRange == choice) {
                findProductByPriceRange();
                shouldContinue = true;
            }            
            else if (Choice::findCategoryByName == choice) {
                findCategoryByName();
                shouldContinue = true;
            }
        }
        else {
            cout << endl << message << endl;
            cout << "--------------------------";
            cout << endl << endl;
            shouldContinue = true;
        }
    } while (shouldContinue);

    return 0;
}