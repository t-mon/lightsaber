#include "vibration.h"

Vibration::Vibration(QObject *parent) :
    QObject(parent)
{
    m_settings = new QSettings("lightsaber");

}

void Vibration::powerOnVibration()
{

    m_rumble.setAttackIntensity(1);
    m_rumble.setAttackTime(1000);
    m_rumble.setIntensity(0.005);
    m_rumble.setDuration(2800);
    m_rumble.setFadeTime(1400);
    m_rumble.setFadeIntensity(1);
    m_rumble.start();

}

void Vibration::powerOffVibration()
{
    m_rumble.setAttackIntensity(0.05);
    m_rumble.setAttackTime(300);
    m_rumble.setIntensity(0.1);
    m_rumble.setDuration(640);
    m_rumble.setFadeTime(340);
    m_rumble.setFadeIntensity(1);
    m_rumble.start();
}

void Vibration::swingVibration()
{
    m_rumble.setAttackIntensity(0.01);
    m_rumble.setAttackTime(150);
    m_rumble.setIntensity(1);
    m_rumble.setDuration(790);
    m_rumble.setFadeTime(240);
    m_rumble.setFadeIntensity(0.01);
    m_rumble.start();
}

void Vibration::hitVibration()
{
    m_rumble.setAttackIntensity(1);
    m_rumble.setAttackTime(300);
    m_rumble.setIntensity(1);
    m_rumble.setDuration(400);
    m_rumble.setFadeTime(100);
    m_rumble.setFadeIntensity(0.5);
    m_rumble.start();
}


void Vibration::startstopVibration(const bool &powerstate)
{
    if(powerstate){
        m_rumble.stop();
        if(m_settings->value("Vibration").toBool()){
            powerOnVibration();
        }

    } else {
        m_rumble.stop();
        if(m_settings->value("Vibration").toBool()){
            powerOffVibration();
        }
    }
}

void Vibration::stopVibration()
{
    m_rumble.stop();
}
