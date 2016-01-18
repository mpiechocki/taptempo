import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    id: window
    width: 300
    height: 500
    visible: true

    Image {
        id: background
        source: "images/background.png"
        anchors.fill: parent
    }

    Rectangle {
        id: bpmRect
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: parent.height / 6
        color: "white"
        width: 70
        height: 70
        radius: 20

        Text {
            id: bpmText
            text: "--"
            font.bold: true
            font.pointSize: 20
            anchors.centerIn: parent

            Connections {
                target: logic
                onNewBpm: {
                    bpmText.text = logic.bpm()
                }
            }
        }
    }

    Rectangle {
        id: tapArea
        width: 100
        height: 100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height / 6
        color: "transparent"

        Image {
            source: "images/pushbutton.png"
            anchors.fill: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                logic.tapClicked()
            }
        }
    }
}

