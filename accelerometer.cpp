#include "accelerometer.h"
#include <QDebug>
#include <QAccelerometerReading>

Accelerometer::Accelerometer(QObject *parent) :
    QObject(parent)
{
    m_sensor = new QAccelerometer(this);
    m_sensor->start();

    if (!m_sensor->isActive()){
        qDebug() << "accelerometer sensor didn't start!";
    }else{
        qDebug() << "accelerometer sensor started!";
    }

    connect(m_sensor,SIGNAL(readingChanged()),this,SLOT(accelerometerChanged()));
}

void Accelerometer::accelerometerChanged(){
    QAccelerometerReading *sensordata = m_sensor->reading();
    qreal x = sensordata->x();
    qreal y = sensordata->y();
    qreal z = sensordata->z();
    //qDebug() << "x=" << x << ", y=" << y << ", z=" << z;
    emit accelerometerDataReady(x,y,z);

}

