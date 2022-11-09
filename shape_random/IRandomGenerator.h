#pragma once

class IRandomGenerator {
public:
    virtual void* randomGenerate() = 0;
};