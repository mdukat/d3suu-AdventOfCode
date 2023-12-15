#include <iostream>
#include <string>

/*
    Read from stdin, make sure to add ';' on end of each line 
*/


using namespace std;

#define WSIZE 1000

int main()
{
    cout<<"Hello World"<<endl;
    
    int world[WSIZE][WSIZE];
    for(int i = 0; i<WSIZE; i++){
        for(int j = 0; j<WSIZE; j++)
            world[i][j] = 0;
    }
    
    int overlap = 0;
    int EOI = 0;
    
    while(EOI != 1){
        string result;
        char c;
        int stage = 0;
        int values[4];
        bool hasData = false;
        while(cin >> c){
            
            hasData = true;
            
            if(stage == 0){
                if(c==','){
                    stage++;
                    values[0] = stoi(result);
                    result.clear();
                    continue;
                }
                result.push_back(c);
            }
            
            if(stage == 1){
                if(c=='-'){
                    stage++;
                    values[1] = stoi(result);
                    result.clear();
                    continue;
                }
                result.push_back(c);
            }
            
            if(stage == 2){ // '>'
                if(c=='>'){
                    stage++;
                    continue;
                }
            }
            
            if(stage == 3){
                if(c==','){
                    stage++;
                    values[2] = stoi(result);
                    result.clear();
                    continue;
                }
                result.push_back(c);
            }
            
            if(stage == 4){
                if(c==';'){
                    values[3] = stoi(result);
                    result.clear();
                    break;
                }
                result.push_back(c);
            }
        }
        
        if(!hasData){
            break;
        }
        
        cout << values[0] << ' ' << values[1] << ' ' << values[2] << ' ' << values[3] << ' ' << endl;
        
        // Work on world
        
        if(values[0] == values[2]){ // only horizontal
            if(values[1] < values[3]){
                cout << "Parsed by 92" << endl;
                for(int i = values[1]; i<=values[3]; i++){
                    world[i][values[0]]++;
                }
            }
            if(values[1] > values[3]){
                cout << "Parsed by 99" << endl;
                for(int i = values[1]; i>=values[3]; i--){
                    world[i][values[0]]++;
                }
            }
            if(values[1] == values[3]){
                cout << "Parsed by 105" << endl;
                world[values[1]][values[0]]++;
            }
            continue;
        }
        
        if(values[1] == values[3]){ // only vertical
            if(values[0] < values[2]){
                cout << "Parsed by 113" << endl;
                for(int i = values[0]; i<=values[2]; i++){
                    world[values[1]][i]++;
                }
            }
            if(values[0] > values[2]){
                cout << "Parsed by 119" << endl;
                for(int i = values[0]; i>=values[2]; i--){
                    world[values[1]][i]++;
                }
            }
            if(values[0] == values[2]){
                cout << "Parsed by 125" << endl;
                world[values[0]][values[2]]++;
            }
            continue;
        }
        
        // diagonal
        int x1 = values[0];
        int y1 = values[1];
        int x2 = values[2];
        int y2 = values[3];
        
        //cout << "Diagonal " << x1 << ',' << y1 << " -> " << x2 << ',' << y2 << endl;
        
        if(x1 < x2){
            if(y1 < y2){
                cout << "Parsed by 141" << endl;
                int X = x1;
                int Y = y1;
                while((X <= x2) && (Y <= y2)){
                    world[X][Y]++;
                    X++;
                    Y++;
                }
            }
            
            // Something is wrong here
            if(y1 > y2){
                cout << "Parsed by 153" << endl;
                //cout << "Diagonal " << x1 << ',' << y1 << " -> " << x2 << ',' << y2 << endl;
                int X = x1;
                int Y = y1;
                while((X <= x2) && (Y >= y2)){
                    //cout << "Point: " << X << ',' << Y << endl;
                    world[Y][X]++; // Yeah, I don't know
                    X+=1;
                    Y-=1;
                }
            }
            
        }
        
        if(x1 > x2){
            if(y1 < y2){
                cout << "Parsed by 169" << endl;
                int X = x1;
                int Y = y1;
                while((X >= x2) && (Y <= y2)){
                    world[X][Y]++;
                    X--;
                    Y++;
                }
            }
            
            // Something is wrong here
            if(y1 > y2){
                cout << "Parsed by 181" << endl;
                //cout << "Diagonal " << x1 << ',' << y1 << " -> " << x2 << ',' << y2 << endl;
                int X = x1;
                int Y = y1;
                while((X >= x2) && (Y >= y2)){
                    //cout << "Point: " << X << ',' << Y << endl;
                    world[Y][X]++; // Yeah, I don't know
                    X--;
                    Y--;
                }
            }
            
        }
        
        
        
    }
    
    // print world
    for(int i = 0; i<WSIZE; i++){
        for(int j = 0; j<WSIZE; j++){
            
            if(world[i][j] == 0)
                cout << '.';
            else
                cout << world[i][j];
                
            if(world[i][j] >= 2)
                overlap++;
                
        }
        cout << endl;
    }
    
    cout << "Overlap: " << overlap << endl;

    return 0;
}
