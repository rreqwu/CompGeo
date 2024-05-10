#include <iostream>
#include <vector>

using namespace std;

// Определение констант для классификации точек
const int LEFT = -1;
const int BEYOND = -2;

// Тип данных для точки
struct Point {
    int x, y;

    // Перегрузка оператора <
    bool operator<(const Point& other) const {
        return x == other.x ? y < other.y : x < other.x;
    }

    // Функция определения положения точки относительно отрезка между p1 и p2
    int classify(Point p1, Point p2) {
        // Реализация classify здесь
        return 0; // Замените на актуальную логику
    }
};

// Тип данных для полигона
struct Polygon {
    vector<Point> vertices;

    // Добавить точку в полигон
    void insert(Point p) {
        vertices.push_back(p);
    }
};

// Функция для построения выпуклой оболочки
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
    // Пример использования функции giftwrapHull
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