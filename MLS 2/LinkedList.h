//
//  LinkedList.h
//  MLS
//
//  Created by Mayank Raj on 11/13/18.
//  Copyright © 2018 Mayank Raj. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h
#include "MusicClipPtr.h"

class DataSet{
public:
    int size;
    class DataSetNode{
        
    public:
        int x;
        DataSetNode * next;
        DataSetNode(){
            next = nullptr;
            x = -1;
        }
        
    };
    DataSet(){
        DataSethead = nullptr;
        Qend = nullptr;
    }
    DataSetNode * DataSethead;
    DataSetNode * Qend;
    void add(int);
    void remove();
    void printAll();
    bool isPartOf(int);
};

class Node{

public:
    int nodeID;
    Node* next;
    Node* selfPointer;
    MusicClipPtr* data;
    Node(int d){
        nodeID = d;
        data = new MusicClipPtr();
        next = nullptr;
        selfPointer = this;
    }
    void printNode();
    
};

class LinkedList{
    
public:
    int length;
    Node* head;
    
    LinkedList(){
        head = NULL;
        length = 0;
    };
    ~LinkedList();
    MusicClipPtr * currentNode(int index);
    void add(int i);
    void remove();
    void print(DataSet&);
    
};



void DataSet::add(int x1){
    DataSetNode * q = new DataSetNode();
    q->x = x1;
    this->size++;
    if(DataSethead == nullptr)
    {
        DataSethead = q;
        Qend = q;
    }
    else{
        Qend->next = q;
        Qend = q;
        
    }
    
    
}

void DataSet::remove(){
    DataSetNode *temp = DataSethead;
    delete DataSethead;
    DataSethead = temp->next;
    size = size - 1;
    
}
void DataSet::printAll(){
    DataSetNode *temp = DataSethead;
    while(temp!=nullptr){
        std::cout<<"\n"<<temp->x;
        temp = temp->next;
        
    }
}

bool DataSet::isPartOf(int part){
    DataSetNode * temp = DataSethead;
    while(temp!=nullptr){
        if(temp->x == part)
            return true;
    }
    return false;
}


#endif /* LinkedList_h */
