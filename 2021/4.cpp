#include <iostream>
#include <fstream>
#include <string>
#include <sstring>

using namespace std;

class bingoCard {
    int bingo[5][5];
    public:
        void writeBingo(string input);
        int isBingoWon();
        void addNumber(int number);
}

int main()
{
    cout<<"Hello World";

    return 0;
}
