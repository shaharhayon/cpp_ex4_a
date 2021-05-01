
#include "Researcher.hpp"
using namespace pandemic;

Researcher::Researcher(Board& board, City city) : Player(board, city){};
std::string Researcher::role(){
    return std::string("Researcher");
}

Player& Researcher::discover_cure(Color color){
    if(this->num_of_cards(color) < 5){
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
        if (removed == 5){
            break;
        }
    }
    this->_board._cures.at(color) = true;
    return *this;
}
