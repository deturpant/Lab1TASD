#include <iostream>
#include "BidList.h"
int main() {
    using namespace KVA;
    BidList list;
    list.AddToEnd(12);
    list.AddToEnd(36);
    list.AddToEnd(48);
    list.printList();
    list.DeleteElementNumber(1);
    list.printList();
    return 0;
}
