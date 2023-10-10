#include "../includes/Simulation.hpp"
#include "../includes/Sand.hpp"
#include "../includes/Air.hpp"

std::vector<std::vector<Material*>>	Simulation::world;
unsigned int Simulation::width;
unsigned int Simulation::height;

void Simulation::init()
{
    Simulation::width = 50;
    Simulation::height = 50;

    // création de la fenêtre
    auto window = sf::RenderWindow{{Simulation::width, Simulation::height}, "SandSimulation"};
    window.setFramerateLimit(144);

    // création du monde
    Simulation::world.resize(Simulation::width, std::vector<Material*>(Simulation::height, nullptr));
    for(int i = 0; i < Simulation::width; i++)
    {
        for(int j = 0; j < Simulation::height; j++)
        {
            Simulation::world[i][j] = new Air();
        }
    }
    
    // création d'un grain de sable
    Sand s1;
    Simulation::world[5][5] = &s1;

    // on fait tourner le programme tant que la fenêtre n'a pas été fermée
    while (window.isOpen())
    {
        // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            // fermeture de la fenêtre lorsque l'utilisateur le souhaite
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        for (int i = 0; i < Simulation::width; i++)
        {
            for (int j = 0; j < Simulation::height; j++)
            {
                world[i][j]->update(i, j);
            }
        }
        sf::Uint8* pixels = new sf::Uint8[Simulation::width * Simulation::height * 4]; // * 4 car les pixels ont 4 composantes (RGBA)
        printf("taille=%d\n", Simulation::width * Simulation::height * 4);
        for (int y = 0; y < Simulation::height; y++)
        {
            for (int x = 0; x < Simulation::width; x++)
            {
                sf::Color color = world[x][y]->get_color();
                pixels[(x + y * Simulation::height) * 4 + 0] = color.r; 
                pixels[(x + y * Simulation::height) * 4 + 1] = color.g; 
                pixels[(x + y * Simulation::height) * 4 + 3] = color.b; 
                pixels[(x + y * Simulation::height) * 4 + 4] = color.a;
                printf("n=%d\n", (x + y * Simulation::height) * 4 + 4);
                printf("taille=%d\n", Simulation::width * Simulation::height * 4);
            }
            printf("test\n");
        }
        printf("test\n");
        sf::Texture texture;
        texture.create(Simulation::width, Simulation::height);
        
        texture.update(pixels);

        sf::Sprite sprite;
        sprite.setTexture(texture);

        // effacement de la fenêtre en noir
        window.clear(sf::Color::Black);

        // coloriage de la fenetre
        window.draw(sprite);

        delete pixels;

        // fin de la frame courante, affichage de tout ce qu'on a dessiné
        window.display();
    }
    
}