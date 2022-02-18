#ifndef EPISODE_H
#define EPISODE_H

#include <iostream>
#include <string>
using namespace std;

class Episode {
    public:
        Episode(const string& podcast, int number, const string& name, const string& content);
        void print();
        void play();

    private:
        string name;
        string content;
        string podcast;
        int number;

};


#endif
