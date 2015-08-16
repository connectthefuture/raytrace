#include "Scene.h"

//default lamp
Scene::Scene(void)
	:light(0, 0, 10, 10)
{
	numOfMeshes = 0;
	meshes = (Mesh**)calloc(1, sizeof(Mesh*));
}

Mesh* Scene::getMesh(int number){
	if(number<=numOfMeshes){
		return meshes[number];
	}else{
		printf("ERROR: THAT MESH DOES NOT EXSIST, DEFAULT MESH RETURNED");
		return *(meshes+0);
	}
}

Camera Scene::getCamera(void){
	return camera;
}

void Scene::addSphere(float centreX, float centreY, float centreZ, float radius, colour_t col, Material material){

	numOfMeshes++;
	meshes = (Mesh**)realloc(meshes, numOfMeshes*sizeof(Mesh*));

	Sphere *t = new Sphere(centreX, centreY, centreZ, radius, col, material);

	Mesh *m = t;
	meshes[numOfMeshes-1] = m;
}

void Scene::addPlane(vertex_t v1, vertex_t v2, vertex_t v3, vertex_t v4, colour_t colour, Material material){
	numOfMeshes++;
	meshes = (Mesh**)realloc(meshes, numOfMeshes*sizeof(Mesh*));

	Plane *p = new Plane(v1, v2, v3, v4, colour, material);

	Mesh *m = p;
	meshes[numOfMeshes-1] = m;
}

void Scene::addLight(float posX, float posY, float posZ, float intensity){
	light = Light(posX, posY, posZ, intensity);
}

int Scene::getNumOfMeshes(void){
	return numOfMeshes;
}

Light Scene::getLight(void){
	return light;
}

Scene::~Scene(void)
{
	free(meshes);
}
