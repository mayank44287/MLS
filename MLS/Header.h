//
//  Header.h
//  MLS
//
//  Created by Mayank Raj on 11/12/18.
//  Copyright © 2018 Mayank Raj. All rights reserved.
//
#ifndef Header_h
#define Header_h
class SmartPointer{
    
    
};

class MusicClip{
    
    int ID;
    std::string Artist;
    enum Genre{POP MUSIC, FOLK MUSIC, JAZZ, BLUES, CLASSICAL, OPERA, COUNTRY MUSIC, REGGAE,ROCK};
    BandMembers People;
    std::vector<char> Clip;
    double Price;
    
};

class BandMembers{
    std::vector<char> Names;
    
public:
    void enterNames();
    void getNames();
}
#endif /* Header_h */
