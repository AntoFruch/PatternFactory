//
// Created by Antonin Fruchet on 22/10/2026.
//

#include "CameraBehaviour.h"

#include "Managers/Input/InputManager.h"


CameraBehaviour::CameraBehaviour(float speed) : speed(speed)
{
    moveAction = InputManager::findAction("Move");
}

void CameraBehaviour::Start()
{

}

void CameraBehaviour::Update(const sf::Time& elapsedTime)
{
    auto direction = moveAction->ReadValue<sf::Vector2f>();
    if (direction.length() != 0)
        gameObject->transform.move(
            direction.normalized()*speed*elapsedTime.asSeconds()
            );
}
