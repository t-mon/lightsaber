#include "lightsabersettings.h"
#include <QDebug>


LightsaberSettings::LightsaberSettings(QObject *parent) :
    QObject(parent)
{
    m_settings = new QSettings("lightsaber",QString(),this);
}


int LightsaberSettings::lightsaberSensitivityHit() const
{
    return m_settings->value("LightsaberSensitivityHit").toInt();
}

void LightsaberSettings::setlightsaberSensitivityHit(int sensitivity)
{
    m_settings->setValue("LightsaberSensitivityHit", sensitivity);
    qDebug() << "hit-sensitivitiy saved to " << sensitivity;
    emit lightsaberHitSensChanged();
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


