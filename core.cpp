#include "core.h"
#include <stdlib.h>
#include <QDebug>

Core::Core(QObject *parent) :
    QObject(parent)
{

    m_accelerometer = new Accelerometer(this);
    m_soundeffects = new Soundeffects(this);
    m_settings = new LightsaberSettings(this);

    sensitivityHit = m_settings->getsensitivityHit();
    sensitivitySwing = 3;

    //Sound connectons
    connect(this,SIGNAL(lightsaberMoved(QString)),m_soundeffects,SLOT(playSaberEffect(QString)));
    connect(this,SIGNAL(lightsaberPowerChanged(bool)),m_soundeffects,SLOT(playOnOffSound(bool)));

    connect(m_accelerometer,SIGNAL(accelerometerDataReady(qreal,qreal,qreal)),this,SLOT(detectLightsaberMove(qreal,qreal,qreal)));
    connect(m_settings,SIGNAL(sensitivityHitChanged(int)),this,SLOT(lightsaberSensitivityHitChanged(int)));
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
        emit lightsaberMoved("/home/user/lightsaber/ltsaberhit01.wav");
        qDebug() << "lightsaber hit";
    }else if((x-accel_x > abs(sensitivitySwing)) || (y-accel_y > abs(sensitivitySwing)) || (z-accel_z > abs(sensitivitySwing))){
        emit lightsaberMoved("/home/user/lightsaber/SlowSabr.wav");
        qDebug() << "lightsaber slow movement";
    }else{
        //qDebug() << "lightsaber no movement";
    }


    accel_x = x;
    accel_y = y;
    accel_z = z;
}

void Core::on_lightsaberPowerChanged()
{
    qDebug() << "Lightsaber Power Status changed to " << lightsaberPowerStatus;
    if(lightsaberPowerStatus){
        emit lightsaberMoved("/home/user/lightsaber/ltsaberon01.wav");
    } else {
        emit lightsaberMoved("/home/user/lightsaber/ltsaberoff01.wav");
    }

}

void Core::lightsaberSensitivityHitChanged(int sensitivity)
{
    sensitivityHit = sensitivity;
    qDebug() << "test";
}
