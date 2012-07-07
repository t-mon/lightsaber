#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <QObject>
#include <QSensor>
#include <QAccelerometer>
#include <QTimer>


QTM_USE_NAMESPACE


class Accelerometer : public QObject
{
    Q_OBJECT
public:
    explicit Accelerometer(QObject *parent = 0);
    
    private:
    QAccelerometer *m_sensor;

signals:
    void accelerometerDataReady(const qreal &x, const qreal &y, const qreal &z);
    
private slots:
    void accelerometerChanged();

};

#endif // ACCELEROMETER_H
