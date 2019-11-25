#include"pch.h"
#include"ship.h"
#include<math.h>

Ship::Ship()
{
	pm_sta_shipdata = new sta_shipdata;
	pm_dy_shipdata = new dy_shipdata;

}
Ship::Ship(sta_shipdata stdat)
{

	pm_sta_shipdata = new sta_shipdata;
	pm_dy_shipdata = new dy_shipdata;
	pm_sta_shipdata->name = stdat.name;
	for (int i = 0; i < 5; i++) {
		pm_sta_shipdata->number[i] = stdat.number[i];
	}
	for (int i = 0; i < 10; i++) {
		pm_sta_shipdata->MMSI[i] = stdat.MMSI[i];
	}
	pm_sta_shipdata->length = stdat.length;
	pm_sta_shipdata->width = stdat.width;
	pm_sta_shipdata->draft = stdat.draft;
	pm_sta_shipdata->displacement = stdat.displacement;

}

Ship::~Ship()
{
	delete pm_sta_shipdata;
	delete pm_dy_shipdata;
}

void Ship::set_position(double latu, double lotu)
{
	pm_dy_shipdata->latitude = latu;
	pm_dy_shipdata->longitude = lotu;
}

void Ship::set_speed_course(double _speed, double _course) 
{
	pm_dy_shipdata->speed = _speed;
	pm_dy_shipdata->course = _course;
	dy_set_profile();
}
void Ship::set_ship_profile() 
{
	/*pm_dy_shipdata->ship_profile[0].x = 0;
	pm_dy_shipdata->ship_profile[0].y = 0;
	pm_dy_shipdata->ship_profile[1].x = pm_sta_shipdata->width;
	pm_dy_shipdata->ship_profile[1].y = 0;
	pm_dy_shipdata->ship_profile[2].x = pm_sta_shipdata->width;
	pm_dy_shipdata->ship_profile[2].y = pm_sta_shipdata->length;
	pm_dy_shipdata->ship_profile[3].x = pm_sta_shipdata->width * 0.5;
	pm_dy_shipdata->ship_profile[3].y = pm_sta_shipdata->length * 1.4;
	pm_dy_shipdata->ship_profile[4].x = 0;
	pm_dy_shipdata->ship_profile[4].y = pm_sta_shipdata->length;*/

	pm_dy_shipdata->ship_profile[0].x = -0.5*pm_sta_shipdata->width;
	pm_dy_shipdata->ship_profile[0].y = -0.5 * pm_sta_shipdata->length;
	pm_dy_shipdata->ship_profile[1].x = 0.5 * pm_sta_shipdata->width;
	pm_dy_shipdata->ship_profile[1].y = -0.5 * pm_sta_shipdata->length;
	pm_dy_shipdata->ship_profile[2].x = 0.5 * pm_sta_shipdata->width;
	pm_dy_shipdata->ship_profile[2].y = 0.5 * pm_sta_shipdata->length;
	pm_dy_shipdata->ship_profile[3].x = 0;
	pm_dy_shipdata->ship_profile[3].y = pm_sta_shipdata->length * 0.9;
	pm_dy_shipdata->ship_profile[4].x = -0.5 * pm_sta_shipdata->width;
	pm_dy_shipdata->ship_profile[4].y = 0.5 * pm_sta_shipdata->length;
}
void Ship:: dy_set_profile()
{
	for (int i = 0; i < 5; i++) {
		double x = pm_dy_shipdata->ship_profile[i].x;
		double y = pm_dy_shipdata->ship_profile[i].y;
		pm_dy_shipdata->ship_profile[i].x = sin(pm_dy_shipdata->course*3.14/180)*y+cos(pm_dy_shipdata->course * 3.14 / 180)*x;
		pm_dy_shipdata->ship_profile[i].y = cos(pm_dy_shipdata->course * 3.14 / 180) * y - sin(pm_dy_shipdata->course * 3.14 / 180) * x;
	}
}
void Ship::set_ship_profile_byscale(double scale) 
{
	for (int i = 0; i < 5; i++) {
		pm_dy_shipdata->ship_profile[i].x *= scale;
		pm_dy_shipdata->ship_profile[i].y *= scale;
	}
}

double Ship::ca_juli(double lati, double longi)
{
	//计算距离
	double a, b, R;
	R = 6378137; // 地球半径
	a = (lati- pm_dy_shipdata->latitude)* 3.14 / 180.0;
	b = (longi- pm_dy_shipdata->longitude) * 3.14 / 180.0;
	double sa2, sb2;
	sa2 = sin(a / 2.0);
	sb2 = sin(b / 2.0);
	double juli = 2 * R * asin(sqrt(sa2 * sa2 + cos(pm_dy_shipdata->latitude * 3.14 / 180.0) * cos(lati * 3.14 / 180.0) * sb2 * sb2));
	return juli;
	
}
void Ship::showmessage()
{
	cout << "船名：" << pm_sta_shipdata->name << endl;
	cout << "呼号：";
	for (int i = 0; i < 4; i++) {
		cout << pm_sta_shipdata->number[i];
	}
	cout << endl;
	cout << "MMSI：";
	for (int i = 0; i < 9; i++) {
		cout << pm_sta_shipdata->MMSI[i];
	}
	cout << endl;
	cout << "船长：" << pm_sta_shipdata->length << "米" << endl;
	cout << "船宽：" << pm_sta_shipdata->width << "米" << endl;
	cout << "吃水：" << pm_sta_shipdata->draft << "米" << endl;
	cout << "排水：" << pm_sta_shipdata->displacement << "吨" << endl;
	cout << "航向：" << pm_dy_shipdata->course << "°" << endl;
	cout << "航速：" << pm_dy_shipdata->speed << "km/h" << endl;
	cout << "船舶位置：" << pm_dy_shipdata->latitude << "°";
	if (pm_dy_shipdata->latitude < 0)
		cout << "S"<<" ";
	else
		cout << "N"<<" ";
	cout << pm_dy_shipdata->longitude << "°";
	if (pm_dy_shipdata->longitude < 0)
		cout << "W" << endl;
	else
		cout << "E" << endl;
	cout << "船舶轮廓信息：";
	for (int i = 0; i < 5; i++) {
		cout <<"("<< pm_dy_shipdata->ship_profile[i].x 
			<< "," << pm_dy_shipdata->ship_profile[i].y <<")"<< " ";
	}
	cout << endl;
}
sta_shipdata* Ship::outsm()
{

	return pm_sta_shipdata;
}
dy_shipdata* Ship::outdm()
{
	return pm_dy_shipdata;
}
double Ship::ca_fangwei(double lati, double longi)
{
	//计算方位
	double b = (longi - pm_dy_shipdata->longitude) * 3.14 / 180.0;
	double y = sin(b) * cos(lati * 3.14 / 180.0);
	double x = cos(pm_dy_shipdata->latitude * 3.14 / 180.0) * sin(lati * 3.14 / 180.0) - sin(pm_dy_shipdata->latitude * 3.14 / 180.0) * cos(lati * 3.14 / 180.0) * cos(b);
	double brng = atan2(y, x) * 180;
	if (brng < 0)
		brng = brng + 360;
	return brng;
}
