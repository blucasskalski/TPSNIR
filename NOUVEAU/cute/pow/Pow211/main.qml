import QtQuick 2.2
import QtQuick.Window 2.1
Window {
    visible: true
    width: 360
    height: 360
    Rectangle {
        id: main
        color: "#baaa9e"
        anchors.fill: parent
        Grid {
            id: grid
            anchors.centerIn: parent
            rows: 4
            columns: 4
            spacing: 10
            Repeater {
                model: 16
                delegate: Rectangle {
                    width: 70
                    height: 70
                    color: "#cbbeb1"
                    Text {
                        text: board.tile(index)
                    }
                }
            }
        }
    }
}
