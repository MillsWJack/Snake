#include "Snake.h"

Snake::Snake(int blockSize)
{
	m_size = blockSize;
	m_bodyRect.setSize(sf::Vector2f(m_size - 1, m_size - 1));	//-1 to give the illusion of seperation
	Reset();
}

Snake::~Snake()
{
}

sf::Vector2i Snake::GetPosition()
{
	return (!m_snakeBody.empty() ? m_snakeBody.front().position : sf::Vector2i(1, 1));
}

void Snake::Extend()
{
	if (m_snakeBody.empty())
	{
		return;
	}
	SnakeSegment& tail_head = m_snakeBody[m_snakeBody.size() - 1];

	if (m_snakeBody.size() > 1)
	{
		SnakeSegment& tail_bone = m_snakeBody[m_snakeBody.size() - 2];

		if (tail_head.position.x == tail_bone.position.x)
		{
			if (tail_head.position.y > tail_bone.position.y)
			{
				m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
			}
			else
			{
				m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
			}
		}
		else if (tail_head.position.y == tail_bone.position.y)
		{
			if (tail_head.position.x > tail_bone.position.x)
			{
				m_snakeBody.push_back(SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
			}
			else
			{
				m_snakeBody.push_back(SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
			}
		}
	}
	else
	{
		if (m_dir == Direction::Up)
		{
			m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
		}
		else if (m_dir == Direction::Right)
		{
			m_snakeBody.push_back(SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
		}
		else if (m_dir == Direction::Down)
		{
			m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
		}
		else if (m_dir == Direction::Left)
		{
			m_snakeBody.push_back(SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
		}
	}
}

void Snake::Reset()
{
	m_snakeBody.clear();						//Remove any previous segments

	m_snakeBody.push_back(SnakeSegment(5, 7));
	m_snakeBody.push_back(SnakeSegment(5, 6));
	m_snakeBody.push_back(SnakeSegment(5, 5));

	SetDirection(Direction::None);				//Start with no direction
	m_speed = 15;								//Starting speed
	m_lives = 3;								//Set lives
	m_score = 0;								//Reset score
	m_lost = false;
}

void Snake::Move()
{
	for (int i = m_snakeBody.size() - 1; i > 0; --i)
	{
		m_snakeBody[i].position = m_snakeBody[i - 1].position;
	}
	if (m_dir == Direction::Left)
	{
		--m_snakeBody[0].position.x;
	}
	else if (m_dir == Direction::Right)
	{
		++m_snakeBody[0].position.x;
	}
	else if (m_dir == Direction::Up)
	{
		--m_snakeBody[0].position.y;
	}
	else if (m_dir == Direction::Down)
	{
		++m_snakeBody[0].position.y;
	}
}

void Snake::Update()
{
	if (m_snakeBody.empty() || m_dir == Direction::None)
	{
		return;
	}
	Move();
	CheckCollision();
}

void Snake::Cut(int segments)
{
	for (int i = 0; i < segments; ++i)
	{
		m_snakeBody.pop_back();
	}
	--m_lives;
	if (!m_lives)
	{
		Lose();
		return;
	}
}

void Snake::Render(sf::RenderWindow& window)
{
	if (m_snakeBody.empty())
	{
		return;
	}

	auto head = m_snakeBody.begin();
	m_bodyRect.setFillColor(sf::Color::Yellow);
	m_bodyRect.setPosition(head->position.x * m_size, head->position.y * m_size);
	window.draw(m_bodyRect);

	m_bodyRect.setFillColor(sf::Color::Green);
	for (auto iter = m_snakeBody.begin() + 1; iter != m_snakeBody.end(); ++iter)
	{
		m_bodyRect.setPosition(iter->position.x * m_size, iter->position.y * m_size);
		window.draw(m_bodyRect);
	}
}

void Snake::CheckCollision()
{
	if (m_snakeBody.size() < 5)
	{
		return;
	}
	SnakeSegment& head = m_snakeBody.front();
	for (auto iter = m_snakeBody.begin() + 1; iter != m_snakeBody.end(); ++iter)
	{
		if (iter->position == head.position)
		{
			int segments = m_snakeBody.end() - iter;
			Cut(segments);
			break;
		}
	}
}