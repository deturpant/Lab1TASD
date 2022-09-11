#include <iostream>
#include "BidList.h"
int main() {
    using namespace KVA;
    BidList list;
    list.AddToStart(12);
    list.AddToStart(23);
    list.AddToEnd(5454);
    list.printList();
    return 0;
}
