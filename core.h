/*  Lightsaber
 *
 *  Copyright (C) 2012 Simon Stuerz
 *  stuerz.simon@gmail.com
 *
 *  Lightsaber is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Lightsaber is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <qmlapplicationviewer.h>

#include "accelerometer.h"
#include "soundeffects.h"
#include "lightsabersettings.h"
#include "vibration.h"
#include "meegostuff.h"

class Core : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool lightsaberPower READ lightsaberPower WRITE setlightsaberPowerStatus NOTIFY lightsaberPowerChanged())

public:
    explicit Core(QObject *parent = 0);
    bool lightsaberPower();
    bool lightsaberPowerStatus;

private:
    Soundeffects *m_soundeffects;
    LightsaberSettings *m_settings;
    Vibration *m_vibration;
    MeeGoStuff *m_system;
    Accelerometer *m_accelerometer;
    QmlApplicationViewer *m_viewer;

signals:
    void lightsaberMoved(const int &swingOrHit);
    void lightsaberPowerChanged(const bool &lightsaberPower);
    
private slots:
    void lightsaberMovementRecognized(Accelerometer::Movement movement);
    void setlightsaberPowerStatus(bool status);

};

#endif // CORE_H
