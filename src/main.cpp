#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({200, 200}), "SFML works!");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    const auto onClose = [&window](const sf::Event::Closed&)
    {
        window.close();
    };

    const auto onKeyPressed = [&window](const sf::Event::KeyPressed& keyPressed)
    {
        if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
            window.close();
        switch (keyPressed.scancode)
        {
            case sf::Keyboard::Scancode::A:
                break;

            case sf::Keyboard::Scancode::W:
                break;

            case sf::Keyboard::Scancode::D:
                break;

            case sf::Keyboard::Scancode::S:
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

        // end the current frame
        window.display();
    }

    return 0;
}