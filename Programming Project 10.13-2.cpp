// Updated code that 10.13-2 Requested
// Jada

#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

class Clock {
protected:
    int alarm_hours = -1;  
    int alarm_minutes = -1;

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

    // Set the alarm time
    void set_alarm(int hours, int minutes) {
        alarm_hours = hours;
        alarm_minutes = minutes;
    }

    // Check if alarm is triggered
    bool is_alarm_triggered(int current_hours, int current_minutes) {
        if (alarm_hours == -1 || alarm_minutes == -1) {
            return false;  // Alarm not set
        }
        if (current_hours > alarm_hours || (current_hours == alarm_hours && current_minutes >= alarm_minutes)) {
            alarm_hours = -1;  // Clear the alarm after it's triggered
            alarm_minutes = -1;
            return true;
        }
        return false;
    }

    
    std::string get_time() {
        int hours = get_hours();
        int minutes = get_minutes();
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << hours << ":"
            << std::setw(2) << std::setfill('0') << minutes;

        
        if (is_alarm_triggered(hours, minutes)) {
            oss << " \u23F0";  // Unicode for alarm clock
        }

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

    
    void set_alarm(int hours, int minutes) {
        int adjusted_hours = hours - time_offset;
        if (adjusted_hours < 0) {
            adjusted_hours += 24;  // Handle negative hours
        } else if (adjusted_hours >= 24) {
            adjusted_hours -= 24;  // Handle hours exceeding 24
        }
        Clock::set_alarm(adjusted_hours, minutes);
    }
};

int main() {
    Clock localClock;
    localClock.set_alarm(14, 30);  
    std::cout << "Local time: " << localClock.get_time() << std::endl;

    WorldClock nyClock(3);  
    nyClock.set_alarm(17, 30);  
    std::cout << "New York time: " << nyClock.get_time() << std::endl;

    return 0;
}
