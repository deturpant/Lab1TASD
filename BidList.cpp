//
// Created by deturpant on 11.09.22.
//

#include "BidList.h"
#include <iostream>
namespace KVA {
    BidList::BidList() {
        head = nullptr;
        tail = nullptr;
    }
    void BidList::printList() {
        Node *tmp = head;
        while (tmp!= nullptr) {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
    void BidList::AddToEnd(int _data) {
        Node *tmp = new Node;
        tmp->next = nullptr;
        tmp->data = _data;
        if (!isListEmpty()) {
            tmp->prev = tail;
            tail->next = tmp;
            tail = tmp;
        }
        else {
            tmp->prev = NULL;
            head = tail = tmp;
        }
    }

    void BidList::AddToStart(int _data) {
        Node *tmp = new Node;
        tmp->data = _data;
        tmp->prev = nullptr;
        if (!isListEmpty()) {
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        }
        else {
            tmp->next = NULL;
            head = tail = tmp;
        }
    }

    bool BidList::isListEmpty() {
        if (head==NULL) {
            return true;
        }
        return false;
    }
} // KVA