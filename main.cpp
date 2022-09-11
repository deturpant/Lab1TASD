#include <iostream>
#include "BidList.h"
int main() {
    using namespace KVA;
    BidList list;
    list.AddToStart(12);
    list.AddToEnd(5454);
    list.AddToEnd(123456);
    list.printList();
    list.AddToMid(999);
    list.printList();
    list.AddToMid(7777);
    list.printList();
    list.AddToMid(555);
    list.printList();
    list.AddToMid(666);
    list.printList();
    return 0;
}
