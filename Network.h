#ifndef NETWORK_H
#define NETWORK_H

#include "PodArray.h"
#include "Podcast.h"
#include "Subscriber.h"
#include "defs.h"
#include <string>
using namespace std;

class Network{
    public:
        Network(const string& name);
        ~Network();

        //get els from collections
        bool getPodcast(const string& podcast, Podcast** p);

        //add/remove
        bool addPodcast(const string& podcast, const string& host);
        bool removePodcast(const string& podcast);
        bool addEpisode(const string& podcast, const string& title, const string& content);
        bool addSubscriber(const string& name, const string& creditcard);

        //client services
        bool download(const string& subscriber, const string& podcast, Podcast** p);
        bool stream(const string& subscriber, const string& podcast, int episode, Episode** ep);
        bool hasSubscriber(const string& name);
        void print();

    private:
        string name;
        int numSubs;
        PodArray* podArray; //PodArray pointer
        Subscriber* subscriber[MAX_SUBS];  //SA pointer
};

#endif
