//
// Created by deturpant on 11.09.22.
//
#include <iostream>

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

    public:
        BidList();

        void printList();

        void addToStart();

        void addToEnd();

        void addToMid();

        void deleteElementNumber();

        void findElement();

        void deleteElementData();

        void deleteList();

        void notRepet();

        void printEmpty();
    };

    template<typename T>
    BidList<T>::BidList() {
        head = nullptr;
        tail = nullptr;
        lenList = 0;
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
            std::cout << "\n\nСпиcок пуст.\n\n";
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
        if (lenList < num) {
            std::cout << "\nВведенная позиция для добавления некорректна!\n";
        } else if (num == -1) {
            std::cout << "pass\n\n\n";
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
            std::cout << "\nВведенная позиция для добавления некорректна!\n";
        }
    }

    template<typename T>
    void BidList<T>::deleteElementNumber() {
        int num{};
        printList();
        std::cout << "Пожалуйства, введите номер для удаления: ";
        std::cin >> num;
        if (lenList < num || num <= 0) {
            std::cout << "Введен неверный индекс. Удаление невозможно\n";

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
            std::cout << "Введен неверный индекс. Удаление невозможно\n";

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
            Node *tmp = new Node;
            while (head != NULL) {
                tmp = head;
                head = head->next;
                delete[] tmp;
            }
            tail = NULL;
            lenList = 0;
            std::cout << "Список удален.\n";
        } else {
            std::cout << "Список пустой. Удаление невозможно\n";
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
            std::cout << "Элемент не найден! Проверьте вводимые данные\n";
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
    void BidList<T>::printEmpty() {
        if (head == NULL) {
            std::cout << "Список пуст!!!\n";
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
        tmp->next = nullptr;
        tmp->data = _data;
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
    void BidList<T>::notRepet() {
        BidList<T> a = copyList();
        Node *tmp = new Node;
        Node *tmp2 = new Node;
        int st{};
        tmp = a.head;
        std::cout << "Символы, которые входят в последовательность по одному разу: ";
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
                    std::cout << tmp->data << " ";
                }
            }
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }

} // KVA

#endif //LAB1_BIDLIST_H
