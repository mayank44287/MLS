//
//  main.cpp
//  MLS
//
//  Created by Mayank Raj on 11/11/18.
//  Copyright © 2018 Mayank Raj. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "MusicClipPtr.h"
#include "BandMembers.h"
#include "LinkedList.h"
#include <fstream>
using namespace std;

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList(){
    std::cout<<"list deleted";
}

void LinkedList::add(int data){
    Node* node = new Node();
    node->data = data;
    node->next = this->head;
    this->head = node;
    this->length++;
}

void LinkedList::remove(int data){
    
}

void LinkedList::print(){
    
    Node* head = this->head;
    int i = 1;
    while(head){
        std::cout<<i<<":"<<head->data<<std::endl;
        head = head->next;
        i++;
    }
}
class myexception: public exception
{
    virtual const char* what() const throw()
    {
        return "My exception happened";
    }
} myex;

void serialize(){
    
    
    fstream file;
    file.open("mayank.txt",fstream::in| fstream::out | fstream::app);
    if(!file){
        cout<<"coud nt create file"<<endl;
    }
    //int id = obj->getID();
   // string gen = obj->getGenre();
    //double pr = obj->getPrice();
    //file << "ID: " << id << endl << "Genre: " << gen <<endl << "Price: " << pr << endl;
    //file << "Mayank" << endl;
    try {
        //file.write((char*)&obj, sizeof(obj));
        file<<"mayank"<<endl;
    } catch (exception e) {
        cout<<e.what()<<endl;
        
    }

    file.close();
    
    
}


int main ()
{

    
    MusicClipPtr obj1;
    obj1->setID(5);
    obj1->setGenre("hard metal");
    obj1->setPrice(180);
    ofstream file1;
    file1.open("maya.txt",ios::out);
    file1 << "mayank"<< endl;
    file1.close();
    obj1->display();
   
    
    
    
    
    return 0;
}
