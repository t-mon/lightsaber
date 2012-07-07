import QtQuick 1.1
import com.nokia.meego 1.0
import QtMobility.systeminfo 1.1

Page {
    id: settingsPage

    tools: commonTools

    ScreenSaver {
        screenSaverInhibited: true
    }

    Column {
        id: settingsCol
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: appWindow.pageMargin
        spacing: 10

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Lightsaber hit-sensitivity"
        }

        Slider {
            id: lightsaberSensitivityHit
            value: lightsaberSettings.lightsaberSensitivityHit
            maximumValue: 20
            minimumValue: 8
            stepSize: 1
            valueIndicatorVisible: true
            onValueChanged: lightsaberSettings.lightsaberSensitivityHit = lightsaberSensitivityHit.value

        }

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
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

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Lightsaber color"
        }

        Row {
            id: colorRow
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Rectangle {
                id: redLightsaberColorRectangle
                height: 60
                width: 60
                radius: 25
                border.color: "gray"
                border.width: 2

                color: "red"

                MouseArea {
                    id: redLightsaberColor
                    anchors.fill: parent

                    onPressed: {
                        redLightsaberColorRectangle.border.color = "white"
                        blueLightsaberColorRectangle.border.color = "gray"
                    }
                }
            }
            Rectangle {
                id: blueLightsaberColorRectangle
                height: 60
                width: 60
                radius: 25
                border.color: "gray"
                border.width: 2

                color: "blue"

                MouseArea {
                    id: blueLightsaberColor
                    anchors.fill: parent

                    onPressed: {
                        blueLightsaberColorRectangle.border.color = "white"
                        redLightsaberColorRectangle.border.color = "gray"
                    }
                }

            }
        }



    }

}
