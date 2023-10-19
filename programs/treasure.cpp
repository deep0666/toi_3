#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int n_num[500], nn=0, nt=0, nts=0;;
double x=0, y=0, point;
char n_news[500][3];

double result(double x, double y){
    x *= x;
    y *= y;

    return sqrt(x+y);
}

void set_point(){
    for(int i=0; i<nn; ++i){

        double n = (n_num[i] * n_num[i])/2;

        if(strcmp(n_news[i], "N") == 0){
            y += n_num[i];
        }
        else if(strcmp(n_news[i], "NE") == 0){
            x += sqrt(n);
            y += sqrt(n);
        }
        else if(strcmp(n_news[i], "E") == 0){
            x += n_num[i];
        }
        else if(strcmp(n_news[i], "SE") == 0){
            x += sqrt(n);
            y -= sqrt(n);
        }
        else if(strcmp(n_news[i], "S") == 0){
            y -= n_num[i];
        }
        else if(strcmp(n_news[i], "SW") == 0){
            x -= sqrt(n);
            y -= sqrt(n);
        }
        else if(strcmp(n_news[i], "W") == 0){
            x -= n_num[i];
        }
        else if(strcmp(n_news[i], "NW") == 0){
            x -= sqrt(n);
            y += sqrt(n);
        }
    }
}

int cut(string text){

    for(int i=0; i<text.length(); ++i){
        if(text[i] >= '0' && text[i] <= '9'){
            n_num[nn] = text[i] - 48;
            ++nn;
        }
        else if(text[i] >= 'A' && text[i] <= 'Z'){
            n_news[nt][nts] = text[i];
            ++nts;
        }
        else if(text[i] == ' '){
            ++nt;
            nts = 0;
        }
    }
}

int main(){
    string text;

    fflush(stdin);
    getline(cin, text);
    cut(text);

    set_point();

    printf("%.3f %.3f\n%.3f", x, y, result(x, y));

}
/*
3N 1E 1N 3E 2S 1W *
6NW *

1N 2NE 3E 4SE 5S 6SW 7W 8NW *
*/
