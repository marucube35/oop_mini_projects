#pragma once

class IConverter {
public:
    virtual string convert(void* shape) = 0;
};