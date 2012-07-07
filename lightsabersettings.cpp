#include "lightsabersettings.h"
#include <QDebug>
LightsaberSettings::LightsaberSettings(QObject *parent) :
    QObject(parent)
{
    m_settings = new QSettings("lightsaber");
}
void LightsaberSettings::setsensitivityHit(const int &sensitivity)
{
    m_settings->setValue("hit_sensitivity",sensitivity);
    qDebug() << "hit-sensitivity set to" << sensitivity;
    emit sensitivityHitChanged(sensitivity);
}

int LightsaberSettings::getsensitivityHit()
{
    return m_settings->value("hit_sensitivity",10).toInt();
}


void LightsaberSettings::setDisplayStateOn(const bool &displaySuspandState){
    m_settings->setValue("DisplayAutoSuspend", displaySuspandState);
    qDebug() << "Display Settings Value changed to:" << displaySuspandState;
    emit keepDisplayOnChanged();
}

bool LightsaberSettings::isShowStatusBarOn()
{
    return m_settings->value("ShowStatusBar", true).toBool();
}

bool LightsaberSettings::isDisplayStateOn(){
    return m_settings->value("DisplayAutoSuspend", true).toBool();
}

void LightsaberSettings::setShowStatusBar(const bool &showStatusBar)
{
    m_settings->setValue("ShowStatusBar", showStatusBar);
    qDebug() << "Statusbar Settings Value changed to:" << showStatusBar;
    emit showStatusBarChanged();

}
