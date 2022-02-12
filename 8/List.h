//
// Created by Veter on 15.11.2021.
//

#ifndef INC_8_LIST_H
#define INC_8_LIST_H
#include <iostream>
using namespace std;
struct element {
    element* pointer;
    int information;
};
class errorClass {
public :
    errorClass(){}
    errorClass(char* error, int minValue = -10000, int maxValue = 10000) : message(error), minValue(minValue), maxValue(maxValue){}
    ~errorClass(){}
    int checkInteger(int n) {
        while(1) {
            cin.clear();
            rewind(stdin);
            cin >> n;
            if (cin.fail() || n < minValue || n > maxValue) {}
            else {return n;}
        }
    }
    int minValue;
    int maxValue;
    char* message;
};
class List {
private:
    element* begin;
    element* tale;
public:
    List() : begin(NULL), tale(NULL) {}
    void add();
    void show();
    void deleteElement();
    void search(int n);
    void sort();
};


#endif //INC_8_LIST_H