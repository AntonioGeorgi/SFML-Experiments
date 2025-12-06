#include <SFML/Graphics.hpp>
#include <iostream>
#include <Constants.h>
#include <Entity.h>


int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({TILE_SIZE * MAP_WIDTH, TILE_SIZE * MAP_HEIGHT}), "SFML works!");
    window.setSize(WINDOW_SIZE);
    
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Entity player(sf::Vector2i(0,0), sf::Color::Red);

    const auto onClose = [&window](const sf::Event::Closed&)
    {
        window.close();
    };

    const auto onKeyPressed = [&window, &player](const sf::Event::KeyPressed& keyPressed)
    {
        if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
            window.close();
        switch (keyPressed.scancode)
        {
            case sf::Keyboard::Scancode::A:
                player.move(-1, 0);
                break;

            case sf::Keyboard::Scancode::W:
                player.move(0, -1);
                break;

            case sf::Keyboard::Scancode::D:
                player.move(1, 0);
                break;

            case sf::Keyboard::Scancode::S:
                player.move(0, 1);
                break;

            default:
                break;
        }
    };

    const auto onResized = [&window](const sf::Event::Resized& resized)
    {
        std::cout << "new width: " << resized.size.x << std::endl;
        std::cout << "new height: " << resized.size.y << std::endl;
    };

    const auto onFocusLost = [&window](const sf::Event::FocusLost&)
    {
        //myGame.pause();
    };

    const auto onFocusGained = [&window](const sf::Event::FocusGained&)
    {
        //myGame.resume();
    };

    while (window.isOpen()) 
    {
        window.handleEvents(onClose, onKeyPressed, onResized);

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(shape);
        window.draw(player);

        // end the current frame
        window.display();
    }

    return 0;
}