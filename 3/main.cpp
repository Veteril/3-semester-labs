#include <iostream>
using namespace std;
class Decimal;
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
    cout << "\n1. ++Operator" << endl;
    cout << "2. Operator=" << endl;
    cout << "3. Operator+" << endl;
    cout << "4. Operator==" << endl;
    cout << "5. Friend function operator--" << endl;
    cout << "6. Friend function operator-" << endl;
    cout << "7. Friend function operator<<" << endl;
    cout << "8. Quit program" << endl;
    cout << "9. Extra task9" << endl;
    cout << "Enter the number :";
    int n = CheckInteger(1,9);
    return n;
}
class Decimal {
private:
    unsigned int value;
public:
    Decimal (unsigned int a) : value(a) {}
    Decimal() : value(0) {}
    unsigned int GetValue() {
        return value;
    }
    void Print() {
        cout << "value = " << value << endl;
    }
    Decimal operator++(){
        ++value;
        return Decimal(value);
    }
    Decimal operator++(int) {
        return Decimal(value++);
    }
    Decimal operator+(const Decimal x){
        Decimal temp;
        temp = value + x.value;
        return temp;
    }
    Decimal operator=(const Decimal x)
    {
        value = x.value;
        return Decimal(value);
    }
    bool operator==(const Decimal x){
        return (value == x.value) ? true : false;
    }
    operator unsigned int() {
        return value;
    }
    friend Decimal operator--(Decimal& x);
    friend Decimal operator-(Decimal& x, char a);
    friend ostream& operator<<(ostream &out,Decimal x);
};
Decimal operator--(Decimal& x) {
    x.value--;
    return x;
}
Decimal operator-(Decimal& x, char a) {
    x.value -= a;
    return x;
}
ostream& operator<<(ostream &out,Decimal x) {
    out << "\nClass Decimal, value = " << x.value << endl;
}


int main() {
    Decimal c1(25), c2(50);
    cout << "value = 0" << endl;
    while(1) {
        unsigned int n;
        switch(menu()) {
            case 1:
                ++c1;
                c1.Print();
                break;
            case 2:
                c1 = c2;
                c1.Print();
                break;
            case 3:
                c1 = c1 + c2;
                c1.Print();
                break;
            case 4:
                if (c1 == c2) {
                    cout << "Values are equal" << endl;
                }
                break;
            case 5:
                --c1;
                c1.Print();
                break;
            case 6:
                char a;
                cout << "Enter the symbol : ";
                cin >> a;
                c1 - a;
                c1.Print();
                break;
            case 7:
                cout << c1;
                break;
            case 8:
                return 0;
            case 9:
                Decimal c(0);
                cout << "c : " << c << "\na : " << c1 << "\nb : " << c2;
                c = ++c1 + c2++;
                cout << "c : " << c << "\na : " << c1 << "\nb : " << c2;
        }
    }
}
