/* Stadium Seats Manager - Additional training project for Coders School (http://coders.school).
   
   Project start date: 13.05.2021 18:11 by Piotr K. (http://piotrq.eu)

   Contributors:
   Your name could be here ... :)

*/
#include <iostream>
#include <memory>
#include "menu.hpp"
#include "stadium.hpp"
#include "seat.hpp"

int main()
{
    std::shared_ptr<stadium> StadiumManager = std::make_shared<stadium>(30, 5, 3); // Create Stadium Manager object. Define the size of Stadium (SeatsInLine*RowsOfLines*Floors)
    menu MenuManager(StadiumManager);                                              // Create MenuManager object and push StadiumManager object smart pointer inside;

    MenuManager(); // Overloaded () function begin main menu loop.
}