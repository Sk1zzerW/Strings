#include <iostream>
#include <string>
#include <cctype>

void removeCharAt(std::string& str, size_t pos) {
    if (pos < str.size()) {
        str.erase(pos, 1);
    }
    else {
        std::cerr << "Position is out of range!\n";
    }
}

void removeAllOccurrences(std::string& str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
}

void insertCharAt(std::string& str, size_t pos, char ch) {
    if (pos <= str.size()) {
        str.insert(pos, 1, ch);
    }
    else {
        std::cerr << "Position is out of range!\n";
    }
}

void replaceDotsWithExclamations(std::string& str) {
    for (char& ch : str) {
        if (ch == '.') {
            ch = '!';
        }
    }
}

int countOccurrences(const std::string& str, char ch) {
    int count = 0;
    for (char c : str) {
        if (c == ch) {
            count++;
        }
    }
    return count;
}

void countCharacters(const std::string& str, int& letters, int& digits, int& others) {
    letters = digits = others = 0;
    for (char c : str) {
        if (std::isalpha(c)) {
            letters++;
        }
        else if (std::isdigit(c)) {
            digits++;
        }
        else {
            others++;
        }
    }
}

int main() {
    std::string str;
    char ch;
    size_t pos;

    //1
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);
    std::cout << "Enter the position of the character to remove: ";
    std::cin >> pos;
    removeCharAt(str, pos);
    std::cout << "String after removal: " << str << "\n";

    //2
    std::cout << "\nEnter a string: ";
    std::cin.ignore();
    std::getline(std::cin, str);
    std::cout << "Enter the character to remove: ";
    std::cin >> ch;
    removeAllOccurrences(str, ch);
    std::cout << "String after removing all occurrences of '" << ch << "': " << str << "\n";

    //3
    std::cout << "\nEnter a string: ";
    std::cin.ignore();
    std::getline(std::cin, str);
    std::cout << "Enter the position to insert the character: ";
    std::cin >> pos;
    std::cout << "Enter the character to insert: ";
    std::cin >> ch;
    insertCharAt(str, pos, ch);
    std::cout << "String after insertion: " << str << "\n";

    //4
    std::cout << "\nEnter a string with periods to replace: ";
    std::cin.ignore();
    std::getline(std::cin, str);
    replaceDotsWithExclamations(str);
    std::cout << "String after replacing dots with exclamations: " << str << "\n";

    //5
    std::cout << "\nEnter a string: ";
    std::cin.ignore();
    std::getline(std::cin, str);
    std::cout << "Enter the character to count: ";
    std::cin >> ch;
    int count = countOccurrences(str, ch);
    std::cout << "Character '" << ch << "' appears " << count << " times.\n";

    //6
    int letters, digits, others;
    std::cout << "\nEnter a string: ";
    std::cin.ignore();
    std::getline(std::cin, str);
    countCharacters(str, letters, digits, others);
    std::cout << "Letters: " << letters << ", Digits: " << digits << ", Others: " << others << "\n";

    return 0;
}//p.s я попытался сделать всё в одном коде
