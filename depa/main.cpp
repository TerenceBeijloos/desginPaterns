#include "Circuit.h"

#include <iostream>
#include "Defines.h"
#include <vector>
#include "Input.h"

int main()
{
    Input i;
    i.addInput("hoi");
    i.addInput("doei");

    i.setInput("hoi", true);
    i.setInput("doei", true);

    for (const auto &p : i.iterateObj())
    {
        std::cout << p.first << '\t' << p.second;
    }
    //Circuit circuit;

    //circuit.addComponent(STR_AND, "NODE1");

    std::cin.get();

    return 0;
}