// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {
    id: settingsSeparator
    anchors.left: parent.left
    anchors.right: parent.right
    height: 20
    Rectangle{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        color: "transparent"
        height: parent.height
        width: parent.width
        Rectangle{
            anchors.left: parent.left
            height: 5
            width: parent.width *6/7
            color: "gray"
            smooth: true
        }
    }
}
