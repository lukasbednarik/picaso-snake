import QtQuick 2.0

Rectangle {
    id: menuButton

    signal clicked
    property alias text: buttonText.text

    width: parent.width / 2
    height: screen.height / 12
    anchors.horizontalCenter: parent.horizontalCenter
    radius: 5
    antialiasing: true

    border {
        color: "black"
        width: 1
    }

    gradient: Gradient {
        GradientStop { position: 0.0; color: menuButton.focus ? "#FF6600" : "#FFFF99" }
        GradientStop { position: 1.0; color: menuButton.focus ? "#EE0000" : "#FF6600" }
    }

    Text {
        id: buttonText
        anchors.centerIn: menuButton
        font.pixelSize: menuButton.height / 1.414
        style: Text.Raised
        color: "black"
        styleColor: "gray"
    }

    MouseArea {
        anchors.fill: menuButton
        onClicked: menuButton.clicked()  // TODO animace na focus a potom emit signal
    }

    Keys.onSpacePressed: clicked()
    Keys.onReturnPressed: clicked()
}

