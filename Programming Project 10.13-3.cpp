10.13-3 Jada Isable 10.13-1-3


#include <iostream>
#include <vector>
#include <string>


class Appointment {
protected:
    std::string description;
    int hour, minute;

public:
    Appointment(std::string desc, int h, int m) : description(desc), hour(h), minute(m) {}

    virtual bool occurs_on(int year, int month, int day) = 0;  
    virtual void print() const {
        std::cout << description << " at " << hour << ":" << (minute < 10 ? "0" : "") << minute << std::endl;
    }

    virtual ~Appointment() {}
};


class Onetime : public Appointment {
private:
    int year, month, day;

public:
    Onetime(std::string desc, int y, int m, int d, int h, int min) 
        : Appointment(desc, h, min), year(y), month(m), day(d) {}

    bool occurs_on(int y, int m, int d) override {
        return (year == y && month == m && day == d);
    }
};


class Daily : public Appointment {
public:
    Daily(std::string desc, int h, int min) : Appointment(desc, h, min) {}

    bool occurs_on(int y, int m, int d) override {
        return true;  
    }
};


class Weekly : public Appointment {
private:
    int start_year, start_month, start_day;

public:
    Weekly(std::string desc, int y, int m, int d, int h, int min) 
        : Appointment(desc, h, min), start_year(y), start_month(m), start_day(d) {}

    bool occurs_on(int y, int m, int d) override {
        // Just a basic check; in reality, you'd calculate the day of the week.
        // For simplicity, assume it's weekly starting from the given start date.
        return ((y > start_year) || (y == start_year && m > start_month) ||
                (y == start_year && m == start_month && d >= start_day)) && (d % 7 == start_day % 7);
    }
};


class Monthly : public Appointment {
private:
    int day;

public:
    Monthly(std::string desc, int d, int h, int min) : Appointment(desc, h, min), day(d) {}

    bool occurs_on(int y, int m, int d) override {
        return (day == d);  
    }
};


int main() {
    std::vector<Appointment*> appointments;

    // Add different types of appointments
    appointments.push_back(new Onetime("Dentist appointment", 2024, 10, 5, 14, 30));
    appointments.push_back(new Daily("Daily meeting", 9, 0));
    appointments.push_back(new Weekly("Weekly soccer practice", 2024, 9, 30, 16, 0));
    appointments.push_back(new Monthly("Pay rent", 1, 10, 0));

    int year, month, day;
    std::cout << "Enter a date (YYYY MM DD): ";
    std::cin >> year >> month >> day;

    std::cout << "Appointments on " << year << "-" << month << "-" << day << ":" << std::endl;
    for (Appointment* appt : appointments) {
        if (appt->occurs_on(year, month, day)) {
            appt->print();
        }
    }

    
    for (Appointment* appt : appointments) {
        delete appt;
    }

    return 0;
}
