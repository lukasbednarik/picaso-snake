import QtQuick 2.0

Rectangle {
    id: gameMenu

    signal toMenu

    width: parent.width
    height: parent.height
    color: "lightblue"

    Text {
        id: title
        text: "Picaso Snake"
        font.family: "Ayuthaya"
        font.bold: true
        font.pointSize: screen.height / 10
    }

    Keys.onEscapePressed: toMenu()

    onToMenu: {
        gameMenu.visible = true
        //gameMenu.color = "transparent"
    }


    Column {
        width: parent.width
        spacing: parent.height / 10
        anchors.verticalCenter: parent.verticalCenter
        z: 1

        MenuButton {
            id: newgame
            text: "New game"
            focus: true
            KeyNavigation.up: quit
            KeyNavigation.down: score
            onClicked: {
                gameMenu.visible = false
                pageLoader.source = "play.qml"
            }
        }

        MenuButton {
            id: score
            text: "Score"
            KeyNavigation.up: newgame
            KeyNavigation.down: quit
            onClicked: {
                gameMenu.visible = false
                pageLoader.source = "score.qml"
            }
        }

        MenuButton {
            id: quit
            text: "Quit"
            KeyNavigation.up: score
            KeyNavigation.down: newgame
            onClicked: Qt.quit()
        }
    }
}

