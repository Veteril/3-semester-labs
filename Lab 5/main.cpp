
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class B {
private:
    int id;
protected:
    char nameOfProduct[40];
public:
    B(const char* s1, int i) : id(i) {
        strcpy(nameOfProduct, s1);
    }
    B() { };
    ~B() {};
    void Print() {
        cout << "\n\nName: " << nameOfProduct;
        cout << "\n\nID: " << id;
    }
};

class P1 :virtual  public B {
private:
    char shop[20];
protected:
    int cost;
public:
    P1(int i, const char* s1, const char* s, int j) : B(s1, i) {
        strcpy(shop, s);
        cost = j;
    }
    P1() {};
    ~P1() {};
    void Print()
    {
        cout << "\n\nName: " << nameOfProduct;
        cout << "\n\nShop: " << shop;
        cout << "\n\nCost: " << cost;

    }
};

class P11 : public P1 {
private:
    int shelLife;
protected:
    char production[20];
public:
    P11(int i, const char* s1, const char* s, int j, const char* h, int a) : P1(i, s1, s, j) {
        strcpy(production, h);
        shelLife = a;
    }
    ~P11() {};
    void Print() {
        cout << "\n\nName: " << nameOfProduct;
        cout << "\n\nWhere Producted: " << production;
        cout << "\n\nShelf Life: " << shelLife;
        cout << "\n\nCost: " << cost;

    }
};
class P2 :virtual public B {
private:
    char sort[20];
protected:
    int numberOfProduct;
public:
    P2(int i, const char* s1, const char* s, int j) : B(s1, i) {
        strcpy(sort, s);
        numberOfProduct = j;
    }
    P2() {};
    ~P2() {};
    void Print() {
        cout << "\n\nName: " << nameOfProduct;
        cout << "\n\nSostav: " << sort;
        cout << "\n\nNumber of product: " << numberOfProduct;

    }
};
class P21 : public P2 {
private:
    int dateOfBirth;
protected:
    char deliveryMethod[20];
public:
    P21(int i, const char* s1, const char* s, int j, const char* h, int a) : P2(i, s1, s, j) {
        strcpy(deliveryMethod, h);
        dateOfBirth = a;
    }
    ~P21() {};
    void Print() {
        cout << "\n\nName: " << nameOfProduct;
        cout << "\n\nDelivery Method: " << deliveryMethod;
        cout << "\n\nIt was created: " << dateOfBirth;
        cout << "\n\nNumber of Product: " << numberOfProduct;
    }
};
int CheckInteger(int minValue, int maxValue) {
    int n;
    while (1) {
        cin >> n;
        if (n > maxValue || n < minValue || cin.fail()) {
            cout << "Wrong value, try again...\n";
            cin.clear();
            rewind(stdin);
        }
        else
            return n;
    }
}
class P3 : public P21, public P11
{
private:
    int alreadyBought;
protected:
    char storeDepartment[20];
public:

    P3(int id, const char* name, const char* division, const char* shopName,
        int numberOfProduct, int cost, const char* DeliveryMethod, int serve_remain, const char* producted, int shelfLife,
        int sailed, const char* ski) : B(name, id), P21(id, name, division, numberOfProduct, DeliveryMethod, serve_remain),
        P11(id, name, shopName, cost, producted, shelfLife) {
        strcpy(storeDepartment, ski);
        alreadyBought = sailed;
    }
    ~P3() {};
    void Print() {
        cout << "\n\nName: " << nameOfProduct;
        cout << "\nDelivery Method: " << deliveryMethod;
        cout << "\nNumber of Product: " << numberOfProduct;
        cout << "\nWhere Producted: " << production;
        cout << "\nCost: " << cost;
        cout << "\nAlready sailed: " << alreadyBought;
        cout << "\nStore Department : " << storeDepartment << endl << endl;
    }

    void SetValue () {
        char *name, *division,  *shopName, *DeliveryMethod, *producted , *ski;
        int numberOfProduct, cost, serve_remain, shelfLife;
        int sailed;
        name = new char(40);
        DeliveryMethod = new char(40);
        producted = new char(40);
        ski = new char(40);
        cout << "Name : ";
        cin >> nameOfProduct;
        cout << "Delivery : ";
        cin >> deliveryMethod;
        cout << "Number : ";
        this->numberOfProduct = CheckInteger(0, 10000);
        cout << "Where created : ";
        cin >> production;
        cout << "Cost : ";
        this->cost = CheckInteger(0, 10000);
        cout << "Already bought : ";
        alreadyBought = CheckInteger(0, 10000);
        cout << "Store Department : ";
        cin >> storeDepartment;
    }
};

int menu() {
    cout << "\n1. Print" << endl;
    cout << "2. Set Value" << endl;
    cout << "3. Quit" << endl;
    int n = CheckInteger(1,3);
    return n;
}

int main() {
    P3 a(1, "Milk", "net", "Milk Factory №3", 200, 3,
        "Truck", 0, "Milk Factory", 3, 20, "Dairy Department");
    while (1) {
        switch (menu()) {
        case 1:
            a.Print();
            a.B::Print();
            break;
        case 2:
            a.SetValue();
            break;
        case 3:
            return 0;
        }
    }
}// ввод с клавивтцры protected,редактирование
