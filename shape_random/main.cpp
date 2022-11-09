
#include <iostream>
#include <vector>
using namespace std;

#include "IShape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "IntegerGenerator.h"
#include "IRandomGenerator.h"

struct {
    int n;
    vector<IShape*> shapes;
} state;

int main()
{
    const int min = 6;
    const int max = 12;
    
    // Config
    vector<IShape*> prototypes = {
      new Rectangle(),
      new Circle(), 
      new Triangle()
    };
    
    state.n = IntegerGenerator::instance()->next(min, max);
    cout << "Will generate " << state.n << " random shape(s)\n";
    
    vector<IShape*> a;
    
    for(int i = 0; i < state.n; i++) {
        int index = IntegerGenerator::instance()->next(prototypes.size());
        auto rng = dynamic_cast<IRandomGenerator*> (prototypes[index]);
        IShape* shape = (IShape*) rng->randomGenerate();
        a.push_back(shape);
    }
    
    for(int i = 0; i < a.size(); i++) {
        cout << a[i]->toString() << endl
            << "     perimeter=" << a[i]->perimeter() 
            << ", area=" << a[i]->area() << endl;
    }

    return 0;
}