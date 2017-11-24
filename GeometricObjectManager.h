#pragma once
#include <list>
#include "Graphics/GeometricObject.h"
using namespace std;

class GeometricObjectManager
{
public:
	GeometricObjectManager();
	~GeometricObjectManager();

    void addObject(GeometricObject* newObject);
	void renderAll();

    void printAll();

private:
    list<GeometricObject*> Figures;

};


