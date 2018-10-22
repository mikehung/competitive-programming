#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x, y;
};

struct Figure {
    char type;
    Figure(char t): type(t) {}
    virtual bool contain(const Point &p) = 0;
    virtual ~Figure() {}
};

struct Rectangle: public Figure {
    Rectangle(): Figure('r') {}
    double ax, ay, bx, by;
    bool contain(const Point &p) {
        return ax < p.x && bx > p.x && ay < p.y && by > p.y;
    }
};

struct Circle: public Figure {
    Circle(): Figure('c') {}
    double a, b, r;
    bool contain(const Point &p) {
        return (p.x-a)*(p.x-a) + (p.y-b)*(p.y-b) < r*r;
    }
};

Point p;
Rectangle rec;
Circle cir;
Figure *figure;
vector<Figure*> figures;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char ch;
    while (cin >> ch) {
        if (ch == '*') break;
        if (ch == 'r') {
            cin >> rec.ax >> rec.by >> rec.bx >> rec.ay;
            figure = new Rectangle(rec);
        } else {
            cin >> cir.a >> cir.b >> cir.r;
            figure = new Circle(cir);
        }
        figures.push_back(figure);
    }

    int i = 0;
    while (cin >> p.x >> p.y && (p.x != 9999.9 || p.y != 9999.9)) {
        ++i;
        bool ok = false;
        for (int j = 0; j < (int) figures.size(); ++j) {
            if (figures[j]->contain(p)) {
                ok = true;
                cout << "Point " << i << " is contained in figure " << j+1 << '\n';
            }
        }
        if (!ok) {
            cout << "Point " << i << " is not contained in any figure\n";
        }
    }
    for (auto &figure: figures) {
        delete figure;
    }

    return 0;
}
