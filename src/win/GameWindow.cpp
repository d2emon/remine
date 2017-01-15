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
    if (!texture.loadFromFile("res/tiles.jpg"))
        return EXIT_FAILURE;
    sprite.setTexture(texture);

    for(int i=1; i <= 10; i++)
        for(int j=1; j <= 10; j++)
        {
            sgrid[i][j] = 10;
            if (rand() % 5 == 0)
                grid[i][j] = 9;
            else
                grid[i][j] = 0;
        }

    for(int i=1; i <= 10; i++)
        for(int j=1; j <= 10; j++)
        {
            int n=0;
            if (grid[i  ][j  ] == 9) continue;
            if (grid[i+1][j  ] == 9) n++;
            if (grid[i  ][j+1] == 9) n++;
            if (grid[i-1][j  ] == 9) n++;
            if (grid[i  ][j-1] == 9) n++;
            if (grid[i+1][j+1] == 9) n++;
            if (grid[i-1][j-1] == 9) n++;
            if (grid[i-1][j+1] == 9) n++;
            if (grid[i+1][j-1] == 9) n++;

            grid[i][j] = n;
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

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                int x = pos.x / spriteWidth;
                int y = pos.y / spriteWidth;

                printf("%d, %d :: %d, %d\n", pos.x, pos.y, x, y);
                if (event.key.code == sf::Mouse::Left)
                {
                    sgrid[x][y] = grid[x][y];
                }
                else if (event.key.code == sf::Mouse::Right)
                {
                    sgrid[x][y] = 11;
                }
            }
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
            if(sgrid[i][j] == 9)
                sgrid[i][j] = grid[i][j];
            sprite.setTextureRect(sf::IntRect(sgrid[i][j]*spriteWidth, 0, spriteWidth, spriteWidth));
            sprite.setPosition(i*spriteWidth, j*spriteWidth);
            window.draw(sprite);
        }

    // Draw the sprite
    // window.draw(sprite);

    // Update the window
    window.display();

}
