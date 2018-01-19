#include "Player.h"
#include "Game.h"

//constructor
Player::Player(sf::Vector2f position, sf::Texture& texture, int life)
{
    //setting the value of lives
    lives = life;
    //set the spite texture
    sprite.setTexture(texture);
    //set the spite position
    sprite.setPosition(position);
    //set the sprite scale
    sprite.setScale(1.5f,1.5f);
    //set the default direction
    sf::Vector2i direction(0, Down);
}

//destructor
Player::~Player()
{
}

//draws the player
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states = getTransform();
    target.draw(sprite,states);
}

//update function
void Player::update(sf::Time deltaTime)
{
    //sets sprPosition to equal the location of the player
    sf::Vector2f sprPosition = sprite.getPosition();
    int x = sprPosition.x + 1;
    int y = sprPosition.y + 1;

    //determines if the player is off screen
    if(x < 0)
        Game::PspeedX += 1;
    if(x > 1324)
        Game::PspeedX -= 1;
    if(y < 0)
        Game::PspeedY += 1;
    if(y > 652)
        Game::PspeedY -= 1;

    //diagonal movement
    if ((Game::PspeedX == 1.f || Game::PspeedX == -1.f) && (Game::PspeedY == 1.f || Game::PspeedY == -1.f)) {
        Game::PspeedX = Game::PspeedX / 1.25;
        Game::PspeedY = Game::PspeedY / 1.25;
    }

    //moves the player bases on the offset of the passed in X and Y value
    sprite.move(Game::PspeedX, Game::PspeedY);
}


//changes the players amount of lives
void Player::changeLives(int tempLife)
{
    //sets the number of lives to be equal to itself + the passed in number
    lives = lives + tempLife; //sets the number of lives to be the passed in value to the function

    //determines if the player has less than or 0 lives to then end the game
    if(lives <= 0)
    {
        //end game, close window or display a restart screen
    }
}
