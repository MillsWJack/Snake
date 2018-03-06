#include "window.h"

window::window()
{
	Setup("Window", sf::Vector2u(640, 480));
}

window::window(const std::string& title, const sf::Vector2u& size)
{
	Setup(title, size);
}

window::~window()
{
	Destroy();
}

void window::BeginDraw()
{
	m_window.clear(sf::Color(81, 81, 81, 255));
}

void window::EndDraw()
{
	m_window.display();
}

void window::Update()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
		{
			m_isDone = true;
		}
		else if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::F11)
		{
			ToggleFullScreen();
		}
	}
}

void window::ToggleFullScreen()
{
	m_isFullscreen = !m_isFullscreen;
	Destroy();
	Create();
}

void window::Draw(sf::Drawable& l_drawable)
{
	m_window.draw(l_drawable);
}

void window::Setup(const std::string& title, const sf::Vector2u& size)
{
	m_windowSize = size;
	m_windowTitle = title;
	m_isFullscreen = false;
	m_isDone = false;
	Create();
}

void window::Destroy()
{
	m_window.close();
}

void window::Create()
{
	auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.create({ m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, style);
}