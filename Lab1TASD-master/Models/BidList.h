//
// Created by deturpant on 11.09.22.
//
#include <iostream>
#include "MyException.h"
#include <cstring>
#include <limits>
#include <fstream>

#ifndef LAB1_BIDLIST_H
#define LAB1_BIDLIST_H

namespace KVA {
    template<typename T>
    class BidList {
    private:
        class Node {
        public:
            T data;
            Node *next;
            Node *prev;
        };

        Node *head;
        Node *tail;
        int lenList{};
        int findEl(T _data);
        BidList<T> copyList();
        void add(T _data);
        void delet(int num);
        bool isListEmpty();
        ~BidList();
    public:
        BidList();
        void printList();
        void printListReverse();
        void addToStart();
        void addToEnd();
        void addToMid();
        void deleteElementNumber();
        void findElement();
        void deleteElementData();
        void deleteList();
        void notRepet();
        void printEmpty();
        void clearCIN();
        void readFromFile();
        void outToFile();
    };

    template<typename T>
    BidList<T>::BidList() {
        head = nullptr;
        tail = nullptr;
        lenList = 0;
    }
    template<typename T>
    void BidList<T>::clearCIN() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
    }
    template<typename T>
    void BidList<T>::printList() {
        if (!isListEmpty()) {
            std::cout << "\n\n\nList: [ ";
            Node *tmp = head;
            while (tmp != nullptr) {
                std::cout << tmp->data << " ";
                tmp = tmp->next;
            }
            std::cout << "]\n\n\n";
        } else {
            throw MyException{"List empty"};
        }
    }

    template<typename T>
    void BidList<T>::printListReverse() {
        if (!isListEmpty())
        {
            std::cout << "\n\n\nList: [ ";
            Node* tmp = tail;
            while (tmp!=NULL) {
                std::cout << tmp->data << " ";
                tmp = tmp->prev;
            }
            std::cout << "]\n\n\n";
        }
        else {
            throw MyException{"List empty"};
        }
    }

    template<typename T>
    void BidList<T>::addToEnd() {
        T _data{};
        std::cout << "Введите символ для добавления в список: ";
        std::cin >> _data;
        lenList++;
        Node *tmp = new Node;
        tmp->next = nullptr;
        tmp->data = _data;
        clearCIN();
        if (!isListEmpty()) {
            tmp->prev = tail;
            tail->next = tmp;
            tail = tmp;
        } else {
            tmp->prev = NULL;
            head = tail = tmp;
        }
    }

    template<typename T>
    void BidList<T>::addToStart() {
        T _data{};
        std::cout << "Введите символ для добавления в список: ";
        std::cin >> _data;
        lenList++;
        Node *tmp = new Node;
        tmp->data = _data;
        clearCIN();
        tmp->prev = nullptr;
        if (!isListEmpty()) {
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        } else {
            tmp->next = NULL;
            head = tail = tmp;
        }
    }

    template<typename T>
    void BidList<T>::addToMid() {
        T _data{};
        std::cout << "Введите символ для добавления в список: ";
        std::cin >> _data;
        std::cout << "Введите позицию для добавления в список: ";
        int num{};
        std::cin >> num;
        num -= 2;
        if (lenList <= num) {
            throw MyException{"Incorrect position when adding by index"};
        } else if (num == -1) {
            add(_data);
        } else if (num >= 0) {
            Node *tmp = new Node;
            tmp->data = _data;
            Node *cyc = new Node;
            cyc = head;
            for (int i = 0; i < num; i++) {
                cyc = cyc->next;
            }
            tmp->next = cyc->next;
            tmp->prev = cyc->prev;
            cyc->next = tmp;
            cyc = cyc->next;
            cyc->prev = tmp;
            lenList++;
            std::cout << "Элемент " << _data << " успешно помещен в позицию №" << num + 2 << "\n\n\n";
        }
        else {
            throw MyException{"Incorrect position when adding by index"};
        }
        clearCIN();
    }

    template<typename T>
    void BidList<T>::deleteElementNumber() {
        int num{};
        printList();
        std::cout << "Пожалуйства, введите номер для удаления: ";
        std::cin >> num;
        if (lenList < num || num <= 0) {
            throw MyException{"Invalid delete index"};

        } else {
            num--;
            Node *tmp = new Node;
            Node *tmp2 = new Node;
            Node *deleteTmp = new Node;
            Node *cyc = new Node;
            cyc = head;
            for (int i = 0; i < num; i++) {
                cyc = cyc->next;
            }
            deleteTmp = cyc;
            if (head != deleteTmp & tail != deleteTmp) {
                tmp = deleteTmp->next;
                tmp2 = deleteTmp->prev;
                tmp2->next = tmp;
                tmp->prev = tmp2;
            } else if (head == deleteTmp) {
                tmp = deleteTmp->next;
                head = tmp;
                tmp->prev = NULL;
            } else if (tail == deleteTmp) {
                tmp = deleteTmp->prev;
                tail = tmp;
                tmp->next = NULL;
            }
            std::cout << "Удаление успешно завершено!\n";
            lenList--;
        }

    }

    template<typename T>
    void BidList<T>::delet(int num) {
        if (lenList < num || num <= 0) {
            throw MyException{"Invalid symbol when deleting by value"};

        } else {
            num--;
            Node *tmp = new Node;
            Node *tmp2 = new Node;
            Node *deleteTmp = new Node;
            Node *cyc = new Node;
            cyc = head;
            for (int i = 0; i < num; i++) {
                cyc = cyc->next;
            }
            deleteTmp = cyc;
            if (head != deleteTmp & tail != deleteTmp) {
                tmp = deleteTmp->next;
                tmp2 = deleteTmp->prev;
                tmp2->next = tmp;
                tmp->prev = tmp2;
            } else if (head == deleteTmp) {
                tmp = deleteTmp->next;
                head = tmp;
                tmp->prev = NULL;
            } else if (tail == deleteTmp) {
                tmp = deleteTmp->prev;
                tail = tmp;
                tmp->next = NULL;
            }
            std::cout << "Удаление успешно завершено!\n";
            lenList--;
        }
    }

    template<typename T>
    void BidList<T>::deleteElementData() {
        T _data{};
        std::cout << "Введите символ для удаления: ";
        std::cin >> _data;
        int numberOfDeleteElement = findEl(_data);
        delet(numberOfDeleteElement);
    }

    template<typename T>
    void BidList<T>::deleteList() {
        if (!isListEmpty()) {
            while (head) {
                tail = head->next;
                delete head;
                head = tail;
            }
            lenList = 0;
            std::cout << "Список удален.\n";
        } else {
            throw MyException{"List empty"};
        }

    }

    template<typename T>
    int BidList<T>::findEl(T _data) {
        Node *cyc = new Node;
        int position = 1;
        cyc = head;
        bool flag = false;
        for (int i = 0; i < lenList; i++) {
            if (cyc->data == _data) {
                flag = true;
                break;
            } else {
                cyc = cyc->next;
                position++;
            }
        }
        if (!flag) {
            return -1;

        } else {
            return position;
        }

    }

    template<typename T>
    void BidList<T>::findElement() {
        T _data{};
        std::cout << "Введите символ для поиска: ";
        std::cin >> _data;
        int result{};
        result = findEl(_data);
        if (result == -1) {
            throw MyException{"Element not found when searching"};
        } else {
            std::cout << "Элемент найден под номером " << result << " с данными: " << _data << "\n";
        }
    }

    template<typename T>
    bool BidList<T>::isListEmpty() {
        if (head == NULL) {
            return true;
        }
        return false;
    }

    template<typename T>
    void BidList<T>::readFromFile() {
        std::ifstream in;
        std::string line;
        T tempData;
        in.open("../input.txt", std::ios::in);
        T s;
        while (in.get(s) && !in.eof()) {
            if (std::isdigit(s) || std::isalpha(s)) {
                add(s);
            }
        }
        in.close();
        std::cout << "\nЧтение данных с файла завершено";
        printList();
    }
    template<typename T>
    void BidList<T>::outToFile() {
        std::ofstream  out;
        out.open("../output.txt", std::ios::out);
        Node* node = head;
        for (int i =0; i<lenList;i++) {
            out << node->data << " ";
            node = node->next;
        }
        out.close();
        std::cout << "\n\nВывод данных в файл завершен!\n\n";
    }

    template<typename T>
    void BidList<T>::printEmpty() {
        if (head == NULL) {
            throw MyException{"List empty"};
        } else {
            std::cout << "Список не пуст!\n";
            printList();
        }
    }

    template<typename T>
    BidList<T> BidList<T>::copyList() {
        BidList<T> a;
        Node *tmp = new Node;
        tmp = head;
        for (int i = 0; i < lenList; i++) {
            a.add(tmp->data);
            tmp = tmp->next;
        }
        return a;
    }

    template<typename T>
    void BidList<T>::add(T _data) {
        lenList++;
        Node *tmp = new Node;
        tmp->data = _data;
        tmp->prev = nullptr;
        if (!isListEmpty()) {
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        } else {
            tmp->next = NULL;
            head = tail = tmp;
        }
    }

    template<typename T>
    void BidList<T>::notRepet() {
        BidList<T> a = copyList();
        Node *tmp = new Node;
        Node *tmp2 = new Node;
        int st{};
        bool state = false;
        bool state2 = false;
        tmp = a.head;
        if (!isListEmpty()) {
            for (int i = 0; i < lenList; i++) {
                st = 0;
                if (tmp->data != '\0') {
                    tmp2 = tmp->next;
                    for (int j = i + 1; j < lenList; j++) {
                        if (tmp->data == tmp2->data) {
                            st = 1;
                            tmp2->data = '\0';
                        }
                        tmp2 = tmp2->next;
                    }
                    if (st == 0) {
                        if (!state2) {
                            std::cout << "Символы, которые входят в последовательность по одному разу: ";
                            state2 = true;
                        }
                        std::cout << tmp->data << " ";
                        state = true;
                    }
                }
                tmp = tmp->next;
            }
            if (!state) {
                throw MyException{"Not found characters appearing once"};
            }
            std::cout << std::endl;
        }
        else {
            throw MyException{"List empty"};
        }
        while (a.head) {
            a.tail = a.head->next;
            delete a.head;
            a.head = a.tail;
        }
    }
    template <typename T>
    BidList<T>::~BidList() {
        while (head) {

            tail = head->next;
            delete head;
            head = tail;
        }
        lenList = 0;
    }
} // KVA

#endif //LAB1_BIDLIST_H
