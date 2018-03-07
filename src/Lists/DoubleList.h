#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

class DoubleList{
private:
    struct Node{
        struct Node* next;
        struct Node* previous;
        int* value;
    } *root;
    unsigned int size;
public:
    DoubleList();
    ~DoubleList();
    DoubleList(const DoubleList &other);
    void AddStart(int value);
    void AddEnd(int value);
    bool AddPosition(int value, unsigned int pos);
    bool DelStart();
    bool DelEnd();
    bool DelPosition(unsigned int pos);
    bool EditPosition(int value, unsigned int pos);
    int getValue(unsigned int pos);
    void toString();
};
#endif