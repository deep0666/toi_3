#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, max_cake, cake=0, c8=0, c6=0, c4=0, c2=0, c1=0;
    cin >> n;

    for(int i=0; i<n; i++){
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        c8 += a, c6 += b, c4 += c, c2 += d, c1 += e;
    }

    //cout << c8 << c6 << c4 << c2 << c1 << endl;

    while(c6 > 0){
        max_cake = 6;
        c6--;

        while(c2 > 0 && max_cake < 8){
            max_cake += 2;
            c2--;
        }
        while(c1 > 0 && max_cake < 8){
            max_cake += 1;
            c1--;
        }

        cake++;
    }

    //cout << c8 << c6 << c4 << c2 << c1 << endl;

    while(c4 > 0){
        max_cake = 4;
        c4--;

        while(c4 > 0 && max_cake < 8){
            max_cake += 4;
            c4--;
        }
        while(c2 > 0 && max_cake < 8){
            max_cake += 2;
            c2--;
        }
        while(c1 > 0 && max_cake < 8){
            max_cake += 1;
            c1--;
        }

        cake++;
    }

    //cout << c8 << c6 << c4 << c2 << c1 << endl;

    while(c2 > 0){
        max_cake = 2;
        c2--;

        while(c2 > 0 && max_cake < 8){
            max_cake += 2;
            c2--;
        }
        while(c1 > 0 && max_cake < 8){
            max_cake += 1;
            c1--;
        }

        cake++;
    }

    //cout << c8 << c6 << c4 << c2 << c1 << endl;

    while(c1 > 0){
        max_cake = 1;
        c1--;

        while(c1 > 0 && max_cake < 8){
            max_cake += 1;
            c1--;
        }

        cake++;
    }

    //cout << c8 << c6 << c4 << c2 << c1 << endl;

    cout << cake + c8;

    return 0;
}
/*
3
1 0 1 0 1
0 1 0 1 0
0 1 0 0 0

4
0 0 1 0 0
0 0 0 0 1
0 0 1 0 0
0 1 0 0 0

*/
