//
// Created by Veter on 15.11.2021.
//

#include "List.h"
#include <iostream>
void List::add() {
    cout << "Enter new Element : ";
    element* item = new element();
    int data;
    try {
        std::cin >> data;
        if (cin.fail()) { throw errorClass("Incorrect Value..."); }
    }
    catch(errorClass a) {
        cout << a.message << endl;
        data = a.checkInteger(data);
    }
    item->information = data;
    if (!begin) {
        begin = item;
        tale = item;
    }
    else {
        element *temp = begin;
        while (temp->pointer) {
            temp = temp->pointer;
        }
        temp->pointer = item;
        tale = item;
    }
}

void List::show() {
    if (!begin) {
        throw errorClass("Nothing to Show");
    }
    int n;
    cout << "\n1. Show Diaposone" << endl;
    cout << "2. Show all" << endl;
    try {
        cin >> n;
        if (cin.fail() || n < 1 || n > 2) {
            throw errorClass("Invalid Value...", 1, 2);
        }
    }
    catch(errorClass a) {
        cout << a.message << endl;
        n = a.checkInteger(n);
    }
    if(n == 1) {
        n = 0;
        element *check = begin;
        while(check) {
            n++;
            check = check->pointer;
        }
        cout << "\nEnter the diaposone : ";
        int minValue, maxValue;
        cin >> minValue; cin >> maxValue;
        check = begin; int counter = 1;
        while(counter != minValue) {
            check = check->pointer;
            counter++;
        }
        while(counter != maxValue + 1) {
            std::cout << "Element " << counter << " : " << check->information << std::endl;
            check = check->pointer;
            counter++;
        }
    }
    else {
        element *temp = begin;
        int counter = 1;
        while (temp) {
            std::cout << "Element " << counter << " : " << temp->information << std::endl;
            temp = temp->pointer;
            counter++;
        }
    }
}

void List::deleteElement() {
    if (!begin) {
        throw errorClass("Nothing to Delete");
    }
    else {
        if (tale == begin) {
            tale = NULL;
            begin = NULL;
            return;
        }
        element *current = begin;
        while (current->pointer->pointer) {
            current = current->pointer;
        }
        tale = current;
        current->pointer = NULL;
    }
}

void List::search(int n) {
    element* current = begin;
    int counter = 1;
    while (current) {
        if (current->information == n) {
            std :: cout << "Element " << counter << " : " << current->information << std :: endl;
        }
        counter++;
        current = current->pointer;
    }
}

void List::sort() {

    int counter = 0;
    element *check = begin;
    while(check) {
        counter++;
        check = check->pointer;
    }

    for (int i = 0; i < counter - 1; ++i) {
        element *firstTemp, *secondTemp;
        int temp;
        firstTemp = begin;
        secondTemp = begin->pointer;
        for (int j = 0; j < counter - i - 1; ++j) {
            if (firstTemp->information > secondTemp->information) {
                temp = firstTemp->information;
                firstTemp->information = secondTemp->information;
                secondTemp->information = temp;
            }
            if (secondTemp->pointer) {
                firstTemp = firstTemp->pointer;
                secondTemp = secondTemp->pointer;
            }
            else break;
        }
    }
}


