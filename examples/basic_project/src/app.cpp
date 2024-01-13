#include "moka/ecs/core/ecs.hpp"

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
  std::string helloText = "Hello Moka!";

  void SayHello()
  {
    std::cout << helloText << std::endl;
  }
};

int main()
{
  Entity entity = ECS::Get().newEntity();
  ECS::Get().AddComponent<BasicComponent>(entity);

  ComponentPtr<BasicComponent> C_basicComponent = ECS::Get().GetComponentP<BasicComponent>(entity);
  C_basicComponent->SayHello();
}



