//
//  MusicClip.h
//  MLS
//
//  Created by Mayank Raj on 11/12/18.
//  Copyright © 2018 Mayank Raj. All rights reserved.
//
#include <string>
#include "BandMembers.h"
#ifndef MusicClip_h
#define MusicClip_h
class MusicClip{
    
    int ID;
    std::string Artist;
    enum GenreAvailable{POP_MUSIC, FOLK_MUSIC, JAZZ, BLUES, CLASSICAL, OPERA, COUNTRY_MUSIC, REGGAE,ROCK};
    BandMembers People;
    std::vector<char> Clip;
    double Price;
    
    
    
};

#endif /* MusicClip_h */
