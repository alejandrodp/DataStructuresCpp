#include <iostream>
#include "CircularList.h"

CircularList::CircularList() {
    this->root = nullptr;
    this->size = 0;
}

CircularList::~CircularList(){
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

CircularList::CircularList(const CircularList &other){
    this->root = new struct Node(*other.root);
    this->size = other.size;
    struct Node* pivot = this->root;
    while (pivot->next != nullptr){
        pivot->next = new struct Node(*(pivot->next));
        pivot = pivot->next;
    }
}

void CircularList::AddEnd(int value){
    struct Node* adding = new struct Node;
    adding->value = new int(value);
    if (root == nullptr){
         root = adding;
    }else{
        struct Node* pivot = root;
        while (pivot->next != nullptr){
            pivot = pivot->next;
        }
        pivot->next = adding;
        adding->next = root;
    }
    this->size++;
}

void CircularList::AddStart(int value){
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

bool CircularList::DelStart(){
    if(root == nullptr){
        return false;
    }else{
        struct Node* toDelete = root;
        root = toDelete->next;
        delete toDelete;
        this->size--;
        return true;
    }
}

bool CircularList::DelEnd(){
    if(root == nullptr){
        return false;
    }else if (root->next == nullptr) {
        delete root;
        root = nullptr;
    }else{
        struct Node* prevToLast = root;
        while(prevToLast->next->next != nullptr){
            prevToLast = prevToLast->next;
        }
        delete prevToLast->next;
        prevToLast->next = root;
    }
    this->size--;
    return true;
}

bool CircularList::AddPosition(int value, unsigned int pos){
    if(pos > this->size){
        return false;
    }else if(pos == 0){
        this->AddStart(value);
    }else{
        struct Node* adding = new struct Node;
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

bool CircularList::DelPosition(unsigned int pos){
    if(pos > this->size or this->size == 0){
        return false;
    }else if(pos == 0){
        this->DelStart();
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

int CircularList::getValue(unsigned int pos){
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

void CircularList::toString(){
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

bool CircularList::EditPosition(int value, unsigned int pos){
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