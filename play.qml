import QtQuick 2.0
import SnakeGeometry 1.0


Repeater {
    width: screen.width
    height: screen.height
    model: myModel
    delegate: PolygonItem {
        height: screen.height / 6
        width: screen.width / 6
        x: model.modelData.x * screen.width
        y: model.modelData.y * screen.height
        color: model.modelData.color
        points: model.modelData.points
    }
}

