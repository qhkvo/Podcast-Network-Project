#ifndef CLIENT_H
#define CLIENT_H

#include "Network.h"

using namespace std;

class Client{
    public:
        Client(const string& name);
        ~Client();

        void download(Network* network, const string& podcast);
        void stream(Network* network, const string& podcast, int episode);
        void playLocal(const string& podcast, int episode);
        void print();

    private:
        string name;
        PodArray* downloads;
};

#endif
