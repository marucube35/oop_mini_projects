#pragma once
#include <string>
using namespace std;

class IShape {
public:
    virtual string toString() = 0;
    virtual IShape* generate(int, int) = 0;
    virtual string className() = 0;
    
};