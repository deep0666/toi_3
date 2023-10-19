#include <bits/stdc++.h>
using namespace std;

int main(){
    int w, h, n, cap50=0, cap100=0;
    cin >> w >> h >> n;

    int filter[h][w+10];
    for(int i=0; i<h; i++){
        for(int j=0; j<=w; j++){
            filter[i][j] = 0;
        }
    }

    for(int b=0; b<n; b++){
        int x, a;
        cin >> x >> a;

        for(int j=x; j<x+a; j++){
            for(int k=0; k<h; k++){
                //cout << k << " " << j << endl;
                filter[k][j] += 1;
            }
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(filter[i][j] == 1) cap50++;
            if(filter[i][j] == 0) cap100++;
        }
    }

    cout << cap100 << " " << cap50;

    return 0;
}
/*
7 3 3
1 2
5 3
2 2

7 3 2
0 3
2 4
*/
