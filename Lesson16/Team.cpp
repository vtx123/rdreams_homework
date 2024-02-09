#include "Team.h"

Team::Team(std::string name) : _name(name) {

}

Team::~Team() {
}

bool Team::addPlayer(Player* player) {
    for (int i = 0; i < _players.size(); i++) {
        if (_players[i]->getName() == player->getName()) {
            return false;
        }
    }

    _players.push_back(player);
    return true;
}

bool Team::removePlayer(Player* player) {
    for (int i = 0; i < _players.size(); i++) {
        if (_players[i]->getName() == player->getName()) {
            _players.erase(_players.begin() + i);
            return true;
        }
    }
    return false;
}

void Team::printTeamInfo() {
    std::cout << "Team name: " << _name << std::endl;
    std::cout << "Teammates: " << std::endl;
    for (int i = 0; i < _players.size(); i++) {
        std::cout << "   " << _players[i]->getName() << std::endl;

    }
}

int Team::getPlayersCount() {
    return _players.size();
}