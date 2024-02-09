#pragma once
#include <iostream>
#include <vector>
#include "Player.h"

class Team {
public:
    Team(std::string name);
    ~Team();

    bool addPlayer(Player*);
    bool removePlayer(Player*);

    void printTeamInfo();
    int getPlayersCount();
private:
    std::string _name = "";
    int _countPlayers = 0;
    std::vector<Player*> _players;
};