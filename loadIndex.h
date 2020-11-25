//
// Created by protobit on 22/11/2020.
//

#ifndef REFRACTOR_LOADINDEX_H
#define REFRACTOR_LOADINDEX_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>

class loadIndex {
    std::map<double,double> map;
    const char* _file;
    static double lerp(double start, double end, double i);
    std::pair<double,double> get_bounds(double in);
public:
    bool load(const char* file);
    bool reload();
    double getVal(double in);
    ~loadIndex();
};


#endif //REFRACTOR_LOADINDEX_H
