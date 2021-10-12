//Nikia12200
//Given a 2D array of size N X N . Rotate the array 90 degrees anti-clockwise
#include <bits/stdc++.h>
using namespace std;
void display(int[1000][1000], int);
void rotate(int[1000][1000], int);
int main()
{
    int n;
    cin >> n;
    int a[1000][1000];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Before rotation: " << endl;
    display(a, n);
    rotate(a, n); //function to rotate the image(2d array)
    cout << "After rotation: " << endl;
    display(a, n);
    return 0;
}

void rotate(int a[][1000], int n)
{
    //reverse each row
    for (int row = 0; row < n; row++)
    {
        int start_col = 0;
        int end_col = n - 1;
        while (start_col < end_col)
        {
            swap(a[row][start_col], a[row][end_col]);
            start_col++;
            end_col--;
        }
    }
    //to take transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                swap(a[i][j], a[j][i]);
            }
        }
    }
}

void display(int a[][1000], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}