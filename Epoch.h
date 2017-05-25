#ifndef EPOCH_H
#define EPOCH_H

#include <ctime>
#include <iostream>
using std::time;
using std::ostream;
using std::endl;

class Epoch{
public:
	Epoch(const time_t& time = 0,
			const short& timezone = 0,
			const bool& dst = false);
	Epoch(const short& second = 0,
			const short& minute = 0,
			const short& hour = 0,
			const short& day = 1,
			const short& year = 1970,
			const short& timezone = 0,
			const bool& dst = false);
	void setTimeObj(const time_t time);
	void setTimezone(const short timezone);
	void setDST(const bool dst);
	void setSecond(const short second);
	void setMinute(const short minute);
	void setHour(const short hour);
	void setDay(const short day);
	void setDate();
	void setMonth();
	void setYear(const short year);
	time_t getTimeObj() const;
	short getTimezone() const;
	bool isDST() const;
	short getSecond() const;
	short getMinute() const;
	short getHour() const;
	short getDay() const;
	short getDate() const;
	short getMonth() const;
	short getYear() const; 
	friend ostream& operator<<(ostream& os, Epoch& obj);
	~Epoch();

private:
	void disassemble();
	void assemble();
	void countLeap();

	short second, minute, hour, day, date, month, year;
	time_t timeObj;
	short timezone;
	bool dst;
	short leapCount;
	bool isLeap;
};

#endif
