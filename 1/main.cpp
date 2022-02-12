#include <iostream>
#include <cstring>
using namespace std;
int doors() {
    char* direction;
    direction = (char*)malloc(6 * sizeof(char));
    int value;
    cout << "1. Choose left door\n";
    cout << "2. Choose center door\n";
    cout << "3. Choose right door\n\n";
    cout << "Write 'Center', 'Right' or 'Left' : \n";
    do{
        cin >> direction;
            if (strncmp(direction, "Right" , 5 ) == 0) {
                value = 3;
                break;
            }
            else if (strncmp(direction, "Left" , 4 ) == 0) {
                value = 1;
                break;
            }
            else if (strncmp(direction, "Center" , 6 ) == 0) {
                value = 2;
                break;
            }
            else {
                cout << "Wrong value, try again...\n";
                rewind(stdin);
            }
     }while(1);
    free(direction);
    return value;
};
int main() {
    char name[80];
    cout << "Enter the name of your character..." << endl;
    cin >> name;
    //system("CLS");
    cout << "Somebody : Hi " << name << ". I have some task for you !\n";
    system("pause");
    //system("CLS");
    cout << "Somebody : Listen " << name << ".\n I am not a bad guy, but if you want to survive you should go through the maze!\n";
    system("pause");
    while(1) {
        int lab = 233321, div = 10;
        cout << "You find yourself in a small bright room, in front  of you there are 3 doors.\n";
        int value;
        for (int i = 0; i < 6; ++i) {
            value = doors();
            if (value != lab % div) {

                cout << "Somebody : Dead end...\n\n";
                cout << "1. Back to the beginning\n";
                cout << "2. Back to the last door\n";
                cout << "Write 'Begin' or 'Back' : \n";
                char dir[5];
                while(1) {
                    cin >> dir;
                    if (strncmp(dir, "Begin", 5) == 0) {
                        value = 0;
                        break;
                    } else if (strncmp(dir, "Back", 4) == 0) {
                        value = -1;
                        break;
                    }
                    else {
                        cout << "Wrong value, try again...\n";
                        rewind(stdin);
                    }
                }
                if (value == 0)
                    break;
                if (value == -1) {
                    i--;
                    continue;
                }
            }
            cout << "You went further...\n";
            lab = lab / div;
        }
        if(value != 0) {
            break;
        }
        lab = 233321;
    }
    cout << "^-^ Congratulations, you made it out! ^-^\n";
    system("pause");
    return 0;
}
