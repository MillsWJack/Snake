#pragma once

#include "window.h"

class Game
{
public:
	Game();
	~Game();

	//void HandleInput();
	void Update();
	void Render();
	void RestartClock() { m_elapsed += m_clock.restart(); }

	sf::Time GetElapsed() { return m_elapsed; }
	window* GetWindow() { return &m_window; }

private:
	window m_window;

	sf::Clock m_clock;
	sf::Time m_elapsed;
};

