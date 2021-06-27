#include <iostream>
#include <fstream>
#include <string>

struct Pip_data {
    std::string name="";
    std::string surname = "";
    std::string date="";
    int payment=0;
};

void list() {//вывод содержимого файла
    Pip_data temp;
    std::ifstream file("statement.txt");
    if (file.is_open())
        std::cout << "File open!\n";
    else {
        std::cout << "Error.Invalid file path!\n";
        return;
    }
    while (!file.eof()) {
        temp.name = "";
        file >> temp.name;
        if (temp.name == "")
            break;
        else {
            file >> temp.surname;
            file >> temp.date;
            file >> temp.payment;
            std::cout << "Name: " << temp.name << " " << temp.surname << "\n";
            std::cout << "Date: " << temp.date << "\n";
            std::cout << "Payment: " << temp.payment << "\n";
        }
    }
    file.close();
   
}

void add() {
    Pip_data temp;
    std::ofstream file("statement.txt",std::ios::app);
    if (file.is_open())
        std::cout << "File open!\n";
    else {
        std::cout << "Error.Invalid file path!\n";
        return;
    }
    std::cin.ignore(32767, '\n');
    std::cout << "Name: ";
    std::getline(std::cin, temp.name);
    std::cout << "Date: ";
    std::cin>>temp.date;
    std::cout << "Payment: ";
    std::cin>>temp.payment;
    file << temp.name<<"\n";
    file << temp.date<<"\n";
    file << temp.payment<<"\n";
}
int main()
{
    
    std::string operation;
    for (;;) {
        do {
            std::cout << "Choose operation: ";
            std::cin >> operation;
        } while (!(operation == "list" || operation == "add" || operation == "exit"));
        if (operation == "exit") return 0;
        if (operation == "list") list();
        else if (operation == "add")add();
    }

    
}

