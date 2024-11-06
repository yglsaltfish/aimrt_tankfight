#pragma once
#include <SFML/Graphics.hpp>

namespace Constants {
    // 窗口尺寸
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
    
    // 坦克属性
    const float TANK_SPEED = 5.0f;
    const float TANK_SIZE = 40.0f;
    
    // 子弹属性
    const float BULLET_SPEED = 8.0f;
    const float BULLET_SIZE = 8.0f;
    
    // 方向枚举
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
}