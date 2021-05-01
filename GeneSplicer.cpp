
#include "GeneSplicer.hpp"
using namespace pandemic;

GeneSplicer::GeneSplicer(Board& board, City city) : Player(board, city){};

std::string GeneSplicer::role()
{
    return std::string("Gene Splicer");
}

Player& GeneSplicer::discover_cure(Color color)
{
    if (!(this->_board._cities.at(this->_currentCity)._research_station))
    {
        throw std::invalid_argument("Cant discover cure for this city. this city doesn't have a research station.");
    }
    if (this->_cards.size() < 5)
    {
        throw std::invalid_argument("Cant discover cure for this city. you dont have enough cards.");
    }
    int removed = 0;
    for (std::vector<City>::iterator i = (this->_cards.end() - 1); i != (this->_cards.begin() - 1); i--)
    {
        this->_cards.erase(i);
        removed++;
        if (removed == 5)
        {
            break;
        }
    }
    this->_board._cures.at(this->_board._cities.at(this->_currentCity)._color) = true;
    return *this;
}