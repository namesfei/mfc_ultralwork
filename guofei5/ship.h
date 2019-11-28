
//#include<iostream>
using namespace std;
struct sta_shipdata 
{
	const char* name;
	char MMSI[10];
	char number[5];
	float length;	//单位：米
	float width;	//单位：米
	float draft;
	float displacement; //单位：吨

};
struct zuobiao
{
	double x;
	double y;
};
struct dy_shipdata
{
	zuobiao ship_profile[5];
	double speed;	// 千米/小时
	double course;	// 正北为0°
	double latitude; //北正南负
	double longitude;//东正西负
};

class Ship 
{
public:
	Ship();
	Ship(sta_shipdata stdat);
	~Ship();
	void set_position(double latu, double lotu);
	void set_course(double _course);
	void set_speed(double _speed);
	void set_ship_profile();
	void dy_set_profile();
	void set_ship_profile_byscale(double scale);
	double ca_fangwei(double lati,double longi);
	double ca_juli(double lati, double longi);
	void showmessage();
	sta_shipdata* outsm();
	dy_shipdata* outdm();

private:
	sta_shipdata* pm_sta_shipdata;
	dy_shipdata* pm_dy_shipdata;
	//zuobiao ship_profile[5];
	//double speed;	// 千米/小时
	//double course;	// 正北为0°
	//double latitude; //北正南负
	//double longitude;//东正西负
};
