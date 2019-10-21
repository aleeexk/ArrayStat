#include "Arraystat.h"

int main() {
    Arraystat ar;
    int n;
    std::cout << "Number of values: ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int buf;
        std::cin >> buf;
        ar.pushArray(buf);
    }

};