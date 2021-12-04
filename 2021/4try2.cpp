#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numbers = {7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1};
    
    int bingos_n = 3;
    
    int sanity[][5][5] = {{
            {22,13,17,11,0},
            {8,2,23,4,24},
            {21,9,14,16,7},
            {6,10,3,18,5},
            {1,12,20,15,19}
        },{
            {3,15,0,2,22},
            {9,18,13,17,5},
            {19,8,7,25,23},
            {20,11,10,24,4},
            {14,21,16,12,6}
        },{
            {14,21,17,24,4},
            {10,16,15,9,19},
            {18,8,23,26,20},
            {22,11,13,6,5},
            {2,0,12,3,7}
        }};
    
    cout<<"Hello World"<<endl;
    
    for(int i = 0; i<3; i++){
        for(int j = 0; j<5; j++){
            for(int k = 0; k<5; k++){
                cout << sanity[i][j][k] << '\t';
            }
            cout << endl;
        }
        cout << endl;
    }
    
    for(int numberi = 0; numberi<numbers.size(); numberi++){
        for(int bingo = 0; bingo<3; bingo++){
            
            for(int i = 0; i<5; i++){
                for(int j = 0; j<5; j++){
                    if(numbers[numberi] == sanity[bingo][i][j]){
                        sanity[bingo][i][j] = -1;
                    }
                }
            }
            
        }
        
        // check if bingo horizontal
        for(int bingo = 0; bingo<3; bingo++){
            for(int i = 0; i<5; i++){
                if(sanity[bingo][i][0] == -1 &&
                   sanity[bingo][i][1] == -1 &&
                   sanity[bingo][i][2] == -1 &&
                   sanity[bingo][i][3] == -1 &&
                   sanity[bingo][i][4] == -1){
                    cout << "Win on horizontal bingo #" << bingo+1 << " on line " << i+1 << " with last number " << numbers[numberi] << endl;
                    int sum = 0;
                    for(int j = 0; j<5; j++){
                        for(int k = 0; k<5; k++){
                            if(sanity[bingo][j][k] != -1)
                                sum += sanity[bingo][j][k];
                        }
                    }
                    int fscore = sum*numbers[numberi];
                    cout << "Sum is " << sum << "; Final score: " << fscore << endl;
                    return 0;
                }
            }
        }
        
        // check if bingo vertical
        for(int bingo = 0; bingo<3; bingo++){
            for(int i = 0; i<5; i++){
                if(sanity[bingo][0][i] == -1 &&
                   sanity[bingo][1][i] == -1 &&
                   sanity[bingo][2][i] == -1 &&
                   sanity[bingo][3][i] == -1 &&
                   sanity[bingo][4][i] == -1){
                    cout << "Win on vertical bingo #" << bingo+1 << " on line " << i+1 << " with last number " << numbers[numberi] << endl;
                    int sum = 0;
                    for(int j = 0; j<5; j++){
                        for(int k = 0; k<5; k++){
                            if(sanity[bingo][j][k] != -1)
                                sum += sanity[bingo][j][k];
                        }
                    }
                    int fscore = sum*numbers[numberi];
                    cout << "Sum is " << sum << "; Final score: " << fscore << endl;
                    return 0;
                }
            }
        }
    }
    

    return 0;
}
