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

#include "vibration.h"

Vibration::Vibration(QObject *parent) :
    QObject(parent)
{
    m_settings = new QSettings("lightsaber",QString(),this);

}

void Vibration::powerOnVibration()
{
    if(m_settings->value("Vibration").toBool()){
        m_rumble.setAttackIntensity(1);
        m_rumble.setAttackTime(1000);
        m_rumble.setIntensity(0.005);
        m_rumble.setDuration(2800);
        m_rumble.setFadeTime(1400);
        m_rumble.setFadeIntensity(1);
        m_rumble.start();
    }


}

void Vibration::powerOffVibration()
{
    if(m_settings->value("Vibration").toBool()){
        m_rumble.setAttackIntensity(0.05);
        m_rumble.setAttackTime(300);
        m_rumble.setIntensity(0.1);
        m_rumble.setDuration(640);
        m_rumble.setFadeTime(340);
        m_rumble.setFadeIntensity(1);
        m_rumble.start();
    }
}

void Vibration::swingVibration()
{
    if(m_settings->value("Vibration").toBool()){
        m_rumble.setAttackIntensity(0.01);
        m_rumble.setAttackTime(150);
        m_rumble.setIntensity(1);
        m_rumble.setDuration(790);
        m_rumble.setFadeTime(240);
        m_rumble.setFadeIntensity(0.01);
        m_rumble.start();
    }
}

void Vibration::hitVibration()
{
    if(m_settings->value("Vibration").toBool()){
        m_rumble.setAttackIntensity(1);
        m_rumble.setAttackTime(300);
        m_rumble.setIntensity(1);
        m_rumble.setDuration(400);
        m_rumble.setFadeTime(100);
        m_rumble.setFadeIntensity(0.5);
        m_rumble.start();
    }
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
