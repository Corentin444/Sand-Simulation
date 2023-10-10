#include <SFML/Graphics.hpp>
#include <vector>

#include "../includes/Sand.hpp"
#include "../includes/Air.hpp"
#include "../includes/Material.hpp"

int main()
{
    const int W = 500;
    const int H = 500;

    // création de la fenêtre
    auto window = sf::RenderWindow{{W, H}, "SandSimulation"};
    window.setFramerateLimit(144);

    vector<vector<Material>> world;
    Sand s1;
    world[10][10] = s1;

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

        for (int i = 0; i < W; i++)
        {
            for (int j = 0; j < H; j++)
            {
                world[i][j].update();
            }
            
        }
        

        sf::Uint8* pixels = new sf::Uint8[W * H * 4]; // * 4 car les pixels ont 4 composantes (RGBA)
        pixels[(s1.x + s1.y * H) * 4 + 0] = 255; 
        pixels[(s1.x + s1.y * H) * 4 + 1] = 255; 
        pixels[(s1.x + s1.y * H) * 4 + 3] = 255; 
        pixels[(s1.x + s1.y * H) * 4 + 4] = 255;

        sf::Texture texture;
        texture.create(W, H);
        
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

    return 0;
}