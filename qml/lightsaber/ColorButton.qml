import QtQuick 1.1
import com.nokia.meego 1.0

Item {
    id: colorButton
    property string color
    height: 90
    width: 90
    Rectangle {
        anchors.fill: parent
        radius: 30
        border.color: lightsaberSettings.lightsaberColor == colorButton.color ? "white" : "gray"
        border.width: 5
        color: colorButton.color

        MouseArea {
            anchors.fill: parent
            onPressed: {
                lightsaberSettings.lightsaberColor = colorButton.color
            }
        }
    }
}