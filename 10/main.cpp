#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>

const int crtWidth = 40;
const int crtHeight = 6;
const int crtSize = crtWidth * crtHeight;

void DrawCRT(std::array<char, 240>& crt, int index, int X)
{
    crt[index] = index%40 >= X - 1 && index%40 <= X + 1 ? '#' : '.';
}

void GetCodeParams(std::string codeLine, const std::string& delimiter, std::vector<std::string>& paramsOutput)
{
    size_t pos = 0;
    std::string token;
    while ((pos = codeLine.find(delimiter)) != std::string::npos)
    {
        token = codeLine.substr(0, pos);
        paramsOutput.push_back(token);
        codeLine.erase(0, pos + delimiter.length());
    }
    paramsOutput.push_back(codeLine);
}

int GetSignalStrength(std::vector<std::string>& code, std::array<char, crtSize>& crt, int cycle)
{
    //Calculate X value on cycles
    int X = 1;
    int currentCycle = 1;
    int currentLine = 0;

    while(currentCycle < cycle)
    {
        std::vector<std::string> params = {};
        GetCodeParams(code[currentLine], " ", params);
        //noop
        if (params[0].at(0) == 'n')
        {
            DrawCRT(crt, currentCycle - 1, X);
            currentCycle++;
        }
        //addx
        else if (params[0].at(0) == 'a')
        {
            int add = std::stoi(params[1]);
            DrawCRT(crt, currentCycle - 1, X);
            currentCycle++;
            if (currentCycle == cycle)
                return X * cycle;
            DrawCRT(crt, currentCycle - 1, X);
            currentCycle++;
            X+= add;
        }
        currentLine++;
    }

    //Return signal strength
    return X * cycle;
}

int main()
{
    std::ifstream inputFile("input"); // Replace "example.txt" with the path to your file
    std::vector<std::string> codeLines = {};
    std::array<char, crtSize> crt = {};

    //Read File
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) 
        codeLines.push_back(line);
    
    inputFile.close();

    //10.A
    int sumSignalStrength = 0;
    for (int i = 20; i <= 220; i+=40)
    {
        int signal = GetSignalStrength(codeLines, crt, i);
        sumSignalStrength += signal;
        std::cout << "signal strength - " << i << "(" << signal << ")" << std::endl;
    }
    std::cout << "total signal strength: " << sumSignalStrength << std::endl;

    //10.B
    GetSignalStrength(codeLines, crt, crtSize);
    for (int y = 0; y < crtHeight; y++)
    {
        for (int x = 0; x < crtWidth; x++)
            std::cout << crt[y * crtWidth + x];
        std::cout << std::endl;
    }

	return 0;
}