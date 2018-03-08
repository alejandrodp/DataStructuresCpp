#include <iostream>
#include "DoubleList.h"

DoubleList::DoubleList() {
    this->root = nullptr;
    this->size = 0;
}

DoubleList::~DoubleList(){
    if(this->size == 1){
        delete root;
        root = nullptr;
    }else if(root != nullptr){
    struct Node* toDel = root;
    struct Node* next = root->next;
    while (next->next != nullptr) {
        delete toDel;
        toDel = next;
        next = next->next;
    }
    delete toDel;
    delete next;
    }
}

DoubleList::DoubleList(const DoubleList &other){
    this->root = new struct Node(*other.root);
    this->size = other.size;
    struct Node* pivot = this->root;
    while (pivot->next != nullptr){
        pivot->next = new struct Node(*(pivot->next));
        pivot->next->previous = pivot;
        pivot = pivot->next;
    }
}

void DoubleList::AddEnd(int value){
    struct Node* adding = new struct Node;
    adding->value = value;
    if (root == nullptr){
         root = adding;
    }else{
        struct Node* index = root;
        while (index->next != nullptr){
            index = index->next;
        }
        adding->previous = index;
        index->next = adding;
    }
    this->size++;
}

void DoubleList::AddStart(int value){
    struct Node* adding = new struct Node;
    adding->value = value;
    if (root == nullptr){
        root = adding;
    }else{
        adding->next = root;
        root->previous = adding;
        root = adding;
    }
    this->size++;
}

bool DoubleList::DelStart(){
    if(root == nullptr){
        return false;
    }else if(this->size == 1){
        delete this->root;
        this->root = nullptr;
    }else{
        struct Node* toDelete = root;
        root = toDelete->next;
        root->previous = nullptr;
        delete toDelete;
    }
    this->size--;
    return true;
}

bool DoubleList::DelEnd(){
    if(this->size == 0){
        return false;
    }else if (this->size == 1) {
        delete root;
        root = nullptr;
    }else{
        struct Node* nextToLast = root;
        while(nextToLast->next->next != nullptr){
            nextToLast = nextToLast->next;
        }
        delete nextToLast->next;
        nextToLast->next = nullptr;
    }
    this->size--;
    return true;
}

bool DoubleList::AddPosition(int value, unsigned int pos){
    if(pos > (this->size-1) or this->size == 0){
        return false;
    }else if(pos == 0){
        this->AddStart(value);
    }else{
        struct Node* adding = new struct Node;
        adding->value = value;
        struct Node* elmNextToChange = root;
        for(int i=0; i<(pos-1); i++){
            elmNextToChange = elmNextToChange->next;
        }
        adding->next = elmNextToChange->next;
        elmNextToChange->next->previous = adding;
        adding->previous = elmNextToChange;
        elmNextToChange->next = adding;
    }
    this->size++;
    return true;
}

bool DoubleList::DelPosition(unsigned int pos){
    if(pos > (this->size-1) or this->size == 0){
        return false;
    }else if(pos == 0){
        this->DelStart();
    }else{
        struct Node* toDelete = root;
        for(int i=0; i<pos; i++){
            toDelete = toDelete->next;
        }
        if(toDelete->next == nullptr){
            toDelete->previous->next = nullptr;
        }else{
            toDelete->next->previous = toDelete->previous;
            toDelete->previous->next = toDelete->next;
        }
        delete toDelete;
    }
    this->size--;
    return true;
}

int DoubleList::getValue(unsigned int pos){
    if(pos > this->size or this->size == 0){
        return -1000;
    }else if(pos == 0){
        return root->value;
    }else{
        struct Node* searching = root;
        for(int i=0; i<(pos-1); i++){
            searching = searching->next;
        }
        return searching->next->value;
    }
}

void DoubleList::toString(){
    if(root == nullptr){
        std::cout << "[]" << std::endl << "Size: 0" << std::endl;
    }else{
         struct Node* actual = root;
    std::cout << "[" << std::flush;
    while(actual->next != nullptr){
        std::cout << actual->value << "," << std::flush;
        actual = actual->next;
    }
    std::cout << actual->value << "]" << std::endl;
    std::cout << "Size: " << this->size << std::endl;
    }
}

bool DoubleList::EditPosition(int value, unsigned int pos){
    if(pos > (this->size-1) or this->root == nullptr){
        return false;
    }else if(pos == 0){
        this->root->value = value;
    }else{
        struct Node* searching = root;
        for(int i=0; i<(pos-1); i++){
            searching = searching->next;
        }
        searching->next->value = value;
    }
    return true;
}