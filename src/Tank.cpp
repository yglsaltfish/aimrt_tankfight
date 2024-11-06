#include "Tank.h"

Tank::Tank(float startX, float startY, bool isPlayerTank) 
    : position(startX, startY), isPlayer(isPlayerTank), direction(Constants::UP) {
    speed = Constants::TANK_SPEED;
    
    // 设置坦克主体
    body.setSize(sf::Vector2f(Constants::TANK_SIZE, Constants::TANK_SIZE));
    body.setFillColor(isPlayer ? sf::Color::Blue : sf::Color::Red);
    body.setOrigin(Constants::TANK_SIZE/2, Constants::TANK_SIZE/2);
    body.setPosition(position);
    
    // 设置炮管
    cannon.setSize(sf::Vector2f(8, Constants::TANK_SIZE/2));
    cannon.setFillColor(sf::Color::Black);
    cannon.setOrigin(4, 0);
    cannon.setPosition(position);
}

void Tank::draw(sf::RenderWindow& window) {
    // 更新位置
    body.setPosition(position);
    cannon.setPosition(position);
    
    // 根据方向旋转炮管
    float rotation = 0;
    switch(direction) {
        case Constants::UP:    rotation = 0; break;
        case Constants::DOWN:  rotation = 180; break;
        case Constants::LEFT:  rotation = -90; break;
        case Constants::RIGHT: rotation = 90; break;
    }
    cannon.setRotation(rotation);
    
    // 绘制
    window.draw(body);
    window.draw(cannon);
}

void Tank::move() {
    switch(direction) {
        case Constants::UP:
            if(position.y - speed >= Constants::TANK_SIZE/2)
                position.y -= speed;
            break;
        case Constants::DOWN:
            if(position.y + speed <= Constants::WINDOW_HEIGHT - Constants::TANK_SIZE/2)
                position.y += speed;
            break;
        case Constants::LEFT:
            if(position.x - speed >= Constants::TANK_SIZE/2)
                position.x -= speed;
            break;
        case Constants::RIGHT:
            if(position.x + speed <= Constants::WINDOW_WIDTH - Constants::TANK_SIZE/2)
                position.x += speed;
            break;
    }
}

void Tank::setDirection(Constants::Direction dir) {
    direction = dir;
}