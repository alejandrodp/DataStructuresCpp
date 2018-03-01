#include "SimpleList.h"
#include<iostream>

SimpleList::SimpleList(){
    this->root = nullptr;
    this->size = 0;
}

SimpleList::~SimpleList(){
    if(this->size == 1){
        delete root;
        root = nullptr;
    }else if(root != nullptr){
    struct Node* toDel = root;
    struct Node* next = root->next;
    while(next->next != nullptr){
        delete toDel;
        toDel = next;
        next = next->next;
    }
    delete toDel, next;
    }
}

SimpleList::SimpleList(const SimpleList &other){
    this->root = new struct Node(*other.root);
    this->size = other.size;
}

void SimpleList::AddEnd(int value){
    struct Node* adding = new struct Node;
    adding->value = new int(value);
    adding->next = nullptr;
    if (root == nullptr){
         root = adding;
    }else{
        struct Node* index = root;
        while (index->next != nullptr){
            index = index->next;
        }
        index->next = adding;
    }
    this->size++;
}

void SimpleList::AddStart(int value){
    struct Node* adding = new struct Node;
    adding->value = new int(value);
    adding->next = nullptr;
    if (root == nullptr){
        root = adding;
    }else{
        adding->next = root;
        root = adding;
    }
    this->size++;
}

bool SimpleList::DelStart(){
    if(root == nullptr){
        return false;
    }else{
        struct Node* toDelete = root;
        root = toDelete->next;
        delete toDelete;
        this->size--;
    }
}

bool SimpleList::DelEnd(){
    if(root == nullptr){
        return false;
    }else if (root->next == nullptr) {
        delete root;
        root = nullptr;
        this->size--;
        return true;
    }else{
        struct Node* nextToLast = root;
        while(nextToLast->next->next != nullptr){
            nextToLast = nextToLast->next;
        }
        delete nextToLast->next;
        nextToLast->next = nullptr;
        this->size--;
        return true;
    }
}

bool SimpleList::AddPosition(int value, unsigned int pos){
    if(pos > this->size){
        return false;
    }else if(pos == 0){
        struct Node* adding = new struct Node;
        adding->next = nullptr;
        adding->value = new int(value);
        adding->next = root;
        root = adding;
    }else{
        struct Node* adding = new struct Node;
        adding->next = nullptr;
        adding->value = new int(value);
        struct Node* index = root;
        for(int i=0; i<(pos-1); i++){
            index = index->next;
        }
        adding->next = index->next;
        index->next = adding;
    }
    this->size++;
    return true;
}

bool SimpleList::DelPosition(unsigned int pos){
    if(pos > this->size or this->size == 0){
        return false;
    }else if(pos == 0){
        if(this->size == 1){
        delete root;
        root = nullptr;
        }else{
            struct Node* temp = root;
            root = temp->next;
            delete temp;
        }
    }else{
        struct Node* nextToDeleting = root;
        for(int i=0; i<(pos-1); i++){
            nextToDeleting = nextToDeleting->next;
        }
        struct Node* toDelete = nextToDeleting->next;
        nextToDeleting->next = toDelete->next;
        delete toDelete;
    }
    this->size--;
    return true;
}

int SimpleList::getValue(unsigned int pos){
    if(pos > this->size or this->size == 0){
        return -1000;
    }else if(pos == 0){
        return *(root->value);
    }else{
        struct Node* searching = root;
        for(int i=0; i<(pos-1); i++){
            searching = searching->next;
        }
        return *(searching->next->value);
    }
}

void SimpleList::toString(){
    if(root == nullptr){
        std::cout << "[]" << std::endl << "Size: 0" << std::endl;
    }else{
         struct Node* actual = root;
    std::cout << "[" << std::flush;
    while(actual->next != nullptr){
        std::cout << *(actual->value) << "," << std::flush;
        actual = actual->next;
    }
    std::cout << *(actual->value) << "]" << std::endl;
    std::cout << "Size: " << this->size << std::endl;
    }
}

bool SimpleList::EditPosition(int value, unsigned int pos){
    if(pos > this->size or this->root == nullptr){
        return false;
    }else if(pos == 0){
        *(this->root->value) = value;
    }else{
        struct Node* searching = root;
        for(int i=0; i<(pos-1); i++){
            searching = searching->next;
        }
        *(searching->next->value) = value;
    }
    return true;
}