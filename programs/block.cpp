#include <iostream>
using namespace std;

int m, n, l, score=0;

int re(char arr[6][6], int x, int y){

    while(x > 0 && arr[x-1][y] != '#'){
        arr[x][y] = arr[x-1][y];
        arr[x-1][y] = '-';
        --x;
    }

    return 0;
}

int main(){

    cin >> m >> n;

    char arr[6][6];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    cin >> l;

    for(int i=0; i<l; i++){

        int like=0, x, y;
        char text;
        cin >> x >> y >> text;

        if(text == 'L' && arr[x][y-1] != '#'){
            arr[x][y-1] = arr[x][y];
            arr[x][y] = '-';
            --y;
        }
        else if(text == 'R' && arr[x][y+1] != '#'){
            arr[x][y+1] = arr[x][y];
            arr[x][y] = '-';
            ++y;
        }
        else score -= 5;

        while(arr[x+1][y] == '-'){
            arr[x+1][y] = arr[x][y];
            arr[x][y] = '-';
            ++x;
        }

        if(arr[x][y+1] == arr[x][y]){
            ++like;
            arr[x][y+1] = '-';

            re(arr, x, y+1);
        }
        if(arr[x][y-1] == arr[x][y]){
            ++like;
            arr[x][y-1] = '-';

            re(arr, x, y-1);
        }
        if(arr[x-1][y] == arr[x][y]){
            ++like;
            arr[x-1][y] = '-';

            re(arr, x-1, y);
        }
        if(arr[x+1][y] == arr[x][y]){
            ++like;
            arr[x+1][y] = '-';
        }

        if(like > 0){
            arr[x][y] = '-';
            re(arr, x, y);

            score += (like * 5) + 5;
        }
    }

    cout << score << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }cout << endl;
    }

    return 0;
}
/*
4 5
# A - - #
# # - B #
# A B # #
# # # # #
2
1 3 L
0 1 R

5 5
# A – B #
# B - A #
# # - B #
# A B # #
# # # # #
3
0 1 L
0 3 L
0 1 R

*/
