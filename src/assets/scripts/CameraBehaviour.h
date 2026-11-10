//
// Created by Antonin Fruchet on 22/10/2026.
//

#ifndef COMPONENT_BASED_ARCH_CAMERABEHAVIOUR_H
#define COMPONENT_BASED_ARCH_CAMERABEHAVIOUR_H

#include "Engine.h"

class CameraBehaviour : public Component
{
    const float speed;
    InputAction* moveAction;

public:
    explicit CameraBehaviour(float speed);

    void Start() override;
    void Update(const sf::Time& elapsedTime) override;

private:
    static inline bool s_registered =
        ComponentFactory::Register("CameraBehaviour",
           [](const pugi::xml_node& node) -> std::unique_ptr<Component>
           {
               return std::make_unique<CameraBehaviour>(node.attribute("speed").as_float());
           });
};


#endif //COMPONENT_BASED_ARCH_CAMERABEHAVIOUR_H
