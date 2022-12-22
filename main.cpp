#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

class Circles
{
public:

    int m_R;
    double X;
    double Y;
    sf::CircleShape m_circle;


    Circles(int R, int x, int y, sf::CircleShape Circle)
    {
        m_R = R;
        X = x;
        Y = y;
        m_circle = Circle;
    }
    Circles()
    {
    }
    ~Circles(){}

    void set()
    {
        m_circle.setPosition(X/2 - m_R, Y - 2 * (m_R));
        m_circle.setFillColor(sf::Color(0xFF0000FF));
    }
    /*void pos(int x, int y)
    {
        m_circle.setPosition(x,y);
    }*/
    void move()
    {
        if (m_circle.getPosition().y > 0)
        {
            m_circle.move(0, -40);
        }
        if (m_circle.getPosition().y < 0)
        {
            m_circle.setPosition(m_circle.getPosition().x, 0);
        }
    }

};

class Squares
{
public:
    int m_A;
    double X;
    double Y;
    sf::RectangleShape m_square;

    Squares(int A, double x, double y, sf::RectangleShape square)
    {
        m_A = A;
        X = x;
        Y = y;
        m_square = square;
    }
    ~Squares()
    {}

    void set()
    {
        m_square.setPosition(X / 3 - m_A, Y - 2 * (m_A));
        m_square.setFillColor(sf::Color(0xFF00FFFF));
    }
    void move()
    {
        if (m_square.getPosition().y > 0)
        {
            m_square.move(0, -30);
        }
        if (m_square.getPosition().y < 0)
        {
            m_square.setPosition(m_square.getPosition().x, 0);
        }
    }
};


int main()
{
    int* R = new int; cin >> *R;
    int x = 1600; int y = 900;

    int* A = new int; cin >> *A;

    sf::RenderWindow window(sf::VideoMode(x,y), "Window"); // создание окна
    window.setVerticalSyncEnabled(true); // вертикальная синхронизация

    sf::CircleShape circle(*R);
    Circles circle1(*R, x, y, circle);
    circle1.set();

    sf::RectangleShape square(sf::Vector2f(*A, *A));
    Squares square1(*A, x, y, square);
    square1.set();


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        circle1.move();
        square1.move();
        
        window.clear();
        
        window.draw(circle1.m_circle);
        window.draw(square1.m_square);
        window.display();
    }
    return 0;
}