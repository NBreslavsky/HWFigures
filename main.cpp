#include <iostream>
/*
@author Alex Avdeev with Nikita Breslavsky
DZ po figuram
*/
using namespace std;
struct Points
{
    int x;
    int y;
};

class Figure{
private:
    Points* points = NULL;
    int* tops = NULL;
public:
    Figure() {}

    Figure(int tops)
    {
        try
        {
            if (tops < 3)
                throw "Tops count error";
            else
            {
                this->tops = new int(tops);
                points = (Points*)malloc(*this->tops * sizeof(Points));
            }
        }
        catch (const char* msg)
        {
            cout << msg << endl;
        }
    }

    void SetPoints()
    {
        for (int i = 0; i < *tops; i++)
        {
            cin >> points[i].x >> points[i].y;
        }
    }

    virtual void GetName()
    {
        cout << "Фигура" << endl;
    }

    virtual float GetSquare()
    {
        float* square = new float(0.0);

        for (int i = 0; i < *tops - 1; i++)
        {
            *square += 0.5 * abs(points[i].x * points[i + 1].y - points[i + 1].x * points[i].y);
        }
        *square += 0.5 * abs(points[*tops].x * points[0].y - points[0].x * points[*tops].y);

        return *square;
    }

    virtual float GetPerimeter()
    {
        float* perimeter = new float(0.0);

        for (int i = 0; i < *tops - 1; i++)
        {
            *perimeter += sqrt(pow(points[i + 1].x - points[i].x, 2) + pow(points[i + 1].y - points[i].y, 2));
        }
        *perimeter += sqrt(pow(points[*tops - 1].x - points[0].x, 2) + pow(points[*tops - 1].y - points[0].y, 2));

        return *perimeter;
    }
    ~Figure()
    {
        delete tops;
        free(points);
    }
};

class Rectangle : public Figure  // Класс прямоугольника
{
protected:
    int* width = NULL;
    int* height = NULL;
    using  Figure::SetPoints;
public:
    Rectangle(int w, int h)
    {
        width = new int(w);
        height = new int(h);
    }

    void GetName()
    {
        cout << "Прямоугольник" << endl;
    }

    virtual float GetSquare()
    {
        return *width * *height;
    }

    virtual float GetPerimeter()
    {
        return 2 * (*width + *height);
    }

    ~Rectangle()
    {
        delete width;
        delete height;
    }
};

class Square : public Rectangle  // Класс квадрата
{
public:
    Square(int side)
            : Rectangle(side, side) {}

    void GetName()
    {
        cout << "Квадрат" << endl;
    }

    float GetSquare()
    {
        return pow(*width, 2);
    }

    float GetPerimeter()
    {
        return 4 * *width;
    }
};

class Circle : public Figure // Класс круга
{
private:
    int* radius = NULL;
public:
    Circle(int radius)
    {
        this->radius = new int(radius);
    }

    void GetName()
    {
        cout << "Круг" << endl;
    }

    float GetSquare()
    {
        return 3.14 * pow(*radius, 2);
    }

    float GetPerimeter()
    {
        return 2 * 3.14 * *radius;
    }

    ~Circle()
    {
        delete radius;
    }
};

class Ellipse : public Figure  // Класс элипса
{
private:
    int* r = NULL;
    int* R = NULL;
public:
    Ellipse(int r, int R)
    {
        this->r = new int(r);
        this->R = new int(R);
    }

    void GetName()
    {
        cout << "Эллипс" << endl;
    }

    float GetSquare()
    {
        return 3.14 * *r * *R;
    }

    float GetPerimeter()
    {
        return 2 * 3.14 * sqrt(pow(*r, 2) * pow(*R, 2) / 2);
    }

    ~Ellipse()
    {
        delete r;
        delete R;
    }
};

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    const int count = 100;
    Figure* figure[count];

    for (int i = 0; i < count; i++)
    {
        if (i % 2 == 0)
            figure[i] = new Rectangle(i, i * 2);
        else if (i % 3 == 0)
            figure[i] = new Square(i);
        else if (i % 5 == 0)
            figure[i] = new Circle(i / 5);
        else
            figure[i] = new Ellipse(i / 2, i);
    }

    for (int i = 0; i < count; i++)
    {
        figure[i]->GetName();
        cout << "S = " << figure[i]->GetSquare() << endl;
        cout << "P = " << figure[i]->GetPerimeter() << endl;
        cout << "" << endl;
    }

    for (int i = 0; i < count; i++)
    {
        delete figure[i];
    }
    return 0;
}