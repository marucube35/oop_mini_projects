#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <sstream>
#include <map>
#include <fstream>
using namespace std;

#include "IShape.h"
#include "IConverter.h"
#include "RandomIntegerGenerator.h"
#include "RandomRectangleGenerator.h"
#include "RandomCircleGenerator.h"
#include "RandomTriangleGenerator.h"
#include "RectangleUIConverter.h"
#include "CircleUIConverter.h"
#include "TriangleUIConverter.h"
#include "CircleDataConverter.h"
#include "RectangleDataConverter.h"
#include "TriangleDataConverter.h"

#define OUTPUT "Shapes.txt"
struct {
    vector<IShape*> shapes;
} state; 

tuple<bool, int, string, int> getInteger(int left, int right); 


class ShapeFactory {
private:
    static inline ShapeFactory* _instance = NULL;
    vector<IShape*> _prototypes;
    
    ShapeFactory() { // Cau hinh 1 lan duy nhat
        _prototypes.push_back(new Rectangle());
        _prototypes.push_back(new Circle());
        _prototypes.push_back(new Triangle());
    }
    
public:
    int suportedTypesCount() {
        return _prototypes.size();
    }
    
    IShape* create(int type) {
        const int left = 6;
        const int right = 12;
        IShape* shape = _prototypes[type]->generate(left, right);
        
        return shape;
    }
    
    static ShapeFactory* instance() {
        if (_instance == NULL) {
            _instance = new ShapeFactory();
        }
        
        return _instance;
    }
};

int main()
{
    // 1. Sinh ngau nhien so nguyen n trong khoang [6, 12]
    const int left = 6;
    const int right = 12;
    int n = RandomIntegerGenerator::instance()->next(left, right);

    // 2. Sinh ra n hinh
    for(int i = 0; i < n; i++) {
        int count = ShapeFactory::instance()->suportedTypesCount();
        int type = RandomIntegerGenerator::instance()->next(count);
        IShape* shape = ShapeFactory::instance()->create(type);
        state.shapes.push_back(shape);
    }
    
    // Cau hinh
    map<string, IConverter*> ui = {
        {(new Rectangle())->className(), new RectangleUIConverter() },
        {(new Circle())->className(), new CircleUIConverter() },
        {(new Triangle())->className(), new TriangleUIConverter() }
    };

    map<string, IConverter*> data = {
        {(new Rectangle())->className(), new RectangleDataConverter() },
        {(new Circle())->className(), new CircleDataConverter() },
        {(new Triangle())->className(), new TriangleDataConverter() }
    };
    
    fstream output(OUTPUT, ios::app);
    if (!output) cout << "Output file is not found!\n";
	
    for(int i = 0; i < n; i++) {
        auto uiConverter = ui[state.shapes[i]->className()];
        auto dataConverter = data[state.shapes[i]->className()];
        string uiData = uiConverter->convert((void*) state.shapes[i]);
        string fileData = dataConverter->convert((void*)state.shapes[i]);
        
        cout << uiData << endl;
        
        if (output)
            output << fileData << endl;
    }

    output.close();
	
    cout << n;
    return 0;
}