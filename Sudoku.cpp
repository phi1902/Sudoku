#include<bits/stdc++.h>
using namespace std;

int cell[9][9];
bool check[9][9];
int sol[9][9];
bool visited[10];

void print(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            printf("%d ", sol[i][j]);
        }
        puts("");
    }
}
void cl(){
    for(int i = 1; i <= 9; i++){
        visited[i] = false;
    }
}
bool isok(int x, int y){
    int cell9x = (x / 3) * 3;
    int cell9y = (y / 3) * 3;

    cl();
    for(int i = cell9x; i < cell9x + 3; i++){
        for(int j = cell9y; j < cell9y + 3; j++){
            if(sol[i][j] != 0){
                if(visited[sol[i][j]] == true){
                    return false;
                }else{
                    visited[sol[i][j]] = true;
                }
            }
        }
    }
    cl();
    for(int i = 0; i < 9; i++){
        if(sol[i][y] != 0){
            if(visited[sol[i][y]] == true){
                return false;
            }else{
                visited[sol[i][y]] = true;
            }
        }
    }
    cl();
    for(int j = 0; j < 9; j++){
        if(sol[x][j] != 0){
            if(visited[sol[x][j]] == true){
                return false;
            }else{
                visited[sol[x][j]] = true;
            }
        }
    }
    return true;
}
void solve(int x, int y){
    if(check[x][y] == true){
        if(x < 8 || y < 8){
            if(y < 8){
                solve(x, y + 1);
            }else{
                solve(x + 1, 0);
            }
        }else{
            print();
            exit(0);
        }
    }else{
        for(int i = 1; i <= 9; i++){
            sol[x][y] = i;
            if(isok(x, y)){
                if(x < 8 || y < 8){
                    if(y < 8){
                        solve(x, y + 1);
                    }else{
                        solve(x + 1, 0);
                    }
                }else{
                    print();
                    exit(0);
                }
            }
        }
        sol[x][y] = 0;
    }
}
int main(){
    // trống = false, x;
    // có số = true, số;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            sol[i][j] = 0;
        }
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            scanf("%d", &cell[i][j]);
            if(cell[i][j] == 0){
                check[i][j] = false;
            }else{
                check[i][j] = true;
                sol[i][j] = cell[i][j];
            }
        }
    }
    puts("");
    solve(0, 0);
}
// LOL :))
