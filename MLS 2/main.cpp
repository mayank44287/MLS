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
#include "LinkedList.h"
#include <fstream>
using namespace std;

MusicClipPtr::MusicClipPtr()  {
  
    mMusicClip = nullptr;
    
}
//deep copy method
void MusicClipPtr::dCopy(MusicClipPtr& temp){
    this->mMusicClip = new MusicClip();
    *mMusicClip = *temp;
    ofstream file;
    file.open("temp.clip",ios::out);
    file.write((char*)mMusicClip, sizeof(*mMusicClip));
    file.close();
}


//method to lead instance fro  file
void MusicClipPtr::loadFromFile(int id){
    string filename = "file"+ to_string(id)+".dat";
    
    fstream file;
    file.open(filename, ios::in);
    mMusicClip = new MusicClip();
    file.read((char *)mMusicClip, sizeof(*mMusicClip));
    mMusicClip->display();
    //music = tempObject;
    
    
}
//method to save data to file
void MusicClipPtr::saveToFile(int id){
    
    string filename = "file" + to_string(id) + ".dat";
    fstream file;
    //MusicClip tempObject;
    file.open(filename, ios::out);
    //tempObject = music;
    file.write((char *)&mMusicClip, sizeof(mMusicClip));
    file.close();
    freeMemory();
    
    
}

//method to create new file
void MusicClipPtr::newFile(int index){
    fstream file;
    string filename = "file" + to_string(index) +".dat";
    mMusicClip = new MusicClip();
    this->mMusicClip->getData(index);
    file.open(filename, ios::out);
    file.write((char *)mMusicClip, sizeof(*mMusicClip));
    file.close();
    
    
    
}

//method to print data of node of linked list
void Node:: printNode(){
    if((*data).isNull() == true){
        cout<<"node is empty"<<nodeID<<endl;
    }
    else
        (*data)->display();
    
}

/*LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}*/

//destructor
LinkedList::~LinkedList(){
    std::cout<<"list deleted";
}

//method to add data to linked list node
void LinkedList::add(int i){
    Node* node = new Node(i);
    //node = &d;
    if(head == NULL){
        head = node;
    }
    else{
        node->next = head;
        head =  node;
    }
  
    this->length++;
}

//method to remove node from linked list
void LinkedList::remove(){
    if(head->next == nullptr){
        head = nullptr;
    }
    else{
        Node * d;
        d = head->next;
        head->next = nullptr;
        head = d;
        
    }
}
//method to print linked list
void LinkedList::print(DataSet& mem)
    
    {
        Node * temp;
        int freeIn;
        temp = head;
        while(temp!=nullptr){
            
            if(temp->data->isNull()){
                
                //does file exist? if yes retrieve
                std::string filename = "file"+std::to_string(temp->nodeID)+".dat";
                std::ifstream file(filename);
                if(file.good()){
                    if(mem.size<3){
                        temp->data->loadFromFile(temp->nodeID);
                        mem.add(temp->nodeID);
                    }
                    else{
                        //memQ is full, free up space
                        freeIn = mem.DataSethead->x;
                        MusicClipPtr *ref= this->currentNode(freeIn);
                        ref->saveToFile(freeIn);
                        mem.remove();
                        temp->data->loadFromFile(temp->nodeID);
                        mem.add(temp->nodeID);
                    }
                }
            }
            temp->printNode();
            temp = temp->next;
            
        }
        
        
    
   /* Node* head = this->head;
    int i = 1;
    while(head){
        std::cout<<i<<":"<<&head->data<<std::endl;
        head = head->next;
        i++;
        
    }*/
    /*Node * temp;
    temp = this->head;
    while(temp){
        temp->printNode();
        temp = temp->next;
    }*/
    
    
}
//custom exception
class myexception: public exception
{
    virtual const char* what() const throw()
    {
        return "My exception happened";
    }
} myex;

/*void serialize(){
    
    
    fstream file;
    file.open("file111.dat",fstream::in| fstream::out | fstream::app);
    if(!file){
        cout<<"coud nt create file"<<endl;
    }
    MusicClipPtr obj;
    obj->setID(111);
    obj->setGenre("rock");
    obj->setPrice(1000);
    //double pr = obj->getPrice();
    //file << "ID: " << id << endl << "Genre: " << gen <<endl << "Price: " << pr << endl;
    //file << "Mayank" << endl;
    try {
        file.write((char*)&obj, sizeof(obj));
        //file<<"m"<<endl;
    } catch (exception e) {
        cout<<e.what()<<endl;
        
    }

    file.close();
    
    
}*/
//mehtod return the current mnode
MusicClipPtr * LinkedList::currentNode(int index){
 
    Node* node = head;
    if(node == NULL){
        std::cout<<"acnakdakjd"<<endl;
        return nullptr;
    }
    else{
        while(node != nullptr){
            if(node->nodeID == index)
                
                return node->data;
            else
                node = node->next;
        }
        return nullptr;
    }
}
//method to check if a given file exists
bool fExists(string fileName){
 
    ifstream ifile(fileName);
    if(!ifile){
        return false;
    }
    else{
        cout<<"file already exists with the given index, please use edit option to go ahead"<<endl;
        return true;
    }
}

//save object file
void saveToObj(int index, string Genre, double Price, LinkedList* list){
 
    //MusicClipPtr obj1;
    Node* current = new Node(index);
    current = list->head;
    //MusicClipPtr *obj = new MusicClipPtr(index);
    //obj = current->data;
    while(current != NULL){
        if(current->nodeID == index)
        {
            if(current->data->access() == NULL){
                //current->data->loadFromFile(111);
                //obj->access()->setID(index);
                //obj->access()->setGenre(Genre);
                //obj->access()->setPrice(Price);
                cout<<"EMpty pointer"<<endl;
                //obj->saveToFile(index);
            }
       }
        current = current->next;
    }
   // obj1->setID(index);
   // obj1->setGenre(Genre);
  //  obj1->setPrice(Price);
    //obj1.saveToFile(index);
    
}


int main ()
{

    
    //int index;
    //string Genre;
    //double Price;
    DataSet mem;
    LinkedList list;
    MusicClipPtr *ptr;
    //int i = 0;
    for (int i = 0; i < 10; i++){
        list.add(i);
    }
    //ccint l = list->length;
    //cout<<"lenght is:" << l<< endl;
    //list->print();
    //char ch,resume;
    bool flag = false;
    int current_index = -1;
    int anIndex = -1;
    
    cout<< "Please enter any of the following commands to continue:"<< endl;
    cout<<"List - l"<<endl;
    cout<<"Edit - e"<< endl;
    cout<< "create - c"<<endl;
    cout<< "copy - y"<<endl;
    cout<< "Read command from file - i"<<endl;
    cout<<" Change Price - p" << endl;
    cout<<"Save all Clips - s" << endl;
    cout<<"Quit MLS - q"<<endl;
    char userInput,resume;
    //cin >> userInput;
    
  
    do {
        cout<<"Enter the command choice__";
        cin>>userInput;
        switch (userInput) {
                
            case 'l':{
                list.print(mem);
                flag = false;
                cout<<"\nPlease enter r to resume";
                cin>>resume;
                if(resume == 'r')
                    flag = true;
                
                
                break;}
                
            case 'e':{
                cout<<"\nEnter index for file to edit:: ";
                if(mem.size<3){
                    cin>>current_index;
                    MusicClipPtr * ptr = list.currentNode(current_index);
                    
                    if(!mem.isPartOf(current_index)){
                        
                        ptr->loadFromFile(current_index);
                        mem.add(current_index);
                        (*ptr)->getData(current_index);
                        //ptr->saveFile(current_index);
                    }
                    else{
                        (*ptr)->getData(current_index);
                    }
                }
                else {
                    cout<<"Memory stack full!\n";
                }
                cout<<"\nPlease enter r to resume:  ";
                cin>>resume;
                flag = false;
                if(resume == 'r')
                    flag = true;
                
                break;}
                
            case 'c':{
                if(mem.size<3){
                    cout<<"\nEnter index for file::";
                    cin>>anIndex;
                    
                    ptr = list.currentNode(anIndex);    //returns current index object
                    
                    
                    
                    ptr->newFile(anIndex);
                    mem.add(anIndex);
                }
                else{
                    cout<<"Memory is  full!\n";
                }
                flag = false;
                
                cout<<"Please enter r to resume:  ";
                
                cin>>resume;
                if(resume == 'r')
                    flag = true;
                
                break;}
        
                
            case 'y':{
                MusicClipPtr deepCopyptr;       //deep copy for clip
                if(current_index!=-1)
                {
                    ptr = list.currentNode(current_index);
                    deepCopyptr.dCopy(*ptr);
                }
                else{
                    cout<<"\nInvalid current index. Cannot copy";
                }
                flag = true;
                break;}
            
                
            case 'i':{
                ifstream file;
                char ch;
                file.open("adasda", ios::in);
                while(!file.eof()){
                    file.read((char *)&ch, sizeof(ch));
                }
                break;}
                
            case 'p':{
                if(current_index!= -1){
                    ptr = list.currentNode(current_index);
                    double newPrice;
                    cout<<"Enter new price";
                    cin>>newPrice;
                    (*ptr)->setPrice(newPrice);
                    
                }
                else{
                    cout<<"Invalid current index.";
                }
                flag = false;
                break;}
            
                
            case 's':{
                int length = mem.size;
                for(int i = 0; i< length; i++){
                    current_index = mem.DataSethead->x;
                    ptr = list.currentNode(current_index);
                    ptr->saveToFile(current_index);
                    //delete music clip here
                    mem.remove();
                    }
                
                flag = false;
                cout<<"Press r to continue:  ";
                cin>>resume;
                if(resume == 'r')
                    flag = true;
                break;}
        
        
            case 'q':{
                flag = false;
                break;}
                
            default:{
                cout<<"Invalid entry"<<endl;
                flag = true;
                break;}
        }
        
        } while (flag == true);
        
    
   
    
    
    

    
    return 0;
    
}

