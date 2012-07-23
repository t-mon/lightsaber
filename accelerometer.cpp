#include "accelerometer.h"
#include <QDebug>
#include <QAccelerometerReading>

Accelerometer::Accelerometer(QObject *parent) :
    QObject(parent)
{

    m_settings = new QSettings("lightsaber",QString(),this);
    m_sensor = new QAccelerometer(this);
    m_sensor->start();

    if (!m_sensor->isActive()){
        qDebug() << "accelerometer sensor didn't start!";
    }else{
        qDebug() << "accelerometer sensor started!";
    }

    sensitivityHit = m_settings->value("LightsaberSensitivityHit").toInt();
    sensitivitySwing = 3;

    connect(m_sensor,SIGNAL(readingChanged()),this,SLOT(accelerometerChanged()));
    connect(this,SIGNAL(accelerometerDataReady(qreal,qreal,qreal)),this,SLOT(detectLightsaberMove(qreal,qreal,qreal)));
}

void Accelerometer::setAccelerometerSensitivityHit(int sensitivity)
{
    sensitivityHit = sensitivity;
    qDebug() << "hit-sensitivitiy changed to " << sensitivity;
    emit accelerometerSensitivityHitChanged();
}

int Accelerometer::accelerometerSensitivityHit() const
{
    return sensitivityHit;
}

void Accelerometer::accelerometerChanged(){
    QAccelerometerReading *sensordata = m_sensor->reading();
    qreal x = sensordata->x();
    qreal y = sensordata->y();
    qreal z = sensordata->z();

    //qDebug() << "x=" << x << ", y=" << y << ", z=" << z;
    emit accelerometerDataReady(x,y,z);

}

void Accelerometer::detectLightsaberMove(const qreal &x, const qreal &y, const qreal &z)
{

    if( (x-accel_x > abs(sensitivityHit)) || (y-accel_y > abs(sensitivityHit)) || (z-accel_z > abs(sensitivityHit)) ){
        emit movementChanged(MovementHit);
        qDebug() << "lightsaber hit -> with sensitivityvalue: " << sensitivityHit;
    }else if((x-accel_x > abs(sensitivitySwing)) || (y-accel_y > abs(sensitivitySwing)) || (z-accel_z > abs(sensitivitySwing))){
        emit movementChanged(MovementSwing);
        qDebug() << "lightsaber slow movement  -> with sensitivityvalue: " << sensitivitySwing;
    }else{
        //qDebug() << "lightsaber no movement";
    }

    accel_x = x;
    accel_y = y;
    accel_z = z;
}
