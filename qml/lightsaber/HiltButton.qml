import QtQuick 1.1
import com.nokia.meego 1.0

Item {
    id: hiltButton
    property string character
    height: 210
    width: 90
    Rectangle {
        anchors.fill: parent
        radius: 20
        border.color: LightsaberSettings.hiltCharacter == hiltButton.character ? "white" : "gray"
        border.width: LightsaberSettings.hiltCharacter == hiltButton.character ? 7 : 5
        color: "transparent"

        Image {

            height: 180
            width: 60
            id: hiltButtonImage
            anchors.centerIn: parent
            source: "lightsaber_hilt_" + hiltButton.character + "_on.png"
        }

        MouseArea {
            anchors.fill: parent
            onPressed: {
                LightsaberSettings.hiltCharacter = hiltButton.character
            }
        }
    }
}
