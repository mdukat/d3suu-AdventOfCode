#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
#include <tuple>

int p1(std::string data, int noun, int verb){
    std::vector<int> memory;
    std::stringstream datastream;
    datastream << data;

    while(true){
        std::string buffer;
        getline(datastream, buffer, ',');

        if(buffer.size() == 0)
            break;

        //std::cout << std::stoi(buffer) << std::endl;
        memory.push_back(std::stoi(buffer));
    }

    memory[1] = noun;
    memory[2] = verb;

    for(int pc = 0;;){
        if(memory[pc] == 99)
            break;
        if(memory[pc] == 1) {
            memory[memory[pc + 3]] = memory[memory[pc + 1]] + memory[memory[pc + 2]];
        }
        if(memory[pc] == 2)
            memory[memory[pc+3]] = memory[memory[pc+1]] * memory[memory[pc+2]];
        if((memory[pc] != 1) && (memory[pc] != 2) && (memory[pc] != 99)){
            std::cout << "ERROR" << std::endl;
            memory[0] = -1;
            break;
        }
        pc += 4;
    }

    //std::cout << memory[0] << std::endl;
    return memory[0];
}

std::tuple<int, int> p2(std::string data, int lookfor){
    for(int i = 0; i <= 99; i++){
        for(int j = 0; j <= 99; j++){
            int retval = p1(data, i, j);
            if(retval == -1)
                continue;
            if(retval == lookfor)
                return std::make_tuple(i, j);
        }
    }
    return std::make_tuple(0,0);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::string data = "1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,13,1,19,1,19,6,23,1,23,6,27,1,13,27,31,2,13,31,35,1,5,35,39,2,39,13,43,1,10,43,47,2,13,47,51,1,6,51,55,2,55,13,59,1,59,10,63,1,63,10,67,2,10,67,71,1,6,71,75,1,10,75,79,1,79,9,83,2,83,6,87,2,87,9,91,1,5,91,95,1,6,95,99,1,99,9,103,2,10,103,107,1,107,6,111,2,9,111,115,1,5,115,119,1,10,119,123,1,2,123,127,1,127,6,0,99,2,14,0,0";
    std::string tdata = "1,9,10,3,2,3,11,0,99,30,40,50";
    assert(p1(data, 12, 2) == 12490719);
    assert(p1(tdata, 9, 10) == 3500);
    std::cout << "Tests OK" << std::endl;

    std::tuple<int, int> odp = p2(data, 19690720);
    std::cout << std::get<0>(odp) << ' ' << std::get<1>(odp) << std::endl;
    std::cout << 100 * std::get<0>(odp) + std::get<1>(odp) << std::endl;

    return 0;
}
