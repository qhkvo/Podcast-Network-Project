#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

using namespace std;

#include <iostream>
#include <string>

class Subscriber{
    public:
        Subscriber(string name, string creditcard);

        bool matches(const string& name);


    private:
        string name;
        string creditcard;
};

#endif