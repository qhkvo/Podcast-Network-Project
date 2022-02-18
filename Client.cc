#include "Client.h"

Client::Client(const string& name){
    this->name = name;
    downloads = new PodArray();
}

Client::~Client(){
    delete downloads;
}

void Client::download(Network* network, const string& podcast){
    Podcast* p;
    if(network->download(name, podcast, &p)){
       downloads->addPodcast(new Podcast(*p));
       return;
    }
    cout << "download error" <<endl;

}

void Client::stream(Network* network, const string& podcast, int episode){
    Episode* e;
    if(network->stream(name, podcast, episode, &e)){
        e->play();
    }
}

void Client::playLocal(const string& podcast, int episode){
    Podcast* p;
    Episode* e;
    if(downloads->getPodcast(podcast, &p)){
        if(p->getEpisode(episode, &e)){ return e->play(); }
    }
    cout <<"playLocal error." <<endl;
}

void Client::print(){
    cout << "name: " << name <<endl;
}
