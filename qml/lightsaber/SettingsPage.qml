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

import QtQuick 1.1
import com.nokia.meego 1.0
import QtMobility.systeminfo 1.1

Page {
    id: settingsPage

    tools: commonTools

    ScreenSaver {
        screenSaverInhibited: LightsaberSettings.keepDisplayOn
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
            spacing: 10

            CheckBox{
                id: displaySuspendState
                text: displaySuspendState.checked ? "Screensaver Off" : "Screensaver On"
                checked: LightsaberSettings.keepDisplayOn
                //onCheckedChanged: lightsaberSettings.keepDisplayOn = displaySuspendState.checked
            }
            CheckBox{
                id: showStatusBarState
                text: showStatusBarState.checked ? "Show statusbar On" : "Show statusbar Off"
                checked: LightsaberSettings.showStatusBar
                //onCheckedChanged: lightsaberSettings.showStatusBar = showStatusBarState.checked
            }
            CheckBox{
                id: vibrationState
                text: vibrationState.checked ? "Vibration On" : "Vibration Off"
                checked: LightsaberSettings.vibrationOnOff
            }

            SettingsSeparator{
            }

            Label {
                anchors.left: parent.left
                text: "Lightsaber hit-sensitivity"
            }

            Slider {
                id: lightsaberSensitivityHit
                value: LightsaberSettings.lightsaberSensitivityHit
                maximumValue: 20
                minimumValue: 7
                stepSize: 1
                valueIndicatorVisible: true

                valueIndicatorText: if(value <= 11){
                                        "low"
                                    }else if(value <= 16 && value > 11){
                                        "medium"
                                    }else if(value <=20 && value > 16){
                                        "high"
                                    }
                onValueChanged: accelerometerData.accelerometerSensitivityHit = value
            }

            SettingsSeparator{
            }

            Label {
                anchors.left: parent.left
                text: "Lightsaber swing-sensitivity"
            }

            Slider {
                id: lightsaberSensitivitySwing
                maximumValue: 6
                minimumValue: 1
                value: LightsaberSettings.lightsaberSensitivitySwing
                stepSize: 1
                valueIndicatorVisible: true

                valueIndicatorText: if(value <= 2){
                                        "low"
                                    }else if(value <=4 && value > 2){
                                        "medium"
                                    }else if(value <=6 && value > 4){
                                        "high"
                                    }
                onValueChanged: accelerometerData.accelerometerSensitivitySwing = value

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

            Row{
                id: hiltCharacterRow
                spacing: 15
                anchors.horizontalCenter: parent.horizontalCenter

                HiltButton{
                    character: "LukeSkywalker"
                }
                HiltButton{
                    character: "DarthVader"
                }
            }

            Label {
                id: hiltCharacterLabel
                anchors.horizontalCenter: parent.horizontalCenter
                text: LightsaberSettings.hiltCharacter

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
                LightsaberSettings.keepDisplayOn = displaySuspendState.checked
                LightsaberSettings.showStatusBar = showStatusBarState.checked
                LightsaberSettings.vibrationOnOff = vibrationState.checked
                LightsaberSettings.lightsaberSensitivityHit = lightsaberSensitivityHit.value
                LightsaberSettings.lightsaberSensitivitySwing = lightsaberSensitivitySwing.value
                pageStack.pop(settingsPage);
                myMenu.close();

            }
        }

        ToolIcon {
            platformIconId: "toolbar-view-menu"
            anchors.right: parent.right
            onClicked: {
                if(myMenu.status == DialogStatus.Open){
                    myMenu.close();
                }else{
                    myMenu.open()
                }
            }
        }
    }
}
