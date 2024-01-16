#include "moka/ecs/core/ecs.hpp"
#include <iostream>

using namespace moka::ecs;

class BasicComponent : public Component
{
friend class moka::ecs::ECS;
protected:
  void _Init() override
  {
    std::cout << "New component initialized!" << std::endl;
  }

public:
  std::string helloTo = "Moka";

  void SayHello()
  {
    MOKA_LOGF("default", moka::log::LogLevel::WARNING, "Hello %s!", helloTo.c_str());
  }
};

int main()
{
  Entity entity = ECS::Get().newEntity();
  ECS::Get().AddComponent<BasicComponent>(entity);

  ComponentPtr<BasicComponent> C_basicComponent = ECS::Get().GetComponentP<BasicComponent>(entity);
  C_basicComponent->SayHello();
}



