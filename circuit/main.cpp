
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Circuit {
public:
    virtual double r() = 0;
};

class SimpleCircuit: public Circuit {
private:
    double _r;
public:
    double r() {
        return _r;
    }
    
    SimpleCircuit(double r) : _r(r) {}
};

class ComplexCircuit: public Circuit {
protected:
    vector<Circuit*> _subCircuits;
public:
    void add(Circuit* c) {
        _subCircuits.push_back(c);
    }
    
    virtual double r() {
        return 0;
    }
};

class ParallelCircuit: public ComplexCircuit {
public:
    double r() {
        double result = 0;
        
        for(int i = 0; i < _subCircuits.size(); ++i) {
            result += 1 / _subCircuits[i]->r();    
        }
        
        result = 1 / result;
        
        return result;
    }
};

class SequentialCircuit: public ComplexCircuit {
public:
    double r() {
        double result = 0;
        
        for(int i = 0; i < _subCircuits.size(); ++i) {
            result += _subCircuits[i]->r();    
        }
        
        return result;
    }  
};


int main()
{
    ComplexCircuit* final = new SequentialCircuit();
    final->add(new SimpleCircuit(2.4)); // r1
    
    ComplexCircuit* r24 = new ParallelCircuit();
    r24->add(new SimpleCircuit(14)); // r2
    r24->add(new SimpleCircuit(6)); // r4
    
    ComplexCircuit* r35 = new ParallelCircuit();
    r35->add(new SimpleCircuit(4)); // r3
    r35->add(new SimpleCircuit(6)); // r5
    
    final->add(r24);
    final->add(r35);
    
    
    cout << final->r();

    return 0;
}
