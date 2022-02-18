#include "Network.h"

Network::Network(const string& name){
    this->name = name;

    podArray = new PodArray();
    numSubs =0;

}

Network::~Network(){
    delete podArray;

    for(int i=0; i< numSubs; i++){
        delete subscriber[i];
    }
}

//get els from collections
bool Network::getPodcast(const string& podcast, Podcast** p){

    if(podArray->getPodcast(podcast, p) == true){return true;}
    return false;
}

//add/remove

bool Network::addPodcast(const string& podcast, const string& host){
    if(podArray->isFull() == false){
        Podcast *newPod = new Podcast(podcast, host);
        podArray->addPodcast(newPod);
        return true;
    }
    return false;
}

bool Network::removePodcast(const string& podcast){
    Podcast* p;

    if(podArray->removePodcast(podcast, &p) == true){
        delete p;
        return true;
    }

    return false;
}

bool Network::addEpisode(const string& podcast, const string& title, const string& content){
    Podcast* p;

    if(getPodcast(podcast, &p )){  //if exist
        p->addEpisode(title , content);
        return true;
    }
    return false;

}

bool Network::addSubscriber(const string& name, const string& creditcard){
    if(numSubs < MAX_SUBS){
        Subscriber *newSub = new Subscriber(name, creditcard);
        subscriber[numSubs] = newSub;
        numSubs++;
        return true;
    }
    return false;
}

//client services

bool Network::download(const string& subscriber, const string& podcast, Podcast** p){

    if(!hasSubscriber(subscriber)){
        cout<< "There is no subscriber: "<<subscriber <<endl;
        return false;
    }

    if(!getPodcast(podcast, p)){
        cout<< "There is no podcast: "<<podcast <<endl;
        return false;
    }

    return true;

}

bool Network::stream(const string& subscriber, const string& podcast, int episode, Episode** ep){
    Podcast* p;

    if(!hasSubscriber(subscriber)){
        cout<< "There is no subscriber: " << subscriber <<endl;
        return false;
    }

    if(!getPodcast(podcast, &p)){
        cout<< "There is no podcast: " <<podcast <<endl;
        return false;
    }

    if(!p->getEpisode(episode, ep) ){
        cout<< "There is no episode: "<<episode <<endl;
        return false;
    }

    return true;
}

bool Network::hasSubscriber(const string& name){

    for(int i=0; i<numSubs; i++){
        if(subscriber[i]->matches(name)){return true;};
    }
    return false;

}
void Network::print(){
  cout<<"name: " << name <<endl;

}
