#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

TEST_CASE("PLAYER ROLES")
{
    Board board;
    OperationsExpert player_oe(board, City::Atlanta);
    Dispatcher player_d(board, City::Atlanta);
    Scientist player_s(board, City::Atlanta, 4);
    Researcher player_r(board, City::Atlanta);
    Medic player_m(board, City::Atlanta);
    Virologist player_v(board, City::Atlanta);
    GeneSplicer player_gs(board, City::Atlanta);
    FieldDoctor player_fd(board, City::Atlanta);

    CHECK_EQ(player_oe.role(), string("OperationsExpert"));
    CHECK_EQ(player_d.role(), string("Dispatcher"));
    CHECK_EQ(player_s.role(), string("Scientist"));
    CHECK_EQ(player_r.role(), string("Researcher"));
    CHECK_EQ(player_m.role(), string("Medic"));
    CHECK_EQ(player_v.role(), string("Virologist"));
    CHECK_EQ(player_gs.role(), string("GeneSplicer"));
    CHECK_EQ(player_fd.role(), string("FieldDoctor"));
}

TEST_CASE("DRIVE")
{
    Board board;
    OperationsExpert player_oe(board, City::Atlanta);
    Dispatcher player_d(board, City::Atlanta);
    Scientist player_s(board, City::Atlanta, 4);
    Researcher player_r(board, City::Atlanta);
    Medic player_m(board, City::Atlanta);
    Virologist player_v(board, City::Atlanta);
    GeneSplicer player_gs(board, City::Atlanta);
    FieldDoctor player_fd(board, City::Atlanta);

    CHECK_NOTHROW(player_d.drive(City::Washington));
    CHECK_THROWS(player_d.drive(City::Tokyo));
    CHECK_NOTHROW(player_m.drive(City::Washington));
    CHECK_THROWS(player_m.drive(City::Tokyo));
}

TEST_CASE("FLY_DIRECT")
{
    Board board;
    OperationsExpert player_oe(board, City::Atlanta);
    Dispatcher player_d(board, City::Atlanta);
    Scientist player_s(board, City::Atlanta, 4);
    Researcher player_r(board, City::Atlanta);
    Medic player_m(board, City::Atlanta);
    Virologist player_v(board, City::Atlanta);
    GeneSplicer player_gs(board, City::Atlanta);
    FieldDoctor player_fd(board, City::Atlanta);

    CHECK_THROWS(player_d.fly_direct(City::Tokyo));
    player_d.take_card(City::Tokyo);
    CHECK_NOTHROW(player_d.fly_direct(City::Tokyo));
    CHECK_THROWS(player_d.fly_direct(City::Miami));
    player_d.take_card(City::Tokyo);
    player_d.build();
    CHECK_NOTHROW(player_d.fly_direct(City::Miami));

    CHECK_THROWS(player_oe.fly_direct(City::Tokyo));
    player_oe.take_card(City::Tokyo);
    CHECK_NOTHROW(player_oe.fly_direct(City::Tokyo));
}

TEST_CASE("FLY_CHARTER")
{
    Board board;
    OperationsExpert player_oe(board, City::Atlanta);
    Dispatcher player_d(board, City::Atlanta);
    Scientist player_s(board, City::Atlanta, 4);
    Researcher player_r(board, City::Atlanta);
    Medic player_m(board, City::Atlanta);
    Virologist player_v(board, City::Atlanta);
    GeneSplicer player_gs(board, City::Atlanta);
    FieldDoctor player_fd(board, City::Atlanta);

    CHECK_THROWS(player_d.fly_direct(City::Tokyo));
    player_d.take_card(City::Atlanta);
    CHECK_NOTHROW(player_d.fly_direct(City::Tokyo));

}

TEST_CASE("FLY_SHUTTLE")
{
    Board board;
    OperationsExpert player_oe(board, City::Atlanta);
    Dispatcher player_d(board, City::Atlanta);
    Scientist player_s(board, City::Atlanta, 4);
    Researcher player_r(board, City::Atlanta);
    Medic player_m(board, City::Atlanta);
    Virologist player_v(board, City::Atlanta);
    GeneSplicer player_gs(board, City::Atlanta);
    FieldDoctor player_fd(board, City::Atlanta);

    CHECK_THROWS(player_d.fly_shuttle(City::Tokyo));
    player_oe.build();
    CHECK_THROWS(player_d.fly_shuttle(City::Tokyo));
    player_oe.take_card(City::Tokyo);
    player_oe.fly_direct(City::Tokyo);
    player_oe.build();
    CHECK_NOTHROW(player_d.fly_direct(City::Tokyo));
}

TEST_CASE("BUILD")
{
    Board board;
    OperationsExpert player_oe(board, City::Atlanta);
    Dispatcher player_d(board, City::Atlanta);
    Scientist player_s(board, City::Atlanta, 4);
    Researcher player_r(board, City::Atlanta);
    Medic player_m(board, City::Atlanta);
    Virologist player_v(board, City::Atlanta);
    GeneSplicer player_gs(board, City::Atlanta);
    FieldDoctor player_fd(board, City::Atlanta);

    CHECK_THROWS(player_d.build()));
    player_d.take_card(City::Atlanta);
    CHECK_NOTHROW(player_d.build());
    CHECK_NOTHROW(player_oe.build());
}
