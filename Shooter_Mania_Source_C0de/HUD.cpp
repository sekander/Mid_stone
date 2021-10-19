#include "HUD.hpp"

#include <string>

namespace Sekander
{
	HUD::HUD(GameDataRef data) : _data(data)
	{
		_scoreText.setFont(_data->assets.GetFont("Flappy Font"));
		_scoreText.setString("0");
		_scoreText.setCharacterSize(25);
		_scoreText.setFillColor(sf::Color::Blue);
		_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 8,
			_scoreText.getGlobalBounds().height / 24);

		_scoreText.setPosition(_data->window.getSize().x / 2,
			_data->window.getSize().y / 5);


		text.setFont(_data->assets.GetFont("Flappy Font"));
		text.setString("Score : ");
		text.setCharacterSize(25);
		text.setFillColor(sf::Color::Blue);
		text.setOrigin(_scoreText.getGlobalBounds().width / 2,
			_scoreText.getGlobalBounds().height / 8);
		text.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 5);



		m_clock_text.setFont(_data->assets.GetFont("Flappy Font"));
		m_clock_text.setString("");
		m_clock_text.setCharacterSize(25);
		m_clock_text.setFillColor(sf::Color::Green);
		m_clock_text.setOrigin(_scoreText.getGlobalBounds().width / 2,
			_scoreText.getGlobalBounds().height / 8);









	}



	void HUD::Update()
	{
		_scoreText.setPosition(this->_data->manager.Get("red")->getPosition().x + 430,
			this->_data->manager.Get("red")->getPosition().y - 450);

		//text.setPosition(this->_data->manager.Get("red")->getPosition().x + 280,
		//					   this->_data->manager.Get("red")->getPosition().y - 550);
//


		text.setPosition(_scoreText.getPosition().x - 200,
			_scoreText.getPosition().y);


		m_clock_text.setPosition(_scoreText.getPosition().x - 900,
			_scoreText.getPosition().y);

		//mytext.setPosition(this->_data->manager.Get("red")->getPosition().x + 280,
		//					   this->_data->manager.Get("red")->getPosition().y - 550);


		//text.setPosition();
		//mytext.setPosition();
	}

	void HUD::Draw() {


		_data->window.draw(_scoreText);
		_data->window.draw(text);
		_data->window.draw(m_clock_text);

	}

	void HUD::UpdateScore(int score) {
		_scoreText.setString(std::to_string(score));
	}

	void HUD::Update_text(std::string s)
	{
		m_clock_text.setString(" Game Clock : " + s);
	}
}
