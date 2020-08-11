/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <bits/stdc++.h>
using namespace std;
#define blocco 1000

int N;
char carattere;
char muro[] = "+" ;
int va, vb, vc; //I valori di paragone

int my_min(int na, int nb, int nc)
{
    if(na<nb && na<nc)
    {
        return na;
    }
    else
    {
        if(nb<nc)
            return nb;
        else
            return nc;
    }
}

int main()
{
//  uncomment the following lines if you want to read/write from files
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> N;
    vector <vector <int> > mappa;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> carattere;
            if(carattere==muro[0])      //Nel caso ci sia un blocco metto un valore di mosse per essere raggiunto alto
            {
                mappa[i].push_back(blocco);
            }
            else
            {
                if(i==0 && j==0)
                {
                    mappa[i].push_back(0);
                }
                else            //Mi creo una mappa con il numero di mosse minime per arrivare a quel punto
                {
                    if(i==0)
                        va=blocco;
                    else
                        va=mappa[i-1][j];

                    if(j==0)
                        vb=blocco;
                    else
                        vb=mappa[i][j-1];

                    if(i==0 || j ==0)
                        vc=blocco;
                    else
                        vc=mappa[i-1][j-1];

                    mappa[i].push_back(my_min(va,vb,vc));
                }
            }
        }
    }

    cout << mappa[N-1][N-1] << endl;
    return 0;
}

