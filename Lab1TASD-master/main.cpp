#include <iostream>
#include "Models/BidList.h"
#include "Models/MyException.h"
using namespace KVA;

const int ITEMS = 13;
void checkIndexMenuCIN(int num) {
    if (std::cin.fail() || num > ITEMS || num < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
        throw MyException{"Invalid index command menu"};
    }
}
void clearCIN() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
}
template<typename T>
void startMenu(BidList<T>* list) {
    try {
    while (true) {
        std::cout <<"Главное меню\n"
                    "1.  Добавить элемент в начало списка\n"
                    "2.  Добавить элемент в конец списка\n"
                    "3.  Добавить элемент в список по заданному номеру\n"
                    "4.  Вывести список на экран\n"
                    "5.  Вывести список на экран в обратном порядке\n"
                    "6.  Удаление элемента списка по номеру\n"
                    "7.  Удаление элемента списка по значению\n"
                    "8.  Поиск элемента по значению\n"
                    "9.  Проверка списка на пустоту\n"
                    "10. Чтение элементов из файла\n"
                    "11. Запись элементов списка в файл\n"
                    "12. Поиск неповторяющихся элементов\n"
                    "13. Удаление списка\n"
                    "0.  Выход\n--> ";
        int num{};
        std::cin >> num;
        checkIndexMenuCIN(num);
            switch(num) {
                case 1: {
                    T _data{};
                    std::cout << "Введите символ для добавления в список: ";
                    std::cin >> _data;
                    list->addToStart(_data);
                    clearCIN();
                    break;
                }
                case 2: {
                    T _data{};
                    std::cout << "Введите символ для добавления в список: ";
                    std::cin >> _data;
                    list->pushback(_data);
                    clearCIN();
                    break;
                }
                case 3: {
                    T _data{};
                    std::cout << "Введите символ для добавления в список: ";
                    std::cin >> _data;
                    clearCIN();
                    std::cout << "Введите позицию для добавления в список: ";
                    int num{};
                    std::cin >> num;
                    list->addToMid(_data, num);
                    break;
                }
                case 4:
                    list->printList();
                    break;
                case 5:
                    list->printListReverse();
                    break;
                case 6: {
                    int num{};
                    list->printList();
                    std::cout << "Пожалуйства, введите номер для удаления: ";
                    std::cin >> num;
                    list->deleteElementNumber(num);
                    break;
                }
                case 7: {
                    T _data{};
                    list->printList();
                    std::cout << "Введите символ для удаления: ";
                    std::cin >> _data;
                    int numberOfDeleteElement = list->findEl(_data);
                    if (numberOfDeleteElement==-1) {
                        throw MyException{"Invalid symbol for search"};
                    }
                    else {
                        list->deleteElementNumber(numberOfDeleteElement);
                    }
                    break;
                }
                case 8: {
                    T _data{};
                    std::cout << "Введите символ для поиска: ";
                    std::cin >> _data;
                    int result{};
                    result = list->findEl(_data);
                    if (result == -1) {
                        throw MyException{"Element not found when searching"};
                    } else {
                        std::cout << "Элемент найден под номером " << result << " с данными: " << _data << "\n";
                    }
                    std::cin.clear();
                    break;
                }
                case 9:
                    if (list->isListEmpty()) {
                        throw MyException{"List empty"};
                    } else {
                        std::cout << "Список не пуст!\n";
                        list->printList();
                    }
                    break;
                case 10:
                    list->readFromFile();
                    break;
                case 11:
                    list->outToFile();
                    break;
                case 12:
                    list->notRepet();
                    break;
                case 13:
                    list->deleteList();
                    break;
                case 0:
                    list->outToFile();
                    exit(0);
                    break;
                default:
                    break;
            }
        }
        std::cin.clear();
    }
    catch (const MyException& exception) {
        std::cout << "Error: " << exception.getError() << "\n";
        startMenu(list);
    }
}
int main() {
    BidList<char>* list = new BidList<char>;
    startMenu(list);
    return 0;
}
