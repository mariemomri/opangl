import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick3D 2.15  // Import QtQuick3D for OpenGL rendering

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "QtQuick CRUD Interface"

    Rectangle {
        width: parent.width
        height: parent.height
        color: "#ecf0f1"

        Column {
            spacing: 20
            anchors.centerIn: parent
            width: parent.width * 0.9

            // En-tête de l'application
            Text {
                text: "CRUD Operations"
                font.pixelSize: 24
                color: "#2c3e50"
                anchors.horizontalCenter: parent.horizontalCenter
            }

            // Champ de texte pour ID et Nom
            Row {
                spacing: 10
                width: parent.width
                anchors.horizontalCenter: parent.horizontalCenter

                // Champ de texte pour l'ID
                TextField {
                    id: idField
                    width: 100
                    height: 40
                    placeholderText: "ID"
                    font.pixelSize: 18
                    background: Rectangle {
                        color: "#ecf0f1"
                        radius: 10
                        border.color: "#bdc3c7"
                        border.width: 1
                    }
                }

                // Champ de texte pour le Nom
                TextField {
                    id: nameField
                    width: parent.width - idField.width - 20
                    height: 40
                    placeholderText: "Name"
                    font.pixelSize: 18
                    background: Rectangle {
                        color: "#ecf0f1"
                        radius: 10
                        border.color: "#bdc3c7"
                        border.width: 1
                    }
                }
            }

            // 4 boutons pour CRUD
            Row {
                spacing: 10
                width: parent.width
                anchors.horizontalCenter: parent.horizontalCenter

                // Bouton Ajouter
                Button {
                    text: "Ajouter"
                    width: 120
                    height: 50
                    background: Rectangle {
                        radius: 12
                        color: "#f39c12"
                        border.color: "#e67e22"
                        border.width: 2
                    }
                    onClicked: {
                        if (idField.text !== "" && nameField.text !== "") {
                            dbManager.addItem(idField.text, nameField.text); // Appel pour ajouter
                            listModel.append({itemId: idField.text, name: nameField.text});
                            idField.text = ""; // Clear ID field
                            nameField.text = ""; // Clear Name field
                        } else {
                            console.log("ID et Nom doivent être renseignés");
                        }
                    }
                }

                // Bouton Lire
                Button {
                    text: "Lire"
                    width: 120
                    height: 50
                    background: Rectangle {
                        radius: 12
                        color: "#f39c12"
                        border.color: "#e67e22"
                        border.width: 2
                    }
                    onClicked: {
                        var name = dbManager.getItemName(idField.text);
                        if (name !== "") {
                            nameField.text = name; // Afficher le nom
                        } else {
                            console.log("L'élément avec cet ID n'existe pas.");
                        }
                    }
                }

                // Bouton Mettre à jour
                Button {
                    text: "Mettre à jour"
                    width: 120
                    height: 50
                    background: Rectangle {
                        radius: 12
                        color: "#f39c12"
                        border.color: "#e67e22"
                        border.width: 2
                    }
                    onClicked: {
                        if (idField.text !== "" && nameField.text !== "") {
                            dbManager.updateItem(idField.text, nameField.text);
                            // Mise à jour de la liste d'éléments
                            for (var i = 0; i < listModel.count; i++) {
                                if (listModel.get(i).itemId === idField.text) {
                                    listModel.set(i, {itemId: idField.text, name: nameField.text});
                                }
                            }
                            idField.text = "";
                            nameField.text = "";
                        } else {
                            console.log("ID et Nom doivent être renseignés");
                        }
                    }
                }

                // Bouton Supprimer avec le design
                Button {
                    text: "Supprimer"
                    width: 120
                    height: 50
                    background: Rectangle {
                        radius: 12
                        color: "#f39c12"
                        border.color: "#e67e22"
                        border.width: 2
                    }
                    onClicked: {
                        for (var i = 0; i < listModel.count; i++) {
                            if (listModel.get(i).itemId === idField.text) {
                                listModel.remove(i);  // Suppression de l'élément du modèle
                                idField.text = "";     // Effacer le champ ID
                                nameField.text = "";   // Effacer le champ Nom
                                break;
                            }
                        }
                    }
                }
            }

            // Liste des éléments ajoutés
            ScrollView {
                width: parent.width
                height: 200
                contentItem: ListView {
                    width: parent.width
                    height: 200
                    model: listModel
                    delegate: Rectangle {
                        width: parent.width
                        height: 50
                        color: "#ecf0f1"
                        border.color: "#bdc3c7"
                        radius: 8
                        Row {
                            anchors.fill: parent
                            spacing: 10
                            Text {
                                text: "ID: " + model.itemId
                                color: "#2c3e50"
                                font.pixelSize: 16
                            }
                            Text {
                                text: "Name: " + model.name
                                color: "#2c3e50"
                                font.pixelSize: 16
                            }
                        }
                    }
                }
            }

            // Modèle de liste pour afficher les éléments
            ListModel {
                id: listModel
                ListElement { itemId: "1"; name: "Item 1" }
                ListElement { itemId: "2"; name: "Item 2" }
            }

            // 3D OpenGL View (using View3D)
            View3D {
                id: view3D
                width: parent.width
                height: 200
                clearColor: "lightgray"  // Background color for OpenGL

                // Camera for the 3D view
                Camera {
                    id: camera
                    position: Qt.vector3d(0, 0, 10)  // Camera position
                    lookAt: Qt.vector3d(0, 0, 0)     // Camera target
                }

                // Simple 3D cube
                Model {
                    source: "#cube"  // Built-in cube model
                    scale: Qt.vector3d(2, 2, 2)
                    position: Qt.vector3d(0, 0, 0)
                    material: DefaultMaterial {
                        diffuseColor: "blue"
                    }
                }
            }
        }
    }
}
