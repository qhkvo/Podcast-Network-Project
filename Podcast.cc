#include "Podcast.h"
#include "Episode.h"
#include "defs.h"

Podcast::Podcast(string title, string host){
    //DA array pointer
    episode = new Episode*[MAX_EPS];  //Or create NUM_EPS in defs?

    this->title = title;
    this->host = host;
    numEps = 0;
}
Podcast::Podcast(Podcast& p){
    this->title = p.title;
    this->host = p.host;
    episode = new Episode*[MAX_EPS];
    numEps = p.numEps;

    Episode* ep;
    for(int i=0; i<numEps; i++){
        ep = p.episode[i];
        episode[i] = new Episode(*ep);
    }
}

//Destructor
Podcast::~Podcast(){
    //for every els in pointer array
    for(int i=0; i < numEps; i++){
        delete episode[i];
    }

    //for pointer array
    delete[] episode;
}

//getters
string Podcast::getTitle(){ return title;}
string Podcast::getHost(){ return host;}
int Podcast::getNumEpisodes(){ return numEps;}

bool Podcast::addEpisode(string title, string content){
    //if eposide array full, return false. Else create new ep
    if(numEps < MAX_EPS){
        Episode *newEp = new Episode(this->title, numEps, title, content);
        episode[numEps++] = newEp;
        return true;
    }
    return false;
}

bool Podcast::getEpisode(int index, Episode** ep){
    //If index valid, retrieve the episode at that location in the Episode array and assign it to ep. Return true
    if(index >=0 && index < numEps){
        *ep = episode[index];
        return true;
    }
    return false;
}

bool Podcast::lessThan(Podcast& pod){
    if(this->title < pod.title){ return true;}
    return false;
}

void Podcast::print(){
    cout << "title: " << title <<endl;
    cout << "host: " << host<< endl;
}
