#include <iostream>
#include "Models/BidList.h"
#include "Menu/MyMenu.h"
#include "Menu/MyMenuItem.h"
#include "StartProgram.h"
#include "Models/MyException.h"
using namespace KVA;

const int ITEMS_COUNT = 13;
int main() {
    BidList<char>* list = new BidList<char>;
    MyMenuItem items[ITEMS_COUNT]{
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
            MyMenuItem{"Чтение из файла", readFile},
            MyMenuItem{"Запись в файл", writeFile},
            MyMenuItem{"Выход из программы", ex}

    };
    MyMenu menu("List programm", items, ITEMS_COUNT);
    startProgramm(list, menu);
    return 0;
}
