#include "../Include/Cipher.hpp"
#include "../Include/FileManager.hpp"
// #include "Cipher.cpp"
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QWidget>
#include <QComboBox>
#include <QLabel>
using namespace std;

// To complie please run this command in terminal:
//g++ -fPIC Main.cpp Cipher.cpp FileManager.cpp -o main `pkg-config --cflags --libs Qt5Widgets`

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;

    QVBoxLayout *layout = new QVBoxLayout(&window);
    QHBoxLayout *topLayout = new QHBoxLayout();

    QLineEdit *input = new QLineEdit();
    input->setPlaceholderText("Enter plaintext");
    QLineEdit *key = new QLineEdit();
    QTextEdit *res = new QTextEdit();

    res->setReadOnly(true);
    //dropdownbox
    QComboBox *dropbox = new QComboBox();
    dropbox->addItem("Encrypt");
    dropbox->addItem("Decrypt");
    QLabel *modeLabel = new QLabel("Mode:");

    key->setPlaceholderText("Enter key");

    topLayout->addWidget(modeLabel);
    layout->addWidget(dropbox);
    topLayout->addStretch(1);
    layout->addWidget(input);
    layout->addWidget(key);
    layout->addWidget(res);

    window.setLayout(layout);
    window.setWindowTitle("Encrypted Password Manager");
    window.resize(450, 250);
    window.show();

    QPushButton button("generate text");
    layout->addWidget(&button);
    QObject::connect(&button, &QPushButton::clicked, [&]() {
        QString choice =dropbox->currentText();
        if(choice == "Encrypt"){
            string plaintext = input->text().toStdString();
            string keyText = key->text().toStdString();
            string ciphertext = Cipher::vigenereEncrypt(plaintext, keyText);
            res->setText(QString::fromStdString(ciphertext));
            FileManager::writeToFile("encrypted.txt", ciphertext);
        } else if (choice =="Decrypt"){
            string ciphertext = input->text().toStdString();
            string keyText = key->text().toStdString();
            string plaintext = Cipher::vigenereDecrypt(ciphertext, keyText);
            res->setText(QString::fromStdString(plaintext));
            FileManager::writeToFile("decrypted.txt", plaintext);
        }
    });
    return app.exec();
}
