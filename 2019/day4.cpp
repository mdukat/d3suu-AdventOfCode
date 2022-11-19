#include <iostream>
#include <sstream>

int getNumberFromPosition(std::string s, int pos){
    int retval;
    std::stringstream number;
    number << s[pos];
    number >> retval;
    number.clear();
    return retval;
}

int p1(int lower, int upper){

    int correctPasswords = 0;

    for(int i = lower; i<= upper; i++){
        std::stringstream ss;
        ss << i;
        std::string s;
        ss >> s;

        // Going from left to right, the digits never decrease
        int buffer = 0;
        int neverDecrease = 0;
        for(int j = 0; j<6; j++){
            int current = getNumberFromPosition(s, j);

            if(current >= buffer){
                buffer = current;
                neverDecrease++;
            }else{
                break;
            }
        }

        if(neverDecrease != 6) {
            continue;
        }

        // Two adjacent digits are the same
        int sameAdjacent = 0;
        for(int j = 0; j<5; j++){
            int current = getNumberFromPosition(s, j);
            int next = getNumberFromPosition(s, j+1);

            if(current == next)
                sameAdjacent++;
        }

        if(sameAdjacent == 0){
            continue;
        }

        if((sameAdjacent > 0) && (neverDecrease == 6)){
            correctPasswords++;
        }
    }
    return correctPasswords;
}

int p2(int lower, int upper){

    int correctPasswords = 0;

    for(int i = lower; i<= upper; i++){
        std::stringstream ss;
        ss << i;
        std::string s;
        ss >> s;

        // Going from left to right, the digits never decrease
        int buffer = 0;
        int neverDecrease = 0;
        for(int j = 0; j<6; j++){
            int current = getNumberFromPosition(s, j);

            if(current >= buffer){
                buffer = current;
                neverDecrease++;
            }else{
                break;
            }
        }

        if(neverDecrease != 6) {
            continue;
        }

        // Two adjacent digits are the same
        int sameAdjacent = 0;
        for(int j = 0; j<5; j++){
            int current = getNumberFromPosition(s, j);
            int next = getNumberFromPosition(s, j+1);

            if(current == next)
                sameAdjacent++;
        }

        if(sameAdjacent == 0){
            continue;
        }

        // two adjacent matching digits are not part of a larger group of matching digits
        // This does not work properly, as it ignores cases with correct number pairs
        int sameBigAdjacent = 0;
        for(int j = 0; j<4; j++){
            int current = getNumberFromPosition(s, j);
            int next = getNumberFromPosition(s, j+1);
            int nextnext = getNumberFromPosition(s, j+2);

            if((current == next) && (next == nextnext))
                sameBigAdjacent++;
        }

        if(sameBigAdjacent != 0){
            continue;
        }

        if((sameAdjacent > 0) && (neverDecrease == 6) && (sameBigAdjacent == 0)){
            correctPasswords++;
        }
    }
    return correctPasswords;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << p1(265275, 781584) << std::endl;
    std::cout << p2(265275, 781584) << std::endl;
    return 0;
}
