#pragma once

class HitBox
{
public:
	HitBox();

	sf::RectangleShape rect;
	sf::Vector2f rectPos = rect.getPosition();

	void UpdateTr(const sf::Transformable& tr, const sf::FloatRect& localBound);
	void Draw(sf::RenderWindow& window);
	void SetOrigin(Origins preset);
	sf::Vector2f GetPosition() { return rectPos; }
};