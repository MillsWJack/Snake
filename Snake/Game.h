#pragma once

#include "window.h"
#include "Snake.h"
#include "World.h"

class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	void RestartClock() { m_elapsed += m_clock.restart().asSeconds(); }

	sf::Time GetElapsed() { return m_clock.getElapsedTime(); }
	window* GetWindow() { return &m_window; }

private:
	window m_window;
	sf::Clock m_clock;
	float m_elapsed;

	World m_world;
	Snake m_snake;
};

