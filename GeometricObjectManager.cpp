#include "GeometricObjectManager.h"
#include <Algorithm>
GeometricObjectManager::GeometricObjectManager()
{
}

GeometricObjectManager::~GeometricObjectManager()
{
}

void GeometricObjectManager::addObject(GeometricObject* newObject)
{
	Figures.push_back(newObject);
}

void GeometricObjectManager::renderAll()
{
    for_each(Figures.begin(), Figures.end(), [](GeometricObject* &thisObject) {thisObject->render(); });
}

void GeometricObjectManager::printAll()
{
    for_each(Figures.begin(), Figures.end(),
             [](GeometricObject* &thisObject)
                {
                    qDebug() <<"Position" << thisObject->getPosition().getX() << thisObject->getPosition().getY();
                    //qDebug() <<"endPoint" << thisObject->EndPoint.getX() << thisObject->EndPoint.getY();
                });

}
