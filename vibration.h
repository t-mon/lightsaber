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

#ifndef VIBRATION_H
#define VIBRATION_H

#include <QObject>
#include <QFeedbackHapticsEffect>
#include <QSettings>

QTM_USE_NAMESPACE


class Vibration : public QObject
{
    Q_OBJECT
public:
    explicit Vibration(QObject *parent = 0);

private:
    QFeedbackHapticsEffect m_rumble;
    QSettings *m_settings;
    
public slots:
    void powerOnVibration();
    void powerOffVibration();
    void swingVibration();
    void hitVibration();
    void stopVibration();
    void startstopVibration(const bool &powerstate);
    
};

#endif // VIBRATION_H
