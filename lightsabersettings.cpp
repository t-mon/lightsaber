#include "lightsabersettings.h"
#include <QDebug>


LightsaberSettings::LightsaberSettings(QObject *parent) :
    QObject(parent)
{
    m_settings = new QSettings("lightsaber");
}



int LightsaberSettings::lightsaberSensitivityHit() const
{
    return m_settings->value("LightsaberSensitivityHit").toInt();
}

void LightsaberSettings::setlightsaberSensitivityHit(int sensitivity)
{
    m_settings->setValue("LightsaberSensitivityHit", sensitivity);
    qDebug() << "hit-sensitivitiy changed to " << sensitivity;
    emit lightsaberSensitivityHitChanged(sensitivity);
}

bool LightsaberSettings::isShowStatusBarOn()
{
    return m_settings->value("ShowStatusBar", true).toBool();
}

void LightsaberSettings::setDisplayStateOn(const bool &displaySuspandState){
    m_settings->setValue("DisplayAutoSuspend", displaySuspandState);
    qDebug() << "Display Settings Value changed to:" << displaySuspandState;
    emit keepDisplayOnChanged();
}

bool LightsaberSettings::isDisplayStateOn(){
    return m_settings->value("DisplayAutoSuspend", true).toBool();
}

void LightsaberSettings::setShowStatusBar(const bool &showStatusBar)
{
    m_settings->setValue("ShowStatusBar", showStatusBar);
    qDebug() << "Show statusbar settings value changed to:" << showStatusBar;
    emit showStatusBarChanged();

}

QString LightsaberSettings::lightsaberColor() const
{
    return m_settings->value("Lightsaber_color", "blue").toString();
}

void LightsaberSettings::setLightsaberColor(QString color)
{
    m_settings->setValue("Lightsaber_color", color);
    qDebug() << "Lightsabercolor changed to " << color;
    emit lightsaberColorChanged();
}


