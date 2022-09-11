//
// Created by deturpant on 11.09.22.
//

#ifndef LAB1_BIDLIST_H
#define LAB1_BIDLIST_H

namespace KVA {
    struct Node {
        char *data;
        Node *next;
        Node *prev;
    };
    class BidList {
    private:
        Node *head;
        Node *tail;
        int lenList{};
        int findEl(char* _data);
    public:
        BidList();
        void printList();
        void AddToStart(char* _data);
        void AddToEnd(char* _data);
        void AddToMid(char* _data);
        bool isListEmpty();
        void DeleteElementNumber(int num);
        void findElement(char* _data);
        void DeleteElementData(char* _data);
        void DeleteList();
    };

} // KVA

#endif //LAB1_BIDLIST_H
