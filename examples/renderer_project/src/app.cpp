#include <filesystem>
#include <iostream>
#include <glm/glm.hpp>
#include "moka/ecs/core/ecs.hpp"
#include "moka/world/components/transform.h"
#include "moka/project/project.h"
#include "moka/renderer/components/model.h"
#include "moka/renderer/main_loop.h"

using std::filesystem::path;
using namespace moka::ecs;
using namespace moka::misc;
using namespace moka::world::components;
using namespace moka::renderer;
using namespace moka::renderer::components;

#define EXE_DIR_MAX_CHARACTERS 256
static char g_exePath[EXE_DIR_MAX_CHARACTERS];

#ifdef __linux__
#define RETRIEVE_EXE_DIR() std::string __temp = std::filesystem::canonical("/proc/self/exe"); strcpy(g_exePath, __temp.c_str())
#else
#define RETRIEVE_EXE_DIR() GetModuleFileName(NULL, g_exePath, sizeof(EXE_DIR_MAX_CHARACTERS))
#endif

int main()
{
  RETRIEVE_EXE_DIR();
  path dir = path(g_exePath).parent_path().parent_path();
  moka::project::Global::currentProjectPath = dir;

  auto& mainLoop = Singleton<MainLoop>::Ref();

  Entity entity = ECS::Get().newEntity();
  ECS::Get().AddComponent<Model>(entity);
  ComponentPtr<Model> C_model = ECS::Get().GetComponentP<Model>(entity);
  C_model->Init("resources/model.glb");

  mainLoop.Run();
}



