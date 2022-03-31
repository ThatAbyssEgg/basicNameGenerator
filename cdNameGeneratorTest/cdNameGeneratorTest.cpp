#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

int main()
{
repeatWithAnotherFile:

    int option;
    std::cout << "1: Male" << endl << "2: Female" << endl << "3: Events" << endl;
    cin >> option;

repeat:
    std::ifstream ifs;

    if (option == 1)
    {
        ifs.open("maleCharNames.json");
    }
    else if (option == 2)
    {
        ifs.open("femaleCharNames.json");
    }
    else if (option == 3)
    {
        ifs.open("events.json");
    }
    else
    {
        cout << "Please, input the needed number.";
    }
    if (!ifs.is_open())
    {
        std::cerr << "Unable to open file\n";
        throw 1;
    }

    srand(time(NULL));

    json j;
    ifs >> j;
    ifs.close();
     
    string randomFirstLine = j["firstNames"][rand() % j["firstNames"].size()];

    j.find("middleNames");
    string randomMiddleLine = j["middleNames"][rand() % j["middleNames"].size()];

    std::cout << randomFirstLine << randomMiddleLine << endl;
    
    string finalOption;
    
    cout << "1: Repeat" << endl << "2: Repeat with another file" << endl << "3: Exit" << endl;
    cin >> finalOption;

    if (finalOption == "1")
    {
        goto repeat;
    }
    else if (finalOption == "2")
    {
        goto repeatWithAnotherFile;
    }
    else 
    {
        system("pause");
    }

    return 0;  
}
