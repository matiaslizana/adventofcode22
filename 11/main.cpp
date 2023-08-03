#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Monkey.h"

void GetParams(std::string line, const std::string& delimiter, std::vector<std::string>& paramsOutput)
{
    size_t pos = 0;
    while ((pos = line.find(delimiter)) != std::string::npos)
    {
        std::string token = line.substr(0, pos);
        paramsOutput.push_back(token);
        line.erase(0, pos + delimiter.length());
    }
    paramsOutput.push_back(line);
}

bool StartsWith(const std::string& str, const std::string& prefix) {
    return str.substr(0, prefix.size()) == prefix;
}

int main()
{
    std::ifstream inputFile("input"); // Replace "example.txt" with the path to your file
    
    //Read File
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::shared_ptr<Monkey>> monkeys = {};

    while (std::getline(inputFile, line))
    {
        if (StartsWith(line, "Monkey"))
            monkeys.push_back(std::make_shared<Monkey>());
    }

    inputFile.clear();
    inputFile.seekg(0);

    int monkeyCount = 0;
    while (std::getline(inputFile, line))
    {
        std::string itemsStr {};
        std::string operationStr {};
        std::string divisibleStr {};
        std::string trueMonkeyStr {};
        std::string falseMonkeyStr {};
        std::string emptyStr {};
            
        std::getline(inputFile, itemsStr);
        std::getline(inputFile, operationStr);
        std::getline(inputFile, divisibleStr);
        std::getline(inputFile, trueMonkeyStr);
        std::getline(inputFile, falseMonkeyStr);
        std::getline(inputFile, emptyStr);

        std::vector<std::string> items {};
        GetParams(itemsStr.substr(18), ",", items);
        for (int i = 0; i < items.size(); i++)
            monkeys[monkeyCount]->AddItem(stoi(items[i]));

        std::vector<std::string> params {};
        GetParams(operationStr.substr(23), " ", params);
        monkeys[monkeyCount]->SetOperation(params[0], params[1]);
        
        monkeys[monkeyCount]->SetDivisible(stoi(divisibleStr.substr(21)));

        int trueMonkey = stoi(trueMonkeyStr.substr(29));
        int falseMonkey = stoi(falseMonkeyStr.substr(30));
        monkeys[monkeyCount]->SetTrueMonkey(monkeys[trueMonkey]);
        monkeys[monkeyCount]->SetFalseMonkey(monkeys[falseMonkey]);

        monkeyCount++;
    }
    
    inputFile.close();

    constexpr int numRounds = 20;

    for (int round = 0; round < numRounds; round++)
    {
        for (std::shared_ptr<Monkey> m : monkeys)
            m->Turn();

        int monkey = 0;
        std::cout << "Round " << round << ": " << std::endl;
        std::cout << "-----------------" << std::endl;

        for (std::shared_ptr<Monkey> m : monkeys)
        {
            std::cout << "Monkey " << monkey << ": ";
            m->ShowItems();
            std::cout << std::endl;
            monkey++;
        }
        std::cout << std::endl;
    }

    std::vector<int> mostInspectedMonkeys (monkeys.size());

    for (int i = 0; i < monkeys.size(); i++)
        mostInspectedMonkeys[i] = monkeys[i]->GetInspectedItems();

    std::sort(mostInspectedMonkeys.begin(), mostInspectedMonkeys.end());
    std::reverse(mostInspectedMonkeys.begin(), mostInspectedMonkeys.end());

    int monkeyBusiness = 0;
    if(mostInspectedMonkeys.size() >= 2)
        monkeyBusiness = mostInspectedMonkeys[0] * mostInspectedMonkeys[1];
	
    std::cout << "Monkey Business: " << monkeyBusiness << std::endl;

    return 0;
}