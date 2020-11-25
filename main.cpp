#include <iostream>
#include "loadIndex.h"

long double d2r(long double in) {
    return in * (M_PIl)/180;
}

long double r2d(long double in) {
    return in * 180/(M_PIl);
}

int main() {
    loadIndex indexr{};
    indexr.load("indextest.ind");
    double wavelength;
    double angle;
    std::cout << "What is the wavelength of light?\n> ";
    std::cin >> wavelength;
    std::cout << "What is the angle of entry for the light?\n> ";
    std::cin >> angle;
    std::cout << r2d(asin(d2r(r2d(sin(d2r(angle)))/indexr.getVal(wavelength))));
    return 0;
}
