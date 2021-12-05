#include <iostream>
#include <string>

/*
    Read from stdin, make sure to add ';' on end of each line 
*/


using namespace std;

int main()
{
    cout<<"Hello World"<<endl;
    
    // sanity
    int world[10][10];
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++)
            world[i][j] = 0;
    }
    
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
                for(int i = values[1]; i<=values[3]; i++){
                    world[i][values[0]]++;
                }
            }
            if(values[1] > values[3]){
                for(int i = values[1]; i>=values[3]; i--){
                    world[i][values[0]]++;
                }
            }
            if(values[1] == values[3]){
                world[values[1]][values[0]]++;
            }
        }
        
        if(values[1] == values[3]){ // only vertical
            if(values[0] < values[2]){
                for(int i = values[0]; i<=values[2]; i++){
                    world[values[1]][i]++;
                }
            }
            if(values[0] > values[2]){
                for(int i = values[0]; i>=values[2]; i--){
                    world[values[1]][i]++;
                }
            }
            if(values[0] == values[2]){
                world[values[0]][values[2]]++;
            }
        }
        
        
        
    }
    
    // print world
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            cout << world[i][j];
        }
        cout << endl;
    }

    return 0;
}
