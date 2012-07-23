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
            }
            CheckBox{
                id: showStatusBarState
                text: showStatusBarState.checked ? "Show statusbar On" : "Show statusbar Off"
                checked: lightsaberSettings.showStatusBar
            }
            CheckBox{
                id: vibrationState
                text: vibrationState.checked ? "Vibration On" : "Vibration Off"
                checked: lightsaberSettings.vibrationOnOff
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
                valueIndicatorText: if(value < 12){
                                        "low"
                                    }else if(value < 16 && value >= 12){
                                        "medium"
                                    }else if(value <=20 && value >= 16){
                                        "high"
                                    }
                onValueChanged: accelerometer.accelerometerSensitivityHit = value
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
    ToolBar {
        id: commonTools



        ToolIcon {
            platformIconId: "toolbar-back"
            anchors.left: parent.left
            onClicked: {
                lightsaberSettings.keepDisplayOn = displaySuspendState.checked
                lightsaberSettings.lightsaberSensitivityHit = lightsaberSensitivityHit.value
                lightsaberSettings.showStatusBar = showStatusBarState.checked
                lightsaberSettings.vibrationOnOff = vibrationState.checked
                pageStack.pop(settingsPage);

            }
        }

        ToolIcon {
            platformIconId: "toolbar-view-menu"
            anchors.right: parent.right
            onClicked: {
                myMenu.open();
            }
        }

    }
}
