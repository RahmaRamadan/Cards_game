#include <bits/stdc++.h>

using namespace std;

int cards [4][4] ;
int arr [9] = {0} ;

void print () ;

int main()
{
    int arrangement [9] = {0} ;

    int counter = 1 ;
    int temp = 0 ;

    while (counter <= 8)
    {
        temp = rand() % 9; //random
        if (arr[temp] == 0 && temp != 0)
        {
            arr[temp] ++, arrangement[counter ++] = temp ; //fill in array
        }
    }

    counter = 1;
    for (int i=0 ; i<2 ; i++)
        for(int j=0 ; j<4 ; j++)
            cards[i][j] = arrangement[counter++] ;

    counter = 1;
    for (int i=3 ; i>1 ; i--)
        for (int j=3 ; j>=0 ; j--)
            cards[i][j] = arrangement[counter++] ;

    bool finish = false ;
    int x1, y1, x2, y2 ;
    memset(arr, 0, sizeof(arr));
    counter = 0;
    while (!finish)
    {
        print() ;
        cout << "Enter Coordinates of First Card : " ;
        cin >> x1 >> y1 ;
        x1-- ;
        y1-- ;

        cout << "Enter Coordinates of Second Card : " ;
        cin >> x2 >> y2 ;
        x2--;
        y2--;

        if (cards [x1][y1] == cards [x2][y2]) //if two numbers is equal to each other boo = true
            arr [ cards[x1][y1] ] = 1, counter ++;
        if (counter == 8)
            finish = true ;


    }
    print () ;
    cout << "The Game ended \n" ;

    return 0;
}


void print () //to show data
{
    cout << "\n\n      1    2    3    4   " << endl ;
    cout << "      ----------------   " << endl ;
    int row = 1 ;
    for (int i=0 ; i<4 ; i++)
    {
        cout << row++ << "|" ;
        for (int j=0 ; j<4 ; j++)
        {
            if (arr[ cards[i][j] ] == 0)
                cout << "    *" ;
            else
                cout << "    " << cards [i][j]  ;
        }
        cout << endl ;
    }
}
