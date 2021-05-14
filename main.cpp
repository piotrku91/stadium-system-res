#include <iostream>
#include <memory>
#include "menu.hpp"
#include "stadium.hpp"
#include "seat.hpp"

int main()
{

    std::shared_ptr<stadium> StadiumManager = std::make_shared<stadium>(30, 5, 3);
    menu MenuManager(StadiumManager);
    MenuManager();

};