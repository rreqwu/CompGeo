#include <iostream>
#include <vector>

using namespace std;

// ����������� �������� ��� ������������� �����
const int LEFT = -1;
const int BEYOND = -2;

// ��� ������ ��� �����
struct Point {
    int x, y;

    // ���������� ��������� <
    bool operator<(const Point& other) const {
        return x == other.x ? y < other.y : x < other.x;
    }

    // ������� ����������� ��������� ����� ������������ ������� ����� p1 � p2
    int classify(Point p1, Point p2) {
        // ���������� classify �����
        return 0; // �������� �� ���������� ������
    }
};

// ��� ������ ��� ��������
struct Polygon {
    vector<Point> vertices;

    // �������� ����� � �������
    void insert(Point p) {
        vertices.push_back(p);
    }
};

// ������� ��� ���������� �������� ��������
Polygon* giftwrapHull(Point s[], int n) {
    int a, i;
    for (a = 0, i = 1; i < n; i++)
        if (s[i] < s[a])
            a = i;

    Point* tempPoints = new Point[n + 1]; // Allocate memory for n+1 points
    for (int i = 0; i < n; i++) {
        tempPoints[i] = s[i];
    }

    tempPoints[n] = tempPoints[a];

    Polygon* p = new Polygon;

    for (int m = 0; m < n; m++) {
        swap(tempPoints[a], tempPoints[m]);
        p->insert(tempPoints[m]);
        a = m + 1;

        for (int i = m + 2; i < n; i++) {
            int c = tempPoints[i].classify(tempPoints[m], tempPoints[a]);
            if (c == LEFT || c == BEYOND)
                a = i;
        }

        if (a == n) {
            delete[] tempPoints; // Free the allocated memory
            return p;
        }
    }

    delete[] tempPoints; // Free the allocated memory
    return NULL;
}

int main() {
    // ������ ������������� ������� giftwrapHull
    Point points[5] = { {0, 5}, {4, 3}, {2, 0}, {1, 3}, {3, 1} };
    Polygon* convexHull = giftwrapHull(points, 5);

    if (convexHull) {
        cout << "Convex Hull vertices:" << endl;
        for (Point v : convexHull->vertices) {
            cout << v.x << "," << v.y << endl;
        }
    }
    else {
        cout << "No Convex Hull found." << endl;
    }

    return 0;
}