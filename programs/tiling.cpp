#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, all=0;
    cin >> n;
    int tiling[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> tiling[i][j];
        }
    }

    for(int i=1; i<=9; i++){
        for(int x=0; x<n; x++){
            for(int y=0; y<n; y++){

                if(tiling[x][y] == i){
                    int like=0;

                    if(tiling[x+1][y] == i) like++;
                    if(tiling[x-1][y] == i) like++;
                    if(tiling[x][y+1] == i) like++;
                    if(tiling[x][y-1] == i) like++;

                    if(like == 2 && tiling[x+1][y+1] != i) all++;
                    else if(like == 2 && tiling[x+1][y+1] == i){
                        tiling[x][y] = 0;
                        tiling[x+1][y] = 0;
                        tiling[x][y+1] = 0;
                        tiling[x+1][y+1] = 0;
                    }
                }
            }
        }
    }

    cout << all;

    return 0;
}
/*
3
1 1 0
1 2 2
3 2 2

4
2 2 9 0
2 3 9 9
1 3 3 2
1 1 2 2

5
3 3 6 6 0
3 5 5 6 8
2 2 5 8 8
2 1 4 4 7
1 1 4 7 7
*/
