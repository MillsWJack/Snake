#pragma once
#include <SFML/Graphics.hpp>

class window
{
public:
	window();
	window(const std::string& title, const sf::Vector2u& size);
	~window();

	void BeginDraw();	//Clear the window
	void EndDraw();		//Display the changes

	void Update();

	bool isDone() { return m_isDone; }
	bool isFullscreen() { return m_isFullscreen; }
	sf::Vector2u GetWindowSize() { return m_windowSize; }

	void ToggleFullScreen();

	void Draw(sf::Drawable& l_drawable);

private:

	void Setup(const std::string& title, const sf::Vector2u& size);
	void Destroy();
	void Create();

	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullscreen;
};

