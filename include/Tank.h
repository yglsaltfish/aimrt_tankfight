#pragma once
#include "Constants.h"
#include <SFML/Graphics.hpp>

class Tank {
private:
    sf::Vector2f position;
    Constants::Direction direction;
    bool isPlayer;
    float speed;
    sf::RectangleShape body;
    sf::RectangleShape cannon;

public:
    Tank(float startX, float startY, bool isPlayerTank);
    void move();
    void draw(sf::RenderWindow& window);
    void setDirection(Constants::Direction dir);
    void shoot();
    
    // getter方法
    sf::Vector2f getPosition() const { return position; }
    Constants::Direction getDirection() const { return direction; }
};