import QtQuick 2.0


Item {
    id: screen
    width: 500
    height: 500

    Loader { id: pageLoader }

    GameMenu { id: gameMenu }
}

