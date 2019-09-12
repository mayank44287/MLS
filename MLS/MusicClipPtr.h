//
//  MusicClipPtr.h
//  MLS
//
//  Created by Mayank Raj on 11/12/18.
//  Copyright © 2018 Mayank Raj. All rights reserved.
//
#include <vector>
#include <string>
#ifndef MusicClipPtr_h
#define MusicClipPtr_h

/*this is the smart pointer class which has a nested class as well */
class MusicClipPtr{
    
private:
    int number;
    //T* mPointer;
    /*nested class is accessed using the smart pointer instance*/
    class MusicClip{
        
    public:
        friend class MusicClipPtr;
        int id;
        int index;
        std::string Artist;
        enum  GenreAvailable{POP_MUSIC, FOLK_MUSIC, JAZZ, BLUES, CLASSICAL, OPERA, COUNTRY_MUSIC, REGGAE,ROCK,Unassigned};
        GenreAvailable Genre;
        std::vector<std::string> People;
        std::string title;
        //BandMembers People;
        std::vector<char> Clip;
        double price;
        int i;
        //constructor
        MusicClip(){
            id = -1;
            Artist = "Unassigned";
            Genre= GenreAvailable::Unassigned;
            index = -1;
            //char * string = nullptr;
            //people.push_back(string);
            title = "Unassigned";
            price = 0.0;
            i = 0;
            
        }
        
        //setters
        void setIndex(int num){
            index = num;
        }
        void setID(int num){
            id = num;
            
        };
        
        void ArtistName(std::string a){
            Artist = a;
        };
        
        void setGenre(GenreAvailable g){
            Genre = g;
        };
        
        void setTitle(std::string a){
            title = a;
        };
        
        void setPrice(double p){
            price = p;
        };
        
        //getters
        int getID(){
            return id;
        };
        
        int getIndex(){
            return index;
        };
        
        std::string ArtissName(){
            return Artist;
        };
        
        std::string getTitle(){
            return title;
        };
        
        GenreAvailable getGenre(){
            return Genre;
        };
        
        
        
        double getPrice(){
            return price;
        }
        
        
        inline void display(){
            
            std::cout<<"Index :" << index<<std::endl;
            std::cout<<"Identifier :" <<this->id<<std::endl;
            std::cout<<"Artist :" << this->Artist<<std::endl;
            std::cout<<"Genre :" << this->Genre<<std::endl;
            std::cout<<"Title :" << this->title<<std::endl;
            std::cout<<"Price :" << price<<std::endl;
        }
        
        //MusicClipPtr& operator=(const MusicClipPtr&) ;
        //MusicClipPtr(const MusicClipPtr&) ;
        inline void getData(int x){
            index = x;
            std::cout<<"Enter id: ";
            std::cin.ignore();
            std::cin>>id;
            std::cout<<"Enter artist name:  ";
            std::cin.ignore();
            getline(std::cin, Artist);
            std::cout<<"Enter Genre:  ";
            std::cout<<"POP_MUSIC = 1, FOLK_MUSIC = 2, JAZZ = 3, BLUES = 4, CLASSICAL = 5, OPERA = 6, COUNTRY_MUSIC = 7, REGGAE = 8,ROCK = 9"<<std::endl;
            //std::cin.ignore();
            std::cin>>i;
            
            
            switch(i){
                    
                    //GenreAvailable g;
                case 1:
                    this->Genre = POP_MUSIC;
                    
                    //g = POP_MUSIC;
                    //this->setGenre(g);
                    break;
                case 2:
                    this->Genre = FOLK_MUSIC ;
                    //g = FOLK_MUSIC;
                    //this->setGenre(g);
                    break;
                    
                case 3:
                    this->Genre = JAZZ ;
                    //g = JAZZ;
                    //this->setGenre(g);
                    break;
                    
                case 4:
                    this->Genre = BLUES;
                    //g = BLUES;
                    //this->setGenre(g);
                    break;
                    
                case 5:
                    this->Genre =  CLASSICAL ;
                    //g = CLASSICAL;
                    //this->setGenre(g);
                    break;
                    
                case 6:
                    this->Genre = OPERA ;
                    //g = OPERA;
                    //this->setGenre(g);
                    break;
                    
                case 7:
                    this->Genre = COUNTRY_MUSIC;
                    //g = COUNTRY_MUSIC;
                    //this->setGenre(g);
                    break;
                    
                case 8:
                    this->Genre = REGGAE;
                    //g= REGGAE;
                    //this->setGenre(g);;
                    break;
                    
                case 9:
                    this->Genre = ROCK;
                    //g = ROCK;
                    //this->setGenre(g);
                    break;
                default:
                    std::cout<<"select any value from 1 to 9 as mentioned above"<<std::endl;
            }
            //getline(std::cin,);
            std::cout<<"Enter title:  ";
            std::cin.ignore();
            getline(std::cin, title);
            std::cout<<"Enter price of song:  ";
            std::cin>>price;
        }
        
    };
    MusicClip* mMusicClip;
    //MusicClip music;
public:
    MusicClipPtr();
    ~MusicClipPtr(){};
    void saveToFile(int);
    void loadFromFile(int index)  ;
    void newClip(int index );
    void dCopy(MusicClipPtr&);
    void newFile(int index);
    //MusicClipPtr(MusicClip* ptr = new MusicClip()): mMusicClip(ptr){}
    inline void freeMemory(){
        delete mMusicClip;
        //clipPointer = nullptr;
    }
    
    MusicClip* access(){
        return mMusicClip;
    }
    //void serialize
    
    inline MusicClip& operator*(){
        if (mMusicClip == NULL)
        {//clipPointer = getFromFile}
        }
        return *mMusicClip;
    };
    
    inline MusicClip* operator->(){
        if (mMusicClip == NULL)
        {}///call file method to initialise file and return data from there
        
        return mMusicClip;
            
    };
        
    inline bool isNull(){
        if(mMusicClip == nullptr)
            return true;
        else
            return false;
    }
  

    
};


    
    

#endif /* MusicClipPtr_h */
