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

    sensitivityHit = 14;
    sensitivitySwing = 3;

    swing = 0;
    hit = 1;

    //Sound connectons
    connect(this,SIGNAL(lightsaberMoved(int)),m_soundeffects,SLOT(playSaberEffect(int)));
    connect(this,SIGNAL(lightsaberPowerChanged(bool)),m_soundeffects,SLOT(playOnOffSound(bool)));
    connect(this,SIGNAL(lightsaberPowerChanged(bool)),m_vibration,SLOT(startstopVibration(bool)));

    connect(m_soundeffects,SIGNAL(playHitsound()),m_vibration,SLOT(hitVibration()));
    connect(m_soundeffects,SIGNAL(playSwingsound()),m_vibration,SLOT(swingVibration()));

    connect(m_accelerometer,SIGNAL(accelerometerDataReady(qreal,qreal,qreal)),this,SLOT(detectLightsaberMove(qreal,qreal,qreal)));
    connect(m_settings,SIGNAL(lightsaberSensitivityHitChanged(int)),this,SLOT(on_lightsaberSensitivityHitChanged(int)));
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




void Core::detectLightsaberMove(const qreal &x, const qreal &y, const qreal &z)
{

    if( (x-accel_x > abs(sensitivityHit)) || (y-accel_y > abs(sensitivityHit)) || (z-accel_z > abs(sensitivityHit)) ){
        emit lightsaberMoved(hit);
        qDebug() << "lightsaber hit -> with sensitivityvalue: " << sensitivityHit;
    }else if((x-accel_x > abs(sensitivitySwing)) || (y-accel_y > abs(sensitivitySwing)) || (z-accel_z > abs(sensitivitySwing))){
        emit lightsaberMoved(swing);
        qDebug() << "lightsaber slow movement  -> with sensitivityvalue: " << sensitivitySwing;
    }else{
        //qDebug() << "lightsaber no movement";
    }

    accel_x = x;
    accel_y = y;
    accel_z = z;
}



void Core::on_lightsaberSensitivityHitChanged(const int &sensitivity)
{
    sensitivityHit = sensitivity;
    qDebug() << "test changed sens hit";
}

