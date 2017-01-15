#include "Background.h"
#include <time.h>

int backgroundsCount = 10;
sf::String backgrounds[10] = {
    "res/background/1.png",
    "res/background/2.png",
    "res/background/3.png",
    "res/background/4.png",
    "res/background/5.png",
    "res/background/6.png",
    "res/background/7.png",
    "res/background/8.png",
    "res/background/9.png",
    "res/background/10.png",
};

sf::String bgFile()
{
    srand(time(0));

    int backgroundId = rand() % backgroundsCount;

    return backgrounds[backgroundId];
}

Background::Background()
{
    if (texture.loadFromFile(bgFile()))
        setTexture(texture);
    //ctor
}
