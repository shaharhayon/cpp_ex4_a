#pragma once
#include <string>
#include "Player.hpp"

namespace pandemic
{
    class Medic : public Player
    {
    private:
        void default_cure();

    public:
        Medic(Board& board, City city);
        virtual std::string role();
        virtual Player& drive(City city);
        virtual Player& fly_direct(City city);
        virtual Player& fly_charter(City city);
        virtual Player& fly_shuttle(City city);
        virtual Player& build();
        virtual Player& discover_cure(Color color);
        virtual Player& treat(City city);
    };
}