
#include <stdio.h>
#include <stdlib.h>
#include<math.h>


float circleArea(float r){
return M_PI*r*r; }

float circlePerimeter(float r){
return M_PI*(r+r);
}

float sphereVolume(float r){
	return (4.0/3.0)*M_PI*r*r*r;
}

float sphereSurfacearea(float r){
	return 4*M_PI*r*r;
}

float cylinderVolume(float r, float h){
float baseArea=circleArea(r);
float volume=h*baseArea;
return volume;
}

float cylinderSurfacearea(float r,float h){
	float baseArea=circleArea(r);
	float sideArea=circlePerimeter(r);
	float surfacearea=(baseArea)*2+(sideArea*h);
	return surfacearea;
}

float coneVolume(float r,float h){
	float baseArea=circleArea(r);
	float volume=baseArea*(h/3.0);
	return volume;
}

float coneSurfacearea(float r,float h){
	float baseArea=circleArea(r);
	float l=sqrt(h*h+r*r);
	float surfaceArea=baseArea+l*r*M_PI;
	return surfaceArea;
}

int main(void) {
	float r=6.2;
	float h=8.1;
	float area=circleArea(r);
	float area1=sphereSurfacearea(r);
	float area2=cylinderSurfacearea(r,h);
	float area3=coneSurfacearea(r,h);
	float vol1=cylinderVolume(r, h);
	float vol=sphereVolume(r);
	float vol2=coneVolume(r,h);
	float areas=area+area1+area2+area3;
	float vols=vol+vol1+vol2;
	printf("Circle:\t  Radius = %.1f\t\t\t\t\t Area   = %.1f\n",r,area);
	printf("Sphere:\t  Radius = %.1f\t\t       Volume   = %.1f\t Area   = %.1f\n",r,vol,area1);
	printf("Cylinder: Radius = %.1f\t Height = %.1f  Volume   = %.1f\t Area   = %.1f\n",r,h,vol1,area2);
	printf("Cone:     Radius = %.1f\t Height = %.1f  Volume   = %.1f\t Area   = %.1f\n",r,h,vol2,area3);
	printf("Sum: \t\t\t\t       Volumes = %.1f\t Areas = %.1f\n",vols,areas);
	return EXIT_SUCCESS;
}
