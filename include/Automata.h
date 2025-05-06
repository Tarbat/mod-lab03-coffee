// Copyright 2022 GHA Test Team
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <vector>
#include <string>

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
    int cash;
    int currChoice;
    std::vector<std::string>menu;
    std::vector<int> price;
    STATES state;

public: 
    Automata();
    void on();
    void off();
    void coin(int);
    void getMenu();
    STATES getState();
    void choice(int);
    void check();
    void cancel();
    void cook();
    void finish();
};

#endif // INCLUDE_AUTOMATA_H_
