#include "../Include/Cipher.hpp"
#include "../Include/FileManager.hpp"
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QStackedWidget>
#include <QHBoxLayout>
using namespace std;

// To compile:
// g++ -fPIC Main.cpp Cipher.cpp FileManager.cpp -o main `pkg-config --cflags --libs Qt5Widgets`

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create stacked widget to manage pages
    QStackedWidget *stack = new QStackedWidget();

    // ========== FRONT PAGE ==========
    QWidget *frontPage = new QWidget();
    QVBoxLayout *frontLayout = new QVBoxLayout(frontPage);

    QLabel *header = new QLabel("Welcome to Encryption Password Management");
    header->setAlignment(Qt::AlignCenter);
    header->setStyleSheet("font-size: 18px; font-weight: bold; margin: 10px;");

    QPushButton *addCredential = new QPushButton("Add Credential");
    QPushButton *deleteCredential = new QPushButton("Delete Credential");
    QPushButton *findCredential = new QPushButton("Find Credential");
    QPushButton *updateCredential = new QPushButton("Update Credential");

    frontLayout->addWidget(header);
    frontLayout->addSpacing(20);
    frontLayout->addWidget(addCredential);
    frontLayout->addWidget(deleteCredential);
    frontLayout->addWidget(findCredential);
    frontLayout->addWidget(updateCredential);
    frontLayout->addStretch();

    // ========== FEATURE PAGE (Encrypt/Decrypt UI) ==========
    QWidget *featurePage = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(featurePage);

    QComboBox *dropbox = new QComboBox();
    dropbox->addItem("Encrypt");
    dropbox->addItem("Decrypt");

    QLineEdit *input = new QLineEdit();
    input->setPlaceholderText("Enter plaintext or ciphertext");

    QLineEdit *key = new QLineEdit();
    key->setPlaceholderText("Enter key");

    QTextEdit *res = new QTextEdit();
    res->setReadOnly(true);

    QPushButton *generateBtn = new QPushButton("Generate");
    QPushButton *backBtn = new QPushButton("← Back to Home");

    layout->addWidget(new QLabel("Mode:"));
    layout->addWidget(dropbox);
    layout->addWidget(input);
    layout->addWidget(key);
    layout->addWidget(res);
    layout->addWidget(generateBtn);
    layout->addWidget(backBtn);

    // Add pages to stack
    stack->addWidget(frontPage);   // index 0
    stack->addWidget(featurePage); // index 1

    // Show initial front page
    QWidget window;
    QVBoxLayout *mainLayout = new QVBoxLayout(&window);
    mainLayout->addWidget(stack);
    window.setWindowTitle("Encrypted Password Manager");
    window.resize(450, 300);
    window.show();

    // ========== CONNECTIONS ==========
    auto goToFeaturePage = [stack]() { stack->setCurrentIndex(1); };
    QObject::connect(addCredential, &QPushButton::clicked, goToFeaturePage);
    QObject::connect(deleteCredential, &QPushButton::clicked, goToFeaturePage);
    QObject::connect(findCredential, &QPushButton::clicked, goToFeaturePage);
    QObject::connect(updateCredential, &QPushButton::clicked, goToFeaturePage);

    QObject::connect(backBtn, &QPushButton::clicked, [stack]() {
        stack->setCurrentIndex(0);
    });

    QObject::connect(generateBtn, &QPushButton::clicked, [=]() {
        QString choice = dropbox->currentText();
        string text = input->text().toStdString();
        string keyText = key->text().toStdString();

        if (choice == "Encrypt") {
            string ciphertext = Cipher::vigenereEncrypt(text, keyText);
            res->setText(QString::fromStdString(ciphertext));
            FileManager::writeToFile("encrypted.txt", ciphertext);
        } else {
            string plaintext = Cipher::vigenereDecrypt(text, keyText);
            res->setText(QString::fromStdString(plaintext));
            FileManager::writeToFile("decrypted.txt", plaintext);
        }
    });

    return app.exec();
}
