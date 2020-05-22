#include "Circuit.h"

#include <iostream>
#include "Defines.h"
#include <vector>
#include <string>
#include "Input.h"
#include "AdjList.h"
#include "InputFileHandler.h"

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

	AdjList testList;

    for(int i = 0; i < 5; i++){
        testList.addVertex();
        testList.addEdge(i, 2+i);
        testList.addEdge(i, 9-i);
	}


    InputFileHandler fileHandler;
    std::string fileName = "circuit1.txt";

    fileHandler.getNodeDescriptions(fileName);

    std::cin.get();

    return 0;
}