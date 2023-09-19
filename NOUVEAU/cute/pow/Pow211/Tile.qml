import QtQuick 2.2

Rectangle {
    id: tile
    property int tileWidth: 70
    property string tileValue: ""
    property string tileColor: "lightsteelblue"
    function fontSize(value) {
        var v = parseInt(value, 10);
        if (v < 1024) return tileWidth / 2.5;
        return tileWidth / 3;
    }
    width: tileWidth
    height: tileWidth
    radius: tileWidth / 10
    color: tileColor
    Text {
        text: tileValue
        font.pointSize: fontSize(tileValue)
        anchors.centerIn: parent
        color: "black"
    }
}
