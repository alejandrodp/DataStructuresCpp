#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

class CircularList{
private:
    struct Node{
        struct Node* next;
        int value;
    } *root;
    unsigned int size;
public:
    CircularList();
    ~CircularList();
    CircularList(const CircularList &other);
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