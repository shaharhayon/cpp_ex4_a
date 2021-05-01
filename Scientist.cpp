
#include "Scientist.hpp"
using namespace pandemic;
Scientist::Scientist(Board& board, City city, int n) : Player(board, city), _n(n){}

std::string Scientist::role(){
    return std::string("Scientist");
}

Player& Scientist::discover_cure(Color color){
    if(!(this->_board._cities.at(this->_currentCity)._research_station)){
        throw std::invalid_argument("Cant discover cure for this city. this city doesn't have a research station.");
    }
    if(this->num_of_cards(color) < this->_n){
        throw std::invalid_argument("Cant discover cure for this city. you dont have enough cards of this color.");
    }
    int removed = 0;
    for (std::vector<City>::iterator i = (this->_cards.end() - 1); i != (this->_cards.begin() - 1); i--)
    {
        if (this->_board._cities.at(*i)._color == color)
        {
            this->_cards.erase(i);
            removed++;
        }
        if (removed == this->_n){
            break;
        }
    }
    this->_board._cures.at(color) = true;
    return *this;
}
