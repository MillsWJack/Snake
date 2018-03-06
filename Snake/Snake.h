#pragma once
#include <SFML\Graphics.hpp>

enum class Direction{None, Up, Down, Left, Right };

struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x, y) {}
	sf::Vector2i position;
};

class Snake
{
public:
	Snake(int blockSize);
	~Snake();

	void SetDirection(Direction dir);
	Direction GetDirection();
	int GetSpeed();
	sf::Vector2i GetPosition();
	int GetLives();
	int GetScore();
	void IncreaseScore();
	bool HasLost();

	void Lose();
	void ToggleLost();

	void Extend();
	void Reset();

	void Move();
	void Update();
	void Cut(int segments);
	void Render(sf::RenderWindow& window);
};

