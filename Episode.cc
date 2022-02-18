#include "Episode.h"


Episode::Episode(const string& podcast, int number, const string& name, const string& content){
    this->podcast = podcast;
    this->number = number;
    this->name = name;
    this->content = content;
}




void Episode::print(){
    cout<<endl;
    cout << "Podcast: " << podcast <<endl;
    cout << "Name: " << name <<endl;
    cout << "Episode: " << number <<endl;
    cout << "Content: " << content<<endl;
    cout<<endl;
}

void Episode::play(){
  cout <<endl;
  cout << "this is a play function" <<endl;
  print();
}
