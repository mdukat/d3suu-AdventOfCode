#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> sanityNumbers = {7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1};
vector<int> inputNumbers = {14,30,18,8,3,10,77,4,48,67,28,38,63,43,62,12,68,88,54,32,17,21,83,64,97,
                            53,24,2,60,96,86,23,20,93,65,34,45,46,42,49,71,9,61,16,31,1,29,40,59,87,
                            95,41,39,27,6,25,19,58,80,81,50,79,73,15,70,37,92,94,7,55,85,98,5,84,99,
                            26,66,57,82,75,22,89,74,36,11,76,56,33,13,72,35,78,47,91,51,44,69,0,90,52};

class bingoCard {
    int bingo[5][5];
    int selected[5][5];
    int rowsWritten = 0;
    public:
        bingoCard();
        //void writeBingo(int row[5]);
        //int isBingoWon();
        //void addNumber(int number);
        //void showBingo();
        //void showSelected();
};

bingoCard::bingoCard(){
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            bingo[i][j] = 0;
            selected[i][j] = 0;
        }
    }
}

int main()
{
    cout<<"Hello World"<<endl;
    
    // Write bingo cards

    return 0;
}
