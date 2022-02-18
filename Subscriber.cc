#include "Subscriber.h"

Subscriber::Subscriber(string name,string creditcard){
    this->name  = name;
    this->creditcard = name;
}

bool Subscriber::matches(const string& name){
    if(this->name == name){return true;}
    return false; 
}


