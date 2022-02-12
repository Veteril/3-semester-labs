#include <iostream>
#include <string>
using namespace std;
class Task;
class CheckTask;
int CheckInteger(int minValue,int maxValue) {
    int n;
    while(1) {
        cin >> n;
        if(n > maxValue || n < minValue || cin.fail()) {
            cout << "Wrong value, try again...\n";
            cin.clear();
            rewind(stdin);
        }
        else
            return n;
    }
}
int menu(){
    cout << "\n1. Set values in class" << endl;
    cout << "2. Show array" << endl;
    cout << "3. Quit program" << endl << endl;
    cout << "Enter the number :";
    int n = CheckInteger(1,3);
    return n;
}


class Task {
private:
    int id;
    int result;
    string name;

public:
    static int ID;
    Task(string name) : name(name), result(0), id(ID) {
        ID++;
    }
    Task() : name("Task"), result(0), id(ID) {
        ID++;
    }
    ~Task() {
        cout << "Destructor 'Task' activated" << endl;
    }
    void SetName() {
        string value;
        cout << "Enter the name of " << this->id << " class :";
        cin >> value;
        name = value;
        cout << endl;
    }
    void Print() {
        cout << "\t"  << name << "\tid " << id << "\tTask completed : " << result << "%\n\n";
    }
    friend class CheckTask;

};
int Task::ID = 1;
class CheckTask {
public:
    ~CheckTask(){
        cout << "Destructor 'CheckTask' activated" << endl;
    }
    void check(Task& value) {
        cout << "Enter the result :";
        value.result = CheckInteger(0,100);
    }
};
void Show(int size , Task chain[]) {
    cout << "\n1. Show all elements" << endl;
    cout << "2. Show range" << endl << endl;
    cout << "Enter the value :";
    int n = CheckInteger(1,2);
    cout << endl;
    if(n == 1) {
        for (int i = 0; i < size; ++i) {
            chain[i].Print();
        }
    }
    else {
        int x,y;
        cout << "Input id range(From x to y)\n" << "From : ";
        x = CheckInteger(1,size); cout << "To : ";
        y = CheckInteger(x,size);
        cout << endl;
        for (int i = x - 1; i < y; ++i) {
            chain[i].Print();
        }
    }
}
void SetValues(int size,Task* chain) {
    while(true) {
        cout << "\n1. Change name" << endl;
        cout << "2. Set result" << endl << endl;
        cout << "Enter the value :";
        switch (CheckInteger(1, 2)) {
            case 1:
                cout << "\n1. Change all names" << endl;
                cout << "2. Change in a range" << endl << endl;
                if (CheckInteger(1, 2) == 1) {
                    for (int i = 0; i < size; ++i) {
                        chain[i].SetName();
                    }
                } else {
                    int x, y;
                    cout << "Input id range(From x to y)\n" << "From : ";
                    x = CheckInteger(1, size);
                    cout << "To : ";
                    y = CheckInteger(x, size);
                    cout << endl;
                    for (int i = x - 1; i < y; ++i) {
                        chain[i].SetName();
                    }
                }
                break;
            case 2:
                cout << "\n1. Change all results" << endl;
                cout << "2. Change in a range" << endl << endl;
                if (CheckInteger(1, 2) == 1) {
                    CheckTask a;
                    for (int i = 0; i < size; ++i) {
                        a.check(chain[i]);
                    }
                } else {
                    int x, y;
                    cout << "Input id range(From x to y)\n" << "From : ";
                    x = CheckInteger(1, size);
                    cout << "To : ";
                    y = CheckInteger(x, size);
                    cout << endl;
                    CheckTask a;
                    for (int i = x - 1; i < y; ++i) {
                        a.check(chain[i]);
                    }
                }
        }
        cout << "Do you want to change something else ?";
        cout << "\n1. Yes" << endl;
        cout << "2. No" << endl << endl;
        cout << "Enter the value :";
        if (CheckInteger(1, 2) == 2)
            break;
    }
}
int main() {
    int arraySize;
    cout << "Enter the size of array : ";
    cin >> arraySize;
    Task chain[arraySize];
    while(1) {
        switch(menu()) {
            case 1:
                SetValues(arraySize,chain);
                break;
            case 2:
                Show(arraySize,chain);
                break;
            case 3:
                return 0;
        }
    }
}

