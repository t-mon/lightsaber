import QtQuick 1.1
import com.nokia.meego 1.0
import QtMobility.systeminfo 1.1

Page {
    id: settingsPage

    tools: commonTools

    ScreenSaver {
        screenSaverInhibited: lightsaberSettings.keepDisplayOn
    }

    Flickable {
        id: settingPageFlickable
        anchors.fill: parent
        contentHeight: settingsColumn.height
        flickableDirection: Flickable.VerticalFlick

        Column {
            id: settingsColumn
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: appWindow.pageMargin
            spacing: 10

            CheckBox{
                id: displaySuspendState
                text: displaySuspendState.checked ? "Screensaver Off" : "Screensaver On"
                checked: lightsaberSettings.keepDisplayOn
                onCheckedChanged: lightsaberSettings.keepDisplayOn = displaySuspendState.checked
            }
            CheckBox{
                id: showStatusBarState
                text: showStatusBarState.checked ? "Show statusbar On" : "Show statusbar Off"
                checked: lightsaberSettings.showStatusBar
                onCheckedChanged: lightsaberSettings.showStatusBar = showStatusBarState.checked
            }
            CheckBox{
                id: vibrationState
                text: vibrationState.checked ? "Vibration On" : "Vibration Off"
                checked: lightsaberSettings.vibrationOnOff
                onCheckedChanged: lightsaberSettings.vibrationOnOff = vibrationState.checked
            }

            SettingsSeparator{
            }

            Label {
                anchors.left: parent.left
                text: "Lightsaber hit-sensitivity"
            }

            Slider {
                id: lightsaberSensitivityHit
                value: lightsaberSettings.lightsaberSensitivityHit
                maximumValue: 20
                minimumValue: 8
                stepSize: 1
                valueIndicatorVisible: true
                onValueChanged:  lightsaberSettings.lightsaberSensitivityHit = lightsaberSensitivityHit.value

            }

            SettingsSeparator{
            }

            Label {
                anchors.left: parent.left
                text: "Lightsaber swing-sensitivity"
            }

            Slider {
                id: lightsaberSensitivitySwing
                maximumValue: 5
                minimumValue: 1
                value: 3
                stepSize: 1
                valueIndicatorVisible: true
            }

            SettingsSeparator{
            }

            Label {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Lightsaber colors"
            }

            Grid {
                id: colorRow
                columns: 3
                spacing: 15
                anchors.horizontalCenter: parent.horizontalCenter

                ColorButton{
                    color: "blue"
                }
                ColorButton{
                    color: "red"
                }
                ColorButton{
                    color: "green"
                }
                ColorButton{
                    color: "yellow"
                }
                ColorButton{
                    color: "violet"
                }
                ColorButton{
                    color: "orange"
                }
            }

            SettingsSeparator{
            }
        }
    }
}


