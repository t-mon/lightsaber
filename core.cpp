#include "core.h"
#include <stdlib.h>
#include <QDebug>
#include <QtDeclarative>
#include <QDeclarativeContext>

Core::Core(QObject *parent) :
    QObject(parent)
{

    m_accelerometer = new Accelerometer(this);
    m_soundeffects = new Soundeffects(this);
    m_settings = new LightsaberSettings(this);
    m_vibration = new Vibration(this);
    m_system = new MeeGoStuff(this);

    m_qmlDeclarativeView.rootContext()->setContextProperty("accelerometerData",m_accelerometer);
    m_qmlDeclarativeView.show();

    lightsaberPowerStatus = false;


    //Sound connectons
    connect(this,SIGNAL(lightsaberPowerChanged(bool)),m_soundeffects,SLOT(playOnOffSound(bool)));
    connect(this,SIGNAL(lightsaberPowerChanged(bool)),m_vibration,SLOT(startstopVibration(bool)));

    connect(m_accelerometer,SIGNAL(movementChanged(Accelerometer::Movement)),this,SLOT(lightsaberMovementRecognized(Accelerometer::Movement)));

    connect(m_soundeffects,SIGNAL(playHitsound()),m_vibration,SLOT(hitVibration()));
    connect(m_soundeffects,SIGNAL(playSwingsound()),m_vibration,SLOT(swingVibration()));

    connect(m_system,SIGNAL(powerStatusChangedByKey(bool)),this,SLOT(setlightsaberPowerStatus(bool)));

}

void Core::setlightsaberPowerStatus(bool status)
{
    if(lightsaberPowerStatus != status){
        lightsaberPowerStatus = status;
        qDebug() << "Lightsaber Power Status changed to " << lightsaberPowerStatus;
        emit lightsaberPowerChanged(lightsaberPowerStatus);
    }
}

bool Core::lightsaberPower()
{
    return lightsaberPowerStatus;
}

void Core::lightsaberMovementRecognized(Accelerometer::Movement movement)
{
    switch(movement){
    case Accelerometer::MovementHit:
        m_soundeffects->playSaberEffect(Soundeffects::SoundEffectHit);
        break;
    case Accelerometer::MovementSwing:
        m_soundeffects->playSaberEffect(Soundeffects::SoundEffectSwing);
        break;
    }

}




