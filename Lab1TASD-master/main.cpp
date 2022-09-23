#include <iostream>
#include "Models/BidList.h"
#include "Menu/MyMenu.h"
#include "Menu/MyMenuItem.h"
#include "StartProgram.h"

using namespace KVA;

int main() {
    BidList<char>* list = new BidList<char>;
    MyMenuItem items[11]{
            MyMenuItem{"Добавить элемент в конец", addElEnd},
            MyMenuItem{"Добавить элемент в начало", addElSt},
            MyMenuItem{"Добавить элемент в необходимую позицию", addElMid},
            MyMenuItem{"Удалить элемент по номеру", deleteNum},
            MyMenuItem{"Удалить элемент по значению", deleteData},
            MyMenuItem{"Вывести список на экран", print},
            MyMenuItem{"Поиск по значению", findEl},
            MyMenuItem{"Проверка на пустоту списка", empty},
            MyMenuItem{"Поиск неповторяющихся символов", solve},
            MyMenuItem{"Удаление списка", del},
            MyMenuItem{"Выход из программы", ex}
    };
    MyMenu menu("List programm", items, 11);
    startProgramm(list, menu);
    return 0;
}
