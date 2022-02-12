#ifndef LAB_12_BRACKETSCHECK_H
#define LAB_12_BRACKETSCHECK_H

#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include <vector>

class UserException : public std::exception {
private:
    std::string errorMessage;
public:
    explicit UserException(std::string err_msg) : errorMessage(std::move(err_msg)) {}

    const char *what() { return errorMessage.c_str(); }
};

class BracketsCheck {
private:
    std::string m_sourceFile;
    std::string m_resFile;

    std::vector<std::string> m_brackets;

    std::vector<std::string> m_correct;
    std::vector<std::string> m_incorrect;

public:
    BracketsCheck(std::string sourceFile, std::string resFile) : m_sourceFile(std::move(sourceFile)),
                                                                 m_resFile(std::move(resFile)) {}

    void loadTXT();

    void check();

    void saveInTXT();
};


#endif //LAB_12_BRACKETSCHECK_H
