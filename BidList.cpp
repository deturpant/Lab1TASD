//
// Created by deturpant on 11.09.22.
//

#include "BidList.h"
#include <iostream>

namespace KVA {
    BidList::BidList() {
        head = nullptr;
        tail = nullptr;
        lenList = 0;
    }

    void BidList::printList() {
        Node *tmp = head;
        while (tmp != nullptr) {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }

    void BidList::AddToEnd(char *_data) {
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

    void BidList::AddToStart(char *_data) {
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

    void BidList::AddToMid(char *_data) {
        Node *tmp = new Node;
        tmp->data = _data;
        Node *cyc = new Node;
        cyc = head;
        int position{};
        if (lenList > 2) {
            position = lenList / 2;
            for (int i = 0; i < position; i++) {
                cyc = cyc->next;
            }
            tmp->next = cyc->next;
            tmp->prev = cyc->prev;
            cyc->next = tmp;
            cyc = cyc->next;
            cyc->prev = tmp;
            lenList++;
        } else {
            std::cout << "Добавление в середину возможно при количестве элементов более двух!\n";
        }
    }

    void BidList::DeleteElementNumber(int num) {
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
        }

    }

    void BidList::DeleteElementData(char *_data) {
        int numberOfDeleteElement = findEl(_data);
        DeleteElementNumber(numberOfDeleteElement);
    }

    void BidList::DeleteList() {
        if (!isListEmpty()) {
            head = NULL;
            tail = NULL;
            lenList = 0;
            std::cout << "Список удален.\n";
        } else {
            std::cout << "Список пустой. Удаление невозможно\n";
        }
    }

    int BidList::findEl(char *_data) {
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

    void BidList::findElement(char *_data) {
        int result{};
        result = findEl(_data);
        if (result == -1) {
            std::cout << "Элемент не найден! Проверьте вводимые данные\n";
        } else {
            std::cout << "Элемент найден под номером " << result << " с данными: " << _data << "\n";
        }
    }

    bool BidList::isListEmpty() {
        if (head == NULL) {
            return true;
        }
        return false;
    }
} // KVA