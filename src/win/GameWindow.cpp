#include "GameWindow.h"

GameWindow::GameWindow(sf::RenderWindow &window): D2Window(window)
{
    //ctor
}

GameWindow::~GameWindow()
{
    //dtor
}

int GameWindow::load()
{
    // Load a sprite to display
    if (!texture.loadFromFile("res/cb.bmp"))
        return EXIT_FAILURE;
    sprite.setTexture(texture);
    return 1;
}

int GameWindow::run()
{
    load();

	// Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        show();
    }

    return 1;
}

void GameWindow::show()
{
    // Clear screen
    window.clear();

    // Draw the sprite
    window.draw(bg);
    window.draw(sprite);

    // Update the window
    window.display();

}
