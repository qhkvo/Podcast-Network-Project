# A2
## Quynh Vo (101203972)

### Learning outcome
1. write an application that is (mostly) separated into into control, view, entity, and collection object classes.
2. use a UML diagram to implement classes and the interaction between between classes.
3. implement a “deep copy” of nested objects.

### Source files and header files
- defs.h
- main.cc
    instantiates a TestControl object and calls launch
- Client.cc, Client.h:
    Interacts with the Network to stream episodes or download podcasts
    Manages a collection of downloaded Podcasts

- Episode.cc, Episode.h
    Contains information about the Episode
    Plays content through a View object, i.e., std::cout

- Network.cc, Network.h:
    Manages collections of Podcasts and Subscribers
    Provides services to the Client (such as download and stream).
    Prints error information to std::cout

- PodArray.cc, PodArray.h
    Data structure for Podcasts.

- Podcast.cc, Podcast.h
    Contains information about the Podcast
    Maintains a collection of Episodes

- Subscriber.cc, Subscriber.h
    Contains information about the Subscriber

- Makefile

### Test files
- TestControl.cc, TestControl.h
    Controls the running of tests on your application
    Interacts with TestView

- TestView.cc, TestView.h
    Takes input from the user performing the tests

### To run the program (in command line)
1. make
2. ./a2
