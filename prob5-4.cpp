#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
using namespace std;

const int MAX_SIZE = 100;
const int PATH = 1; 
const int VISITED = 2; 

int maze[MAX_SIZE][MAX_SIZE];

ifstream mazefile("input.txt");

void read_maze() {
    mazefile >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mazefile >> maze[i][j];
        }
    }
}

void print_maze() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

struct Position {
    int x, y;
    Position() {}
    Position(int x, int y) : x(x), y(y) {}
};

int offset[8][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1},
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1} 
};
bool is_in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool is_path(int x, int y) {
    return is_in(x, y) && maze[x][y] == PATH;
}

int move(Position start) {
    stack<Position> s;
    s.push(start);
    int size = 0;

    while (!s.empty()) {
        Position cur = s.top();
        s.pop();

        if (maze[cur.x][cur.y] == VISITED) continue;

        maze[cur.x][cur.y] = VISITED;
        size++;

        for (int i = 0; i < 8; i++) {
            int x = cur.x + offset[i][0];
            int y = cur.y + offset[i][1];

            if (is_path(x, y)) {
                s.push(Position(x, y));
            }
        }
    }

    return size;
}

void find_components() {
    int count = 0;
    vector<int> s;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (maze[i][j] == PATH) {
                int size = move(Position(i, j));
                s.push_back(size);
                count++;
            }
        }
    }

    for (int i = 0; i < s.size(); i++) {
        cout << s[i]<<" ";
    }
}

int main() {
    int m;
    mazefile >> m;

    for (int i = 0; i < m; i++) {
        read_maze();
        
        find_components();
        cout << endl;
    }

    return 0;
}