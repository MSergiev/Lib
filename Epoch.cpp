#include "Epoch.h"

Epoch::Epoch(const time_t & time, const short& timezone, const bool& dst) {
	setTimeObj(time);
	disassemble();
	setTimezone(timezone);
	setDST(dst);
}

Epoch::Epoch(const short & second, const short & minute, const short & hour, const short & day, const short & year, const short& timezone, const bool& dst) {
	setSecond(second);
	setMinute(minute);
	setHour(hour);
	setDay(day);
	setMonth();
	setDate();
	setYear(year);
	assemble();
	setTimezone(timezone);
	setDST(dst);
}

void Epoch::setTimeObj(const time_t time) {
	this->timeObj=time;
}

void Epoch::setTimezone(const short timezone) {
	this->timezone=timezone;
	this->hour+=timezone;
}

void Epoch::setDST(const bool dst) {
	this->dst=dst;
	if(dst && day >= 85 && day <= 302) this->hour++;
}

void Epoch::setSecond(const short second) {
	this->second=second;
}

void Epoch::setMinute(const short minute) {
	this->minute=minute;
}

void Epoch::setHour(const short hour) {
	this->hour=hour;
}

void Epoch::setDay(const short day) {
	this->day=day;
}

void Epoch::setDate() {
	short mDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	short diff = 0;
	for (short i = 0; i < month-1; i++) diff+=mDays[i];
	this->date=(day-diff-leapCount);	
}

void Epoch::setMonth() {
	this->month=(day/31);
}

void Epoch::setYear(const short year) {
	this->year=year;
}

time_t Epoch::getTimeObj() const {
    return timeObj;
}

short Epoch::getTimezone() const {
    return timezone;
}

bool Epoch::isDST() const {
    return dst;
}

short Epoch::getSecond() const {
    return second;
}

short Epoch::getMinute() const {
    return minute;
}

short Epoch::getHour() const {
    return hour;
}

short Epoch::getDay() const {
	return day;
}

short Epoch::getDate() const {
	return date;
}

short Epoch::getMonth() const {
    return month;
}

short Epoch::getYear() const {
    return year;
}

ostream& operator<<(ostream& os, Epoch& obj){
	os << (obj.hour<10?"0":"") << obj.hour << ":";
	os << (obj.minute<10?"0":"") << obj.minute << ":";
	os << (obj.second<10?"0":"") << obj.second << endl;
	os << (obj.date<10?"0":"") << obj.date << ".";
	os << (obj.month<10?"0":"") << obj.month << ".";
	os << obj.year << endl;
	os << "Time zone: UTC" << (obj.timezone>0?"+":"") << obj.timezone << endl;
	os << "Daylight savings " << (obj.dst?"":"not ") << "active" << endl;
	return os;
}

Epoch::~Epoch() {
}

void Epoch::disassemble() {
	setSecond(timeObj%60);
	setMinute((timeObj/60)%60);
	setHour((timeObj/3600)%24);
	setDay((timeObj/86400)%365+1);
	setMonth();
	setYear((timeObj/31556926)+1970);
	countLeap();
	setDate();
}

void Epoch::assemble() {
	timeObj = second+minute*60+hour*3600*day*87600*year*31556926-1970;
}

void Epoch::countLeap(){
	leapCount = 0;
	for (int i = 1970; i <= year; ++i) if(i%4==0 && (i%100!=0 || i%400==0)) leapCount++;
}
