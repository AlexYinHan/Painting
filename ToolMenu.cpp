#include "ToolMenu.h"
#include <Algorithm>
ToolObject::ToolObject()
{

}
ToolObject::~ToolObject()
{

}
void ToolObject::render()
{

}
ToolManager::ToolManager()
{

}
ToolManager::~ToolManager()
{

}

void ToolManager::render()
{
	for_each(tools.begin(), tools.end(), [](ToolObject thisTool) {thisTool.render(); });
}

