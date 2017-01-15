#include "GameWindow.h"
#include <time.h>
#include "settings.h"

GameWindow::GameWindow(sf::RenderWindow &window): D2Window(window)
{
    srand(time(0));
}

GameWindow::~GameWindow()
{
    //dtor
}

int GameWindow::load()
{
    int grid[12][12];

    if (!texture.loadFromFile("res/tiles.jpg"))
        return EXIT_FAILURE;
    sprite.setTexture(texture);

    for(int i=1; i <= 10; i++)
        for(int j=1; j <= 10; j++)
        {
            sgrid[i][j] = 10;
        }
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
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
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
    window.draw(bg);

    for(int i=1; i <= 10; i++)
        for(int j=1; j <= 10; j++)
        {
            sprite.setTextureRect(sf::IntRect(sgrid[i][j]*spriteWidth, 0, spriteWidth, spriteWidth));
            sprite.setPosition(i*spriteWidth, j*spriteWidth);
            window.draw(sprite);
        }

    // Draw the sprite
    // window.draw(sprite);

    // Update the window
    window.display();

}
