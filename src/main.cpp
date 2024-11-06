#include <SFML/Graphics.hpp>
#include "Tank.h"
#include "Constants.h"

int main() {
    // 创建窗口
    sf::RenderWindow window(
        sf::VideoMode(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT),
        "Tank Game"
    );
    window.setFramerateLimit(60);
    
    // 创建坦克
    Tank playerTank(Constants::WINDOW_WIDTH / 2.f, 
                   Constants::WINDOW_HEIGHT - 100.f, true);
    Tank enemyTank(Constants::WINDOW_WIDTH / 2.f, 100.f, false);
    
    // 游戏主循环
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // 处理输入
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            playerTank.setDirection(Constants::UP);
            playerTank.move();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            playerTank.setDirection(Constants::DOWN);
            playerTank.move();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            playerTank.setDirection(Constants::LEFT);
            playerTank.move();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            playerTank.setDirection(Constants::RIGHT);
            playerTank.move();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            playerTank.shoot();
        }
        
        // 清空窗口
        window.clear(sf::Color::White);
        
        // 绘制
        playerTank.draw(window);
        enemyTank.draw(window);
        
        // 显示
        window.display();
    }
    
    return 0;
}