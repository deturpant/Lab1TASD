#include <iostream>
#include "BidList.h"

int main() {
    using namespace KVA;
    BidList list;
    list.AddToEnd('a');
    list.AddToEnd('b');
    list.AddToEnd('c');
    list.AddToStart('e');
    list.AddToEnd('b');
    list.AddToMid('e');
    list.printList();
    list.NotRepet();
    return 0;
}
