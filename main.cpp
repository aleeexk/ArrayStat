#include "Arraystat.h"

int main() {
    Arraystat ar;
    int n;
    cout << "Number of values: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int buf;
        cin >> buf;
        ar.pushArray(buf);
    }

};