#pragma once
#include "common.h"
#include <list>
using namespace std;

class ToolObject
{
public:
	ToolObject();
	~ToolObject();
	void render();
private:
	Vector3 position;
};

class ToolManager
{
public:
	ToolManager();
	~ToolManager();

	void render();
private:
	list<ToolObject> tools;
};


