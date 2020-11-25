//
// Created by protobit on 22/11/2020.
//

#include "loadIndex.h"

double loadIndex::getVal(double in) {
    if (map.find(in)!=map.end())
        return map[in];
    else {
        auto pair = get_bounds(in);
        double first = map[pair.first];
        double second = map[pair.second];
        return first+in*(second-first); //DOESNT WORK HERE FIXME
    }
}

bool loadIndex::load(const char *filename) {
    _file = filename;
    return reload();
}

bool loadIndex::reload() {
    std::ifstream file(_file);
    std::string line;
    while (getline(file, line)) {
        std::istringstream ss(line);
        double a,b;
        char comma;
        ss >> a >> comma >> b;
        map[a] = b;
    }
    file.close();
}

loadIndex::~loadIndex() {
    ;
}

double loadIndex::lerp(double start, double end, double i) {
    return (1-i)*start + i*end;
}

std::pair<double,double> loadIndex::get_bounds(double in) {
    double key_low = 0.0;
    double key_high = 0.0;
    for (auto i : map) {
        if (in > i.first) {
            key_low = i.first;
        }
        else if (in < i.first) {
            key_high = i.first;
            return std::make_pair(key_low,key_high);
        }
    }
}
