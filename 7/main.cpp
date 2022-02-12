#include <iostream>
#include <cstring>
using namespace std;

int CheckInteger(int minValue,int maxValue);
template <class Field>
class Order {
private:
    Field * pointer;
    Field * tale;
    int size;
public:
    Order() : pointer(NULL), tale(NULL),size(0) {}
    ~Order() {delete [] pointer;}
    void addField() {
        Field add;
        cout << "Enter Element :" << endl;
        cin >> add;
        Field * temp = new Field[size];
        for (int i = 0; i < size; ++i) {
            temp[i] = pointer[i];
        }
        size++;
        pointer = new Field[size];
        tale = &pointer[size - 1];
        for (int i = 0; i < size - 1; ++i) {
            pointer[i] = temp[i];
        }
        pointer[size - 1] = add;
    }
    void showArr() {
        if (pointer == NULL) {
            cout << "There nothing to watch..." << endl;
            return;
        }
        for (int i = 0; i < size; ++i) {
            cout << "\n Element " << i + 1 << " = " << pointer[i] << endl;
        }
    }
    void sort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - 1; ++j) {
                if (pointer[j] > pointer[j+1]) {
                    Field temp;
                    temp = pointer[j];
                    pointer[j] = pointer[j+1];
                    pointer[j+1] = temp;
                }
            }
        }
        tale = &pointer[size - 1];
    }
    void addMajority() {
        int n;
        cout << "Enter number of elements in majority : ";
        n = CheckInteger(1, size);
        cout << "\nEnter Majority : ";
        Field* major = new Field[n];
        for (int i = 0; i < n; ++i) {
            cin >> major[i];
        }
        int counter = 0;
        for (int i = 0; i < size; ++i) {
            if (major[counter] == pointer[i]) {
                counter++;
                if (counter == n)
                    break;
            }
            else {
                counter = 0;
            }
        }
        if (counter == n) {
            Field * temp = new Field[size];
            for (int i = 0; i < size; ++i) {
                temp[i] = pointer[i];
            }
            size+= n;
            pointer = new Field[size];
            tale = &pointer[size - 1];
            for (int i = 0; i < size - n; ++i) {
                pointer[i] = temp[i];
            }
            counter = 0;
            for (int i = size - n; i < size; ++i) {
                pointer[i] = major[counter];
                counter++;
            }
            return;
        }
        else{
            cout << "\nMajority not found" << endl;
            return;
        }
    }
    void DeleteDuplicates() {
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (pointer[i] == pointer[j]) {
                    Field * temp = new Field[size];
                    int counter = 0, flag = -1;
                    for (int l = 0; l < size; ++l) {
                        if (pointer[l] == pointer[i]) {
                            if (flag == -1) {
                                flag++;
                                temp[counter] = pointer[l];
                                counter++;
                                continue;
                            }
                            else
                                flag ++;
                        }
                        else {
                            temp[counter] = pointer[l];
                            counter++;
                        }
                    }
                    size -= flag;
                    pointer = new Field[size];
                    for (int k = 0; k < size; ++k) {
                        pointer[k] = temp[k];
                    }
                    tale = &pointer[size - 1];
                    break;
                }
            }
        }
    }
};

template<>
class Order<char*> {
private :
    int size;
    char* pointer;
    char* tale;
public :
    Order() : pointer(NULL), tale(NULL),size(0) {}
    ~Order() {delete [] pointer;}
    void addField() {
        cout << "Enter Element :" << endl;
        char a; cin >> a;
        char* temp = new char[size];
        for (int i = 0; i < size; ++i) {
            temp[i] = pointer[i];
        }
        size++;
        pointer = new char[size];
        tale = &pointer[size - 1];
        for (int i = 0; i < size - 1; ++i) {
            pointer[i] = temp[i];
        }
        pointer[size - 1] = a;
    }
    void showArr() {
        if (pointer == NULL) {
            cout << "There nothing to watch..." << endl;
            return;
        }
        for (int i = 0; i < size; ++i) {
            cout << "\n Element " << i + 1 << " = " << pointer[i] << endl;
        }
    }
    void sort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - 1; ++j) {
                if (pointer[j] > pointer[j+1]) {
                    char temp;
                    temp = pointer[j];
                    pointer[j] = pointer[j+1];
                    pointer[j+1] = temp;
                }
            }
        }
        tale = &pointer[size - 1];
    }
};


int CheckInteger(int minValue,int maxValue) {
    int n;
    while (true) {
        cin >> n;
        if (cin.fail() || n < minValue || n > maxValue) {
            cout << "Wrong Value, try again...";
            cin.clear();
            rewind(stdin);
        }
        else
            return n;
    }
}

int menu () {
    int n;
    cout << "\n1. Add Element\n";
    cout << "2. Show Elements\n";
    cout << "3. Sort Elements\n";
    cout << "4. Add Majority\n";
    cout << "5. Delete Duplicates\n";
    cout << "6. Quit Program\n";
    n = CheckInteger(1,6);
    return n;
}

int main() {
    Order <int> obj;
    Order <char*> obj1;
    int n;
    while (true) {
        switch(menu()) {
            case 1:
                cout << "\n1. First class" << endl;
                cout << "\n2. Char* class" << endl;
                n = CheckInteger(1,2);
                if (n == 1)
                    obj.addField();
                else
                    obj1.addField();
                break;
            case 2:
                cout << "\n1. First class" << endl;
                cout << "\n2. Char* class" << endl;
                n = CheckInteger(1,2);
                if (n == 1)
                    obj.showArr();
                else
                    obj1.showArr();
                break;
            case 3:
                cout << "\n1. First class" << endl;
                cout << "\n2. Char* class" << endl;
                n = CheckInteger(1,2);
                if (n == 1)
                    obj.sort();
                else
                    obj1.sort();
                break;
            case 4:
                obj.addMajority();
                break;
            case 5:
                obj.DeleteDuplicates();
                break;
            case 6:
                return 0;
        }
    }
}//копирование множества, УДАЛЕНИЕ ДУБЛИКАТОВ
