#include<bits/stdc++.h>     // Accepted
using namespace std;

void display(int n, vector<vector<int>>& mv) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<mv[i][j]<<" ";
        } 
        cout<<"\n";
    }
}

void knightTour(int n, int r, int c, int move, vector<vector<int>>& mv) {  // mv -> moves vector

    if(r < 0 || c < 0 || r >= n || c >= n || mv[r][c] > 0) {
        return;
    }
    else if(move == n*n) {
        mv[r][c] = move;
        display(n,mv);
        mv[r][c] = 0;
        return;
    }

    mv[r][c] = move;

    knightTour(n,r-2, c+1, move+1, mv);
    knightTour(n,r-1, c+2, move+1, mv);
    knightTour(n,r+1, c+2, move+1, mv);
    knightTour(n,r+2, c+1, move+1, mv);
    knightTour(n,r+2, c-1, move+1, mv);
    knightTour(n,r+1, c-2, move+1, mv);
    knightTour(n,r-1, c-2, move+1, mv);
    knightTour(n,r-2, c-1, move+1, mv);

    mv[r][c] = 0;

    return;
}

int main() {
    int n,r,c;
    cin >> n >> r >> c;

    vector<vector<int>> mv(n,vector<int>(n,0));

    knightTour(n,r,c,1,mv);


    return 0;
}