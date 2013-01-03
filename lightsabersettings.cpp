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

#include "lightsabersettings.h"
#include <QDebug>


LightsaberSettings::LightsaberSettings(QObject *parent) :
    QObject(parent)
{
    m_settings = new QSettings("lightsaber",QString(),this);
}

int LightsaberSettings::lightsaberSensitivityHit() const
{
    return m_settings->value("LightsaberSensitivityHit",15).toInt();
}

void LightsaberSettings::setlightsaberSensitivityHit(int sensitivity)
{
    m_settings->setValue("LightsaberSensitivityHit", sensitivity);
    qDebug() << "hit-sensitivitiy saved to " << sensitivity;
    emit lightsaberHitSensChanged();
}

int LightsaberSettings::lightsaberSensitivitySwing() const
{
    return m_settings->value("LightsaberSensitivitySwing",4).toInt();
}

void LightsaberSettings::setlightsaberSensitivitySwing(int sensitivity)
{
    m_settings->setValue("LightsaberSensitivitySwing", sensitivity);
    qDebug() << "swing-sensitivitiy saved to " << sensitivity;
    emit lightsaberSwingSensChanged();
}


bool LightsaberSettings::isShowStatusBarOn()
{
    return m_settings->value("ShowStatusBar", true).toBool();
}

void LightsaberSettings::setDisplayStateOn(bool displaySuspandState){
    m_settings->setValue("DisplayAutoSuspend", displaySuspandState);
    qDebug() << "Display Settings Value saved to:" << displaySuspandState;
    emit keepDisplayOnChanged();
}

bool LightsaberSettings::isDisplayStateOn()
{
    return m_settings->value("DisplayAutoSuspend", true).toBool();
}

void LightsaberSettings::setShowStatusBar(bool showStatusBar)
{
    m_settings->setValue("ShowStatusBar", showStatusBar);
    qDebug() << "Show statusbar settings value saved to:" << showStatusBar;
    emit showStatusBarChanged();

}

QString LightsaberSettings::lightsaberColor() const
{
    return m_settings->value("Lightsaber_color", "blue").toString();
}

void LightsaberSettings::setLightsaberColor(QString color)
{
    m_settings->setValue("Lightsaber_color", color);
    qDebug() << "Lightsabercolor saved to " << color;
    emit lightsaberColorChanged();
}

QString LightsaberSettings::hiltCharacter() const
{
    return m_settings->value("HiltCharacter","DarthVader").toString();
}

void LightsaberSettings::setHiltCharacter(QString character)
{
    m_settings->setValue("HiltCharacter",character);
    qDebug() << "Hilt Character saved to " << character;
    emit hiltCharacterChanged();
}

bool LightsaberSettings::vibrationOnOff()
{
    return m_settings->value("Vibration", true).toBool();
}

void LightsaberSettings::setVibrationOnOff(bool vibrationOnOff)
{
    m_settings->setValue("Vibration", vibrationOnOff);
    qDebug() << "Vibration saved to " << vibrationOnOff;
    emit vibrationOnOffChanged();
}


