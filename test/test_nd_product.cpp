#include <iostream>

#include <nd_product.h>

int main (int argc, char* argv[]) {
    vector<int> a;
    vector<int> b;
    a.push_back(4);
    a.push_back(2);
    a.push_back(7);
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    a.push_back(6);
    a.push_back(2);
    a.push_back(8);
    a.push_back(9);
    cout << "[main] vector A (";
    for(unsigned int i = 0; i < a.size(); i++) {
        if(i > 0)
            cout << ", ";
        cout << a[i];
    }
    cout << ")" << endl;
    b.push_back(3);
    b.push_back(5);
    b.push_back(2);
    b.push_back(1);
    b.push_back(7);
    b.push_back(6);
    b.push_back(9);
    b.push_back(2);
    b.push_back(1);
    b.push_back(3);
    cout << "[main] vector B (";
    for(unsigned int i = 0; i < b.size(); i++) {
        if(i > 0)
            cout << ", ";
        cout << b[i];
    }
    cout << ")" << endl;

    NdProduct* ndProd = new NdProduct(false);
    int sum = ndProd->dotProduct(a, b);
    cout << "[main] sum dot product ["<< sum <<"]" << endl;

    delete ndProd;

    return 0;
}
