#include <SFML/Graphics.hpp>
#include <iostream>
#include <Constants.h>
#include <Player.h>
#include <Immovable.h>
#include <Collider.h>


int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({TILE_SIZE * MAP_WIDTH, TILE_SIZE * MAP_HEIGHT}), "SFML works!");
    window.setSize(WINDOW_SIZE);
    
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Collider collider;

    Player player(sf::Vector2i(10,10));
    sf::Vector2i playerPos = player.getPosition();
    std::cout << "player-position: " << playerPos.x << ", " << playerPos.y << std::endl;


    Immovable Immovable(sf::Vector2i(15,15));
    sf::Vector2i ImmovablePos = Immovable.getPosition();
    std::cout << "Immovable-position: " << ImmovablePos.x << ", " << ImmovablePos.y << std::endl;

    const auto onClose = [&window](const sf::Event::Closed&)
    {
        window.close();
    };

    const auto onKeyPressed = [&window, &player](const sf::Event::KeyPressed& keyPressed)
    {
        if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
            window.close();
        sf::Keyboard::Scancode keyPressedScancode = keyPressed.scancode;
        player.handleInput(keyPressedScancode);
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
        window.draw(Immovable);

        // end the current frame
        window.display();
    }

    return 0;
}