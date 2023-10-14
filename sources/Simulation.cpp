#include "../includes/Simulation.hpp"
#include "../includes/Sand.hpp"
#include "../includes/Air.hpp"
#include "../includes/Water.hpp"
#include "../includes/Stone.hpp"

std::vector<std::vector<Material *>> Simulation::world;
unsigned int Simulation::width;
unsigned int Simulation::height;
std::vector<sf::Texture> Simulation::textures;
int Simulation::brush;

void Simulation::init_textures()
{
    std::vector<std::string> files = {"sand.png", "water.png", "stone.png"};
    for (auto file : files)
    {
        sf::FileInputStream stream;
        stream.open("../../resources/" + file);

        sf::Texture texture;
        texture.loadFromStream(stream);

        Simulation::textures.push_back(texture);
    }
    printf("%d textures loaded\n", Simulation::textures.size());
}

void Simulation::init_world()
{
    Simulation::brush = 0;
    Simulation::width = 50;
    Simulation::height = 50;

    // création du monde
    Simulation::world.resize(Simulation::width, std::vector<Material *>(Simulation::height, nullptr));
    for (int i = 0; i < Simulation::width; i++)
    {
        for (int j = 0; j < Simulation::height; j++)
        {
            Simulation::world[i][j] = new Air();
        }
    }
}

void Simulation::loop()
{
    Simulation::brush = 0;
    const int cell_size = 16;

    // création de la fenêtre
    auto window = sf::RenderWindow{{Simulation::width * cell_size, Simulation::height * cell_size}, "SandSimulation"};
    window.setFramerateLimit(144);

    // on fait tourner le programme tant que la fenêtre n'a pas été fermée
    while (window.isOpen())
    {
        sf::sleep(sf::milliseconds(50));
        // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
        sf::Event event;

        bool click = false;
        // tant qu'il y a des évènements à traiter...
        while (window.pollEvent(event))
        {
            // on regarde le type de l'évènement...
            switch (event.type)
            {
            // fenêtre fermée
            case sf::Event::Closed:
                window.close();
                break;
               
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::T)
                {
                    Simulation::brush = (Simulation::brush + 1) % 3;
                }
                
            // on ne traite pas les autres types d'évènements
            default:
                break;
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            // on lit la position locale de la souris (relativement à une fenêtre)
            sf::Vector2i pos = sf::Mouse::getPosition(window); // window est un sf::Window
            int x = pos.x / cell_size;
            int y = pos.y / cell_size;
            if (x < Simulation::width && y < Simulation::height && Simulation::world[x][y]->get_id() == -1)
            {
                Material *m;
                switch (Simulation::brush)
                {
                case 0:
                    m = new Sand();
                    break;
                
                case 1:
                    m = new Water();
                    break;

                case 2:
                    m = new Stone();
                    break;
                
                default:
                    break;
                }
                Simulation::world[x][y] = m;
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            // on lit la position locale de la souris (relativement à une fenêtre)
            sf::Vector2i pos = sf::Mouse::getPosition(window); // window est un sf::Window
            int x = pos.x / cell_size;
            int y = pos.y / cell_size;
            Simulation::world[x][y] = new Air();
        }

        // On met à jour le monde
        for (int y = Simulation::height - 1; y >= 0; y--)
        {
            for (int x = 0; x < Simulation::width; x++)
            {
                Simulation::world[x][y]->update(x, y);
            }
        }

        // effacement de la fenêtre en noir
        window.clear(sf::Color::Black);

        // dessin de la frame courante
        for (int y = 0; y < Simulation::height; y++)
        {
            for (int x = 0; x < Simulation::width; x++)
            {
                if (Simulation::world[x][y]->get_id() != -1)
                {
                    sf::Texture *texture = Simulation::world[x][y]->get_texture();
                    sf::Sprite sprite;
                    sprite.setTexture(*texture);
                    sprite.setPosition(sf::Vector2f(x * cell_size, y * cell_size));
                    window.draw(sprite);
                }
            }
        }

        // fin de la frame courante, affichage de tout ce qu'on a dessiné
        window.display();
    }
}
