#include "core.h"
#include <stdlib.h>
#include <QDebug>


Core::Core(QObject *parent) :
    QObject(parent)
{

    m_accelerometer = new Accelerometer(this);
    m_soundeffects = new Soundeffects(this);
    m_settings = new LightsaberSettings(this);
    m_vibration = new Vibration(this);


    //Sound connectons
    //connect(this,SIGNAL(lightsaberMoved(int)),m_soundeffects,SLOT(playSaberEffect(int)));
    connect(m_accelerometer,SIGNAL(movementChanged(Accelerometer::Movement)),this,SLOT(lightsaberMovementRecognized(Accelerometer::Movement)));
    connect(this,SIGNAL(lightsaberPowerChanged(bool)),m_soundeffects,SLOT(playOnOffSound(bool)));
    connect(this,SIGNAL(lightsaberPowerChanged(bool)),m_vibration,SLOT(startstopVibration(bool)));

    connect(m_soundeffects,SIGNAL(playHitsound()),m_vibration,SLOT(hitVibration()));
    connect(m_soundeffects,SIGNAL(playSwingsound()),m_vibration,SLOT(swingVibration()));

}

void Core::setlightsaberPowerStatus(bool status)
{
    lightsaberPowerStatus = status;
    qDebug() << "Lightsaber Power Status changed to " << lightsaberPowerStatus;
    emit lightsaberPowerChanged(lightsaberPowerStatus);

}

bool Core::getlightsaberPowerStatus()
{
    return lightsaberPowerStatus;
}

void Core::lightsaberMovementRecognized(Accelerometer::Movement movement)
{
    switch(movement){
        case Accelerometer::MovementHit:
            m_soundeffects->playSaberEffect(Soundeffects::SoundEffectHit);
            qDebug() << "------------hit";
        case Accelerometer::MovementSwing:
            m_soundeffects->playSaberEffect(Soundeffects::SoundEffectSwing);
            qDebug() << "------------swing";

    }

}




