//
// Created by deturpant on 11.09.22.
//

#ifndef LAB1_BIDLIST_H
#define LAB1_BIDLIST_H

namespace KVA {
    struct Node {
        int data;
        Node *next;
        Node *prev;
    };
    class BidList {
    private:
        Node *head;
        Node *tail;
        int lenList{};
    public:
        BidList();
        void printList();
        void AddToStart(int _data);
        void AddToEnd(int _data);
        void AddToMid(int _data);
        bool isListEmpty();
        void DeleteElementNumber(int num);
    };

} // KVA

#endif //LAB1_BIDLIST_H
