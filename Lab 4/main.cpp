#include <iostream>
using namespace std;
class Complex;
class Value {
private :
    int a;
    int i;
public :
    Value() : a(0), i(0){}
    friend istream& operator >>(istream& in, Complex &X);
    friend class Complex;
    friend ostream& operator <<(ostream& out, Value X){
        cout << "Complex value = " << X.a << "+"<< X.i << "i" << endl;
        return out;
    }
    friend void SortArray(Complex* ARR, int size);
    friend int SumOfElements(Complex a, int value);
    void* operator new(size_t);
    void* operator new[](size_t);
    void operator delete(void* ptr);
    void operator delete[](void* ptr);
};
class Complex {
private :
    int size[3];
    Value*** arr;
public:
    Complex() {
        arr = NULL;
        for (int i = 0; i < 3; ++i) {
            size[i] = 0;
        }
    }
    Complex(const Complex& temp)  {
        this->arr = new Value**[temp.size[0]];
        for (int i = 0; i < temp.size[0]; ++i) {
            this->arr[i] = new Value*[temp.size[1]];
        }
        for (int i = 0; i < temp.size[0]; ++i) {
            for (int j = 0; j < temp.size[1]; ++j) {
                this->arr[i][j] = new Value[temp.size[2]];
            }
        }
        this->size[0] = temp.size[0];
        this->size[1] = temp.size[1];
        this->size[2] = temp.size[2];
        for (int i = 0; i < size[0]; ++i) {
            for (int j = 0; j < size[1]; ++j) {
                for (int k = 0; k < size[2]; ++k) {
                    this->arr[i][j][k].a = temp.arr[i][j][k].a;
                    this->arr[i][j][k].i = temp.arr[i][j][k].i;
                }
            }
        }
    }
    Complex(int a, int b, int c)  {
        arr = new Value**[a];
        for (int i = 0; i < a; ++i) {
            arr[i] = new Value*[b];
        }
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                arr[i][j] = new Value[c];
            }
        }
        size[0] = a;
        size[1] = b;
        size[2] = c;
    }
    ~Complex() {
            for (int i = 0; i < size[0]; ++i) {
                for (int j = 0; j < size[1]; ++j) {
                    delete[] arr[i][j];
                }
                delete[] arr[i];
            }
            delete[] arr; 
            cout << "Destructor activated\n";
        }
    friend ostream& operator <<(ostream& out,const Complex &X) {
            for (int i = 0; i < X.size[0]; ++i) {
                for (int j = 0; j < X.size[1]; ++j) {
                    for (int k = 0; k < X.size[2]; ++k) {
                        out << X.arr[i][j][k];
                    }
                }
            }
            return out;
        }
    friend istream& operator >>(istream& in, Complex &X) {
        cout << "Input a size of your array :\n" << "OZ = ";
        cin >> X.size[0]; cout << "\nOY = "; cin >> X.size[1];
        cout << "\nOX = "; cin >> X.size[2]; cout << endl;
        X.arr = new Value**[X.size[0]];
        for (int i = 0; i < X.size[0]; ++i) {
            X.arr[i] = new Value*[X.size[1]];
        }
        for (int i = 0; i < X.size[0]; ++i) {
            for (int j = 0; j < X.size[1]; ++j) {
                X.arr[i][j] = new Value[X.size[2]];
            }
        }
        for (int i = 0; i < X.size[0]; ++i) {
            for (int j = 0; j < X.size[1]; ++j) {
                for (int k = 0; k < X.size[2]; ++k) {
                    cout << "\nEnter the value of arr[" << i << "]["
                         << j << "][" << k << "] : ";
                    cin >> X.arr[i][j][k].a;
                    cin >> X.arr[i][j][k].i;
                }
            }
        }
        return in;
    }
    friend void SortArray(Complex* ARR, int size);
    friend int SumOfElements(Complex a, int value);
    friend class Value;
    void SetValue() {
        for (int i = 0; i < size[0]; ++i) {
            for (int j = 0; j < size[1]; ++j) {
                for (int k = 0; k < size[2]; ++k) {
                    cout << "\nEnter the value of arr[" << i << "]["
                    << j << "][" << k << "] : ";
                    cin >> arr[i][j][k].a;
                    cin >> arr[i][j][k].i;
                }
            }
        }
    }
        void* operator new(size_t);
        void* operator new[](size_t);
        void operator delete(void* ptr);
        void operator delete[](void* ptr);
    };
    void* Complex::operator new(size_t size) {
        return ::operator new(size);
    }
    void* Complex::operator new[](size_t size) {
        return ::operator new[](size);
    }
    void Complex::operator delete(void* ptr){
        ::operator delete(ptr);
    }
    void Complex::operator delete[](void* ptr){
        ::operator delete[](ptr);
    }
    void* Value::operator new(size_t size) {
        return ::operator new(size);
    }
    void* Value::operator new[](size_t size) {
        return ::operator new[](size);
    }
    void Value::operator delete(void* ptr){
        ::operator delete(ptr);
    }
    void Value::operator delete[](void* ptr){
        ::operator delete[](ptr);
    }
    void SortArray(Complex* ARR, int size) {
        cout << "How you want to sort?" << endl;
        cout << "1. From i" << endl;
        cout << "2. From a" << endl;
        int value; cin >> value;
        Complex temp(ARR[0]);
        int counter = 0;
        for (int i = 1; i < size; i++){
             if (SumOfElements(ARR[i], value) > SumOfElements(temp, value)) {
                 temp = ARR[i];
                 counter = i;
             }
        }
            cout << "The biggest array is " << counter << endl;
            cout << temp;
    }
    int SumOfElements(Complex a, int value) {
        int sum = 0;
        if (value == 1) {
            for (int i = 0; i < a.size[0]; i++) {
                for (int j = 0; j < a.size[1]; j++)
                {
                    for (int k = 0; k < a.size[2]; k++)
                    {
                        sum += a.arr[i][j][k].i;
                    }
                }
            }
            return sum;
        }
        else {
            for (int i = 0; i < a.size[0]; i++) {
                for (int j = 0; j < a.size[1]; j++)
                {
                    for (int k = 0; k < a.size[2]; k++)
                    {
                        sum += a.arr[i][j][k].a;
                    }
                }
            }
            return sum;
        }
    }
    int main() {
        /*int i, j, k;
        cout << "Input a size of your array :\n" << "OZ = ";
        cin >> i; cout << "\nOY = "; cin >> j;
        cout << "\nOX = "; cin >> k; cout << endl;
        Complex* c = new Complex(i, j ,k);
        c->SetValue();
        Complex* c1 = new Complex(*c);
        delete c;
        cout << *c1;
        delete c1;*/
        int size = 5;
        Complex* c2 = new Complex[5];
        for (int d = 0; d < 5; ++d) {
            cin >> c2[d];
            cout << c2[d];
        }
        SortArray(c2, size);
        delete[] c2;
        return 0;
}
