#include "TransfomableRect.h"

TransfomableRect::TransfomableRect()
{
}

void TransfomableRect::SetPosition(sf::Vector2f& pos)
{
	rect.setPosition(pos);
}

void TransfomableRect::SetScale(sf::Vector2f& scale)
{
	rect.setScale(scale);
}
