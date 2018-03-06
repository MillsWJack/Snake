#pragma once
#include <SFML\Graphics.hpp>

enum class Direction{None, Up, Down, Left, Right };

struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x, y) {}
	sf::Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;

class Snake
{
public:
	Snake(int blockSize);
	~Snake();

	inline int GetLives() { return m_lives; }
	inline int GetScore() { return m_score; }
	inline Direction GetDirection() { return m_dir; }
	inline int GetSpeed() { return m_speed; }
	sf::Vector2i GetPosition();

	void SetDirection(Direction dir) { m_dir = dir; }
	
	void IncreaseScore() { m_score += 10; }
	bool HasLost() { return m_lost; }
	void Lose() { m_lost = true; }
	void ToggleLost() { m_lost = !m_lost; }

	void Extend();							//Extend based on what direction snake is facgin
	void Reset();							//Set snake to starting pos
	void Move();							//Move snake based on current direction
	void Update();							//Update Snake
	void Cut(int segments);
	void Render(sf::RenderWindow& window);

private:
	void CheckCollision();					//Check for collisions

	SnakeContainer m_snakeBody;	//Vector for segments
	int m_size;								//Size of graphics
	Direction m_dir;						//Current direction
	int m_speed;							//Current speed
	int m_lives;							//Current lives
	int m_score;							//Current score
	bool m_lost;							//Loss state
	sf::RectangleShape m_bodyRect;			//Renderering shape
};

