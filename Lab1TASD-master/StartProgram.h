//
// Created by deturpant on 11.09.22.
//
#include <iostream>
#include "Models/BidList.h"
#include "Menu/MyMenu.h"
#include "Menu/MyMenuItem.h"
#include "Models/MyException.h"
using namespace KVA;

int addElSt() {
    return 2;
}

int addElEnd() {
    return 1;
}

int addElMid() {
    return 3;
}

int deleteNum() {
    return 4;
}

int deleteData() {
    return 5;
}

int print() {
    return 6;
}

int findEl() {
    return 7;
}

int empty() {
    return 8;
}

int solve() {
    return 9;
}

int del() {
    return 10;
}

int ex() {
    return 11;
}
template <typename T>
void startProgramm(BidList<T>* list, MyMenu menu) {
    try {
    while (menu.runCommand()) {
            if (menu.getSelect() == print()) {
                list->printList();
            }
            if (menu.getSelect() == addElEnd()) {
                list->addToEnd();
            }
            if (menu.getSelect() == addElMid()) {
                list->addToMid();
            }
            if (menu.getSelect() == addElSt()) {
                list->addToStart();
            }
            if (menu.getSelect() == deleteNum()) {
                list->deleteElementNumber();
            }
            if (menu.getSelect() == deleteData()) {
                list->deleteElementData();
            }
            if (menu.getSelect() == findEl()) {
                list->findElement();
            }
            if (menu.getSelect() == empty()) {
                list->printEmpty();
            }
            if (menu.getSelect() == solve()) {
                list->notRepet();
            }
            if (menu.getSelect() == del()) {
                list->deleteList();
            }
            if (menu.getSelect() == ex()) {
                exit(0);
            }
        }
    }
    catch (const MyException& exception) {
        std::cout << "Error: " << exception.getError() << "\n";
        startProgramm(list, menu);
    }
}

#ifndef LAB1_STARTPROGRAM_H
#define LAB1_STARTPROGRAM_H

#endif //LAB1_STARTPROGRAM_H
