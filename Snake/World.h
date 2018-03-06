#pragma once
#include <SFML/Graphics.hpp>

#include "Snake.h"

class World
{
public:
	World(sf::Vector2u windSize);
	~World();

	inline int GetBlockSize() { return m_blockSize; }

	void RespawnApple();

	void Update(Snake& player);
	void Render(sf::RenderWindow& window);

private:
	sf::Vector2u m_windowSize;
	sf::Vector2i m_item;					//Vector for apple coordinates
	int m_blockSize;

	sf::CircleShape m_appleShape;			//Circle for the apple
	sf::RectangleShape m_bounds[4];
};

