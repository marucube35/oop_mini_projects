#include <memory>
using namespace std;

class Product;

typedef bool (*Predicate)(shared_ptr<void> item, void* args) ; // void* ===>  object*