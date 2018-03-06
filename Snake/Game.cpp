#include "Game.h"

Game::Game()
	:m_window("Snake", sf::Vector2u(800,600))
{
}

Game::~Game()
{
}

void Game::Update()
{
	m_window.Update();
}

void Game::Render()
{
	m_window.BeginDraw();		//clear screen
	//draw drawable
	m_window.EndDraw();			//display
}