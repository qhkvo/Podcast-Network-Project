#ifndef PODCAST_H
#define PODCAST_H

#include "Episode.h"
#include <iostream>
#include <string>
using namespace std;

class Podcast{
    public:
        Podcast(string title, string host);
        ~Podcast();
        //copy constructor
        Podcast(Podcast&);

        string getTitle();
        string getHost();
        int getNumEpisodes();

        bool getEpisode(int index, Episode** ep);
        bool addEpisode(string title, string content);
        bool lessThan(Podcast& pod);
        void print();


    private:
        string title;
        string host;
        int numEps;
        Episode** episode;  //DA Pointer
};



#endif
