#ifndef BASEBALL_CPLUS_SKILLS_H
#define BASEBALL_CPLUS_SKILLS_H

class Batting {
public:
    Batting() = default;
    Batting(int contact, int power) : m_contact(contact), m_power(power) {};

    int m_contact = 50;
    int m_power = 60;
};

class Fielding {
public:
    Fielding() = default;
    Fielding(int Throw, int accuracity) : m_throw(Throw), m_accuracity(accuracity) {};

    int m_throw = 60;
    int m_accuracity = 70;
};

class BaseRunning {
public:
    BaseRunning() = default;
    BaseRunning(int speed, int steal) : m_speed(speed), m_steal(steal) {};

    int m_speed = 60;
    int m_steal = 50;
};


#endif //BASEBALL_CPLUS_SKILLS_H
