// Jada Isable Group6 
// Sergio,Ethan,Jada

#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

class Clock {
public:
    
    virtual int get_hours() {
        time_t current_time = time(0);
        tm* local_time = localtime(&current_time);
        return local_time->tm_hour;
    }

    virtual int get_minutes() {
        time_t current_time = time(0);
        tm* local_time = localtime(&current_time);
        return local_time->tm_min;
    }

    // Get the current time as a formatted string "HH:MM"
    std::string get_time() {
        int hours = get_hours();
        int minutes = get_minutes();
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << hours << ":"
            << std::setw(2) << std::setfill('0') << minutes;
        return oss.str();
    }
};

class WorldClock : public Clock {
private:
    int time_offset;  
public:
    
    WorldClock(int offset) : time_offset(offset) {}

    
    int get_hours() override {
        int hours = Clock::get_hours() + time_offset;
        if (hours >= 24) {
            hours -= 24;  // Wrap around if time exceeds 24 hours
        } else if (hours < 0) {
            hours += 24;  // Wrap around if time is negative
        }
        return hours;
    }
};

int main() {
    Clock localClock;
    std::cout << "Local time: " << localClock.get_time() << std::endl;

    WorldClock nyClock(3);  // Assuming 3 hours ahead 
    std::cout << "New York time: " << nyClock.get_time() << std::endl;

    return 0;
}
