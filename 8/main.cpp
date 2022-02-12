#include <iostream>
#include "List.h"
using namespace std;

int menu() {
    int n;
    cout << "1.Add\n2.Show\n3.Delete\n4.Sort\n5.Quit\n";
    try {
        cin >> n;
        if (cin.fail() || n < 1 || n > 5) {
            throw errorClass("Invalid Value...", 1, 4);
        }
    }
    catch(errorClass a) {
        cout << a.message << endl;
        n = a.checkInteger(n);
    }
    return n;
}
int main() {
    List temp;
    while (1) {
        switch (menu()) {
            case 1 :
                    temp.add();
                break;
            case 2:
                try {
                    temp.show();
                }
                catch (errorClass a) {
                    cout << a.message << endl;
                }
                break;
            case 3:
                try {
                    temp.deleteElement();
                }
                catch (errorClass a) {
                    cout << a.message << endl;
                }
                break;
            case 4:
                temp.sort();
                break;
            case 5:
                return 0;
        }
    }
}