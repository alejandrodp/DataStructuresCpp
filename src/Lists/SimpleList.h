#ifndef SIMPLE_LIST_H
#define SIMPLE_LIST_H

class SimpleList{
private:
    struct Node{
        struct Node* next;
        int value;
    } *root;
    unsigned int size;
public:
    SimpleList();
    ~SimpleList();
    SimpleList(const SimpleList &other);
    void AddStart(int value);
    void AddEnd(int value);
    bool AddPosition(int value, unsigned int pos);
    bool DelStart();
    bool DelEnd();
    bool DelPosition(unsigned int pos);
    bool EditPosition(int value, unsigned int pos);
    int getValue(unsigned int pos);
    void toString();
    int getSize();
};
#endif