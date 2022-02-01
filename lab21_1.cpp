#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *R1, Rect *R2){
	Rect area;
	if((R1 -> x + R2 -> w) - R2 -> x > 0){
		area.x = R2 -> x;
		area.w = (R1 -> x + R1 -> w) - R2 -> x;
		if((R1 -> x + R1 -> w) > (R2 -> x + R2 -> w)){
			area.x = R2 -> x;
			area.w = R2 -> w;
		}
	}
	if((R1 -> x + R1 -> w) - R2 -> x <= 0){
		area.x = 0;
		area.w = 0;
	}
	if(R2 -> y - (R1 -> y - R1 -> h)){
		area.y = R1 -> y;
		area.h = R1 -> y - (R2 -> y - R2 -> h);
		if((R1 -> y - R1 -> h) < (R2 -> y - R2 -> h) && R1 -> y > R2 -> y){
			area.y = R2 -> y;
			area.h = R2 -> h;
		}
	}
	if((R1 -> x + R1 -> w) - R2 -> x <= 0){
		area.y = 0;
		area.h = 0;
	}
	return area.w*area.h;
}

int main(){
	Rect R1 = {1,1,5,5};
	Rect R2 = {2,2,5,5};	
	cout << overlap(*R1,*R2);	
}
