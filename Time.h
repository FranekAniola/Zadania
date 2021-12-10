#ifndef time 
#define time

#include <iostream>
#include <string>
#include <sstream>

struct Time{
private:

int hour;
int minute;
int second;

public:
Time()=default;

auto countSeconds(Time x)const -> uint64_t{
	int result=(hour*3600)+(minute*60)+second;
	return result;
}

auto countMinutes(Time y)const -> uint64_t{
	
	int result=hour*60+minute;
	return result;
	}



Time(int h, int m, int s){
	hour = h;
	minute = m;
	second = s;
}

		enum class TimeOfTheDay{
			morning,
			afternoon,
			evening,
			night,	
		};
		
		auto const to_string() -> std::string{
		auto result = std::ostringstream{};
		
		if(hour < 10){
			result << "0" << hour << ":";
		}else{
		result << hour << ":";
		}
		
		if(minute < 10){
			result << "0" << minute << ":";
		}else{
		result << minute << ":";
		
		}
		if(second < 10){
			result << "0" << second;
		}else{
		
		result << second;
		}
		
		return result.str();
	}
	
	void next_hour(){
		if(hour==23){
		hour=0;
		}
		else
		{
		hour++;
		}
	}
		
	void next_minute(){
		
		if(minute=59){
		minute=0;
		next_hour();
		}
		else
		{
		minute++;
		}
	}

	void next_second(){
		if(second==59){
		second=0;
		next_minute();
		}
		else
		{
		second++;
		}
	}
	
	auto const string2(TimeOfTheDay dayTime) -> std::string{
	
	switch(dayTime){
	case TimeOfTheDay::morning:
	return "morning";
	
	case TimeOfTheDay::afternoon:
	return "day";
	
	case TimeOfTheDay::evening:
	return "evening";
	
	case TimeOfTheDay::night:
	return "night";
	
	default:
	throw "error";
	break;
	}
	
	exit(0);
	}
	
	auto tod() -> const TimeOfTheDay{
		if(hour>=6 && hour<= 11){
			return TimeOfTheDay::morning;
		}else if(hour>=12 && hour<=18){
			return TimeOfTheDay::afternoon;
		}else if(hour >=19 && hour <=22){
			return TimeOfTheDay::evening;
		}else{
			return TimeOfTheDay::night;
		}
	}
		
	auto timeToMidnight()const -> Time{
	Time toMidnight;

	if(second==0){
	toMidnight.second=second;
	toMidnight.minute=60-minute;
	}else{
	toMidnight.second=60-second;
	toMidnight.minute=59-minute;
	}
	
	if(minute==0){
	toMidnight.minute=minute;
	toMidnight.hour=24-hour;	
	}else{
	toMidnight.hour=23-hour;
	toMidnight.minute=60-minute;
	}
	return toMidnight;
	}
	
	auto operator + (Time const& other) const -> Time{
		
		Time add;
		
		if(hour+other.hour>=24){
			add.hour = hour+other.hour - 24;
		}else{
			 add.hour = hour+other.hour;
		}
		if(minute+other.minute>=60){
			 add.minute = minute+other.minute - 60;
		}else{
			 add.minute = minute+other.minute;
		}
		
		if(second+other.second>=60){
			 add.second = second+other.second - 60;
		}else{
			 add.second = second+other.second;
		}
		return add;
	}
	
	auto operator - ( Time const & other) const -> Time{
		Time sub;
		
		if(hour-other.hour<=0){
			sub.hour = 24 + (hour-other.hour);
		}else{
			 sub.hour = hour-other.hour;
		}
		if(minute-other.minute<=0){
			 sub.minute = minute-other.minute + 60;
			 sub.hour--;
		}else{
			 sub.minute = minute-other.minute;
		}
		
		if(second-other.second<=0){
			 sub.second = second-other.second + 60;
			 sub.minute--;
		}else{
			 sub.second = second-other.second;
		}
		return sub;
	}
	
	auto operator ==(Time const & other) const -> bool{
		
		return (hour == other.hour && minute == other.minute && second == other.second); 
	}
	
	auto operator !=(Time const & other) const -> bool{
		
		return !(*this==other);//second way to do it
	}
	
	auto operator< (Time const& other) const -> bool{
		if(hour<other.hour){
			return true;
		}else if(hour>other.hour){
			return false;
		}else if(hour==other.hour && minute<other.minute){
			return true;
		}else if(hour==other.hour && minute>other.minute){
			return false;
		}else if(hour==other.hour && minute==other.minute && second<other.second){
			return true;
		}else if(hour==other.hour && minute==other.minute && second>other.second){
			return false;
		}else if(hour==other.hour && minute==other.minute && second==other.second){
			return false;
		}
		exit(0);
	}
	auto operator> (Time const& other) const -> bool
	{
		if(hour<other.hour){
			return false;
		}else if(hour>other.hour){
			return true;
		}else if(hour==other.hour && minute<other.minute){
			return false;
		}else if(hour==other.hour && minute>other.minute){
			return true;
		}else if(hour==other.hour && minute==other.minute && second<other.second){
			return false;
		}else if(hour==other.hour && minute==other.minute && second>other.second){
			return true;
		}else if(hour==other.hour && minute==other.minute && second==other.second){
			return false;
		}
		exit(0);
	}
	
};
#endif
