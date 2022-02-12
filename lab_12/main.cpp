#include <iostream>
#include "BracketsCheck.h"

int main() {
    std::string sourceFile = "Brackets.txt";
    std::string resultFile = "Result.txt";

    BracketsCheck test(sourceFile, resultFile);
    try {
        test.loadTXT();
        test.check();
        test.saveInTXT();
    } catch (UserException &exception) {
        std::cout << exception.what() << std::endl << "End of the program!" << std::endl;
    }

    return 0;
}
