#include"pch.h"
#include"ship.h"
#include<math.h>
#include<iostream>
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
	pm_dy_shipdata->course = 0;
	pm_dy_shipdata->speed = 0;

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

void Ship::set_course(double _course) 
{
	pm_dy_shipdata->course = _course;
	dy_set_profile();
}
void Ship::set_speed(double _speed)
{
	pm_dy_shipdata->speed = _speed;
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
	pm_dy_shipdata->ship_profile[2].y = 0.2 * pm_sta_shipdata->length;
	pm_dy_shipdata->ship_profile[3].x = 0;
	pm_dy_shipdata->ship_profile[3].y = pm_sta_shipdata->length * 0.5;
	pm_dy_shipdata->ship_profile[4].x = -0.5 * pm_sta_shipdata->width;
	pm_dy_shipdata->ship_profile[4].y = 0.2 * pm_sta_shipdata->length;
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
	//�������
	double a, b, R;
	R = 6378137; // ����뾶
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
	cout << "������" << pm_sta_shipdata->name << endl;
	cout << "���ţ�";
	for (int i = 0; i < 4; i++) {
		cout << pm_sta_shipdata->number[i];
	}
	cout << endl;
	cout << "MMSI��";
	for (int i = 0; i < 9; i++) {
		cout << pm_sta_shipdata->MMSI[i];
	}
	cout << endl;
	cout << "������" << pm_sta_shipdata->length << "��" << endl;
	cout << "����" << pm_sta_shipdata->width << "��" << endl;
	cout << "��ˮ��" << pm_sta_shipdata->draft << "��" << endl;
	cout << "��ˮ��" << pm_sta_shipdata->displacement << "��" << endl;
	cout << "����" << pm_dy_shipdata->course << "��" << endl;
	cout << "���٣�" << pm_dy_shipdata->speed << "km/h" << endl;
	cout << "����λ�ã�" << pm_dy_shipdata->latitude << "��";
	if (pm_dy_shipdata->latitude < 0)
		cout << "S"<<" ";
	else
		cout << "N"<<" ";
	cout << pm_dy_shipdata->longitude << "��";
	if (pm_dy_shipdata->longitude < 0)
		cout << "W" << endl;
	else
		cout << "E" << endl;
	cout << "����������Ϣ��";
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
	//���㷽λ
	double b = (longi - pm_dy_shipdata->longitude) * 3.14 / 180.0;
	double y = sin(b) * cos(lati * 3.14 / 180.0);
	double x = cos(pm_dy_shipdata->latitude * 3.14 / 180.0) * sin(lati * 3.14 / 180.0) - sin(pm_dy_shipdata->latitude * 3.14 / 180.0) * cos(lati * 3.14 / 180.0) * cos(b);
	double brng = atan2(y, x) * 180;
	if (brng < 0)
		brng = brng + 360;
	return brng;
}
