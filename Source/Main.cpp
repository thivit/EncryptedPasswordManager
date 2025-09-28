#include "../Include/Cipher.hpp"
#include "../Include/FileManager.hpp"
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>
using namespace std;

// To complie please run this command in terminal:
//g++ -fPIC Main.cpp -o app `pkg-config --cflags --libs Qt5Widgets`
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout(&window);

    QLineEdit *input = new QLineEdit();
    input->setPlaceholderText("Enter plaintext");
    QLineEdit *key = new QLineEdit();
    key->setPlaceholderText("Enter key");
    layout->addWidget(input);
    layout->addWidget(key);

    window.setLayout(layout);
    window.setWindowTitle("Encrypted Password Manager");
    window.resize(400, 200);
    window.show();

    QPushButton button("generate text");
    layout->addWidget(&button);
    QObject::connect(&button, &QPushButton::clicked, [&]() {
        // string plaintext = input->text().toStdString();
        // string keyText = key->text().toStdString();
        // string ciphertext = Cipher::encrypt(plaintext, keyText);
        // input->setText(QString::fromStdString(ciphertext));
    //     FileManager::writeToFile("encrypted.txt", ciphertext);
    });
    return app.exec();
}
