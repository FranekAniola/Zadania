#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdint>

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
	
	auto const string2(TimeOfTheDay time) -> std::string{
	
	switch(time){
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
	};
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


};




auto main() ->int
{
	auto t = Time{13,22,0};
	
	t.next_hour();
	
	std::cout<<t.to_string()<<std::endl;
	
	std::cout<<t.string2(t.tod())<<std::endl;
	
	std::cout<<t.countSeconds(t)<< " seconds have passed since midnight :>" <<std::endl;
	std::cout<<t.countMinutes(t)<< " minutes have passed since midnight :>" <<std::endl;
	
	std::cout<<t.timeToMidnight().to_string()<< " time left to midnight :>" <<std::endl;
	return 0;
	
}
